cmake_minimum_required(VERSION 3.16)
project(QtClockProject LANGUAGES CXX)

find_package(QT REQUIRED Qt6 Qt5 REQUIRED COMPONENTS Core Widgets DBus)

# qt_standard_project_setup()

add_subdirectory(digital_clock)
add_subdirectory(timezone_selector)

