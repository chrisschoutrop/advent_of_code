#include "3.hpp"

int main()
{
    //Überprüfen mit gegebenen Antworten

    // half_string Test
    std::array<std::string, 2> splitted;
    splitted = half_string("vJrwpWtwJgWrhcsFMMfFFhFp");
    assert(splitted[0] == "vJrwpWtwJgWr");
    assert(splitted[1] == "hcsFMMfFFhFp");

    splitted = half_string("jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL");
    assert(splitted[0] == "jqHRNqRjqzjGDLGL");
    assert(splitted[1] == "rsFMfFZSrLrFZsSL");

    splitted = half_string("PmmdzqPrVvPwwTWBwg");
    assert(splitted[0] == "PmmdzqPrV");
    assert(splitted[1] == "vPwwTWBwg");

    // find_common_characters Test
    std::unordered_set<char> common;
    common = find_common_characters("vJrwpWtwJgWr", "hcsFMMfFFhFp");
    assert(*common.begin() == 'p');
    common = find_common_characters("jqHRNqRjqzjGDLGL", "rsFMfFZSrLrFZsSL");
    assert(*common.begin() == 'L');
    common = find_common_characters("PmmdzqPrV", "vPwwTWBwg");
    assert(*common.begin() == 'P');

    // get_priority Test
    i64 priority;
    priority = get_priority('p');
    assert(priority == 16);
    priority = get_priority('L');
    assert(priority == 38);
    priority = get_priority('P');
    assert(priority == 42);
    priority = get_priority('v');
    assert(priority == 22);
    priority = get_priority('t');
    assert(priority == 20);
    priority = get_priority('s');
    assert(priority == 19);

    // find_badge Test
    char badge;
    badge = find_badge({"vJrwpWtwJgWrhcsFMMfFFhFp", "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL", "PmmdzqPrVvPwwTWBwg"});
    assert(badge == 'r');
    badge = find_badge({"wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn", "ttgJtRGJQctTZtZT", "CrZsJsPPZsGzwwsLwLmpwMDw"});
    assert(badge == 'Z');
}