cmake_minimum_required(VERSION 3.14)
project(curves_demo LANGUAGES CXX)

# Options
option(BUILD_SHARED_LIBS "Build shared library" ON)

# Library
add_library(curves
    src/Circle.cpp
    src/Ellipse.cpp
    src/Helix3D.cpp
)
target_include_directories(curves
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_compile_features(curves PUBLIC cxx_std_17)
if (MSVC)
    target_compile_definitions(curves PRIVATE CURVES_EXPORTS)
    target_compile_options(curves PRIVATE /W4 /permissive-)
else()
    target_compile_options(curves PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Executable
add_executable(curves_app app/main.cpp)
target_link_libraries(curves_app PRIVATE curves)
target_compile_features(curves_app PRIVATE cxx_std_17)

# Install rules for library + headers
include(GNUInstallDirs)
install(TARGETS curves
        EXPORT curvesTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Install/export the app
install(TARGETS curves_app RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})