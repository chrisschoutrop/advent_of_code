#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <cassert>

typedef int64_t i64;
typedef uint64_t u64;

std::vector<std::string> read_input(std::string inputfile)
{
    std::string line;
    std::ifstream myfile(inputfile);
    std::vector<std::string> output;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            output.push_back(line);
        }
    }
    else
    {
        std::cerr << "könnte die Datei nicht öffnen" << std::endl;
        assert(false);
    }
    return output;
}
std::array<std::string, 2> half_string(std::string input)
{
    // eine Saite in zwei Teile teilen
    std::array<std::string, 2> output;
    output[0] = input.substr(0, input.length() / 2);
    output[1] = input.substr(input.length() / 2);

    //Überprüfen, ob die Teilung richtig durchgeführt wurde
    assert(output[0].size() + output[1].size() == input.size());
    return output;
}

i64 get_priority(char character)
{
    if (character < 'a')
    {
        // Großbuchstabe
        character += 0x20;
        character -= 'a';
        character += 26;
    }
    else
    {
        // Kleinbuchstabe
        character -= 'a';
    }
    character++;

    assert(character >= 0);
    return character;
}

std::unordered_set<char> find_common_characters(std::string s1, std::string s2)
{
    // Buchstabe zur Map hinzufügen
    std::unordered_set<char> m;
    std::unordered_set<char> common;
    for (auto a : s1)
    {
        m.insert(a);
    }

    // Suche in der Map
    for (auto a : s2)
    {
        if (m.find(a) != m.end())
        {
            // Buchstabe gefunden
            common.insert(a);
        }
    }
    if (common.empty())
    {
        std::cerr << "Es gibt keine gemeinsamen Buchstaben >:(" << std::endl;
        assert(false);
    }
    return common;
}

char find_badge(std::array<std::string, 3> elves)
{
    // Finde alle Gemeinsamkeiten zwischen 1 und 2
    std::unordered_set<char> common = find_common_characters(elves[0], elves[1]);

    // Finde alle Gemeinsamkeiten zwischen (1,2) und 3
    for (auto a : elves[2])
    {
        if (common.find(a) != common.end())
        {
            // Badge gefunden
            return a;
        }
    }

    std::cerr << "Es gibt keine gemeinsamen Buchstaben >:(" << std::endl;
    assert(false);
    return -1;
}

void test()
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

int main()
{
    // Tests
    test();

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
