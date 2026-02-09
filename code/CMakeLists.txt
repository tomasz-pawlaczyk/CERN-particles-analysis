cmake_minimum_required(VERSION 3.10)
project(particles_analysis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Pythia
set(PYTHIA_DIR <<insert your Pythia's path here>>)
include_directories(${PYTHIA_DIR}/include)
link_directories(${PYTHIA_DIR}/lib)

# ROOT
find_package(ROOT REQUIRED)
include(${ROOT_USE_FILE})

add_executable(particles_analysis
        src/main.cpp
        src/generator.cpp
        src/analysis.cpp
)

target_link_libraries(particles_analysis
        pythia8
        ${ROOT_LIBRARIES}
)
