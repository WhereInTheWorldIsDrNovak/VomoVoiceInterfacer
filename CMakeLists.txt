cmake_minimum_required(VERSION 3.5)

project(DrawFace LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5
  COMPONENTS
    system window graphics REQUIRED
    )

set(DRAWFACED_DEPENDENCIES
    )
add_executable(DrawFace main.cpp ${DRAWFACED_DEPENDENCIES})

target_link_libraries(
 ${PROJECT_NAME}
 LINK_PUBLIC
 sfml-graphics
)
