#include <jni.h>
#include "aes.h"
#include <string.h>
#include <android/log.h>

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define CBC 1
#define ECB 1

// 获取数组的大小
# define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))

const char *UNSIGNATURE = "UNSIGNATURE";


__attribute__((section (".mytext")))
JNIEXPORT jstring JNICALL
Java_com_lib_encrypt_ndk_EncryptUtile_encrypt(JNIEnv *env, jobject instance, jstring str_) {
    uint8_t AES_KEY[] = "1234567890abcdef";
    const char *in = (*env)->GetStringUTFChars(env, str_, JNI_FALSE);
    char *baseResult = AES_128_ECB_PKCS5Padding_Encrypt(in, AES_KEY);
    (*env)->ReleaseStringUTFChars(env, str_, in);
    return (*env)->NewStringUTF(env, baseResult);
}

__attribute__((section (".mytext")))
JNIEXPORT jstring JNICALL
Java_com_lib_encrypt_ndk_EncryptUtile_decrypt(JNIEnv *env, jobject instance, jstring str_) {
    uint8_t AES_KEY[] = "1234567890abcdef";
    const char *str = (*env)->GetStringUTFChars(env, str_, JNI_FALSE);
    char *desResult = AES_128_ECB_PKCS5Padding_Decrypt(str, AES_KEY);
    (*env)->ReleaseStringUTFChars(env, str_, str);
    return (*env)->NewStringUTF(env, desResult);
    //不用系统自带的方法NewStringUTF是因为如果desResult是乱码,会抛出异常
    //return charToJstring(env,desResult);
}

