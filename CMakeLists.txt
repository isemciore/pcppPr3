cmake_minimum_required(VERSION 3.3)
project(pcppPr3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES main.cpp curveBase.cpp curveBase.h adaptiveSimpson.h hoExHoExHo.cpp hoExHoExHo.h rightVertBotToTop.cpp rightVertBotToTop.h horzLeftToRight.cpp horzLeftToRight.h leftVertBotToTot.cpp leftVertBotToTot.h domain.cpp domain.h)
add_executable(pcppPr3 ${SOURCE_FILES})