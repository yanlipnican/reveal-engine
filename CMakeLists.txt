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
        external/AntTweakBar-1.16/include/
        external/glfw-3.1.2/include/GLFW/
        external/glm-0.9.7.1/
        external/glew-1.13.0/include/
        external/assimp-3.0.1270/include/
        external/bullet-2.81-rev2613/src/
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
        engine/Rendering/Renderer.h
        engine/Rendering/OpenGL/GLRenderer.cpp
        engine/Rendering/OpenGL/GLRenderer.h
        engine/Rendering/RenderManager.cpp
        engine/Rendering/RenderManager.h
        engine/Scene/SceneManager.cpp
        engine/Scene/SceneManager.h
        engine/Scene/Scene.cpp
        engine/Scene/Scene.h
        engine/EngineManager.cpp
        engine/EngineManager.h
        engine/Timing.cpp
        engine/Timing.h
        engine/Logger.cpp
        engine/Logger.h
        engine/Rendering/RendererApi.h
        engine/Rendering/Renderer.cpp
        engine/Rendering/Shader.cpp engine/Rendering/Shader.h engine/Rendering/OpenGL/GLShader.cpp engine/Rendering/OpenGL/GLShader.h engine/util/FileUtil.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
        ${ALL_LIBS}
        )