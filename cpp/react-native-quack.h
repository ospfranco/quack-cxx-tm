#if __has_include(<React-Codegen/RNQuackSpecJSI.h>)
#include <React-Codegen/RNQuackSpecJSI.h>
#elif __has_include("RNQuackSpecJSI.h")
#include "RNQuackSpecJSI.h"
#endif

#include <ReactCommon/CallInvoker.h>
#include <jsi/jsi.h>

namespace facebook::react {
class NativeQuackTurboModule
    : public NativeQuackCxxSpec<NativeQuackTurboModule> {
public:
  NativeQuackTurboModule(std::shared_ptr<CallInvoker> jsInvoker);
  jsi::Value hello(jsi::Runtime &rt);
};
} // namespace facebook::react
