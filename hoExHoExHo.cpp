//
// Created by erik on 2015-11-11.
//

#include <iostream>
#include "hoExHoExHo.h"

hoExHoExHo::hoExHoExHo() {
    pmin_ = -10;
    pmax_ = 5;
    a_ = -10;
    b_ = 5;
    int rev = 0; //ANTI CLOCKWISE START FROM SOUTHWEST CORNER
    arcLength_ = integrate(a_, b_);
}
double hoExHoExHo::xp(double p) {
    if (p>=-10-1e-5 && p<=5+1e-5) { //Corner for both curves does not lie on exactly the same "point"
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

