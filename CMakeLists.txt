cmake_minimum_required(VERSION 3.13)

project(example)


include(cmake/opennurbs.cmake)

add_executable(example
	src/main.cpp)

target_compile_definitions(example PRIVATE OPENNURBS_INPUT_LIBS_DIR=${opennurbs_LIBS_DIR} OPENNURBS_IMPORTS)

target_link_libraries(example opennurbs uuid)

target_include_directories(example
	PUBLIC
	${opennurbs_INCLUDE_DIRS}
)
