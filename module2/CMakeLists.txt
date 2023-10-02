# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

# Module2 的 CMakeLists.txt

project(Module2)

# 指定源文件目录
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCES)

# 指定头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 创建静态库
#add_library(HelloCppModule2 STATIC ${SOURCES})

# 添加可执行文件
add_executable(Module2 ${SOURCES})

# 如果 Module2 需要链接其他库，可以在这里添加链接命令
target_link_libraries(Module2 HelloCppModule1)

# 将 include 目录添加到头文件搜索路径
#target_include_directories(Module2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../module1/include)