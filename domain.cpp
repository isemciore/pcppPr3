//
// Created by erik on 2015-11-11.
//

#include <iostream>
#include "domain.h"
#include <cstdio>

//(0,1)-----------(1,1)->
//---------------------->
//(0,0)------------(1,0)>
domain::domain(curvebase &bt, curvebase &lt,
               curvebase &rt, curvebase &tp) {
    sides[0] = &bt;
    sides[1] = &lt;
    sides[2] = &rt;
    sides[3] = &tp;
    if (!check_consistency()){
        sides[0]=sides[1]=sides[2]=sides[3] = nullptr;
    }
    _m = 0;
    _n = 0;
    _x = _y = nullptr;

}

domain::domain(const domain &domain1) {

}

domain::~domain() {
    if (_m>0){
        delete[] _x;
        delete[] _y;
        if(alt_y_exist){
            delete[] alternative_y;
            alt_y_exist = false;
        }
    }

}

domain::domain(domain &&src) {

}

domain& domain::operator=(const domain& src) {
    if(this==&src) return *this;

    return *this;
}

domain& domain::operator=(domain &&src) {
    if(this==&src) return *this;

    return *this;
}

void domain::generate_Grid(std::size_t m, std::size_t n) {
    auto getXc = [&](double xi, double eta)->double{
        return (1-xi)*sides[1]->x(eta) + xi*sides[2]->x(eta) +
                (1-eta)*sides[0]->x(xi) + eta*sides[3]->x(xi)
                -(1-xi)*(1-eta)*sides[0]->x(0)-xi*(1-eta)*sides[2]->x(0)
                -(1-xi)*eta*sides[3]->x(0)-xi*eta*sides[3]->x(1);
    };
    auto getYc = [&](double xi, double eta)->double{
        return (1-xi)*sides[1]->y(eta) + xi*sides[2]->y(eta) +
               (1-eta)*sides[0]->y(xi) + eta*sides[3]->y(xi)
               -(1-xi)*(1-eta)*sides[0]->y(0)-xi*(1-eta)*sides[2]->y(0)
               -(1-xi)*eta*sides[3]->y(0)-xi*eta*sides[3]->y(1);
    };


    if (m == 0 || n==0 ){return;}//duh*
    if (_m > 0){//grid exist
        delete[] _x;
        delete[] _y;
    }
    _m = m;
    _n = n;
    _x = new double[_m*_n];
    _y = new double[_m*_n];

    double deltaXi = 1.0/(m-1);
    double deltaEta= 1.0/(n-1);
    double xi= 0;
    double eta=0;
    for(std::size_t j=0;j < n; j++){
        for(std::size_t i = 0;i<m;i++){
            xi=i*deltaXi;
            eta=j*deltaEta;
            _x[i+j*m] = getXc(xi,eta);
            _y[i+j*m] = getYc(xi,eta);
            /*
            std::cout << "xi: " <<xi<<" eta: "<<eta<<"\n";
            std::cout << "i: " <<i<<" j: "<<j<<"\n";
            std::cout << "x: "<< _x[i+j*m]<<" y: "<<_y[i+j*m]<<"\n";
            */
        }
    }


}

bool domain::check_consistency() {
    //SW CORNER
           if (fabs(sides[0]->x(0)-sides[1]->x(0)) >1e-5 ||
            fabs(sides[0]->y(0)-sides[1]->y(0))>1e-5 ) {
        return false; //SE
    } else if (fabs(sides[0]->x(1)-sides[2]->x(0)) >1e-5 ||
            fabs(sides[0]->y(1)-sides[2]->y(0))>1e-5 ) {
        return false;
    } else if (fabs(sides[1]->x(1)-sides[3]->x(0)) >1e-10 ||
            fabs(sides[1]->y(1)-sides[3]->y(0))>1e-10){
        return false;
    } else if (fabs(sides[2]->x(1)-sides[3]->x(1)) >1e-10 ||
            fabs(sides[2]->y(1)-sides[3]->y(1)) > 1e-10){
               return false;
    }
    std::cout << "create successsful\n";
    //Check corner
    return true;
}

bool domain::writeBinFile(std::string xValueFileName, std::string yValueFileName) {
    FILE *fp;
    fp = fopen(xValueFileName.c_str(),"w+b");
    fwrite(_x, sizeof(double),_m*_n,fp);
    fclose(fp);
    fp = fopen(yValueFileName.c_str(),"w+b");
    fwrite(_y, sizeof(double),_m*_n,fp);
    fclose(fp);

    if(alt_y_exist){
        fp = fopen((yValueFileName.append("altY")).c_str(),"w+b");
        fwrite(alternative_y, sizeof(double),_m*_n,fp);
        fclose(fp);
    }


    fp = fopen("dataFormat","w+b");
    fwrite(&_m, sizeof(size_t),1,fp);
    fwrite(&_n, sizeof(size_t),1,fp);
    fclose(fp);


    return true;
}



void domain::stretch_grid() {
    double div_fct = 3.0/(exp(1.5)-1);
    alternative_y = new double[_m*_n];
    for(std::size_t i = 0; i < _m*_n;i++){
        alternative_y[i] = div_fct*(exp(0.5*_y[i])-1);
    }
}
