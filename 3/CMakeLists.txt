add_executable(3 3.cpp)
add_executable(3_test 3_test.cpp)
add_test(3_test 3_test)

#copy input file to build directory
configure_file(3_input.txt 3_input.txt)
configure_file(3_test.txt 3_test.txt)
