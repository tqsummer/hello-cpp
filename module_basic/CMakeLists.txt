# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

# Module1Basic的 CMakeLists.txt

project(ModuleBasic)

# 指定源文件目录
#aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCES)

# 指定头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(VariableTypeMain
        ${CMAKE_CURRENT_SOURCE_DIR}/src/variable_type.c)

set(OpCodeStructMain
        ${CMAKE_CURRENT_SOURCE_DIR}/src/operator_codestruct.c)

set(ArrayMain
        ${CMAKE_CURRENT_SOURCE_DIR}/src/array.c)

set(FunctionMain
        ${CMAKE_CURRENT_SOURCE_DIR}/src/function.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/my_math.c)
# 添加可执行文件
add_executable(ModuleBasic-VariableTypeMain ${VariableTypeMain})
add_executable(ModuleBasic-OpCodeStructMain ${OpCodeStructMain})
add_executable(ModuleBasic-ArrayMain ${ArrayMain})
add_executable(ModuleBasic-FunctionMain ${FunctionMain})

# 如果 Module1 需要链接其他库，可以在这里添加链接命令
# target_link_libraries(ModuleBasic <其他库的名称>)