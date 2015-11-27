//
// Created by erik on 2015-11-11.
//

#ifndef PCPPPR3_HORZRIGHTTOLEFT_H
#define PCPPPR3_HORZRIGHTTOLEFT_H


#include "curveBase.h"

class TopCurve : public curvebase {
public:
    TopCurve();

protected:
    virtual double xp(double p) override ;

    virtual double yp(double p) override ;

    virtual double dxp(double p) override ;

    virtual double dyp(double p) override ;

};


#endif //PCPPPR3_HORZRIGHTTOLEFT_H
