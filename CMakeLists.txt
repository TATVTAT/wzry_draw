cmake_minimum_required(VERSION 3.10)

# 项目名
project(AuroraTest LANGUAGES C CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 编译选项
add_compile_options(-w)

# ===== LLVM 混淆选项（可选）=====
# 如果你想启用 LLVM obfuscation，可以手动打开：
# add_compile_options(
#     -mllvm -sub -mllvm -sobf -mllvm -split -mllvm -bcf -mllvm -fla
# )
# ==================================

# 包含头文件目录
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/Draw
        ${CMAKE_SOURCE_DIR}/include/Gerpicture
        ${CMAKE_SOURCE_DIR}/include/ImGui
        ${CMAKE_SOURCE_DIR}/include/KernelInterface
        ${CMAKE_SOURCE_DIR}/include/KMA
        ${CMAKE_SOURCE_DIR}/include/NativeSurface
)

# 自动收集 src 下所有 cpp 文件
file(GLOB_RECURSE SRC_FILES
        ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# 添加可执行文件
add_executable(AuroraTest ${SRC_FILES})

# 链接 driver.a 静态库
add_library(driver STATIC IMPORTED)
set_target_properties(driver PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/prebuilt/kma/driver.a
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include/KMA
)

# 链接库
target_link_libraries(AuroraTest PRIVATE
        driver
        EGL
        GLESv2
        GLESv3
        android
        log
)