//
// Created by Administrator on 2021/2/19.
//

#ifndef NATIVEBITMAPDEMO_N_BITMAP_HELPER_H
#define NATIVEBITMAPDEMO_N_BITMAP_HELPER_H

#define N_BITMAP_HELPER_METHOD_COUNT 1

#include "logger.h"
#include <jni.h>
#include <android/native_window_jni.h>
#include <android/native_window.h>

extern "C" {

extern const char *N_BITMAP_HELPER_CLS_NAME;

extern JNINativeMethod N_BITMAP_HELPER_METHOD[N_BITMAP_HELPER_METHOD_COUNT];

JNIEXPORT void JNICALL NBH_ShowBitmap(JNIEnv *env, jclass jcls, jobject jsurface, jobject jbitmap);
};

#endif //NATIVEBITMAPDEMO_N_BITMAP_HELPER_H
