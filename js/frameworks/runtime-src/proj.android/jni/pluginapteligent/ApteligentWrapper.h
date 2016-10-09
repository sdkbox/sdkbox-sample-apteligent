/****************************************************************************

 Copyright (c) 2014-2015 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_APTELIGENT_WRAPPER_H_
#define _PLUGIN_APTELIGENT_WRAPPER_H_

#include "PluginApteligent.h"
#include "json98.h"

#define TAG "Apteligent"
#define VERSION "v5.5.1"
#define APTELIGENT_CATEGORY_ANDROID "v5.5.5"

namespace sdkbox {

class ApteligentWrapper {

public:
    static ApteligentWrapper* getInstance();

    virtual bool init() = 0;
    virtual void setListener(ApteligentListener* listener) = 0;
    virtual ApteligentListener* getListener() = 0;
    virtual void removeListener() = 0;

    virtual void addFilter(const std::string& filter) = 0;
    virtual void leaveBreadcrumb(const std::string& breadcrumb) = 0;
    virtual void setAsyncBreadcrumbMode(bool writeAsync) = 0;
    virtual bool logNetworkRequest(const std::string& method, const std::string& urlString,
                                                long latency, long bytesRead, long bytesSent, long responseCode) = 0;
    virtual void setOptOutStatus(bool status) = 0;
    virtual bool getOptOutStatus() = 0;
    virtual void setMaxOfflineCrashReports(int max) = 0;
    virtual int maxOfflineCrashReports() = 0;
    virtual std::string getUserUUID() = 0;
    virtual void setUsername(const std::string& username) = 0;
    virtual void setValueforKey(const std::string& value, const std::string& key) = 0;
    virtual bool didCrashOnLastLoad() = 0;
    virtual void beginUserflow(const std::string& name) = 0;
    virtual void beginUserflow(const std::string& name, int value) = 0;
    virtual void cancelUserflow(const std::string& name) = 0;
    virtual void endUserflow(const std::string& name) = 0;
    virtual void failUserflow(const std::string& name) = 0;
    virtual int valueForUserflow(const std::string& name) = 0;
    virtual void setValueforUserflow(int value, const std::string& name) = 0;
    virtual void sendAppLoadData() = 0;
    virtual void setLoggingLevel(int loggingLevel) = 0;
    virtual void updateLocation(double latitude, double longitude) = 0;
};

class ApteligentWrapperDisabled : public ApteligentWrapper {
public:
    bool init() { return false; }
    void setListener(ApteligentListener* listener) {}
    ApteligentListener* getListener() { return NULL; }
    void removeListener() {}

    void addFilter(const std::string& filter) {}
    void leaveBreadcrumb(const std::string& breadcrumb) {}
    void setAsyncBreadcrumbMode(bool writeAsync) {}
    bool logNetworkRequest(const std::string& method, const std::string& urlString,
                            long latency, long bytesRead, long bytesSent, long responseCode) { return false; }
    void setOptOutStatus(bool status) {}
    bool getOptOutStatus() { return false; }
    void setMaxOfflineCrashReports(int max) {}
    int maxOfflineCrashReports() { return 0; }
    std::string getUserUUID() { return ""; }
    void setUsername(const std::string& username) {}
    void setValueforKey(const std::string& value, const std::string& key) {}
    bool didCrashOnLastLoad() { return false; }
    void beginUserflow(const std::string& name) {}
    void beginUserflow(const std::string& name, int value) {}
    void cancelUserflow(const std::string& name) {}
    void endUserflow(const std::string& name) {}
    void failUserflow(const std::string& name) {}
    int valueForUserflow(const std::string& name) { return 0; }
    void setValueforUserflow(int value, const std::string& name) {}
    void sendAppLoadData() {}
    void setLoggingLevel(int loggingLevel) {}
    void updateLocation(double latitude, double longitude) {}
};

class ApteligentWrapperEnabled : public ApteligentWrapper {
public:
    ApteligentWrapperEnabled();
    bool init();
    bool __init(bool asAdUnit);
    void setListener(ApteligentListener* listener);
    ApteligentListener* getListener();
    void removeListener();

    void addFilter(const std::string& filter);
    void leaveBreadcrumb(const std::string& breadcrumb);
    void setAsyncBreadcrumbMode(bool writeAsync);
    bool logNetworkRequest(const std::string& method, const std::string& urlString,
                                                long latency, long bytesRead, long bytesSent, long responseCode);
    void setOptOutStatus(bool status);
    bool getOptOutStatus();
    void setMaxOfflineCrashReports(int max);
    int maxOfflineCrashReports();
    std::string getUserUUID();
    void setUsername(const std::string& username);
    void setValueforKey(const std::string& value, const std::string& key);
    bool didCrashOnLastLoad();
    void beginUserflow(const std::string& name);
    void beginUserflow(const std::string& name, int value);
    void cancelUserflow(const std::string& name);
    void endUserflow(const std::string& name);
    void failUserflow(const std::string& name);
    int valueForUserflow(const std::string& name);
    void setValueforUserflow(int value, const std::string& name);
    void sendAppLoadData();
    void setLoggingLevel(int loggingLevel);
    void updateLocation(double latitude, double longitude);
protected:
    bool nativeInit(const Json& config, bool asAdUnit);
    std::string nativeSDKVersion();

private:
    ApteligentListener* _listener;
};

}

#endif
