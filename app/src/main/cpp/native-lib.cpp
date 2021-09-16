#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_myron_ndklearn_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
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