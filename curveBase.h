//
// Created by erik on 2015-11-10.
//

#ifndef PCPPPR3_CURVEBASE_H
#define PCPPPR3_CURVEBASE_H

#include <map>
#include <cmath>
class curvebase {
private:
protected:
    std::size_t number_density_function_eval_ = 0;
    double pmin_;
    double pmax_;
    double a_;
    double b_;
    int rev_; // orientation of the curve
    double length_;
    double arcLength_;

    //incase base is const, still be able to store "new data" even tho const should not be sused
    mutable std::map<double,double> sToPmap;
    mutable std::map<double,double> pToIntValues;
    mutable std::map<double,double> endIntLocalArea;


    void new_s_to_p_coord(double);
    inline double inte_function_density(double p);
    double ASI(const double&,const double&,const double, unsigned);
    double ASIHelp(const double&,const double&,const double&,
                   const double& ,const double& ,const double& , const double& , unsigned ) ;

    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;
    double integrate(double a, double b); //arc length_ integral

public:
    curvebase(); //constructor
    double x(double s); //arc length_ parametrization
    double y(double s); //arc length_ parametrization
    virtual ~curvebase();
    virtual curvebase & operator=(const curvebase &);

    bool quickInt = false;//(if true, integration will be based on previous values
    std::size_t getDensityEvalTimes() const;
};


#endif //PCPPPR3_CURVEBASE_H
