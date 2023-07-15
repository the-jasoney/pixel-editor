cmake_minimum_required(VERSION 3.16)

project(mbpe4 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appmbpe4
    main.cpp
    editorstate.cpp
    editorstate.h
)

qt_add_qml_module(appmbpe4
    URI mbpe4
    VERSION 1.0
    QML_FILES
        Main.qml
        Editor.qml
    SOURCES
        editorstate.cpp
        editorstate.h
)

set_target_properties(appmbpe4 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER the-jasoney.github.io
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appmbpe4
    PRIVATE Qt6::Quick
)

install(TARGETS appmbpe4
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
