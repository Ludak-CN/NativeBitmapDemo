package com.ludakchen.nativebitmapdemo.util;

import android.graphics.Bitmap;
import android.view.Surface;

/**
 * @author chenlong
 * @date 2021/2/19
 * @Description
 */
public class NBitmapHelper {

    static {
        System.loadLibrary("native_bitmap");
    }

    public static void showBitmap(Surface surface, Bitmap bitmap) {
        nativeShowBitmap(surface, bitmap);
    }

    /**
     * native层处理显示图片
     *
     * @param surface 显示的缓冲区
     * @param bitmap  待显示的图片
     */
    private static native void nativeShowBitmap(Surface surface, Bitmap bitmap);
}
