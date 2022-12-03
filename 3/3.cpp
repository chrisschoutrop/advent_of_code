#include "3.hpp"

int main()
{
    std::vector<std::string> rucksacks = read_input("3_input.txt");
    // std::vector<std::string> rucksacks = read_input("3_test.txt");

    // Teil 1
    i64 sum = 0;
    for (auto s : rucksacks)
    {
        std::array<std::string, 2> splitted = half_string(s);
        std::unordered_set<char> common = find_common_characters(splitted[0], splitted[1]);
        sum += get_priority(*common.begin());
    }
    std::cout << "sum: " << sum << std::endl;

    // Teil 2
    sum = 0;
    for (u64 i = 0; i < rucksacks.size(); i += 3)
    {
        std::array<std::string, 3> group{rucksacks[i], rucksacks[i + 1], rucksacks[i + 2]};
        char badge = find_badge(group);
        sum += get_priority(badge);
    }
    std::cout << "sum: " << sum << std::endl;
}
