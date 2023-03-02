cmake_minimum_required(VERSION 3.0.0)

project(<name>)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src/)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib/)
set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin/)

set(CMAKE_CXX_STANDARD 20)

include_directories(${INCLUDE_DIR})

add_definitions("-D_XKEYCHECK_H")
add_definitions(-DPROJECT_DIR="${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE header_files ${SRC_DIR}/*.h)
file(GLOB_RECURSE src_files ${SRC_DIR}/*.cpp)
file(GLOB lib_files ${LIB_DIR}*.lib)
file(GLOB bin_files ${BIN_DIR}*.dll)

add_executable(${PROJECT_NAME}
    ${header_files}
    ${src_files})

target_link_libraries(${PROJECT_NAME} ${lib_files})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}")

add_custom_command(TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${bin_files} $<TARGET_FILE_DIR:${PROJECT_NAME}>
    VERBATIM)
