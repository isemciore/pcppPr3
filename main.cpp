#include <iostream>
#include "curveBase.h"
#include "BottomCurve.h"
#include "right_curve.h"
#include "top_curve.h"
#include "left_curve.h"
#include "domain.h"
using namespace std;

int main() {
    //COORDINATE 0.0 IS BOTTOM LEFT//
    curvebase* cbBottomPtr;
    BottomCurve bottomCurve = BottomCurve();
    std::cout << bottomCurve.getDensityEvalTimes() << "\n";
    cbBottomPtr = &bottomCurve;
    //for(double s = 0; s <=1; s=s+0.1){ //Manual check for "correctness"
    //    std::cout << "( "<< cbBottomPtr->x(s) <<"," << cbBottomPtr->y(s)<<" )\n";
    //}
    RightCurve rightCurve = RightCurve();
    cbBottomPtr = &rightCurve;
    //for(double s = 0; s <=1; s=s+0.1){
    //    std::cout << "( "<< cbBottomPtr->x(s) <<"," << cbBottomPtr->y(s)<<" )\n";
    //}
    TopCurve topCurve = TopCurve();
    cbBottomPtr = &topCurve;
    //for(double s = 0; s <=1; s=s+0.1){
    //    std::cout << "( "<< cbBottomPtr->x(s) <<"," << cbBottomPtr->y(s)<<" )\n";
    //}
    LeftCurve leftCurve = LeftCurve();
    cbBottomPtr = &leftCurve;
    //for(double s = 0; s <=1; s=s+0.1){
    //    std::cout << "( "<< cbBottomPtr->x(s) <<"," << cbBottomPtr->y(s)<<" )\n";
    //}//
    domain four_side_domain(bottomCurve,leftCurve,rightCurve,topCurve);
    four_side_domain.generate_Grid(20,50);

    cout << "attempt write to file!" << endl;
    four_side_domain.writeBinFile("xValues20","yValues50");


    std::cout << bottomCurve.getDensityEvalTimes() << "\n";
    return 0;
}