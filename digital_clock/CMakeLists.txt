cmake_minimum_required(VERSION 3.16)

project(digital_clock LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core DBus Widgets )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core DBus Widgets )

add_executable(digital_clock
  main.cpp
  digital_clock.h digital_clock.cpp
)
target_link_libraries(digital_clock Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::DBus Qt${QT_VERSION_MAJOR}::Widgets Qt6::DBus )

include(GNUInstallDirs)
install(TARGETS digital_clock
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
