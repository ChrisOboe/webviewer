cmake_minimum_required(VERSION 3.16)

project(webviewer)
find_package(Qt6 COMPONENTS Core Qml Quick WebEngineQuick REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QML_RESOURCE_FILES "qml.qrc")
qt_add_resources(QML_RESOURCE_SRCS ${QML_RESOURCE_FILES})
add_executable(webviewer
	main.cpp
	browser.cpp
    browser.h
	${QML_RESOURCE_SRCS})

target_link_libraries(webviewer PRIVATE Qt6::Core Qt6::Qml Qt6::Quick Qt6::WebEngineQuick)

install(TARGETS webviewer DESTINATION bin)
