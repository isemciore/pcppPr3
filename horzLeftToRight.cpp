//
// Created by erik on 2015-11-11.
//

#include "horzLeftToRight.h"

horzRightToLeft::horzRightToLeft() {
    pmin_ = -10;
    pmax_ = 5;
    a_ = -10;
    b_ = 5;
    int rev = 2;
    arcLength_ = integrate(a_, b_);
}

double horzRightToLeft::xp(double p) {
    return p;
}

double horzRightToLeft::yp(double p) {
    return 3;
}

double horzRightToLeft::dxp(double p) {
    return 1;
}

double horzRightToLeft::dyp(double p) {
    return 0;
}
