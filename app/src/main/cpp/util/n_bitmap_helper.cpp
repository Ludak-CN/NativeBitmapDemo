//
// Created by Administrator on 2021/2/19.
//

#include <string.h>
#include "n_bitmap_helper.h"
#include "../model/MyBitmap.h"

extern "C" {

extern const char *N_BITMAP_HELPER_CLS_NAME{"com/ludakchen/nativebitmapdemo/util/NBitmapHelper"};

extern JNINativeMethod N_BITMAP_HELPER_METHOD[N_BITMAP_HELPER_METHOD_COUNT]{
        {"nativeShowBitmap", "(Landroid/view/Surface;Landroid/graphics/Bitmap;)V", (void *) NBH_ShowBitmap},
};

JNIEXPORT void JNICALL NBH_ShowBitmap(JNIEnv *env, jclass jcls, jobject jsurface, jobject jbitmap) {
    MyBitmap bitmap(env,jbitmap);
    LOGD("BitmapHelper","width:%d",bitmap.getWidth())
    LOGD("BitmapHelper","height:%d",bitmap.getHeight())
    LOGD("BitmapHelper","format:%d",bitmap.getFormat())
    LOGD("BitmapHelper","stride:%d",bitmap.getStride())

    if (bitmap.isLockBitmap()){
        ANativeWindow* pWindow = ANativeWindow_fromSurface(env,jsurface);
        if (pWindow){
            if (!ANativeWindow_setBuffersGeometry(pWindow,bitmap.getWidth(),bitmap.getHeight(),bitmap.getFormat())){
                //申请缓冲区成功,锁定窗口
                ANativeWindow_Buffer pWindowBuffer;
                if (!ANativeWindow_lock(pWindow,&pWindowBuffer, nullptr)){
                    //将图片数据拷贝至窗口缓冲区
                    //窗口缓冲区内存首地址
                    uint8_t* pSurfaceData = (uint8_t*)pWindowBuffer.bits;
                    //窗口缓冲步长，可以理解为宽度，单位字节
                    int surfaceStride = pWindowBuffer.stride*4;
                    //图片缓冲区步长,单位字节
                    int bitmapStride = bitmap.getStride();

                    //将图片缓冲区的数据一行一行拷贝至窗口缓冲区
                    for (int i = 0; i < bitmap.getHeight(); i++) {
                        memcpy(pSurfaceData+(i*surfaceStride),bitmap.getData()+(i*bitmapStride),bitmapStride);
                    }
                    //刷新，释放窗口锁定
                    ANativeWindow_unlockAndPost(pWindow);
                }
            }
        }
    }

}


};