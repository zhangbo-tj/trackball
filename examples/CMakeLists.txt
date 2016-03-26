find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
link_directories(${OPENGL_LIBRARIES})

set(EXAMPLES_FILES Animator.cpp Renderer.cpp RendererOpenGL1.cpp)
add_library(examples ${EXAMPLES_FILES})
target_link_libraries(examples GL)
add_subdirectory(glfw)