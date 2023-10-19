# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

# Module1Basic的 CMakeLists.txt

project(ModuleAdv)

# 指定源文件目录
#aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCES)

# 指定头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(VariableTypeMain
        ${CMAKE_CURRENT_SOURCE_DIR}/src/variable_type.c)

# 添加可执行文件
add_executable(MA-VariableTypeMain ${VariableTypeMain})


# 如果 ModuleAdv 需要链接其他库，可以在这里添加链接命令
# target_link_libraries(ModuleAdv <其他库的名称>)