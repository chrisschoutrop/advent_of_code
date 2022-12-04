#include "4.hpp"

void split_input_test()
{
    // Input parsing test
    std::vector<i64> splitted;
    splitted = split_input("1 2 3 4");
    assert(splitted[0] == 1);
    assert(splitted[1] == 2);
    assert(splitted[2] == 3);
    assert(splitted[3] == 4);

    splitted = split_input("5 6 9 10");
    assert(splitted[0] == 5);
    assert(splitted[1] == 6);
    assert(splitted[2] == 9);
    assert(splitted[3] == 10);

    splitted = split_input("2 54 83 83");
    assert(splitted[0] == 2);
    assert(splitted[1] == 54);
    assert(splitted[2] == 83);
    assert(splitted[3] == 83);
}

void check_full_overlap_test()
{
    assert(check_full_overlap({98, 99, 5, 97}) == false);
    assert(check_full_overlap({1, 2, 3, 4}) == false);
    assert(check_full_overlap({2, 4, 6, 8}) == false);
    assert(check_full_overlap({2, 3, 4, 5}) == false);
    assert(check_full_overlap({5, 7, 7, 9}) == false);
    assert(check_full_overlap({2, 8, 3, 7}) == true);
    assert(check_full_overlap({6, 6, 3, 7}) == true);
    assert(check_full_overlap({2, 6, 4, 8}) == false);
}

void check_some_overlap_test()
{
    assert(check_some_overlap({98, 99, 5, 97}) == false);
    assert(check_some_overlap({1, 2, 3, 4}) == false);
    assert(check_some_overlap({2, 4, 6, 8}) == false);
    assert(check_some_overlap({2, 3, 4, 5}) == false);
    assert(check_some_overlap({5, 7, 7, 9}) == true);
    assert(check_some_overlap({2, 8, 3, 7}) == true);
    assert(check_some_overlap({6, 6, 3, 7}) == true);
    assert(check_some_overlap({2, 6, 4, 8}) == true);
}

int main()
{
    split_input_test();
    check_full_overlap_test();
    check_some_overlap_test();
}
