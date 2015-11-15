#include <iostream>
#include "curveBase.h"
#include "hoExHoExHo.h"
#include "rightVertBotToTop.h"
#include "horzLeftToRight.h"
#include "leftVertBotToTot.h"
#include "domain.h"
using namespace std;

int main() {
    //COORDINATE 0.0 IS BOTTOM LEFT//

    curvebase* cbBottomPtr;
    hoExHoExHo bottomCurve = hoExHoExHo();
    std::cout << bottomCurve.getDensityEvalTimes() << "\n";
    cbBottomPtr = &bottomCurve;
    //for(double s = 0; s <=1; s=s+0.1){
    //    std::cout << "( "<< cbBottomPtr->x(s) <<"," << cbBottomPtr->y(s)<<" )\n";
    //}
    vertBotToTop rightCurve = vertBotToTop();
    cbBottomPtr = &rightCurve;
    //for(double s = 0; s <=1; s=s+0.1){
    //    std::cout << "( "<< cbBottomPtr->x(s) <<"," << cbBottomPtr->y(s)<<" )\n";
    //}
    horzRightToLeft topCurve = horzRightToLeft();
    cbBottomPtr = &topCurve;
    //for(double s = 0; s <=1; s=s+0.1){
    //    std::cout << "( "<< cbBottomPtr->x(s) <<"," << cbBottomPtr->y(s)<<" )\n";
    //}
    leftVertBotToTop leftCurve = leftVertBotToTop();
    cbBottomPtr = &leftCurve;
    //for(double s = 0; s <=1; s=s+0.1){
    //    std::cout << "( "<< cbBottomPtr->x(s) <<"," << cbBottomPtr->y(s)<<" )\n";
    //}
    domain derp(bottomCurve,leftCurve,rightCurve,topCurve);
    derp.generate_Grid(1000,1000);

    derp.stretch_grid();

    cout << "attempt write to file!" << endl;
    derp.writeBinFile("xValues","yValues");


    std::cout << bottomCurve.getDensityEvalTimes() << "\n";
    return 0;
}