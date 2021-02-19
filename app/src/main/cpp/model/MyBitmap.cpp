//
// Created by Administrator on 2021/2/19.
//

#include "MyBitmap.h"

MyBitmap::MyBitmap(JNIEnv *env, jobject bitmap) {
    m_p_BitmapData = nullptr;
    m_p_JavaVm = nullptr;
    m_IsLockBitmap = false;

    if (env&&bitmap){
        m_bitmap = env->NewGlobalRef(bitmap);
        env->GetJavaVM(&m_p_JavaVm);
        if (m_p_JavaVm){
           if ( AndroidBitmap_getInfo(env,bitmap,&m_BitmapInfo)==ANDROID_BITMAP_RESULT_SUCCESS){
               //锁定bitmap
              if ( AndroidBitmap_lockPixels(env,bitmap,(void**)&m_p_BitmapData)==ANDROID_BITMAP_RESULT_SUCCESS){
                  m_IsLockBitmap = true;
              }
           }
        }
    }

    if (m_IsLockBitmap){
        LOGD(TAG,"AndroidBitmap_lockPixels success.")
    }else{
        LOGD(TAG,"AndroidBitmap_lockPixels failed.")
    }

}

MyBitmap::~MyBitmap() {
    if (m_IsLockBitmap){
        m_IsLockBitmap = false;
        JNIEnv* env = nullptr;
        m_p_JavaVm->GetEnv((void**)&env,JNI_VERSION_1_6);
        if (env){
            AndroidBitmap_unlockPixels(env,m_bitmap);
            env->DeleteGlobalRef(m_bitmap);
        }
        LOGD(TAG,"~MyBitmap")
    }
}

uint32_t MyBitmap::getWidth() {
    if (m_IsLockBitmap){
        return m_BitmapInfo.width;
    }
    return 0;
}

uint32_t MyBitmap::getHeight() {
    if (m_IsLockBitmap){
        return m_BitmapInfo.height;
    }
    return 0;
}

int32_t MyBitmap::getFormat() {
    if (m_IsLockBitmap){
        return m_BitmapInfo.format;
    }
    return ANDROID_BITMAP_FORMAT_NONE;
}

int32_t MyBitmap::getStride() {
    if (m_IsLockBitmap){
        return m_BitmapInfo.stride;
    }
    return 0;
}


uint8_t *MyBitmap::getData() {
    if (m_IsLockBitmap){
        return m_p_BitmapData;
    }
    return nullptr;
}

bool MyBitmap::isLockBitmap() {
    return m_IsLockBitmap;
}


