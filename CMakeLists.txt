cmake_minimum_required(VERSION 3.24)
project(RealGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(RealGame
        main.cpp header/Map.h src/Map.cpp header/Object.h header/NullObject.h src/Object.cpp src/NullObject.cpp header/Window.h src/Window.cpp header/Centre.h src/Centre.cpp header/Mineral.h header/AMineral.h src/AMineral.cpp header/BMineral.h src/BMineral.cpp header/Extractor.h header/Extractor.h src/Extractor.cpp header/Equipment.h src/Equipment.cpp header/TransmissionBelt.h src/TransmissionBelt.cpp header/Cutter.h src/Cutter.cpp header/RubbishBin.h src/RubbishBin.cpp)
