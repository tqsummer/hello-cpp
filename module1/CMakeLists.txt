# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

# Module1 的 CMakeLists.txt
project(Module1)

# 指定源文件目录
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCES)

# 指定头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 添加可执行文件
#add_executable(Module1 ${SOURCES})

# 创建静态库
add_library(HelloCppModule1 STATIC ${SOURCES})

# 将 include 目录添加到头文件搜索路径（INTERFACE类型）
target_include_directories(HelloCppModule1 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(INSTALL_DEST_DIR "D:/Workspace/LibraryWorkspace/C/hello-cpp/module1")
# 安装 HelloCppModule1 静态库和头文件
install(TARGETS HelloCppModule1 DESTINATION ${INSTALL_DEST_DIR})
# 安装头文件：整个目录的头文件都安装
install(DIRECTORY
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION ${INSTALL_DEST_DIR}/include)

# 安装头文件：通过GLOB获取头文件列表，foreach循环安装
#file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
#foreach(HEADER ${HEADER_FILES})
#    install(FILES ${HEADER} DESTINATION ${INSTALL_DEST_DIR}/include)
#endforeach()

# 安装头文件：可以手动添加头文件路径，一个个安装
#install(FILES
#        ${CMAKE_CURRENT_SOURCE_DIR}/include/module1_math.h
#        ${CMAKE_CURRENT_SOURCE_DIR}/include/module1_math2.h
#        DESTINATION ${INSTALL_DEST_DIR}/include)


# 如果 Module1 需要链接其他库，可以在这里添加链接命令
# target_link_libraries(Module1 <其他库的名称>)