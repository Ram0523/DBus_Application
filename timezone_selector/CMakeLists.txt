cmake_minimum_required(VERSION 3.16)

project(timezone_selector LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core DBus Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core DBus Widgets)

add_executable(timezone_selector
  main.cpp
  timezone_selector.h timezone_selector.cpp
)
target_link_libraries(timezone_selector Qt${QT_VERSION_MAJOR}::Core  Qt${QT_VERSION_MAJOR}::DBus Qt${QT_VERSION_MAJOR}::Widgets Qt6::DBus)

include(GNUInstallDirs)
install(TARGETS timezone_selector
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
