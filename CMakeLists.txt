cmake_minimum_required(VERSION 3.10)
project(ProjetoDeAlgoritmos C)

# Set compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# Set the output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})

# Set the output directory for the library
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH})

# Include directories
include_directories(include)

# Find source files for the library
file(GLOB LIB_SOURCES "src/*.c")

# Add the static library
add_library(sorter STATIC ${LIB_SOURCES})

# Add the executable
add_executable(main app/main.c)

# Link the executable to the library
target_link_libraries(main sorter)

# Add a custom target for "run"
add_custom_target(run
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
