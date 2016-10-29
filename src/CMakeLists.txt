set(kanarie_SRCS
    main.cpp
    kanarie.cpp
    kanarieview.cpp
    
    # TODO: add_subdirectory로 분할할 것 
    ui/widget/postarea.cpp
    
    ui/settings/accounts.cpp
)

kconfig_add_kcfg_files(kanarie_SRCS KanarieSettings.kcfgc)
ki18n_wrap_ui(kanarie_SRCS 
    kanarieViewBase.ui 
    
    # TODO: k18n_wrap_ui는 ui 디렉토리 안에서만 사용할 것
    # TODO: UI 관련 파일은 전부 ui 디렉토리로 옮길 것
    ui/widget/postarea.ui
    
    ui/settings/accounts.ui
)

add_executable(kanarie ${kanarie_SRCS})

target_link_libraries(kanarie
    Qt5::Widgets
    KF5::CoreAddons
    KF5::I18n
    KF5::XmlGui
    KF5::ConfigWidgets
    # TODO: Phonon 추가해야 하지 않아?
)

install(TARGETS kanarie ${INSTALL_TARGETS_DEFAULT_ARGS})
install(PROGRAMS kanarie.desktop  DESTINATION ${XDG_APPS_INSTALL_DIR})
install(FILES kanarieui.rc DESTINATION ${KXMLGUI_INSTALL_DIR}/kanarie)
