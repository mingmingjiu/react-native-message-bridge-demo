//
// Created by x zm on 2019-11-26.
//

//#include "jsi/jsi/jsi.h"
#include "jsi/jsi.h"

#if ANDROID
#include <jni.h>
#endif

using namespace facebook;

#if ANDROID
extern "C" {
    JNIEXPORT void JNICALL
    Java_com_example_MainActivity_install(JNIEnv* env, jobject thiz, jlong runtimePtr);
}
#endif


/*
   * Exposes Test to JavaScript realm.
   */
class TestBinding : public jsi::HostObject {
public:
    /*
      * Installs TestBinding into JavaSctipt runtime.
      * Thread synchronization must be enforced externally.
      */
    static void install(
            jsi::Runtime &runtime,
            std::shared_ptr<TestBinding> testBinding);

    TestBinding();

    /*
      * `jsi::HostObject` specific overloads.
      */
    jsi::Value get(jsi::Runtime &runtime, const jsi::PropNameID &name) override;


};