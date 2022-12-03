add_executable(2 2.cpp)
add_executable(2_branchless 2_branchless.cpp)

#copy input file to build directory
configure_file(2_input.txt 2_input.txt)
configure_file(2_test.txt 2_test.txt)
