#ifndef RNPACKAGE_HELLO_CXX_MODULE_H_

#include "cxxreact/CxxModule.h"

class HelloCxxModule : public facebook::xplat::module::CxxModule {
public:
    HelloCxxModule();

    std::string getName() override;

    auto getConstants() -> std::map<std::string, folly::dynamic> override;

    auto getMethods() -> std::vector<Method> override;
};

#define RNPACKAGE_HELLO_CXX_MODULE_H_



#endif  // RNPACKAGE_HELLO_CXX_MODULE_H_
