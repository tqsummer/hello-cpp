cmake_minimum_required(VERSION 3.26)
project(hello-cpp)

# 添加模块的子目录
add_subdirectory(system_code)
add_subdirectory(module_adv)
add_subdirectory(module_basic)
add_subdirectory(module1)
add_subdirectory(module2)


set(CMAKE_CXX_STANDARD 17)
