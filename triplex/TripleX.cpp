#include <iostream>

bool PlayGame(int LevelDifficulty) {
    int CodeRange = LevelDifficulty * 3;

    const int Code1 = rand() % CodeRange + 1;
    const int Code2 = rand() % CodeRange + 1;
    const int Code3 = rand() % CodeRange + 1;

    const int CodeProduct = Code1 * Code2 * Code3;
    const int CodeSum = Code1 + Code2 + Code3;
    
    std::cout << "\n++ WELCOME TO LEVEL " << LevelDifficulty << " ++\n\n";
    std::cout << "+ There are three numbers in this combination.\n";
    std::cout << "+ The codes multiply to give " << CodeProduct << ".\n";
    std::cout << "+ The codes add up to " << CodeSum << ".\n\n";

    std::cout << "Enter your guess: \n";

    int Guess1, Guess2, Guess3;
    std::cin >> Guess1 >> Guess2 >> Guess3;

    int GuessProduct = Guess1 * Guess2 * Guess3;
    int GuessSum = Guess1 + Guess2 + Guess3;

    if (GuessProduct != CodeProduct || GuessSum != CodeSum) {
        std::cout << "Sorry! That's not correct.\n\n";
        return false;
    } else {
        std::cout << "That's right!\n\n";
        return true;
    }
}

void PrintIntroduction() {
    std::cout << "You left your phone in the gym locker, but you don't know which one!\n";
    std::cout << "You need to figure out the codes for each gym locker to see if your phone is inside.";
    std::cout << std::endl;
    std::cout << "The gym owner won't give you the exact combinations, but only hints -- hope you're good at factoring!\n\n";

}

int main() {
    srand(time(NULL));

    PrintIntroduction();

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) {
        bool LevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (LevelComplete) {
            LevelDifficulty++;
        } else {
            std::cout << "Try again!\n";
        }
    }
    std::cout << "Congrats! You found your phone!\n";

    return 0;
}