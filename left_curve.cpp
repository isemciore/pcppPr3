//
// Created by erik on 2015-11-11.
//

#include "left_curve.h"

LeftCurve::LeftCurve() {
    pmin_ = 0;
    pmax_ = 3;
    a_ = 0;
    b_ = 3;
    int rev = 3;
    arcLength_ = integrate(a_, b_);

}

double LeftCurve::xp(double p) {
    return -10;
}

double LeftCurve::yp(double p) {
    return p;
}

double LeftCurve::dxp(double p) {
    return 0;
}

double LeftCurve::dyp(double p) {
    return 1;
}
