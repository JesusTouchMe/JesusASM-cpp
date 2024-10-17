cmake_minimum_required(VERSION 3.8)

project(JesusASM)

set(SOURCES
	"src/jasm/Builder.cpp"
)

set(HEADERS
	"include/jasm/Builder.h"
)

source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

add_executable(JesusASM ${SOURCES} ${HEADERS})

target_include_directories(JesusASM PUBLIC include)
target_compile_features(JesusASM PUBLIC cxx_std_20)