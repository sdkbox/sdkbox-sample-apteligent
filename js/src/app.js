
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);

        var label = new cc.LabelTTF("See console log", "sans", 64);
        label.setPosition(winsize.width / 2, winsize.height / 2);
        this.addChild(label);

        return true;
    },

    createTestMenu:function() {
        sdkbox.PluginApteligent.init();
        sdkbox.PluginApteligent.setListener({
            onCrashOnLastLoad: function() { cc.log("onCrashOnLastLoad"); }
        });

        sdkbox.PluginApteligent.addFilter("sensitiveURL");
        sdkbox.PluginApteligent.addFilter("additionalURL");

        // sdkbox.PluginApteligent.LoggingLevel.Silent
        // sdkbox.PluginApteligent.LoggingLevel.Error
        // sdkbox.PluginApteligent.LoggingLevel.Warning
        sdkbox.PluginApteligent.setLoggingLevel(sdkbox.PluginApteligent.LoggingLevel.Info);
        sdkbox.PluginApteligent.setAsyncBreadcrumbMode(true);
        sdkbox.PluginApteligent.updateLocation(30.67, 104.06);

        sdkbox.PluginApteligent.setUsername("MrsCritter");
        sdkbox.PluginApteligent.setValueforKey("5", "Game Level");

        sdkbox.PluginApteligent.leaveBreadcrumb("User tapped start button");


        // flow test
        cc.log("begin user flow: login");
        sdkbox.PluginApteligent.beginUserflow("login");
        var v = Math.floor(Math.random()*99) + 10;
        if (v > 50) {
            cc.log("end user flow: login");
            sdkbox.PluginApteligent.setValueforUserflow(Math.floor(Math.random()*10) + 1, "login");
            var value = sdkbox.PluginApteligent.valueForUserflow("login");
            sdkbox.PluginApteligent.setValueforUserflow(value+5, "login");
            sdkbox.PluginApteligent.endUserflow("login");
        } else if (v > 30) {
            cc.log("fail user flow: login");
            sdkbox.PluginApteligent.failUserflow("login");
        } else {
            cc.log("cancel user flow: login");
            sdkbox.PluginApteligent.cancelUserflow("login");
        }


        // logging network requests
        sdkbox.PluginApteligent.logNetworkRequest("GET", "http://www.abc123def456.com", 2.0, 1000, 100, 200);

    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

