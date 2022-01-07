function(test filename)
    project(test.${filename})
    add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/${filename}.cpp)

    target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

    target_link_libraries(${PROJECT_NAME} PRIVATE raspi)

    add_test(
            NAME ${PROJECT_NAME}
            COMMAND "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}"
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
endfunction()

test("test_26pin")
test("test_40pin")
