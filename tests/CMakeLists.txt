add_executable(vector_test vector_math_test.cpp)
target_link_libraries(vector_test gtest_main)
set(UNIT_TEST vector_test)
add_test(NAME ${UNIT_TEST} COMMAND ${UNIT_TEST})


add_custom_command(
     TARGET ${UNIT_TEST}
     COMMENT "Run tests"
     POST_BUILD 
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
     COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$" --output-on-failures
)