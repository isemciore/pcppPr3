//
// Created by erik on 2015-11-11.
//

#include "leftVertBotToTot.h"

leftVertBotToTop::leftVertBotToTop() {
    pmin_ = 0;
    pmax_ = 3;
    a_ = 0;
    b_ = 3;
    int rev = 3;
    arcLength_ = integrate(a_, b_);

}

double leftVertBotToTop::xp(double p) {
    return -10;
}

double leftVertBotToTop::yp(double p) {
    return p;
}

double leftVertBotToTop::dxp(double p) {
    return 0;
}

double leftVertBotToTop::dyp(double p) {
    return 1;
}
