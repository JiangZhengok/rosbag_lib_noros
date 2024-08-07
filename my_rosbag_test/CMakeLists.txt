cmake_minimum_required(VERSION 3.0.2)
project(test)

set(CMAKE_BUILD_TYPE "Release")

include_directories(
    /codepath/faw_mlc_rosbag/install/aarch64/include
    /codepath/faw_mlc_rosbag/install/aarch64/include/ros_header
)

file(GLOB SRC_FILES "src/*.cpp")

find_library(ROSBAG_STORAGE NAMES my_rosbag_storage PATHS /codepath/faw_mlc_rosbag/install/aarch64/lib NO_DEFAULT_PATH) 

add_executable(test ${SRC_FILES})
target_link_libraries(test ${ROSBAG_STORAGE})
