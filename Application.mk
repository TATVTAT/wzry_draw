# 目标平台（最低支持的 Android API 版本）
APP_PLATFORM := android-21

# 目标 ABI（只编 arm64-v8a）
APP_ABI := arm64-v8a

# 使用的 STL（静态链接 C++ 标准库）
APP_STL := c++_static

# C++ 标准
APP_CPPFLAGS := -std=c++17

# 编译模式（release 带优化，可改为 debug）
APP_OPTIM := release
