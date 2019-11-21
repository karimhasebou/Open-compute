# add_executable(vector_test vector_math_test.cpp)
# add_executable(matrix_math_test matrix_math_test.cpp)

# target_link_libraries(vector_test gtest_main)
# target_link_libraries(matrix_math_test gtest_main)

# set(UNIT_TEST vector_math_test)

# add_test(NAME ${UNIT_TEST} COMMAND ${UNIT_TEST})
# add_test(NAME matrix_math_test COMMAND matrix_math_test)

FILE(GLOB TEST_FILES *.cpp)
foreach(TEST_FILE ${TEST_FILES})
    string(REGEX MATCH "^(.*)\\.[^.]*$" dummy ${TEST_FILE})
    set(TEST_NAME_TMP ${CMAKE_MATCH_1})
    get_filename_component(TEST_NAME ${TEST_NAME_TMP} NAME)

    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} gtest_main)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach(TEST_FILE)


# add_custom_command(
#      TARGET ${UNIT_TEST}
#      COMMENT "Run tests"
#      POST_BUILD 
#      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#      COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$" --output-on-failures
# )