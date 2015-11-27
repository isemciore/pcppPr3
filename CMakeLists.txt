cmake_minimum_required(VERSION 3.3)
project(pcppPr3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES main.cpp curveBase.cpp curveBase.h adaptiveSimpson.h BottomCurve.cpp BottomCurve.h right_curve.cpp right_curve.h top_curve.cpp top_curve.h left_curve.cpp left_curve.h domain.cpp domain.h)
add_executable(pcppPr3 ${SOURCE_FILES})