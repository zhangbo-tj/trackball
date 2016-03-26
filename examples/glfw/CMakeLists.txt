find_package(GLFW REQUIRED)
include_directories(${GLFW_INCLUDE_DIR})
set(LIBS ${LIBS} ${GLFW_LIBRARY} src examples)

set(EXAMPLES_GLFW_FILES example.cpp RenderWindowGLFW.cpp)
add_executable(example ${EXAMPLES_GLFW_FILES})
target_link_libraries(example ${LIBS})