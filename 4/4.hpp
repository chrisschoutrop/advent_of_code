#ifndef H_4_HPP
#define H_4_HPP

#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <cassert>

typedef int64_t i64;

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

std::vector<i64> split_input(const std::string &s)
{
    std::vector<i64> result(4);

    std::istringstream iss(s);
    std::string r0, r1, r2, r3;
    iss >> r0 >> r1 >> r2 >> r3;

    result[0] = std::stoll(r0);
    result[1] = std::stoll(r1);
    result[2] = std::stoll(r2);
    result[3] = std::stoll(r3);

    return result;
}

bool check_full_overlap(std::vector<i64> input)
{
    // set 2 contained in set 1
    if (input[0] <= input[2] && input[1] >= input[3])
    {
        return true;
    }

    // set 1 contained in set 2
    if (input[2] <= input[0] && input[3] >= input[1])
    {
        return true;
    }

    return false;
}

bool check_some_overlap(std::vector<i64> input)
{
    if (check_full_overlap(input))
    {
        return true;
    }

    if (input[0] <= input[2] && input[3] >= input[1] && input[2] <= input[1])
    {
        return true;
    }

    if (input[2] <= input[0] && input[1] >= input[3] && input[3] <= input[1] && input[3] >= input[0])
    {
        return true;
    }

    return false;
}

#endif // H_4_HPP
