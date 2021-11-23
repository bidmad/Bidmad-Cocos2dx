LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := $(LOCAL_PATH)/hellocpp/main.cpp \
                   $(LOCAL_PATH)/../../../Classes/AppDelegate.cpp \
                   $(LOCAL_PATH)/../../../Classes/HelloWorldScene.cpp \
                   $(LOCAL_PATH)/../../../Classes/RewardSampleScene.cpp \
                   $(LOCAL_PATH)/../../../Classes/InterstitialSampleScene.cpp \
                   $(LOCAL_PATH)/../../../Classes/BannerSampleScene.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/RewardInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/InterstitialInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/BannerInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/CommonInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/GoogleGDPRInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/RewardController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/RewardCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/InterstitialController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/InterstitialCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/BannerController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/BannerCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/CommonController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/GoogleGDPRController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/GoogleGDPRCallback.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
