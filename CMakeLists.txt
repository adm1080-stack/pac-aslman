cmake_minimum_required(VERSION 3.10)
project(3DPacMan CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find or Fetch GLFW
find_package(glfw3 QUIET)
if(NOT glfw3_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.3.8
    )
    FetchContent_MakeAvailable(glfw)
endif()

# Source Files
add_executable(3DPacMan 
    src/main.cpp 
    src/Game.cpp
)

# Link Libraries
target_link_libraries(3DPacMan PRIVATE OpenGL::GL glfw)
