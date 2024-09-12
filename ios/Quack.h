#ifdef __cplusplus
#import "react-native-quack.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNQuackSpec.h"

@interface Quack : NSObject <NativeQuackSpec>
#else
#import <React/RCTBridgeModule.h>

@interface Quack : NSObject <RCTBridgeModule>
#endif

@end
