// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
   
    // welcome message
    PrintLine(TEXT("Welcome to BULLCOW GAME"));

    // Prompt for Guess
    PrintLine(TEXT("Guess the 5 letter hidden word"));
    PrintLine(TEXT("Press enter to continue.."));
 
    SetupGame();
    
}


void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
   ClearScreen();
  // FString HiddenWord{TEXT("zapxcslm")};            // variable start capital letters; refactor to make a class variable
   PrintLine(Input);
   
  // auto CheckInput= Input.Equals(HiddenWord, ESearchCase::CaseSensitive);
  // if (CheckInput)
   if (Lives == 0)
   {
       PrintLine(TEXT("Sorry No More Lives...Try Again.."));
       return;
   }
   if (Input == HiddenWord && Lives != 0)  
   {
       PrintLine(TEXT("You win..."));
   }  
   else if (Input == L"") 
   {
       PrintLine(TEXT("Invalid Entry...Try Again..."));
   }    
   else 
   {
       --Lives;
       PrintLine(TEXT("Sorry You Lost...Try Again.."));
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

   FString name;
   if (name.Len() == HiddenWord.Len())
   {
      
   }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("unreal");
    Lives = 3;
}

 
