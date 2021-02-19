package com.ludakchen.nativebitmapdemo.activity;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import com.ludakchen.nativebitmapdemo.R;
import com.ludakchen.nativebitmapdemo.util.NBitmapHelper;

import java.io.IOException;
import java.io.InputStream;

public class MainActivity extends AppCompatActivity {

    SurfaceView mSvBitmap;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mSvBitmap = findViewById(R.id.sv_bitmap);

        mSvBitmap.getHolder().addCallback(new SurfaceHolder.Callback() {
            @Override
            public void surfaceCreated(@NonNull SurfaceHolder holder) {

            }

            @Override
            public void surfaceChanged(@NonNull SurfaceHolder holder, int format, int width, int height) {
                NBitmapHelper.showBitmap(holder.getSurface(),loadBitmapAssets());
            }

            @Override
            public void surfaceDestroyed(@NonNull SurfaceHolder holder) {

            }
        });
    }

    private Bitmap loadBitmapAssets(){
        try {
            InputStream is = getAssets().open("cat.jpg");
            Bitmap bitmap = BitmapFactory.decodeStream(is);
            is.close();
            return bitmap;
        } catch (IOException e) {
            e.printStackTrace();
        }

        return null;
    }
}