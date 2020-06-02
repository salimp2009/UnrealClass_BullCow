// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
    PrintLine(TEXT("Hidden Word is: %s and %i charachters long"), *HiddenWord, HiddenWord.Len());  

    // welcome message
    PrintLine(TEXT("Welcome to BULLCOW GAME"));

    // Prompt for Guess
    PrintLine(TEXT("Guess the 5 letter hidden word"));
    PrintLine(TEXT("Press enter to continue.."));
 
}


void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
   ClearScreen();
   PrintLine(Input);
  // int32 length= HiddenWord.Len();
  // auto CheckInput= Input.Equals(HiddenWord, ESearchCase::CaseSensitive);
  
   if (Lives == 0)
   {
       PrintLine(TEXT("Sorry No More Lives...Try Again.."));
       PrintLine(TEXT("The Hidden word was %s and %i charachters long"), *HiddenWord, HiddenWord.Len());
       //PrintLine(FString::Printf(TEXT("The Hidden word was %s"), *HiddenWord));  // Unreal original method passing values into Strings 
       return;
   }
   if (Input == HiddenWord)  
   {
       PrintLine(TEXT("You win..."));
   }  
   else if(Input.Len()!=HiddenWord.Len())
   {
       --Lives;
       PrintLine(FString::Printf(TEXT("The hidden word is %2d characters long..Try Again.."), HiddenWord.Len() ));
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
}

 
