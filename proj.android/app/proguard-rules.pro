# Add project specific ProGuard rules here.
# By default, the flags in this file are appended to flags specified
# in E:\developSoftware\Android\SDK/tools/proguard/proguard-android.txt
# You can edit the include path and order by changing the proguardFiles
# directive in build.gradle.
#
# For more details, see
#   http://developer.android.com/guide/developing/tools/proguard.html

# Add any project specific keep options here:

# If your project uses WebView with JS, uncomment the following
# and specify the fully qualified class name to the JavaScript interface
# class:
#-keepclassmembers class fqcn.of.javascript.interface.for.webview {
#   public *;
#}

# Proguard Cocos2d-x for release
-keep public class org.cocos2dx.** { *; }
-dontwarn org.cocos2dx.**
-keep public class com.chukong.** { *; }
-dontwarn com.chukong.**
-keep public class com.huawei.android.** { *; }
-dontwarn com.huawei.android.**

# Proguard Apache HTTP for release
-keep class org.apache.http.** { *; }
-dontwarn org.apache.http.**

# Proguard Android Webivew for release. uncomment if you are using a webview in cocos2d-x
#-keep public class android.net.http.SslError
#-keep public class android.webkit.WebViewClient

#-dontwarn android.webkit.WebView
#-dontwarn android.net.http.SslError
#-dontwarn android.webkit.WebViewClient

-keep class com.adop.sdk.** { *; }
-keep class ad.helper.openbidding.** { *; }
-keep class com.adop.sdk.adapter.**{ *; }
-keepnames class * implements java.io.Serializable
-keepclassmembers class * implements java.io.Serializable {
    static final long serialVersionUID;
    private static final java.io.ObjectStreamField[] serialPersistentFields;
    !static !transient <fields>;
    private void writeObject(java.io.ObjectOutputStream);
    private void readObject(java.io.ObjectInputStream);
    java.lang.Object writeReplace();
    java.lang.Object readResolve();
}
-keepclassmembers class * {
    @android.webkit.JavascriptInterface <methods>;
}

# Pangle
-keep class com.bytedance.sdk.** { *; }
-keep class com.bykv.vk.openvk.component.video.api.** { *; }

# Tapjoy
-keep class com.tapjoy.** { *; }
-keep class com.moat.** { *; }
-keepattributes JavascriptInterface
-keepattributes *Annotation*
-keep class * extends java.util.ListResourceBundle {
protected Object[][] getContents();
}
-keep public class com.google.android.gms.common.internal.safeparcel.SafeParcelable {
public static final *** NULL;
}
-keepnames @com.google.android.gms.common.annotation.KeepName class *
-keepclassmembernames class * {
@com.google.android.gms.common.annotation.KeepName *;
}
-keepnames class * implements android.os.Parcelable {
public static final ** CREATOR;
}
-keep class com.google.android.gms.ads.identifier.** { *; }
-dontwarn com.tapjoy.**