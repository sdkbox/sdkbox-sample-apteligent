#include "PluginApteligentLua.hpp"
#include "PluginApteligent/PluginApteligent.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginApteligentLua_PluginApteligent_beginUserflow(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:beginUserflow");
            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginApteligent:beginUserflow");
            if (!ok) { break; }
            sdkbox::PluginApteligent::beginUserflow(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:beginUserflow");
            if (!ok) { break; }
            sdkbox::PluginApteligent::beginUserflow(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginApteligent:beginUserflow",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_beginUserflow'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_setLoggingLevel(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginApteligent:setLoggingLevel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_setLoggingLevel'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::setLoggingLevel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:setLoggingLevel",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_setLoggingLevel'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_setOptOutStatus(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:setOptOutStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_setOptOutStatus'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::setOptOutStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:setOptOutStatus",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_setOptOutStatus'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_setValueforKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:setValueforKey");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginApteligent:setValueforKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_setValueforKey'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::setValueforKey(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:setValueforKey",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_setValueforKey'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_setAsyncBreadcrumbMode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:setAsyncBreadcrumbMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_setAsyncBreadcrumbMode'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::setAsyncBreadcrumbMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:setAsyncBreadcrumbMode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_setAsyncBreadcrumbMode'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_endUserflow(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:endUserflow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_endUserflow'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::endUserflow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:endUserflow",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_endUserflow'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_setUsername(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:setUsername");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_setUsername'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::setUsername(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:setUsername",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_setUsername'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginApteligent::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_maxOfflineCrashReports(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_maxOfflineCrashReports'", nullptr);
            return 0;
        }
        int ret = sdkbox::PluginApteligent::maxOfflineCrashReports();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:maxOfflineCrashReports",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_maxOfflineCrashReports'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_updateLocation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        double arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:updateLocation");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginApteligent:updateLocation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_updateLocation'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::updateLocation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:updateLocation",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_updateLocation'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_valueForUserflow(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:valueForUserflow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_valueForUserflow'", nullptr);
            return 0;
        }
        int ret = sdkbox::PluginApteligent::valueForUserflow(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:valueForUserflow",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_valueForUserflow'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_logNetworkRequest(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 6)
    {
        std::string arg0;
        std::string arg1;
        long arg2;
        long arg3;
        long arg4;
        long arg5;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:logNetworkRequest");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginApteligent:logNetworkRequest");
        ok &= luaval_to_long(tolua_S, 4, &arg2, "sdkbox.PluginApteligent:logNetworkRequest");
        ok &= luaval_to_long(tolua_S, 5, &arg3, "sdkbox.PluginApteligent:logNetworkRequest");
        ok &= luaval_to_long(tolua_S, 6, &arg4, "sdkbox.PluginApteligent:logNetworkRequest");
        ok &= luaval_to_long(tolua_S, 7, &arg5, "sdkbox.PluginApteligent:logNetworkRequest");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_logNetworkRequest'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginApteligent::logNetworkRequest(arg0, arg1, arg2, arg3, arg4, arg5);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:logNetworkRequest",argc, 6);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_logNetworkRequest'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_sendAppLoadData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_sendAppLoadData'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::sendAppLoadData();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:sendAppLoadData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_sendAppLoadData'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_setMaxOfflineCrashReports(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginApteligent:setMaxOfflineCrashReports");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_setMaxOfflineCrashReports'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::setMaxOfflineCrashReports(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:setMaxOfflineCrashReports",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_setMaxOfflineCrashReports'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_getUserUUID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_getUserUUID'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginApteligent::getUserUUID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:getUserUUID",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_getUserUUID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_cancelUserflow(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:cancelUserflow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_cancelUserflow'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::cancelUserflow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:cancelUserflow",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_cancelUserflow'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_setValueforUserflow(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        std::string arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginApteligent:setValueforUserflow");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginApteligent:setValueforUserflow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_setValueforUserflow'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::setValueforUserflow(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:setValueforUserflow",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_setValueforUserflow'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_didCrashOnLastLoad(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_didCrashOnLastLoad'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginApteligent::didCrashOnLastLoad();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:didCrashOnLastLoad",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_didCrashOnLastLoad'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_addFilter(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:addFilter");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_addFilter'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::addFilter(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:addFilter",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_addFilter'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_leaveBreadcrumb(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:leaveBreadcrumb");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_leaveBreadcrumb'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::leaveBreadcrumb(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:leaveBreadcrumb",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_leaveBreadcrumb'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_getOptOutStatus(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_getOptOutStatus'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginApteligent::getOptOutStatus();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:getOptOutStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_getOptOutStatus'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginApteligentLua_PluginApteligent_failUserflow(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginApteligent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginApteligent:failUserflow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginApteligentLua_PluginApteligent_failUserflow'", nullptr);
            return 0;
        }
        sdkbox::PluginApteligent::failUserflow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginApteligent:failUserflow",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginApteligentLua_PluginApteligent_failUserflow'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginApteligentLua_PluginApteligent_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginApteligent)");
    return 0;
}

int lua_register_PluginApteligentLua_PluginApteligent(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginApteligent");
    tolua_cclass(tolua_S,"PluginApteligent","sdkbox.PluginApteligent","",nullptr);

    tolua_beginmodule(tolua_S,"PluginApteligent");
        tolua_function(tolua_S,"beginUserflow", lua_PluginApteligentLua_PluginApteligent_beginUserflow);
        tolua_function(tolua_S,"setLoggingLevel", lua_PluginApteligentLua_PluginApteligent_setLoggingLevel);
        tolua_function(tolua_S,"setOptOutStatus", lua_PluginApteligentLua_PluginApteligent_setOptOutStatus);
        tolua_function(tolua_S,"setValueforKey", lua_PluginApteligentLua_PluginApteligent_setValueforKey);
        tolua_function(tolua_S,"setAsyncBreadcrumbMode", lua_PluginApteligentLua_PluginApteligent_setAsyncBreadcrumbMode);
        tolua_function(tolua_S,"endUserflow", lua_PluginApteligentLua_PluginApteligent_endUserflow);
        tolua_function(tolua_S,"setUsername", lua_PluginApteligentLua_PluginApteligent_setUsername);
        tolua_function(tolua_S,"init", lua_PluginApteligentLua_PluginApteligent_init);
        tolua_function(tolua_S,"maxOfflineCrashReports", lua_PluginApteligentLua_PluginApteligent_maxOfflineCrashReports);
        tolua_function(tolua_S,"updateLocation", lua_PluginApteligentLua_PluginApteligent_updateLocation);
        tolua_function(tolua_S,"valueForUserflow", lua_PluginApteligentLua_PluginApteligent_valueForUserflow);
        tolua_function(tolua_S,"logNetworkRequest", lua_PluginApteligentLua_PluginApteligent_logNetworkRequest);
        tolua_function(tolua_S,"sendAppLoadData", lua_PluginApteligentLua_PluginApteligent_sendAppLoadData);
        tolua_function(tolua_S,"setMaxOfflineCrashReports", lua_PluginApteligentLua_PluginApteligent_setMaxOfflineCrashReports);
        tolua_function(tolua_S,"getUserUUID", lua_PluginApteligentLua_PluginApteligent_getUserUUID);
        tolua_function(tolua_S,"cancelUserflow", lua_PluginApteligentLua_PluginApteligent_cancelUserflow);
        tolua_function(tolua_S,"setValueforUserflow", lua_PluginApteligentLua_PluginApteligent_setValueforUserflow);
        tolua_function(tolua_S,"didCrashOnLastLoad", lua_PluginApteligentLua_PluginApteligent_didCrashOnLastLoad);
        tolua_function(tolua_S,"addFilter", lua_PluginApteligentLua_PluginApteligent_addFilter);
        tolua_function(tolua_S,"leaveBreadcrumb", lua_PluginApteligentLua_PluginApteligent_leaveBreadcrumb);
        tolua_function(tolua_S,"getOptOutStatus", lua_PluginApteligentLua_PluginApteligent_getOptOutStatus);
        tolua_function(tolua_S,"failUserflow", lua_PluginApteligentLua_PluginApteligent_failUserflow);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginApteligent).name();
    g_luaType[typeName] = "sdkbox.PluginApteligent";
    g_typeCast["PluginApteligent"] = "sdkbox.PluginApteligent";
    return 1;
}
TOLUA_API int register_all_PluginApteligentLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginApteligentLua_PluginApteligent(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

