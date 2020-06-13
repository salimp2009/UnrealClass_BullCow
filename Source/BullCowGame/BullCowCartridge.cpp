// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
    //PrintLine(TEXT("Hidden Word is: %s"), *HiddenWord);  
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);

     }
    
  
   // Pseu Code for Guess;
   // IsValid() && IsCorrect
   // if true; WinMsg() && GameOver() || RePlay() (replay; resetlives(), Guess()
   // DeductLives()
   // CheckLives()
   // ShowLives()
   // if(Lives()) ContinueGame() ; Gues()
   // if no; ShowHiddenWord()
   // AskPlayAgain(); ResetHidden(); ResetLives(); Guess()  || GameOver()
   // Replay()
}

void UBullCowCartridge::SetupGame()
{
    // welcome message
    PrintLine(TEXT("Welcome to BULLCOW GAME"));
    HiddenWord = TEXT("unreal");
    Lives = HiddenWord.Len();
    
    PrintLine(TEXT("Guess the %i letter hidden word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), HiddenWord.Len());
    PrintLine(TEXT("Type your guess \nPress enter to continue..."));

    bGameOver = false;
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again:"));
}

void UBullCowCartridge::ProcessGuess(const FString& Input)
{
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You win..."));
        EndGame();
    }
    else
    {
        //--Lives;
        PrintLine(TEXT("Lost a life"));
        PrintLine(TEXT("%i"), --Lives);
        if (Lives > 0)
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("Sorry try guessing again! \n You have %i lives"), Lives);
                // PrintLine(FString::Printf(TEXT("The hidden word is %2d characters long...\nTry Again.."), HiddenWord.Len()));
                // PrintLine(TEXT("The hidden word is %2d characters long..Try Again.."), HiddenWord.Len());                    // Alternative
            }
        }
        else
        {
            PrintLine(TEXT("Sorry No More Lives"));
            EndGame();
        }
    }

}

 
