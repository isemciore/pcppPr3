//
// Created by erik on 2015-11-10.
//

#ifndef PCPPPR3_CURVEBASE_H
#define PCPPPR3_CURVEBASE_H

#include <map>
#include <cmath>
class curvebase {
protected:
    double pmin;
    double pmax;
    double a;
    double b;
    int rev; // orientation of the curve
    double length;
    double arcLength;
    mutable std::map<double,double> sToPmap;

    void newtonStoP(double);
    inline double intFunDensity(double p);
    double ASI(double&,double&,double_t,unsigned);
    double ASIHelp(double&, double&, double&,double& , double& , double& , double& , unsigned );

    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;
    double integrate(double a, double b); //arc length integral

public:
    curvebase(); //constructor

    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization

    virtual ~curvebase();
    virtual curvebase & operator=(const curvebase &);



};


#endif //PCPPPR3_CURVEBASE_H
