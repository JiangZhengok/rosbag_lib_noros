cmake_minimum_required(VERSION 3.5)

project(my_rosbag_storage)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

set(CMAKE_BUILD_TYPE "Release")

# set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install")
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install/aarch64")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ros_header
)

file(GLOB CPP_COMMON_SRC_FILES "src/cpp_common/*.cpp")
file(GLOB ROS_CPP_SERIALIZATION_SRC_FILES "src/roscpp_serialization/*.cpp")
file(GLOB ROS_TIME_SRC_FILES "src/rostime/*.cpp")
file(GLOB ROS_BAG_STORAGE_SRC_FILES "src/rosbag_storage/*.cpp")

message("CPP_COMMON_SRC_FILES: ${CPP_COMMON_SRC_FILES}")
message("ROS_CPP_SERIALIZATION_SRC_FILES: ${ROS_CPP_SERIALIZATION_SRC_FILES}")
message("ROS_TIME_SRC_FILES: ${ROS_TIME_SRC_FILES}")
message("ROS_BAG_STORAGE_SRC_FILES: ${ROS_BAG_STORAGE_SRC_FILES}")

# find_package(Boost REQUIRED)
# include_directories(${Boost_INCLUDE_DIRS})

add_library(my_rosbag_storage SHARED
    ${CPP_COMMON_SRC_FILES} 
    ${ROS_CPP_SERIALIZATION_SRC_FILES} 
    ${ROS_TIME_SRC_FILES} 
    ${ROS_BAG_STORAGE_SRC_FILES}
)
# target_link_libraries(my_rosbag_storage ${Boost_LIBRARIES})

install(TARGETS my_rosbag_storage
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

# find_library(ROSBAG_STORAGE NAMES my_rosbag_storage PATHS ${CMAKE_CURRENT_SOURCE_DIR}/build NO_DEFAULT_PATH) 
# find_library(ROSBAG_STORAGE NAMES my_rosbag_storage PATHS /home/yqnj/1_code/faw_workspace/faw_mlc_rosbag/build NO_DEFAULT_PATH) 
# add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp)
# target_link_libraries(test ${ROSBAG_STORAGE})
