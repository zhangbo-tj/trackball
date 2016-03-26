find_package(GLM REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})
set(SRC_FILES Camera.cpp TrackBallInteractor.cpp)
add_library(src ${SRC_FILES})