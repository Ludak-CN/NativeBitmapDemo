//
// Created by Administrator on 2021/2/19.
//

#include <jni.h>
#include "util/n_bitmap_helper.h"

static bool
registerNativeMethod(JNIEnv *env, const JNINativeMethod *pNativeMethod, const char *clsName,
                     jint methodCount) {
    if (env && pNativeMethod && clsName) {
        jclass cls = env->FindClass(clsName);
        if (cls) {
            jint result = env->RegisterNatives(cls, pNativeMethod, methodCount);
            if (result == JNI_OK) {
                return true;
            }
        }
    }

    return false;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reversed) {
    JNIEnv *env = nullptr;
    jint result = vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (result == JNI_OK) {
        if (registerNativeMethod(env, N_BITMAP_HELPER_METHOD, N_BITMAP_HELPER_CLS_NAME,
                                 N_BITMAP_HELPER_METHOD_COUNT)) {
            return JNI_VERSION_1_6;
        }
    }
    return JNI_ERR;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reversed) {
    JNIEnv *env = nullptr;
    jint result = vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (result == JNI_OK) {
        jclass cls = env->FindClass(N_BITMAP_HELPER_CLS_NAME);
        if (cls) {
            env->UnregisterNatives(cls);
        }
    }
}