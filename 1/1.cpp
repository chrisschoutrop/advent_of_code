#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

void print_solution(const std::vector<uint64_t> &best_elves)
{
    uint64_t sum = std::accumulate(best_elves.begin(), best_elves.end(), 0ull);
    std::cout << "part 1: " << best_elves.back() << "\n";
    std::cout << "part 2: " << sum << std::endl;
}

int main()
{
    std::string line;
    std::ifstream myfile("1_input.txt");
    std::vector<uint64_t> best_elves{0, 0, 0};
    if (myfile.is_open())
    {
        uint64_t current_elf = 0;
        while (getline(myfile, line))
        {
            if (line == "")
            {
                if (current_elf > best_elves.front())
                {
                    best_elves[0] = current_elf;
                }
                std::sort(best_elves.begin(), best_elves.end());
                current_elf = 0;
            }
            else
            {
                current_elf = current_elf + std::stoull(line);
            }
        }
        myfile.close();
    }
    print_solution(best_elves);
}