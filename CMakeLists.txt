cmake_minimum_required(VERSION 2.8.3)
project(pcl_practice)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


#for test_opencv.cpp
add_executable (test_opencv test_opencv.cpp)
target_link_libraries (test_opencv ${OpenCV_LIBS})

#for triming.cpp
add_executable (triming triming.cpp)
target_link_libraries(triming ${OpenCV_LIBS})

#for affine.cpp
add_executable(affine affine.cpp)
target_link_libraries(affine ${OpenCV_LIBS})

#for rotate.cpp
add_executable(rotate rotate.cpp)
target_link_libraries(rotate ${OpenCV_LIBS})
