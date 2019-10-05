cmake_minimum_required(VERSION 3.5)
project(fakedb VERSION 1.0.0 LANGUAGES CXX)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

add_library(fakedb
    src/fakedb.cpp
)

add_library(FakeDB::fakedb ALIAS fakedb)

target_include_directories(fakedb
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(fakedb PRIVATE cxx_auto_type)
target_compile_options(fakedb PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)


include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/FakeDB)

install(TARGETS fakedb
    EXPORT fakedb-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

set_target_properties(fakedb PROPERTIES EXPORT_NAME FakeDB)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT fakedb-targets
  FILE
    FakeDBTargets.cmake
  NAMESPACE
    FakeDB::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/FakeDBConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/FakeDBConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/FakeDBConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/FakeDBConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/FakeDBConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

export(EXPORT fakedb-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/FakeDBTargets.cmake NAMESPACE FakeDB::)

export(PACKAGE FakeDB)