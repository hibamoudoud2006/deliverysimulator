cmake_minimum_required(VERSION 3.10)

project(DeliverySimulator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(DeliverySimulator
    src/main.cpp
    src/Dimensions.cpp
    src/Adresse.cpp
    src/Colis.cpp
    src/Transporteur.cpp
    src/Velo.cpp
    src/Camion.cpp
    src/Drone.cpp
    src/Avion.cpp
    src/Livraison.cpp
    src/SystemeDeLivraison.cpp
)

target_include_directories(DeliverySimulator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
