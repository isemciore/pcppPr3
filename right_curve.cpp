//
// Created by erik on 2015-11-11.
//

#include "right_curve.h"

vertBotToTop::RightCurve() {
    pmin_ = 0;
    pmax_ = 3;
    a_ = 0;
    b_ = 3;
    int rev = 1;
    arcLength_ = integrate(a_, b_);

}

double vertBotToTop::xp(double p) {
    return 5;
}

double vertBotToTop::yp(double p) {
    return p;
}

double vertBotToTop::dxp(double p) {
    return 0;
}

double vertBotToTop::dyp(double p) {
    return 1;
}
