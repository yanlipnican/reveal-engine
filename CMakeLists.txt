cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME engine)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

set(CMKAE_BINARY_DIR ./bin)
set(CMAKE_SOURCE_DIR .)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

find_package(OpenGL REQUIRED)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
    message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
    message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()


# Compile external dependencies
add_subdirectory (external)

if(INCLUDE_DISTRIB)
    add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)


include_directories(
        external/glfw-3.2.1/include/GLFW/
        external/glm/
        external/glew-2.0.0/include/
        .
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_2000
        )

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

set(SOURCE_FILES
        main.cpp
        src/Core/Engine.cpp src/Core/Engine.h src/Core/Renderer.h src/Util/Util.h src/Util/FileUtil.h src/Core/Renderers/Renderer2D.cpp src/Core/Renderers/Renderer2D.h src/Core/Renderers/Renderable2D.cpp src/Core/Renderers/Renderable2D.h src/Core/Window.cpp src/Core/Window.h src/Core/Module.h src/Core/Logger.h src/Core/Loggers/ConsoleLogger.cpp src/Core/Loggers/ConsoleLogger.h src/Core/Shader.cpp src/Core/Shader.h src/Modules/Renderer2DModule.cpp src/Modules/Renderer2DModule.h src/OpenGL.h)

set (CMAKE_CXX_FLAGS -m64)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
        ${ALL_LIBS}
        )