#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// if statements go brrr
/*
    TODO: Clean, can do something fancy like overload ^
    make classes for each of the 3 moves, have the compiler 
    figure it out
    schaar^paper    -> returns +6
    schaar^rock     -> returns +3
    schaar^schaar   -> returns +0
    paper^paper     -> returns +3
    paper^rock      -> returns +6
    paper^schaar    -> returns +0
    rock^paper      -> returns +0
    rock^rock       -> returns +3
    rock^schaar     -> returns +6        
    
*/
int64_t check_win(std::string me, std::string opponent)
{
    // return 0 if lost
    // return 3 if draw
    // return 6 if win
    //  A,X     rock
    //  B,Y     paper
    //  C,Z     schaar
    if (me == "X")
    {
        // rock
        if (opponent == "A")
        {
            return 3;
        }
        else if (opponent == "B")
        {
            return 0;
        }
        else if (opponent == "C")
        {
            return 6;
        }
    }
    else if (me == "Y")
    {
        // paper
        if (opponent == "A")
        {
            return 6;
        }
        else if (opponent == "B")
        {
            return 3;
        }
        else if (opponent == "C")
        {
            return 0;
        }
    }
    else if (me == "Z")
    {
        // schaar
        if (opponent == "A")
        {
            return 0;
        }
        else if (opponent == "B")
        {
            return 6;
        }
        else if (opponent == "C")
        {
            return 3;
        }
    }
    return -1410065407;
}

std::string check_scuffed_win(std::string outcome, std::string opponent)
{
    /*
    X   =   lose
    Y   =   draw
    Z   =   win
    //  A     rock
    //  B     paper
    //  C     schaar
    */
    if (outcome == "X")
    {
        if (opponent == "A")
        {
            // opponent: rock, outcome lose, me schaar
            return "Z";
        }
        else if (opponent == "B")
        {
            // opponent: paper, outcome lose, me rock
            return "X";
        }
        else if (opponent == "C")
        {
            // opponent: schaar, outcome lose, me paper
            return "Y";
        }
    }
    else if (outcome == "Y")
    {
        if (opponent == "A")
        {
            // opponent: rock, outcome draw, me rock
            return "X";
        }
        else if (opponent == "B")
        {
            // opponent: paper, outcome draw, me paper
            return "Y";
        }
        else if (opponent == "C")
        {
            // opponent: schaar, outcome draw, me schaar
            return "Z";
        }
    }
    else if (outcome == "Z")
    {
        if (opponent == "A")
        {
            // opponent: rock, outcome win, me paper
            return "Y";
        }
        else if (opponent == "B")
        {
            // opponent: paper, outcome win, me schaar
            return "Z";
        }
        else if (opponent == "C")
        {
            // opponent: schaar, outcome win, me rock
            return "X";
        }
    }
    return "T";
}

int64_t other_points(std::string me)
{
    if (me == "X")
    {
        // rock
        return 1;
    }
    else if (me == "Y")
    {
        // paper
        return 2;
    }
    else if (me == "Z")
    {
        // schaar
        return 3;
    }
    return -1410065407;
}

int main()
{
    /*
    col 0: opponent move
    col 1: response move
    elke ronde winnen is sus
    winner van toernooi heeft meeste punten
    score:
    rock    1 pt
    paper   2 pt
    schaar  3 pt
    +0 als lost
    +3 als draw
    +6 als win

    A,X     rock
    B,Y     paper
    C,Z     schaar
    */
    std::string line;
    std::ifstream myfile("2_input.txt");
    size_t pos = 0;
    std::string token;
    int64_t sum = 0;
    int64_t scuffed_sum = 0;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::istringstream iss(line);
            std::string me;
            std::string opponent;
            iss >> opponent >> me;
            int64_t points = check_win(me, opponent) + other_points(me);
            sum += points;

            // Scuffed part
            me = check_scuffed_win(me, opponent);
            int64_t scuffed_points = check_win(me, opponent) + other_points(me);

            scuffed_sum += scuffed_points;
        }
    }
    std::cout << "sum: " << sum << std::endl;
    std::cout << "scuffed_sum: " << scuffed_sum << std::endl;
}