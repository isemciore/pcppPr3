//
// Created by erik on 2015-11-10.
//

#include <iostream>
#include "curveBase.h"

curvebase::curvebase()
{
}

double curvebase::x(double s) {
    std::map<double,double>::iterator itpMap = sToPmap.find(s);
    if (itpMap == sToPmap.end()){
        newtonStoP(s);
        itpMap = sToPmap.find(s);
    }
    double pValue = itpMap->second;
    return xp(pValue);
}

double curvebase::y(double s) {
    std::map<double,double>::iterator itpMap = sToPmap.find(s);
    if (itpMap == sToPmap.end()){
        newtonStoP(s);
        itpMap = sToPmap.find(s);
    }
    double pValue = itpMap->second;
    return yp(pValue);
}

void curvebase::newtonStoP(double s){
    double p_curr = (b-a)*s+a;
    double p_next;
    double stepSize = 10;
    double intValue;
    /*
    std::map<double,double> integratedValueMap;
    integratedValueMap.insert(std::make_pair(a,0.0));
    auto intHelp= [this,&integratedValueMap](double p)->double{
        auto iterator = integratedValueMap.lower_bound(p);
        double leftInt = iterator->second;
        double remain = integrate(iterator->first,p);
        integratedValueMap.insert(std::make_pair(p,leftInt+remain));
        return leftInt+remain;
    };*/

    while(stepSize > 1e-10){
        double intHelper = integrate(a,p_curr);
        //double intHelper = intHelp(p_curr);
        double fprime = intFunDensity(p_curr);
        p_next = p_curr - (intHelper - s*arcLength)/fprime;

        stepSize = fabs(p_curr-p_next);
        p_curr = p_next;
    }
    sToPmap.insert(std::make_pair(s,p_curr));
    return;
}


double curvebase::intFunDensity(double p){
    return sqrt(pow(dxp(p),2) + pow(dyp(p),2));
}

double curvebase::integrate(double a, double b) {
    double (*fun) (double);
    //fun = [this] (double p) -> double { return sqrt(pow(dxp(p),2) + pow(dyp(p),2));};
    //fun = &curvebase::intFunDensity;

    return ASI(a,b,1e-10,100);
}


curvebase &curvebase::operator=(const curvebase &src) {
    if(this==&src) return *this;
    pmin = src.pmin;
    pmax = src.pmax;
    a = src.a;
    b= src.b;
    rev =  src.rev; // orientation of the curve
    length = src.length;

    return *this;
}

curvebase::~curvebase() {}





double curvebase::ASI(double& a, double& b,double tol = 1e-10, unsigned recDepth = 100){
    double c = (a+b)/2;
    double width = b-a;
    double fun_a = intFunDensity(a);
    double fun_b = intFunDensity(b);
    double fun_c = intFunDensity(c);
    double inteValue = (width/6)*(fun_a+4*fun_c + fun_b);
    return ASIHelp(a,b,tol,inteValue,fun_a,fun_b,fun_c,recDepth);
}

//INTEGRATION POINTS
//A D C E B
double curvebase::ASIHelp(double& a, double& b, double& tol,double& prevIVal, double& fun_a, double& fun_b, double& fun_c, unsigned recDepth ){
    double c = (a+b)/2;
    double subWidth = (b-a)/2;
    double d = (a+c)/2;
    double e = (c+b)/2;
    double fun_d = intFunDensity(d);
    double fun_e = intFunDensity(e);

    double inteValLeft  = (subWidth/6)*(fun_a+4*fun_d+fun_c);
    double inteValRight = (subWidth/6)*(fun_c+4*fun_e+fun_b);
    double inteValue = inteValLeft+inteValRight;

    if(recDepth < 1 || fabs(inteValue-prevIVal) < 15*tol){
        return inteValue + (inteValue-prevIVal)/15;
    }
    return ASIHelp(a,c,tol,inteValLeft,fun_a,fun_c,fun_d,recDepth-1) +
           ASIHelp(c,b,tol,inteValRight,fun_c,fun_b,fun_e,recDepth-1);

}
