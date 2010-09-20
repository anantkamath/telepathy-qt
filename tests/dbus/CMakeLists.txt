file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/_gen")

tpqt4_setup_dbus_test_environment()

if(HAVE_TEST_PYTHON)
    tpqt4_add_dbus_unit_test(AccountBasics account-basics "")
endif(HAVE_TEST_PYTHON)

if(ENABLE_TP_GLIB_TESTS)
    include_directories(${TELEPATHY_GLIB_INCLUDE_DIR}
                        ${GLIB2_INCLUDE_DIR}
                        ${DBUS_INCLUDE_DIR})

    add_definitions(-DQT_NO_KEYWORDS)

    if(HAVE_TEST_PYTHON)
        tpqt4_add_dbus_unit_test(AccountChannelDispatcher account-channel-dispatcher tp-glib-tests)
        tpqt4_add_dbus_unit_test(Client client tp-glib-tests)
        tpqt4_add_dbus_unit_test(ClientFactories client-factories tp-glib-tests)
    endif(HAVE_TEST_PYTHON)

    tpqt4_add_dbus_unit_test(AccountConnectionFactory account-connection-factory tp-glib-tests)
    tpqt4_add_dbus_unit_test(ChannelBasics chan-basics tp-glib-tests)
    tpqt4_add_dbus_unit_test(ChannelConference chan-conference tp-glib-tests)
    tpqt4_add_dbus_unit_test(ChannelGroup chan-group tp-glib-tests)
    tpqt4_add_dbus_unit_test(ConnectionManagerBasics cm-basics tp-glib-tests)
    tpqt4_add_dbus_unit_test(ConnectionBasics conn-basics tp-glib-tests)
    tpqt4_add_dbus_unit_test(ConnectionCapabilities conn-capabilities tp-glib-tests)
    tpqt4_add_dbus_unit_test(ConnectionRequests conn-requests tp-glib-tests)
    tpqt4_add_dbus_unit_test(ConnectionRoster conn-roster tp-glib-tests)
    tpqt4_add_dbus_unit_test(ConnectionRosterGroups conn-roster-groups tp-glib-tests)
    tpqt4_add_dbus_unit_test(Contacts contacts tp-glib-tests)
    tpqt4_add_dbus_unit_test(ContactsAvatar contacts-avatar tp-glib-tests)
    tpqt4_add_dbus_unit_test(ContactsCapabilities contacts-capabilities tp-glib-tests)
    tpqt4_add_dbus_unit_test(ContactsInfo contacts-info tp-glib-tests)
    tpqt4_add_dbus_unit_test(ContactsLocation contacts-location tp-glib-tests)
    tpqt4_add_dbus_unit_test(DBusProxyFactory dbus-proxy-factory tp-glib-tests)
    tpqt4_add_dbus_unit_test(Handles handles tp-glib-tests)
    tpqt4_add_dbus_unit_test(StatefulProxy stateful-proxy tp-glib-tests)
    tpqt4_add_dbus_unit_test(StreamedMediaChannel streamed-media-chan tp-glib-tests)
    tpqt4_add_dbus_unit_test(StreamedMediaChannelCall streamed-media-chan-call tp-glib-tests)
    tpqt4_add_dbus_unit_test(TextChannel text-chan tp-glib-tests)
endif(ENABLE_TP_GLIB_TESTS)

# Make check target. In case of check, output on failure and put it into a log
# This target has to stay here for catching all of the tests
add_custom_target(check ctest --output-on-failure -O test.log
                  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests)
add_dependencies(check check-local ${_telepathy_qt4_test_cases})