#include <jni.h>
#include "react-native-quack.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_quack_QuackModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return quack::multiply(a, b);
}
