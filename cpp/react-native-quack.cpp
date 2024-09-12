#include "react-native-quack.h"
#include <thread>
#include "macros.h"

namespace facebook::react {

NativeQuackTurboModule::NativeQuackTurboModule(
    std::shared_ptr<CallInvoker> jsinvoker)
    : NativeQuackCxxSpec<NativeQuackTurboModule>(std::move(jsinvoker)) {}

jsi::Value NativeQuackTurboModule::hello(jsi::Runtime &rt) {
  jsi::Function promiseConstructor =
        rt.global().getPropertyAsFunction(rt, "Promise");
  
  return promiseConstructor.callAsConstructor(rt, HOSTFN("promise") {
    auto resolve = std::make_shared<jsi::Value>(rt, args[0]);
    auto reject = std::make_shared<jsi::Value>(rt, args[1]);
    
    std::thread([resolve, reject, jsInvoker = jsInvoker_, &rt]() {
      std::string hello_str = "Hello world from thread";
      jsInvoker->invokeAsync([&rt, resolve, hello_str = std::move(hello_str)]() {
        auto hello_jsi = jsi::String::createFromUtf8(rt, hello_str);
        resolve->asObject(rt).asFunction(rt).call(rt, hello_str);
      });
    }).detach();
    
    return {};
  }));
  
}

} // namespace facebook::react
