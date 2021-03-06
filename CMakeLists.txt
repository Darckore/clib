cmake_minimum_required(VERSION 3.18)

set(OPT_PCH_NAME "pch.h")
set(OPT_STD "cxx_std_20")
set(OPT_UTILS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/_cmake")
set(OPT_DATA_DIR "data")
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

if (NOT DEFINED BUILT_FROM_ROOT)
  set(BUILT_FROM_ROOT OFF)
  if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    set(BUILT_FROM_ROOT ON)
  endif()
endif()

set(OPT_FMT_DIR "${CMAKE_SOURCE_DIR}/../_third_party/fmtlib" CACHE PATH "Fmtlib repo will be cloned here")
set(OPT_GTEST_DIR "${CMAKE_SOURCE_DIR}/../_third_party/gtest" CACHE PATH "Gtest repo will be cloned here")
option(OPT_TESTS "Whether or not to build tests" ${BUILT_FROM_ROOT})
option(OPT_APP "Whether or not to build the application" ${BUILT_FROM_ROOT})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(THIRD_PARTY_DIR third_party)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER cmake)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

set(APP_TARGET app)
set(LIB0_TARGET clib) 
set(TESTS_TARGET tests) 


project(clib_root CXX)

set(TARGET_NAME ${LIB0_TARGET})
add_subdirectory("${TARGET_NAME}")

if(OPT_APP)
  set(TARGET_NAME ${APP_TARGET})
  add_subdirectory("${TARGET_NAME}")
  target_link_libraries(${TARGET_NAME} ${LIB0_TARGET})
endif()

if(OPT_TESTS AND NOT TARGET gtest)
  add_subdirectory("${OPT_UTILS_DIR}/${THIRD_PARTY_DIR}/gtest" gtest)
endif()

if(TARGET gtest)
  enable_testing()
  set(TARGET_NAME ${TESTS_TARGET})
  add_subdirectory("${TARGET_NAME}")
  target_link_libraries(${TARGET_NAME} ${LIB0_TARGET})
  
  if(OPT_APP)
    add_dependencies(${TARGET_NAME} ${APP_TARGET})
  endif()
  
  set_target_properties(gtest PROPERTIES FOLDER ${THIRD_PARTY_DIR}/gtest)
  set_target_properties(gmock PROPERTIES FOLDER ${THIRD_PARTY_DIR}/gtest)
  set_target_properties(gtest_main PROPERTIES FOLDER ${THIRD_PARTY_DIR}/gtest)
  set_target_properties(gmock_main PROPERTIES FOLDER ${THIRD_PARTY_DIR}/gtest)
  
  target_compile_definitions(${TARGET_NAME} PUBLIC GTEST_BUILT)
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
endif()

if(NOT TARGET fmt)
  add_subdirectory("${OPT_UTILS_DIR}/${THIRD_PARTY_DIR}/fmt" fmt)
endif()

if(TARGET fmt)
  target_link_libraries(${LIB0_TARGET} fmt)
  set_target_properties(fmt PROPERTIES FOLDER ${THIRD_PARTY_DIR}/fmt)
endif()

if(BUILT_FROM_ROOT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/_bin" CACHE PATH "Install dir" FORCE)
endif()