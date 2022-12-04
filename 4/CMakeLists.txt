add_executable(4 4.cpp)
add_executable(4_test 4_test.cpp)
add_test(4_test 4_test)

#copy input file to build directory
configure_file(4_input.txt 4_input.txt)
configure_file(4_test.txt 4_test.txt)
