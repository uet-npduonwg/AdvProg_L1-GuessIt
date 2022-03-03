#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

/***
    Args:

    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber()
{
    const int left = 0;
    const int right = 100;
    srand(time(NULL));
    return rand() % (right - left + 1) + left;
}

/***
    Args:

    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess()
{
    std::cout << "Enter your guess (1..100): ";
    int guess;
    std::cin >> guess;
    return guess;
}

/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber)
{
    /***
        TODO: check number with randomNumber and return the result.
              If number is higher than randomNumber, the answer is "Your number is higher."
              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
    string answer = "";
    if (number > randomNumber)
        answer = "Your number is too big\n";
    else if (number < randomNumber)
        answer = "Your number is too small\n";
    else
        answer = "You Win!\n";

    return answer;
}

/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer)
{
    // TODO: return the result after checking that player guessed right or wrong
    if (answer == "You Win!")
        return true;
    else
        return false;
}

/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued)
{
    // TODO: return result after checking player continue playing or not
    bool result = false;
    if (isContinued == 'y' || isContinued == 'Y')
        result = true;
    return result;
}

/***
    Args:

    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion()
{
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    cout << "continue playing? y/n";
    cin >> isContinued;
    return isContinued;
}

void playGuessIt()
{
    int randomNumber = generateRandomNumber();
    int number;
    string answer;

    do
    {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run()
{
    srand(time(0));
    char isContinued;
    do
    {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
