//
// Created by erik on 2015-11-11.
//

#include "leftVertBotToTot.h"

leftVertBotToTop::leftVertBotToTop() {
    pmin = 0;
    pmax = 3;
    a = 0;
    b = 3;
    int rev = 3;
    arcLength = integrate(a,b);

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
