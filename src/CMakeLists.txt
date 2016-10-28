set(kanarie_SRCS
    main.cpp
    kanarie.cpp
    kanarieview.cpp
)

kconfig_add_kcfg_files(kanarie_SRCS KanarieSettings.kcfgc)
ki18n_wrap_ui(kanarie_SRCS kanarieViewBase.ui settingsBase.ui)

add_executable(kanarie ${kanarie_SRCS})

target_link_libraries(kanarie
    Qt5::Widgets
    KF5::CoreAddons
    KF5::I18n
    KF5::XmlGui
    KF5::ConfigWidgets
)

install(TARGETS kanarie ${INSTALL_TARGETS_DEFAULT_ARGS})
install(PROGRAMS kanarie.desktop  DESTINATION ${XDG_APPS_INSTALL_DIR})
install(FILES kanarieui.rc DESTINATION ${KXMLGUI_INSTALL_DIR}/kanarie)
