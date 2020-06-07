// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
    PrintLine(TEXT("Hidden Word is: %s"), *HiddenWord);  

    // welcome message
    PrintLine(TEXT("Welcome to BULLCOW GAME"));
    PrintLine(TEXT("Guess the %i letter hidden word"), HiddenWord.Len());
    PrintLine(TEXT("Type your guess & press enter to continue"));
 
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
   ClearScreen();
   PrintLine(TEXT("Your guess is %s & it is %i long"),*Input, Input.Len());
  
   if (Lives == 0)
   {
       PrintLine(TEXT("Sorry No More Lives...!\nPlease Try Again"));
       PrintLine(TEXT("The Hidden word was %s"), *HiddenWord);
       bGameOver = true;
       return;
   }
   if (Input == HiddenWord)  
   {
       PrintLine(TEXT("You win..."));
       bGameOver = true;
   }  
   else if(Input.Len()!=HiddenWord.Len())
   {
       --Lives;
       PrintLine(FString::Printf(TEXT("The hidden word is %2d characters long...\nTry Again.."), HiddenWord.Len() ));
       //PrintLine(TEXT("The hidden word is %2d characters long..Try Again.."), HiddenWord.Len());
   } 
   else 
   {
       --Lives;
       PrintLine(TEXT("Sorry Wrong Guess...Try Again.."));
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
    HiddenWord = TEXT("unreal");
    Lives = 3;
    bGameOver = false;
}

 
