//
// Created by erik on 2015-11-11.
//

#include "horzLeftToRight.h"

horzRightToLeft::horzRightToLeft() {
    pmin = -10;
    pmax = 5;
    a = -10;
    b = 5;
    int rev = 2;
    arcLength = integrate(a,b);
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
