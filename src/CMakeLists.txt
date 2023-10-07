cmake_minimum_required(VERSION 3.10)

project(webviewer)
find_package(Qt5 COMPONENTS Core Qml Quick WebEngine REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QML_RESOURCE_FILES "qml.qrc")
qt5_add_resources(QML_RESOURCE_SRCS ${QML_RESOURCE_FILES})
add_executable(webviewer
	main.cpp
	browser.cpp
    browser.h
	${QML_RESOURCE_SRCS})

target_link_libraries(webviewer PRIVATE Qt5::Core Qt5::Qml Qt5::Quick Qt5::WebEngine)

install(TARGETS webviewer DESTINATION bin)
