# Extract googletest

execute_process(
    COMMAND ${CMAKE_COMMAND} -E tar xf ${CMAKE_CURRENT_LIST_DIR}/googletest-1.8.1.zip
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

if(result)
    message(FATAL_ERROR "Extract step for googletest failed: ${result}")
endif()

# Add googletest

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(
    ${CMAKE_BINARY_DIR}/third-party/googletest-1.8.1
    ${CMAKE_BINARY_DIR}/third-party/googletest-1.8.1-build
    EXCLUDE_FROM_ALL
)