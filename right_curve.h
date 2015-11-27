//
// Created by erik on 2015-11-11.
//

#ifndef PCPPPR3_VERTBOTTOTOP_H
#define PCPPPR3_VERTBOTTOTOP_H


#include "curveBase.h"

class RightCurve : public curvebase {
public:
    RightCurve();
protected:
    virtual double xp(double p)  override ;

    virtual double yp(double p)  override ;

    virtual double dxp(double p)  override ;

    virtual double dyp(double p) override ;
};


#endif //PCPPPR3_VERTBOTTOTOP_H
