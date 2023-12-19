cmake_minimum_required(VERSION 3.24)
project(RealGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(RealGame
        main.cpp header/Interface/Map.h src/Interface/Map.cpp header/Object.h header/NullObject.h src/Object.cpp src/NullObject.cpp header/Tools/Window.h src/Tools/Window.cpp header/Equipment/Centre.h src/Equipment/Centre.cpp header/Mineral/Mineral.h header/Mineral/AMineral.h src/Mineral/AMineral.cpp header/Mineral/BMineral.h src/Mineral/BMineral.cpp header/Equipment/Extractor.h src/Equipment/Extractor.cpp header/Equipment/Equipment.h src/Equipment/Equipment.cpp header/Equipment/TransmissionBelt.h src/Equipment/TransmissionBelt.cpp header/Equipment/Cutter.h src/Equipment/Cutter.cpp header/Equipment/RubbishBin.h src/Equipment/RubbishBin.cpp header/Tools/Cursor.h src/Tools/Cursor.cpp header/Mineral/NullMineral.h src/Mineral/NullMineral.cpp header/Mineral/HalfAMineral.h src/Mineral/HalfAMineral.cpp header/Interface/MainInterface.h src/Interface/MainInterface.cpp header/Interface/Level.h src/Interface/Level.cpp header/Interface/Store.h src/Interface/Store.cpp src/Mineral/Mineral.cpp header/Tools/SavingFile.h src/Tools/SavingFile.cpp)
