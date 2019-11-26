//
// Created by x zm on 2019-11-26.
//
#include "TestBinding.h"

#if ANDROID
extern "C"
{
JNIEXPORT void JNICALL
Java_com_example_MainActivity_install(JNIEnv *env, jobject thiz, jlong runtimePtr) {
    auto testModuleName = "nativeTest";
    auto &runtime = *((jsi::Runtime *) runtimePtr);
    auto testBinding = std::make_shared<TestBinding>();
    auto object = jsi::Object::createFromHostObject(runtime, testBinding);
    runtime.global().setProperty(runtime, testModuleName, std::move(object));
}

TestBinding::TestBinding() {}

jsi::Value TestBinding::get(
        jsi::Runtime &runtime,
        const jsi::PropNameID &name) {
    auto methodName = name.utf8(runtime);
    if (methodName == "runTest") {
        return jsi::Function::createFromHostFunction(runtime, name, 0, [](
                jsi::Runtime &runtime,
                const jsi::Value &thisValue,
                const jsi::Value *arguments,
                size_t count) -> jsi::Value {
            return 100;
        });
    }
    return jsi::Value::undefined();
}
}
#endif