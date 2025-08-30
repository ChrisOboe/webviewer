import QtQuick
import QtQuick.Window
import QtWebEngine

QtObject {
    id: root

    property Component window: Window {
        id: browserWindow
        onClosing: {
            browser.saveWindowSize(width, height)
            destroy()
        }
        visible: true
        width: browser.loadWindowSize().width
        height: browser.loadWindowSize().height
        title: webview.title 
        
        WebEngineView {
            id: webview
            anchors.fill: parent
            url: browser.url
            onIconChanged: {
                if (icon) {
                    browserWindow.flags = browserWindow.flags | Qt.WindowIcon
                }
            }
            profile: WebEngineProfile {
                storageName: browser.session
                offTheRecord: false
                httpCacheType: WebEngineProfile.DiskHttpCache
                persistentCookiesPolicy: WebEngineProfile.ForcePersistentCookies
            }
            onNewWindowRequested: function(request) {
                var newWindow = window.createObject();
                if (newWindow && newWindow.webview) {
                    request.openIn(newWindow.webview);
                }
            }
        }

        // Make WebEngineView accessible to window
        property alias webview: webview
    }

    Component.onCompleted: {
        var win = window.createObject();
    }
}