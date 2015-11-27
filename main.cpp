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
    RightCurve rightCurve = RightCurve();
    TopCurve topCurve = TopCurve();
    LeftCurve leftCurve = LeftCurve();
    domain four_side_domain(bottomCurve,leftCurve,rightCurve,topCurve);
    four_side_domain.generate_Grid(20,50);

    cout << "attempt write to file!" << endl;
    four_side_domain.writeBinFile("xValues20","yValues50");
    std::cout << bottomCurve.getDensityEvalTimes() << "\n";
    return 0;
}