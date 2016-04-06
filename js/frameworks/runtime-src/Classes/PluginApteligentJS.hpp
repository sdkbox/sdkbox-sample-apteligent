#ifndef __PluginApteligentJS_h__
#define __PluginApteligentJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginApteligent_class;
extern JSObject *jsb_sdkbox_PluginApteligent_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginApteligentJS_PluginApteligent(JSContext *cx, JS::HandleObject global);
void register_all_PluginApteligentJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginApteligentJS_PluginApteligent(JSContext *cx, JSObject* global);
void register_all_PluginApteligentJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginApteligentJS_PluginApteligent_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginApteligentJS_PluginApteligent_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_beginUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_beginUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setLoggingLevel(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setLoggingLevel(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setOptOutStatus(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setOptOutStatus(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setValueforKey(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setValueforKey(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_endUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_endUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setUsername(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setUsername(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_updateLocation(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_updateLocation(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_valueForUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_valueForUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_logNetworkRequest(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_logNetworkRequest(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_sendAppLoadData(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_sendAppLoadData(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_getUserUUID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_getUserUUID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_cancelUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_cancelUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setValueforUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setValueforUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_addFilter(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_addFilter(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_getOptOutStatus(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_getOptOutStatus(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_failUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_failUserflow(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

