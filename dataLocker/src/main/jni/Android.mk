LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# 要生成的.so库名称。java代码System.loadLibrary("firstndk");加载的就是它
LOCAL_MODULE := DataLocker

# C++文件
LOCAL_SRC_FILES := locker.c \
                    aes.c \
                    base64.c

include $(BUILD_SHARED_LIBRARY)