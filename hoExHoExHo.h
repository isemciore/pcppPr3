//
// Created by erik on 2015-11-11.
//

#ifndef PCPPPR3_HOEXHOEXHO_H
#define PCPPPR3_HOEXHOEXHO_H


#include "curveBase.h"

class hoExHoExHo : public curvebase {
public:
    hoExHoExHo();

protected:
    virtual double xp(double p) override;
    virtual double yp(double p) override;
    virtual double dxp(double p) override;
    virtual double dyp(double p) override;
    using curvebase::curvebase;
};


#endif //PCPPPR3_HOEXHOEXHO_H
