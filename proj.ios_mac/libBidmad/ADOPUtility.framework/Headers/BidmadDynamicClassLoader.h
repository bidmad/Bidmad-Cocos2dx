//
//  BidmadDynamicClassLoader.h
//  ADOPUtility
//
//  Created by ADOP_Mac on 2022/04/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BidmadDynamicClassLoader : NSObject

+ (id _Nullable)create:(NSString * _Nonnull)className;

+ (id _Nullable)create:(NSString * _Nonnull)className
           initializer:(SEL _Nonnull)init
                   arg:(id _Nonnull)arg;

+ (id _Nullable)create:(NSString * _Nonnull)className
           initializer:(SEL _Nonnull)init
                  arg1:(id _Nonnull)arg1
                  arg2:(id _Nonnull)arg2;

+ (id _Nullable)create:(NSString * _Nonnull)className
           initializer:(SEL _Nonnull)init
                  arg1:(id _Nonnull)arg1
                  arg2:(id _Nonnull)arg2
                  arg3:(id _Nonnull)arg3;

+ (id _Nullable)create:(NSString * _Nonnull)className
           initializer:(SEL _Nonnull)init
                  arg1:(id _Nonnull)arg1
                  arg2:(id _Nonnull)arg2
                  arg3:(id _Nonnull)arg3
                  arg4:(id _Nonnull)arg4;

+ (id _Nullable)create:(NSString * _Nonnull)className
           initializer:(SEL _Nonnull)init
                  arg1:(id _Nonnull)arg1
                  arg2:(id _Nonnull)arg2
                  arg3:(id _Nonnull)arg3
                  arg4:(id _Nonnull)arg4
                  arg5:(id _Nonnull)arg5;

+ (id _Nullable)create:(NSString * _Nonnull)className
           initializer:(SEL _Nonnull)init
                  arg1:(id _Nonnull)arg1
                  arg2:(id _Nonnull)arg2
                  arg3:(id _Nonnull)arg3
                  arg4:(id _Nonnull)arg4
                  arg5:(id _Nonnull)arg5
                  arg6:(id _Nonnull)arg6;

+ (id _Nullable)createNativeAdFrom:(NSString * _Nonnull)className
                            adcode:(NSString *)adcode
                             pubid:(NSString *)pubid
                  bidmadController:(id)bidmadController
                           isDebug:(BOOL)isDebug
                isChildDirectedAds:(NSNumber * _Nullable)isChildDirectedAds
                      loadCallback:(void (^)(id _Nullable))loadCallback
                     clickCallback:(void (^)(id _Nonnull))clickCallback;

@end

NS_ASSUME_NONNULL_END
