import QtQuick 2.15
import QtQuick.Window 2.0
import QtWebEngine 1.1

Window {
    visible: true
    width: 400
    height: 300
    title: webview.title 
	WebEngineView {
		id: webview
		anchors.fill: parent
		url: browser.url
		profile: WebEngineProfile {
			storageName: browser.session
			offTheRecord: false
		}
	}
}

