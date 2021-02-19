cmake_minimum_required(VERSION 3.4.1)

add_library(
        native_bitmap
        SHARED

        JniImpl.cpp

        ${CMAKE_SOURCE_DIR}/util/logger.h
        ${CMAKE_SOURCE_DIR}/util/n_bitmap_helper.h
        ${CMAKE_SOURCE_DIR}/util/n_bitmap_helper.cpp

        ${CMAKE_SOURCE_DIR}/model/MyBitmap.h
        ${CMAKE_SOURCE_DIR}/model/MyBitmap.cpp

)

find_library(
        log-lib
        log
)

target_link_libraries(
        native_bitmap

        jnigraphics #使用bitmap.h需要链接此库
        android #使用native_window_jni，native_window_jni需要链接此库
        ${log-lib}
)