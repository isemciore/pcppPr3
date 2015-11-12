//
// Created by erik on 2015-11-11.
//

#include "rightVertBotToTop.h"

vertBotToTop::vertBotToTop() {
    pmin = 0;
    pmax = 3;
    a = 0;
    b = 3;
    int rev = 1;
    arcLength = integrate(a,b);

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
