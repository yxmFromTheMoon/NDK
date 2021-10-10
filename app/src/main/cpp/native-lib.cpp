#include <jni.h>
#include <string>
#include <android/log.h>
#include "ArrayList.hpp"

extern "C" JNIEXPORT jstring JNICALL
Java_com_myron_ndklearn_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    ArrayList<int> *list = new ArrayList<int>(100);

    for (int i = 0; i < 100; ++i) {
        list->add(i);
    }

    for (int i = 0; i < list->size(); ++i) {
        __android_log_print(ANDROID_LOG_DEBUG,"ArrayList","i = :%d",i);
    }
    delete(list);
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_myron_ndklearn_MainActivity_signatureParams(JNIEnv *env, jobject) {
    std::string hello = "签名成功";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_myron_ndklearn_MainActivity_00024Companion_signature(JNIEnv *env, jobject thiz) {
    std::string hello = "签名成功";
    return env->NewStringUTF(hello.c_str());
}