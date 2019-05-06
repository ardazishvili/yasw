#-------------------------------
# DOWNLOAD AND BUILD OF GOOGLETEST
# https://github.com/google/googletest/blob/master/googletest/README.md#incorporating-into-an-existing-cmake-project
#-------------------------------

configure_file(googletest-download/CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)

if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)

if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

set(BUILD_SHARED_LIBS_BAK ${BUILD_SHARED_LIBS})
set(BUILD_SHARED_LIBS OFF)
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                    ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                    EXCLUDE_FROM_ALL)
set(BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS_BAK}) 
