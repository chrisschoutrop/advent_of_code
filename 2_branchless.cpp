#include <bitset>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// imagine needing if statements
char check_scuffed_win(char outcome, char opponent)
{
    return (!(outcome ^ 'X')) * ((!(opponent ^ 'A')) * 'Z' + (!(opponent ^ 'B')) * 'X' + (!(opponent ^ 'C')) * 'Y') + (!(outcome ^ 'Y')) * ((!(opponent ^ 'A')) * 'X' + (!(opponent ^ 'B')) * 'Y' + (!(opponent ^ 'C')) * 'Z') + (!(outcome ^ 'Z')) * ((!(opponent ^ 'A')) * 'Y' + (!(opponent ^ 'B')) * 'Z' + (!(opponent ^ 'C')) * 'X');
}
int64_t other_points(int64_t me)
{
    return (!(me ^ 'X')) * 1 + (!(me ^ 'Y')) * 2 + (!(me ^ 'Z')) * 3;
}

int64_t check_win(int64_t me, int64_t opponent)
{
    return (!(me ^ 'X')) * ((!(opponent ^ 'A')) * 3 + (!(opponent ^ 'B')) * 0 + (!(opponent ^ 'C')) * 6) + (!(me ^ 'Y')) * ((!(opponent ^ 'A')) * 6 + (!(opponent ^ 'B')) * 3 + (!(opponent ^ 'C')) * 0) + (!(me ^ 'Z')) * ((!(opponent ^ 'A')) * 0 + (!(opponent ^ 'B')) * 6 + (!(opponent ^ 'C')) * 3);
}

int main()
{
    std::string line;
    std::ifstream myfile("2_input.txt");
    int64_t sum = 0;
    int64_t scuffed_sum = 0;
    while (getline(myfile, line))
    {
        std::istringstream iss(line);
        char me;
        char me_move;
        char opponent;
        iss >> opponent >> me;
        int64_t points = check_win(me, opponent) + other_points(me);
        sum += points;

        // Scuffed part
        me_move = check_scuffed_win(me, opponent);
        int64_t scuffed_points = check_win(me_move, opponent) + other_points(me_move);
        scuffed_sum += scuffed_points;
    }
    std::cout << "sum: " << sum << std::endl;
    std::cout << "scuffed_sum: " << scuffed_sum << std::endl;
}