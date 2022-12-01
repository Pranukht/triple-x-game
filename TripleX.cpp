//libraries
#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty){
    //initial statements for the game
    cout<<" \n\nYOU ARE A SECRET AGENT BREAKING INTO LEVEL " << Difficulty;
    cout<<" SECURE SERVER ROOM \nYOU NEED TO ENTER THE CORRECT CODES TO CONTINUE . . . . . \n\n";
}
bool PlayGame(int Difficulty){
    PrintIntroduction(Difficulty);

    //declaring variables
    int CodeA(rand()%Difficulty+Difficulty);
    int CodeB(rand()%Difficulty+Difficulty);
    int CodeC(rand()%Difficulty+Difficulty);
    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    //Print sum and product
    cout<<endl;
    cout<<"$ There are three numbers in the code.";
    cout<<" \n$ The codes add upto : "<< CodeSum <<" \n$ The codes multiply to give : "<< CodeProduct <<endl;
    cout<<"\nEnter your guesses seperated by a space.\n";

    //Store player guess
    int GuessA, GuessB, GuessC;
    cin>> GuessA >> GuessB >> GuessC;
    int GuessSum = GuessA+GuessB+GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;

    //Check if the player is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        cout<<"You win, you move on to the next level\n";
        return true;
    }
    else{
        cout<<"You lose, try again\n";
        return false; 
    }
}
int main (){ srand(time(NULL));// random sequence generator based on time of day

    int LevelDifficulty (1);
    const int MaxLevel (5);

    while(LevelDifficulty <= MaxLevel){
   
   
        bool bLevelComplete = PlayGame(LevelDifficulty);
        PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();
       
        //managing difficulty
        if (bLevelComplete)
        { 
          ++LevelDifficulty;  
        }
    }
    cout<<"CONGRATULATIONS YOU ARE A MASTER HACKER ;)";
    return 0;
}
