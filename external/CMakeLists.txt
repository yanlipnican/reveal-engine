add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)


set(GLFW_DIR glfw-3.2.1)
set(GLEW_DIR glew-2.0.0)
set(GLM_DIR glm-0.9.8.4)

### GLFW ###

add_subdirectory (${GLFW_DIR})

include_directories(
        ${GLFW_DIR}/include/GLFW/
        ${GLEW_DIR}/include/
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(OPENGL_LIBRARY
            ${OPENGL_LIBRARY}
            -lGL -lGLU -lXrandr -lXext -lX11 -lrt
            ${CMAKE_DL_LIBS}
            ${GLFW_LIBRARIES}
            )
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(OPENGL_LIBRARY
            ${OPENGL_LIBRARY}
            ${CMAKE_DL_LIBS}
            ${GLFW_LIBRARIES}
            )
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

### GLEW ###

set(GLEW_SOURCE
        ${GLEW_DIR}/src/glew.c
        )

set(GLEW_HEADERS
        )


add_library( GLEW_2000 STATIC
        ${GLEW_SOURCE}
        ${GLEW_INCLUDE}
        )

target_link_libraries(GLEW_2000
        ${OPENGL_LIBRARY}
        ${EXTRA_LIBS}
        )
