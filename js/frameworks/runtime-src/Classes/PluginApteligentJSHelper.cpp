#include "PluginApteligentJSHelper.h"
#include "PluginApteligent/PluginApteligent.h"
#include "SDKBoxJSHelper.h"

extern JSObject* jsb_sdkbox_PluginApteligent_prototype;
static JSContext* s_cx = nullptr;

#if (COCOS2D_VERSION < 0x00030000)
#define Ref CCObject
#define Director CCDirector
#define getInstance sharedDirector
#define schedule scheduleSelector
#endif

class Apteligent_CallbackJS: public cocos2d::Ref {
public:
    Apteligent_CallbackJS();
    void schedule();
    void notityJs(float dt);

    std::string _name;

    jsval _paramVal[1];
    int _paramLen;
};

class ApteligentListenerJS : public sdkbox::ApteligentListener, public sdkbox::JSListenerBase
{
public:
    ApteligentListenerJS():sdkbox::JSListenerBase() {
    }

    void onCrashOnLastLoad() {
        Apteligent_CallbackJS* cb = new Apteligent_CallbackJS();
        cb->_name = "onCrashOnLastLoad";
        cb->_paramLen = 0;
        cb->schedule();
    }

    void invokeJS(const char* func, jsval* pVals, int valueSize) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = func;
        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::empty(), &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(valueSize, pVals), &retval);
            }
#else
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, 0, nullptr, &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, valueSize, pVals, &retval);
            }
#endif
        }
    }

};


Apteligent_CallbackJS::Apteligent_CallbackJS():
_paramLen(0) {
}

void Apteligent_CallbackJS::schedule() {
    retain();
    cocos2d::Director::getInstance()->getScheduler()->schedule(schedule_selector(Apteligent_CallbackJS::notityJs), this, 0.1, 0, 0.0f, false);
    autorelease();
}

void Apteligent_CallbackJS::notityJs(float dt) {
    sdkbox::ApteligentListener* lis = sdkbox::PluginApteligent::getListener();
    ApteligentListenerJS* l = dynamic_cast<ApteligentListenerJS*>(lis);
    if (l) {
        l->invokeJS(_name.c_str(), _paramVal, _paramLen);
    }
    release();
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginApteligentJS_PluginApteligent_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#else
bool js_PluginApteligentJS_PluginApteligent_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginApteligentJS_PluginApteligent_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    s_cx = cx;
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    if (argc == 1) {

        if (!args.get(0).isObject())
        {
            ok = false;
        }

        JSB_PRECONDITION2(ok, cx, false, "js_PluginApteligentJS_PluginApteligent_setIAPListener : Error processing arguments");
        ApteligentListenerJS* wrapper = new ApteligentListenerJS();
        wrapper->setJSDelegate(args.get(0));
        sdkbox::PluginApteligent::setListener(wrapper);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginApteligentJS_PluginApteligent_setIAPListener : wrong number of arguments");
    return false;
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void apteligent_set_constants(JSContext* cx, const JS::RootedObject& obj, const std::string& name, const std::map<std::string, int>& params)
#else
void apteligent_set_constants(JSContext* cx, JSObject* obj, const std::string& name, const std::map<std::string, int>& params)
#endif
{
    jsval val = sdkbox::std_map_string_int_to_jsval(cx, params);

    JS::RootedValue rv(cx);
    rv = val;
#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
    JS_SetProperty(cx, obj, name.c_str(), rv);
#else
    JS_SetProperty(cx, obj, name.c_str(), rv.address());
#endif
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void apteligent_register_constants(JSContext* cx, const JS::RootedObject& obj)
#else
void apteligent_register_constants(JSContext* cx, JSObject* obj)
#endif
{
    std::map<std::string, int> enums;
    enums.clear();
    enums.insert(std::make_pair("Silent", sdkbox::CRLoggingLevelSilent));
    enums.insert(std::make_pair("Error", sdkbox::CRLoggingLevelError));
    enums.insert(std::make_pair("Warning", sdkbox::CRLoggingLevelWarning));
    enums.insert(std::make_pair("Info", sdkbox::CRLoggingLevelInfo));
    apteligent_set_constants(cx, obj, "LoggingLevel", enums);
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginApteligentJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginApteligent", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginApteligentJS_PluginApteligent_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    apteligent_register_constants(cx, pluginObj);
}
#else
void register_all_PluginApteligentJS_helper(JSContext* cx, JSObject* global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, JS::RootedObject(cx, global), "sdkbox.PluginApteligent", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginApteligentJS_PluginApteligent_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    apteligent_register_constants(cx, pluginObj);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginApteligentJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginApteligent", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginApteligentJS_PluginApteligent_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    apteligent_register_constants(cx, pluginObj);
}
#endif
