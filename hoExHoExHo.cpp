//
// Created by erik on 2015-11-11.
//

#include <iostream>
#include "hoExHoExHo.h"

hoExHoExHo::hoExHoExHo() {
    pmin = -10;
    pmax = 5;
    a = -10;
    b = 5;
    int rev = 0; //ANTI CLOCKWISE START FROM SOUTHWEST CORNER
    arcLength = integrate(a,b);
}
double hoExHoExHo::xp(double p) {
    if (p>=-10-1e-5 && p<=5+1e-5) {
        return p;
    }
    throw::std::out_of_range("xp OUT OF DOMAIN");
}

double hoExHoExHo::yp(double p) {
    if (p<-3+1e-5 && p >=-10-1e-5){
        return 1.0/2.0*1.0/(1+exp(-3*(p+6)));
    }else if(p>=-3 && p <=5+1e-5){
        return 1.0/2.0*1.0/(1+exp(3*p));
    }
    throw::std::out_of_range("OUT OF DOMAIN YP");

}

double hoExHoExHo::dxp(double p) {
    if (p>=-10-1e-5 && p<=5+1e-5) {
        return 1;
    }
    throw::std::out_of_range("dxp OUT OF DOMAIN");
}

double hoExHoExHo::dyp(double p) {
    if(p < -3+1e-5 && p >= -10-1e-5) {
        return (3 * exp(3 * (p + 6))) / (2 * pow(exp(3 * (p + 6)) + 1, 2));
    }else if (p>=-3 && p <= 5 + 1e-5){
        return -3*exp(3*p)/(2*pow(exp(3*p)+1,2));
    }
    throw::std::out_of_range("OUT OF DOMAIN DYP");
}

