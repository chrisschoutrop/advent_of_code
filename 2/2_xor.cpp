#include <bitset>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


char check_scuffed_win(char outcome, char opponent)
{
    /*
    X   =   lose
    Y   =   draw
    Z   =   win
    //  A     rock
    //  B     paper
    //  C     schaar
    */
    if (outcome == 'X')
    {
        if (opponent == 'A')
        {
            // opponent: rock, outcome lose, me schaar
            return 'Z';
        }
        else if (opponent == 'B')
        {
            // opponent: paper, outcome lose, me rock
            return 'X';
        }
        else if (opponent == 'C')
        {
            // opponent: schaar, outcome lose, me paper
            return 'Y';
        }
    }
    else if (outcome == 'Y')
    {
        if (opponent == 'A')
        {
            // opponent: rock, outcome draw, me rock
            return 'X';
        }
        else if (opponent == 'B')
        {
            // opponent: paper, outcome draw, me paper
            return 'Y';
        }
        else if (opponent == 'C')
        {
            // opponent: schaar, outcome draw, me schaar
            return 'Z';
        }
    }
    else if (outcome == 'Z')
    {
        if (opponent == 'A')
        {
            // opponent: rock, outcome win, me paper
            return 'Y';
        }
        else if (opponent == 'B')
        {
            // opponent: paper, outcome win, me schaar
            return 'Z';
        }
        else if (opponent == 'C')
        {
            // opponent: schaar, outcome win, me rock
            return 'X';
        }
    }
    return 'T';
}

char check_scuffed_win_xor(char outcome, char opponent)
{
    /*
    001 lose
    010 draw
    100 win
    */
   
}


int64_t other_points_xor(int64_t me)
{
    return ((me & 0b100) >> 2) * 3 + (((me & 0b100) ^ 0b100) >> 2) * me;
}

int64_t letter_value(char letter)
{
    switch (letter)
    {
    case 'A':
        return 0b001;
    case 'B':
        return 0b010;
    case 'C':
        return 0b100;
    case 'X':
        return 0b001;
    case 'Y':
        return 0b010;
    case 'Z':
        return 0b100;
    }
    return 0;
}

int64_t check_win_xor(int64_t me, int64_t opponent)
{
    if (!(opponent ^ me))
    {
        return 3;
    }

    int64_t game = opponent ^ me;
    switch (game)
    {
    case 0b011:
        return ((me & 0b010) >> 1) * 6;
    case 0b101:
        return (me & 0b001) * 6;
    case 0b110:
        return ((me & 0b100) >> 2) * 6;
    }

    return 0;
}

int main()
{

    std::string line;
    std::ifstream myfile("2_test.txt");
    int64_t sum_xor = 0;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::istringstream iss(line);
            char me;
            char opponent;
            iss >> opponent >> me;

            sum_xor += check_win_xor(letter_value(me), letter_value(opponent)) + other_points_xor(letter_value(me));

            // Scuffed part
            me = check_scuffed_win(me, opponent);
            std::cout<<std::bitset<8>(me)<<std::endl;
            me = check_scuffed_win_xor(me,opponent);
            std::cout<<std::bitset<8>(me)<<std::endl;
        }
    }
    std::cout << "sum_xor: " << sum_xor << std::endl;
}