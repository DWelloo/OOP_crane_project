cmake_minimum_required(VERSION 3.14)

project(Projekt_3_Kontener LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(Projekt_3_Kontener main.cpp List.h Klasa_MB.h Klasa_M.h Klasa_MM.h Klasa_D.h
    Klasa_DK.h Klasa_DZ.h)

target_link_libraries(Projekt_3_Kontener Qt${QT_VERSION_MAJOR}::Core)
