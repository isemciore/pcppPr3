//
// Created by erik on 2015-11-10.
//

#include <iostream>
#include "curveBase.h"

curvebase::curvebase()
{
}

double curvebase::x(double s) {
	//checking if S-P relation have been calculated previously
    std::map<double,double>::iterator itpMap = sToPmap.find(s); 
    if (itpMap == sToPmap.end()){
        new_s_to_p_coord(s);
        itpMap = sToPmap.find(s);
    }
    double pValue = itpMap->second;
    return xp(pValue);
}

double curvebase::y(double s) {
    std::map<double,double>::iterator itpMap = sToPmap.find(s);
    if (itpMap == sToPmap.end()){
        new_s_to_p_coord(s);
        itpMap = sToPmap.find(s);
    }
    double pValue = itpMap->second;
    return yp(pValue);
}

//find the S-P relation
void curvebase::new_s_to_p_coord(double s){
    double p_curr = (b_ - a_)*s+ a_;
    double p_next;
    double stepSize = 10;
    double intValue;

    while(stepSize > 1e-10){
        double intHelper = integrate(a_,p_curr);
        //double intHelper = intHelp(p_curr);
        double fprime = inte_function_density(p_curr);
        p_next = p_curr - (intHelper - s* arcLength_)/fprime;

        stepSize = fabs(p_curr-p_next);
        p_curr = p_next;
    }
    sToPmap.insert(std::make_pair(s,p_curr));
    return;
}


double curvebase::inte_function_density(double p){
    number_density_function_eval_++;
    return sqrt(pow(dxp(p),2) + pow(dyp(p),2));
}

double curvebase::integrate(double a, double b) {
    double (*fun) (double);
    if (quickInt){
        std::map<double,double>::iterator itLB = pToIntValues.lower_bound(b);
        double retValues;
        if (itLB==pToIntValues.end()){//Never integrated before
            retValues = ASI(a,b,1e-10,100);
        }else{
            retValues = itLB->second + ASI(itLB->first,b,1.0e-10,100);
        }
        pToIntValues.insert(std::make_pair(b,retValues));
        return retValues;
    }else{
        return ASI(a,b,1e-10,100);
    }
}


curvebase &curvebase::operator=(const curvebase &src) {
    if(this==&src) return *this;
    pmin_ = src.pmin_;
    pmax_ = src.pmax_;
    a_ = src.a_;
    b_ = src.b_;
    rev_ =  src.rev_; // orientation of the curve
    length_ = src.length_;

    return *this;
}

curvebase::~curvebase() {}





double curvebase::ASI(const double& a,const double& b, const double tol = 1e-10,unsigned recDepth = 100){
    double c = (a+b)/2;
    double width = b-a;
    double fun_a = inte_function_density(a);
    double fun_b = inte_function_density(b);
    double fun_c = inte_function_density(c);
    double inteValue = (width/6)*(fun_a+4*fun_c + fun_b);
    return ASIHelp(a,b,tol,inteValue,fun_a,fun_b,fun_c,recDepth);
}

//INTEGRATION POINTS
//A D C E B
double curvebase::ASIHelp(const double& a,const double& b,const double& tol, const double& prevIVal,
                          const double& fun_a, const double& fun_b, const double& fun_c,unsigned recDepth ){
    double c = (a+b)/2;
    double subWidth = (b-a)/2;
    double d = (a+c)/2;
    double e = (c+b)/2;
    double fun_d = inte_function_density(d);
    double fun_e = inte_function_density(e);

    double inteValLeft  = (subWidth/6)*(fun_a+4*fun_d+fun_c);
    double inteValRight = (subWidth/6)*(fun_c+4*fun_e+fun_b);
    double inteValue = inteValLeft+inteValRight;

    if(recDepth < 1 || fabs(inteValue-prevIVal) < 15*tol){
        return inteValue + (inteValue-prevIVal)/15;
    }

    return ASIHelp(a,c,tol,inteValLeft,fun_a,fun_c,fun_d,recDepth-1) +
           ASIHelp(c,b,tol,inteValRight,fun_c,fun_b,fun_e,recDepth-1);
}

std::size_t curvebase::getDensityEvalTimes() const {
    return number_density_function_eval_;
}
