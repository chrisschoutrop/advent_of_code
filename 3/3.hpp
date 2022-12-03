#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <cassert>

#ifndef H_3_HPP
#define H_3_HPP

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

#endif //H_3_HPP