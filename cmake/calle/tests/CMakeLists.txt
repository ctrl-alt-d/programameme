function (execute_test data result)
    get_filename_component(test_name ${data} NAME_WE)
    add_test(NAME ${test_name} COMMAND sh -c "cat ${CMAKE_CURRENT_SOURCE_DIR}/${data} | ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}")

    set(input "^${result}$")
    string(REPLACE "\n" "[\n\r\t]*" expected "${input}")

    set_tests_properties(${test_name} PROPERTIES
        PASS_REGULAR_EXPRESSION "${expected}")
endfunction()

#
# Definir els tests
# ----------------------------------------------

execute_test("data1.txt" "IZQUIERDA\n")
execute_test("data2.txt" "DERECHA\nDERECHA\n")
execute_test("data34.txt" "DERECHA\nDERECHA\nDERECHA\nIZQUIERDA\n")
execute_test("data45.txt" "IZQUIERDA\nDERECHA\nIZQUIERDA\nDERECHA\nIZQUIERDA\n")
