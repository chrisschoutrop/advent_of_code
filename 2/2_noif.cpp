#include <bitset>
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
int64_t check_win(char me, char opponent)
{
    // return 0 if lost
    // return 3 if draw
    // return 6 if win
    //  A,X     rock
    //  B,Y     paper
    //  C,Z     schaar
    if (me == 'X')
    {
        // rock
        if (opponent == 'A')
        {
            return 3;
        }
        else if (opponent == 'B')
        {
            return 0;
        }
        else if (opponent == 'C')
        {
            return 6;
        }
    }
    else if (me == 'Y')
    {
        // paper
        if (opponent == 'A')
        {
            return 6;
        }
        else if (opponent == 'B')
        {
            return 3;
        }
        else if (opponent == 'C')
        {
            return 0;
        }
    }
    else if (me == 'Z')
    {
        // schaar
        if (opponent == 'A')
        {
            return 0;
        }
        else if (opponent == 'B')
        {
            return 6;
        }
        else if (opponent == 'C')
        {
            return 3;
        }
    }
    return -1410065407;
}

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

    rock    001
    paper   010
    schaar  100

    paper^rock      011 me wins ->100
    rock^paper      011         ->001
    rock^schaar     101 me wins ->100
    schaar^rock     101         ->001
    schaar^paper    110 me wins ->100
    paper^schaar    110         ->001

    outcome opponent    me
    001     001         
    010     001         001
    100     001

    001     010
    010     010         010
    100     010

    001     100
    010     100         100
    100     100
    */
   std::cout <<"outcome: "<< std::bitset<8>(outcome) << std::endl;
   std::cout <<"outcome&0b010: "<< std::bitset<8>(outcome&0b010) << std::endl;
   std::cout <<"opponent: "<< std::bitset<8>(opponent) << std::endl;
   if(outcome&0b010){
    //Draw
        return opponent;
   }

    
    return 0;  
}

int64_t other_points(char me)
{
    if (me == 'X')
    {
        // rock
        return 1;
    }
    else if (me == 'Y')
    {
        // paper
        return 2;
    }
    else if (me == 'Z')
    {
        // schaar
        return 3;
    }
    return -1410065407;
}

int64_t other_points_xor(int64_t me)
{
    // rock    001
    // paper   010
    // schaar  100
    //std::cout <<"me: "<< std::bitset<8>(me) << std::endl;
    //std::cout <<"((me&0b100)>>2): "<< std::bitset<8>((me&0b100)>>2) << std::endl;
    //std::cout <<"((me&0b100)^0b100): "<< std::bitset<8>(((me&0b100)^0b100)) << std::endl;
    // if(me&0b100){
    //     return 3;
    // }else{
    //     return me;
    // }
    

    return ((me&0b100)>>2)*3+(((me&0b100)^0b100)>>2)*me;


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

int64_t check_win_xor(int64_t me, int64_t opponent){
    //std::cout <<"opponent ^ me: "<< std::bitset<8>(opponent ^ me) << std::endl;
    if(!(opponent ^ me)){
        return 3;
    }
    
    /*
    rock    001
    paper   010
    schaar  100

    paper^rock      011 me wins
    rock^paper      011 
    rock^schaar     101 me wins
    schaar^rock     101
    schaar^paper    110 me wins
    paper^schaar    110
    */
    //me|=0b1000; 1XXXX
    int64_t game=opponent^me;
    //std::cout <<"game: "<< std::bitset<8>(game) << std::endl;
    //std::cout <<"opponent: "<< std::bitset<8>(opponent) << std::endl;
    //std::cout <<"me: "<< std::bitset<8>(me) << std::endl;
    //std::cout <<"((me&0b100)>>2): "<< std::bitset<8>(((me&0b100)>>2)) << std::endl;
    switch (game)
    {
    case 0b011:
        return ((me&0b010)>>1)*6;
    case 0b101:
        return (me&0b001)*6;
    case 0b110:
        return ((me&0b100)>>2)*6;
    }

    return 0;

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
    std::ifstream myfile("2_test.txt");
    int64_t sum = 0;
    int64_t sum_xor = 0;
    int64_t scuffed_sum = 0;
    int64_t scuffed_sum_xor = 0;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::istringstream iss(line);
            char me;
            char me_move;
            char opponent;
            iss >> opponent >> me;
            int64_t points = check_win(me, opponent) + other_points(me);
            sum += points;

            points= check_win_xor(letter_value(me), letter_value(opponent)) + other_points_xor(letter_value(me));
            sum_xor+=points;

            // Scuffed part
            me_move = check_scuffed_win(me, opponent);
            int64_t scuffed_points = check_win(me_move, opponent) + other_points(me_move);
            scuffed_sum += scuffed_points;

            // Scuffed part
            me_move = check_scuffed_win_xor(letter_value(me), letter_value(opponent));
            std::cout <<"me_move: "<< std::bitset<8>(me_move) << std::endl;
            int64_t scuffed_points_xor = check_win_xor(letter_value(me_move), letter_value(opponent)) + other_points_xor(letter_value(me_move));
            scuffed_sum_xor += scuffed_points_xor;            
        }
    }
    std::cout << "sum: " << sum << std::endl;
    std::cout << "sum_xor: " << sum_xor << std::endl;
    std::cout << "scuffed_sum: " << scuffed_sum << std::endl;
    std::cout << "scuffed_sum_xor: " << scuffed_sum_xor << std::endl;

    // // Rock   map to 001
    // int8_t A = 'A' - 0x40;
    // // Paper  map to 010
    // int8_t B = ('B' - 0x40);
    // // Schaar map to 100
    // int8_t C = ('C' - 0x40);

    // // Rock   map to 001
    // int8_t X = 'X' - 0x40;
    // // Paper  map to 010
    // int8_t Y = 'Y' - 0x40;
    // // Schaar map to 100
    // int8_t Z = 'Z' - 0x40;

    // std::cout << std::bitset<8>(letter_value('A')) << std::endl;
    // std::cout << std::bitset<8>(letter_value('B')) << std::endl;
    // std::cout << std::bitset<8>(letter_value('C')) << std::endl;
    // std::cout << std::bitset<8>(letter_value('X')) << std::endl;
    // std::cout << std::bitset<8>(letter_value('Y')) << std::endl;
    // std::cout << std::bitset<8>(letter_value('Z')) << std::endl;
}