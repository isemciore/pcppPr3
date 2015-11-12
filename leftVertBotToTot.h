//
// Created by erik on 2015-11-11.
//

#ifndef PCPPPR3_LEFTVERTTOPTOBOT_H
#define PCPPPR3_LEFTVERTTOPTOBOT_H


#include "curveBase.h"

class leftVertBotToTop : public curvebase{
public:
    leftVertBotToTop();


protected:
    virtual double xp(double p);

    virtual double yp(double p);

    virtual double dxp(double p);

    virtual double dyp(double p);
};


#endif //PCPPPR3_LEFTVERTTOPTOBOT_H
