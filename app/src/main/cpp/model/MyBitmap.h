//
// Created by Administrator on 2021/2/19.
//

#ifndef NATIVEBITMAPDEMO_MYBITMAP_H
#define NATIVEBITMAPDEMO_MYBITMAP_H

#include <android/bitmap.h>
#include <jni.h>
#include "../util/logger.h"


class MyBitmap {

    const char* const TAG = "MyBitmap";

public:
    MyBitmap(JNIEnv* env,jobject bitmap);

    ~MyBitmap();

    uint32_t getWidth();

    uint32_t getHeight();

    int32_t getFormat();

    int32_t getStride();

    uint8_t* getData();

    bool isLockBitmap();

private:
    AndroidBitmapInfo m_BitmapInfo;
    uint8_t* m_p_BitmapData;
    JavaVM* m_p_JavaVm;
    jobject m_bitmap;

    bool m_IsLockBitmap;
};


#endif //NATIVEBITMAPDEMO_MYBITMAP_H
