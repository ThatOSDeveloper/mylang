# Set the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(examplelang C)

# Automatically find all C source files in the src/ directory
file(GLOB SOURCES "src/*.c")

# Create the executable from all found source files
add_executable(examplelang ${SOURCES})

