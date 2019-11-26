#include <regex>
#include "HelloCxxModule.h"
#include "cxxreact/JsArgumentHelpers.h"

#include "cxxreact/Instance.h"
#include "md5.h"

HelloCxxModule::HelloCxxModule() {}

using namespace folly;

std::string HelloCxxModule::getName() {
    return "HelloCxxModule";
}

auto HelloCxxModule::getConstants() -> std::map<std::string, folly::dynamic> {
    return {
            {"one",    1},
            {"two",    2},
            {"animal", "fox"},
    };
}

auto HelloCxxModule::getMethods() -> std::vector<Method> {
    return {
            Method("foo", [](folly::dynamic args, Callback cb) { cb({"foo"}); }),
            Method("bar",
                   [this]() {
                       if (auto reactInstance = getInstance().lock()) {
                           reactInstance->callJSFunction(
                                   "RCTDeviceEventEmitter", "emit",
                                   folly::dynamic::array(
                                           "appStateDidChange",
                                           folly::dynamic::object("app_state",
                                                                  "active")));
                       }
                   }),
            Method("md5", [](folly::dynamic args, Callback cb) {
                std::string a = facebook::xplat::jsArgAsString(args, 0);
                MD5 s(a);
                cb({s.toStr()});
            }),
            Method("testSpeed", [](folly::dynamic args, Callback cb) {
                int i = 0,j = 0,k=0,ret = 0;
                for(;i<10000;i++){
                    for(;j<10000;j++){
                        for (; k < 10000; k++) {
                            ret+=k;
                        }
                    }
                }
                cb({ret});
            })
    };
}


extern "C" HelloCxxModule *createHelloCxxModule() {
    return new HelloCxxModule();
}
