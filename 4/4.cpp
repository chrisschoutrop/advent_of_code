#include "4.hpp"

int main()
{
    std::vector<std::string> input = read_input("4_input.txt");
    // std::vector<std::string> input = read_input("4_test.txt");

    i64 sum;
    // part 1
    sum = 0;
    for (auto s : input)
    {
        std::vector<i64> assignments;
        assignments = split_input(s);
        if (check_full_overlap(assignments))
        {
            sum++;
        }
    }
    std::cout << "sum: " << sum << std::endl;

    sum = 0;
    for (auto s : input)
    {
        std::vector<i64> assignments;
        assignments = split_input(s);
        if (check_some_overlap(assignments))
        {
            sum++;
        }
    }
    std::cout << "sum: " << sum << std::endl;
}
