
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    math.randomseed(os.time())

    sdkbox.PluginApteligent:init()
    sdkbox.PluginApteligent:setListener(function(event)
            dump(event)
        end)

    -- -- sdkbox.PluginApteligent:sendAppLoadData()

    -- filter
    sdkbox.PluginApteligent:addFilter("sensitiveURL")
    sdkbox.PluginApteligent:addFilter("additionalURL")

    dump(sdkbox.PluginApteligent.LoggingLevel)
    sdkbox.PluginApteligent:setLoggingLevel(sdkbox.PluginApteligent.LoggingLevel.Info)
    sdkbox.PluginApteligent:setAsyncBreadcrumbMode(true)
    sdkbox.PluginApteligent:updateLocation(30.67, 104.06)

    sdkbox.PluginApteligent:setUsername("MrsCritter")
    sdkbox.PluginApteligent:setValueforKey("5", "Game Level")

    sdkbox.PluginApteligent:leaveBreadcrumb("User tapped start button")


    -- -- flow test
    sdkbox.PluginApteligent:beginUserflow("login")
    local v = math.random(120)
    if v > 50 then
        print("end user flow: login")
        sdkbox.PluginApteligent:setValueforUserflow(math.random(50), "login")
        local value = sdkbox.PluginApteligent:valueForUserflow("login")
        sdkbox.PluginApteligent:setValueforUserflow(value+5, "login")
        sdkbox.PluginApteligent:endUserflow("login")
    elseif v > 30 then
        print("fail user flow: login")
        sdkbox.PluginApteligent:failUserflow("login")
    else
        print("cancel user flow: login")
        sdkbox.PluginApteligent:cancelUserflow("login")
    end


    -- logging network requests
    sdkbox.PluginApteligent:logNetworkRequest("GET", "http://www.abc123def456.com", 2.0, 1000, 100, 200)


    cc.Label:createWithSystemFont("See console log", "sans", 64)
        :setPosition(display.cx, display.cy)
        :addTo(self)
end

return MainScene
