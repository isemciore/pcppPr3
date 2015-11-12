//
// Created by erik on 2015-11-11.
//

#ifndef PCPPPR3_DOMAIN_H
#define PCPPPR3_DOMAIN_H


#include "curveBase.h"

class domain {
private:
    curvebase * sides[4];
    double *_x, *_y;
    std::size_t _m, _n;

    bool check_consistency();

public:
    domain(curvebase& bt, curvebase& lt,
           curvebase& rt, curvebase& tp);
    domain(const domain&);
    ~domain();

    domain(domain&& src);//moveconstuct
    domain& operator=(const domain&);
    domain& operator=(domain&& src);

    void generate_Grid(std::size_t m, std::size_t n);


    bool writeBinFile(std::string xValueFileName,std::string yValueFileName);
};


#endif //PCPPPR3_DOMAIN_H
