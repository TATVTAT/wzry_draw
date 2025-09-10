LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# 模块名
LOCAL_MODULE := AuroraTest.sh

# C++ 编译选项
LOCAL_CPPFLAGS := -w -std=c++17

# ===== LLVM 混淆选项（可选，按需取消注释） =====
# 简单保护
# LOCAL_CPPFLAGS += -mllvm -sub -mllvm -sobf -mllvm -split -mllvm -bcf -mllvm -fla
# 高强度保护
# LOCAL_CPPFLAGS += -mllvm -sub -mllvm -sub_loop=3 -mllvm -sobf \
#                   -mllvm -split -mllvm -split_num=3 \
#                   -mllvm -bcf -mllvm -bcf_loop=1 -mllvm -bcf_prob=10 \
#                   -mllvm -fla
# ================================================

# include 路径
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/include \
    $(LOCAL_PATH)/include/ImGui \
    $(LOCAL_PATH)/include/Draw \
    $(LOCAL_PATH)/include/KMA

# 自动收集 src 下所有源文件
FILE_LIST := $(wildcard $(LOCAL_PATH)/src/**/*.c*) \
             $(wildcard $(LOCAL_PATH)/src/*.c*)

LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

# 预编译静态库（.a）
LOCAL_STATIC_LIBRARIES := driver

# 链接系统库
LOCAL_LDLIBS := -lEGL -lGLESv2 -lGLESv3 -landroid -llog

include $(BUILD_EXECUTABLE)

# 声明预编译库
include $(CLEAR_VARS)
LOCAL_MODULE := driver
LOCAL_SRC_FILES := prebuilt/kma/driver.a
include $(PREBUILT_STATIC_LIBRARY)
