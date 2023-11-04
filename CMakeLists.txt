cmake_minimum_required(VERSION 3.0)
project(openfield LANGUAGES CXX)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the example games

FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE CXX CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/*.h")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${CXX})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")


