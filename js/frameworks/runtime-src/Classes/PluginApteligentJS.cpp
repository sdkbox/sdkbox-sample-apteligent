#include "PluginApteligentJS.hpp"
#include "cocos2d_specifics.hpp"
#include "PluginApteligent/PluginApteligent.h"
#include "SDKBoxJSHelper.h"
#include "sdkbox/Sdkbox.h"


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

#if (COCOS2D_VERSION >= 0x00031000)
        JS::RootedObject proto(cx, typeClass->proto.ref());
        JS::RootedObject parent(cx, typeClass->parentProto.ref());
#else
        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
#endif
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
        
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        AddObjectRoot(cx, &pp->obj);
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;    
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;    
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_PluginApteligent_class;
JSObject *jsb_sdkbox_PluginApteligent_prototype;

bool js_PluginApteligentJS_PluginApteligent_beginUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            int arg1;
            ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginApteligent::beginUserflow(arg0, arg1);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            sdkbox::PluginApteligent::beginUserflow(arg0);
            return true;
        }
    } while (0);
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_beginUserflow : wrong number of arguments");
    return false;
}
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setLoggingLevel(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_setLoggingLevel : Error processing arguments");
        sdkbox::PluginApteligent::setLoggingLevel(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_setLoggingLevel : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setLoggingLevel(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::setLoggingLevel(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setOptOutStatus(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_setOptOutStatus : Error processing arguments");
        sdkbox::PluginApteligent::setOptOutStatus(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_setOptOutStatus : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setOptOutStatus(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::setOptOutStatus(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setValueforKey(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_setValueforKey : Error processing arguments");
        sdkbox::PluginApteligent::setValueforKey(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_setValueforKey : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setValueforKey(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::setValueforKey(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode : Error processing arguments");
        sdkbox::PluginApteligent::setAsyncBreadcrumbMode(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::setAsyncBreadcrumbMode(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_endUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_endUserflow : Error processing arguments");
        sdkbox::PluginApteligent::endUserflow(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_endUserflow : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_endUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::endUserflow(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setUsername(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_setUsername : Error processing arguments");
        sdkbox::PluginApteligent::setUsername(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_setUsername : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setUsername(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::setUsername(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginApteligent::init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginApteligent::init();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        int ret = sdkbox::PluginApteligent::maxOfflineCrashReports();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        int ret = sdkbox::PluginApteligent::maxOfflineCrashReports();
        jsval jsret;
        jsret = int32_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_updateLocation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        double arg0;
        double arg1;
        ok &= sdkbox::js_to_number(cx, args.get(0), &arg0);
        ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_updateLocation : Error processing arguments");
        sdkbox::PluginApteligent::updateLocation(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_updateLocation : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_updateLocation(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        double arg0;
        double arg1;
        ok &= sdkbox::js_to_number(cx, argv[0], &arg0);
        ok &= sdkbox::js_to_number(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::updateLocation(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_valueForUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_valueForUserflow : Error processing arguments");
        int ret = sdkbox::PluginApteligent::valueForUserflow(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_valueForUserflow : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_valueForUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        int ret = sdkbox::PluginApteligent::valueForUserflow(arg0);
        jsval jsret;
        jsret = int32_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_logNetworkRequest(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 6) {
        std::string arg0;
        std::string arg1;
        long arg2;
        long arg3;
        long arg4;
        long arg5;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_long(cx, args.get(2), &arg2);
        ok &= jsval_to_long(cx, args.get(3), &arg3);
        ok &= jsval_to_long(cx, args.get(4), &arg4);
        ok &= jsval_to_long(cx, args.get(5), &arg5);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_logNetworkRequest : Error processing arguments");
        bool ret = sdkbox::PluginApteligent::logNetworkRequest(arg0, arg1, arg2, arg3, arg4, arg5);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_logNetworkRequest : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_logNetworkRequest(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 6) {
        std::string arg0;
        std::string arg1;
        long arg2;
        long arg3;
        long arg4;
        long arg5;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        ok &= jsval_to_long(cx, argv[2], &arg2);
        ok &= jsval_to_long(cx, argv[3], &arg3);
        ok &= jsval_to_long(cx, argv[4], &arg4);
        ok &= jsval_to_long(cx, argv[5], &arg5);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginApteligent::logNetworkRequest(arg0, arg1, arg2, arg3, arg4, arg5);
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_sendAppLoadData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginApteligent::sendAppLoadData();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_sendAppLoadData : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_sendAppLoadData(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginApteligent::sendAppLoadData();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports : Error processing arguments");
        sdkbox::PluginApteligent::setMaxOfflineCrashReports(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::setMaxOfflineCrashReports(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_getUserUUID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginApteligent::getUserUUID();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_getUserUUID : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_getUserUUID(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginApteligent::getUserUUID();
        jsval jsret;
        jsret = std_string_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_cancelUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_cancelUserflow : Error processing arguments");
        sdkbox::PluginApteligent::cancelUserflow(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_cancelUserflow : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_cancelUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::cancelUserflow(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_setValueforUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        int arg0;
        std::string arg1;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_setValueforUserflow : Error processing arguments");
        sdkbox::PluginApteligent::setValueforUserflow(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_setValueforUserflow : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setValueforUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        int arg0;
        std::string arg1;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::setValueforUserflow(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginApteligent::didCrashOnLastLoad();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginApteligent::didCrashOnLastLoad();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_addFilter(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_addFilter : Error processing arguments");
        sdkbox::PluginApteligent::addFilter(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_addFilter : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_addFilter(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::addFilter(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb : Error processing arguments");
        sdkbox::PluginApteligent::leaveBreadcrumb(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::leaveBreadcrumb(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_getOptOutStatus(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginApteligent::getOptOutStatus();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_getOptOutStatus : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_getOptOutStatus(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginApteligent::getOptOutStatus();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginApteligentJS_PluginApteligent_failUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_failUserflow : Error processing arguments");
        sdkbox::PluginApteligent::failUserflow(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_failUserflow : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_failUserflow(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginApteligent::failUserflow(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginApteligentJS_PluginApteligent_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginApteligent)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;

#if (COCOS2D_VERSION >= 0x00031000)
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
#else
    jsproxy = jsb_get_js_proxy(obj);
#endif

    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginApteligent *nobj = static_cast<sdkbox::PluginApteligent *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginApteligentJS_PluginApteligent(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginApteligent_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginApteligent_class->name = "PluginApteligent";
    jsb_sdkbox_PluginApteligent_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginApteligent_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginApteligent_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginApteligent_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginApteligent_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginApteligent_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginApteligent_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginApteligent_class->finalize = js_PluginApteligentJS_PluginApteligent_finalize;
    jsb_sdkbox_PluginApteligent_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("beginUserflow", js_PluginApteligentJS_PluginApteligent_beginUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLoggingLevel", js_PluginApteligentJS_PluginApteligent_setLoggingLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setOptOutStatus", js_PluginApteligentJS_PluginApteligent_setOptOutStatus, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setValueforKey", js_PluginApteligentJS_PluginApteligent_setValueforKey, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAsyncBreadcrumbMode", js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("endUserflow", js_PluginApteligentJS_PluginApteligent_endUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUsername", js_PluginApteligentJS_PluginApteligent_setUsername, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginApteligentJS_PluginApteligent_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("maxOfflineCrashReports", js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("updateLocation", js_PluginApteligentJS_PluginApteligent_updateLocation, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("valueForUserflow", js_PluginApteligentJS_PluginApteligent_valueForUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logNetworkRequest", js_PluginApteligentJS_PluginApteligent_logNetworkRequest, 6, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sendAppLoadData", js_PluginApteligentJS_PluginApteligent_sendAppLoadData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setMaxOfflineCrashReports", js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUserUUID", js_PluginApteligentJS_PluginApteligent_getUserUUID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cancelUserflow", js_PluginApteligentJS_PluginApteligent_cancelUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setValueforUserflow", js_PluginApteligentJS_PluginApteligent_setValueforUserflow, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("didCrashOnLastLoad", js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addFilter", js_PluginApteligentJS_PluginApteligent_addFilter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("leaveBreadcrumb", js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getOptOutStatus", js_PluginApteligentJS_PluginApteligent_getOptOutStatus, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("failUserflow", js_PluginApteligentJS_PluginApteligent_failUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginApteligent_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginApteligent_class,
        dummy_constructor<sdkbox::PluginApteligent>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginApteligent", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
#if (COCOS2D_VERSION >= 0x00031000)
    JS::RootedObject proto(cx, jsb_sdkbox_PluginApteligent_prototype);
    jsb_register_class<sdkbox::PluginApteligent>(cx, jsb_sdkbox_PluginApteligent_class, proto, JS::NullPtr());
#else
    TypeTest<sdkbox::PluginApteligent> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginApteligent_class;
        p->proto = jsb_sdkbox_PluginApteligent_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
#endif
}
#else
void js_register_PluginApteligentJS_PluginApteligent(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginApteligent_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginApteligent_class->name = "PluginApteligent";
    jsb_sdkbox_PluginApteligent_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginApteligent_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginApteligent_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginApteligent_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginApteligent_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginApteligent_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginApteligent_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginApteligent_class->finalize = js_PluginApteligentJS_PluginApteligent_finalize;
    jsb_sdkbox_PluginApteligent_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("beginUserflow", js_PluginApteligentJS_PluginApteligent_beginUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLoggingLevel", js_PluginApteligentJS_PluginApteligent_setLoggingLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setOptOutStatus", js_PluginApteligentJS_PluginApteligent_setOptOutStatus, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setValueforKey", js_PluginApteligentJS_PluginApteligent_setValueforKey, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAsyncBreadcrumbMode", js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("endUserflow", js_PluginApteligentJS_PluginApteligent_endUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUsername", js_PluginApteligentJS_PluginApteligent_setUsername, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginApteligentJS_PluginApteligent_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("maxOfflineCrashReports", js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("updateLocation", js_PluginApteligentJS_PluginApteligent_updateLocation, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("valueForUserflow", js_PluginApteligentJS_PluginApteligent_valueForUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logNetworkRequest", js_PluginApteligentJS_PluginApteligent_logNetworkRequest, 6, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sendAppLoadData", js_PluginApteligentJS_PluginApteligent_sendAppLoadData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setMaxOfflineCrashReports", js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUserUUID", js_PluginApteligentJS_PluginApteligent_getUserUUID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cancelUserflow", js_PluginApteligentJS_PluginApteligent_cancelUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setValueforUserflow", js_PluginApteligentJS_PluginApteligent_setValueforUserflow, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("didCrashOnLastLoad", js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addFilter", js_PluginApteligentJS_PluginApteligent_addFilter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("leaveBreadcrumb", js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getOptOutStatus", js_PluginApteligentJS_PluginApteligent_getOptOutStatus, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("failUserflow", js_PluginApteligentJS_PluginApteligent_failUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginApteligent_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginApteligent_class,
        dummy_constructor<sdkbox::PluginApteligent>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginApteligent", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginApteligent> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginApteligent_class;
        p->proto = jsb_sdkbox_PluginApteligent_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginApteligentJS_PluginApteligent(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginApteligent_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginApteligent_class->name = "PluginApteligent";
    jsb_sdkbox_PluginApteligent_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginApteligent_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginApteligent_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginApteligent_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginApteligent_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginApteligent_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginApteligent_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginApteligent_class->finalize = js_PluginApteligentJS_PluginApteligent_finalize;
    jsb_sdkbox_PluginApteligent_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("beginUserflow", js_PluginApteligentJS_PluginApteligent_beginUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLoggingLevel", js_PluginApteligentJS_PluginApteligent_setLoggingLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setOptOutStatus", js_PluginApteligentJS_PluginApteligent_setOptOutStatus, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setValueforKey", js_PluginApteligentJS_PluginApteligent_setValueforKey, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAsyncBreadcrumbMode", js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("endUserflow", js_PluginApteligentJS_PluginApteligent_endUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUsername", js_PluginApteligentJS_PluginApteligent_setUsername, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginApteligentJS_PluginApteligent_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("maxOfflineCrashReports", js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("updateLocation", js_PluginApteligentJS_PluginApteligent_updateLocation, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("valueForUserflow", js_PluginApteligentJS_PluginApteligent_valueForUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logNetworkRequest", js_PluginApteligentJS_PluginApteligent_logNetworkRequest, 6, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sendAppLoadData", js_PluginApteligentJS_PluginApteligent_sendAppLoadData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setMaxOfflineCrashReports", js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUserUUID", js_PluginApteligentJS_PluginApteligent_getUserUUID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cancelUserflow", js_PluginApteligentJS_PluginApteligent_cancelUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setValueforUserflow", js_PluginApteligentJS_PluginApteligent_setValueforUserflow, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("didCrashOnLastLoad", js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addFilter", js_PluginApteligentJS_PluginApteligent_addFilter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("leaveBreadcrumb", js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getOptOutStatus", js_PluginApteligentJS_PluginApteligent_getOptOutStatus, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("failUserflow", js_PluginApteligentJS_PluginApteligent_failUserflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginApteligent_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginApteligent_class,
        dummy_constructor<sdkbox::PluginApteligent>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginApteligent", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginApteligent> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginApteligent_class;
        p->proto = jsb_sdkbox_PluginApteligent_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginApteligentJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginApteligentJS_PluginApteligent(cx, ns);

    sdkbox::setProjectType("js");
}
#else
void register_all_PluginApteligentJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginApteligentJS_PluginApteligent(cx, obj);

    sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginApteligentJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginApteligentJS_PluginApteligent(cx, obj);

    sdkbox::setProjectType("js");
}
#endif