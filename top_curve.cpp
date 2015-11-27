//
// Created by erik on 2015-11-11.
//

#include "top_curve.h"

TopCurve::TopCurve() {
    pmin_ = -10;
    pmax_ = 5;
    a_ = -10;
    b_ = 5;
    int rev = 2;
    arcLength_ = integrate(a_, b_);
}

double TopCurve::xp(double p) {
    return p;
}

double TopCurve::yp(double p) {
    return 3;
}

double TopCurve::dxp(double p) {
    return 1;
}

double TopCurve::dyp(double p) {
    return 0;
}
