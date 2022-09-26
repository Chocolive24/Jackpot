#include <iostream>
//#include <stdlib.h>

class Dice
{
public:
    int throwDice(int min, int max) // throw the dices and return a number between 1 and 6
    {
        return min + rand() % (max - min) + 1;
    }
};

int main()
{
    srand(time(NULL)); // allows you to generate a random number over time with the rand function 

    Dice diceA, diceB;

    
    const int startMoney = 5;
    int playerMoney = startMoney;
    int score = 7;

    std::cout << "In this game you throw 2 dices. \n";
	std::cout << "If the sum of the dices is higher than 7 your money is doubled \n";
    std::cout << "If not, you loose everything. \n";

    while(true)
    {
        std::cout << "You have " << playerMoney << " CHF. Tap 1 to throw the dices or 2 to quite the game \n";
        int user_answer;
        std::cin >> user_answer;
        //system("cls");
        if (user_answer == 1) // the user starts the game
        {
            int throw1 = diceA.throwDice(1, 6);
            int throw2 = diceB.throwDice(1, 6);

            std::cout << "Dice 1 : " << throw1 << '\n' << "Dice 2 : " << throw2 << '\n' << "Sum of dices : " << throw1 + throw2 << '\n';
            
            if (throw1 + throw2 > score) // user wins because the sum of the dices is higher than the score
            {
                std::cout << "You Won, the sum is higher than " << score << '\n';
                playerMoney = playerMoney * 2; // double the money of the player 
                score = throw1 + throw2; // the new score to beat is the sum of the dices 
                std::cout << "You can continue but this time the sum of the dices has to be higher than " << score << '\n';
                
            }
            else // user wins because the sum of the dices is lower than the score
            {
                std::cout << "You lost... the sum is not higher than " << score << '\n';
                playerMoney = 0;
                std::cout << "You have " << playerMoney << " CHF. Restart the program to try again. \n";
                break;
            }
        }
        else // the user ends the game
        {
            break;
        }
    }

    return 0;
}
    





