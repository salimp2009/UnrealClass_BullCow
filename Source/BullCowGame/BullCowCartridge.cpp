// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
//#include "HiddenWordList.h"
#include "Math/UnrealMathUtility.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    const FString WordListhPath=FPaths::ProjectContentDir() / TEXT("WordList/WordList.txt");
    //FFileHelper::LoadFileToStringArray(WordList, *WordListhPath);
    FFileHelper::LoadFileToStringArrayWithPredicate(WordList, *WordListhPath, [this](const auto& word) {return IsIsogram(word); });
    //WordList.RemoveAll([this](auto& word) {return !IsIsogram(word);});
    SetupGame();
    PrintLine(TEXT("Hidden Word List has %i"), WordList.Num());  
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
 
   // if true; WinMsg() && GameOver() || RePlay() (replay; resetlives(), Guess()
   // AskPlayAgain(); ResetHidden(); ResetLives(); Guess()  || GameOver()
   // Replay()
}

void UBullCowCartridge::SetupGame()
{
    // welcome message
    PrintLine(TEXT("Welcome to BULLCOW GAME"));

    //HiddenWord = TEXT("unreal");
    HiddenWord = WordList[FMath::RandHelper(WordList.Num())];
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter hidden word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), HiddenWord.Len());
    PrintLine(TEXT("Type your guess \nPress enter to continue..."));

    //const TCHAR HW[] = TEXT("SALIM");
    //PrintLine(TEXT("the 1st character of the Hidden Word is %c"), HiddenWord[0]);
    //PrintLine(TEXT("the 3rd character of the HW is %c"), HW[2]);
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
        return;                                              
    }

    if (Input.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        PrintLine(TEXT("Sorry try guessing again! \n You have %i lives"), Lives);
        // PrintLine(FString::Printf(TEXT("The hidden word is %2d characters long...\nTry Again.."), HiddenWord.Len()));
        return;
    }

    if (!IsIsogram(Input))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }

    PrintLine(TEXT("Lost a life"));
    --Lives;

   if (Lives <=0)
   {
       ClearScreen();
       PrintLine(TEXT("Sorry No More Lives"));
       PrintLine(TEXT("The HiddenWord was : %s \n"), *HiddenWord);

       EndGame(); 
       return;
   }

   PrintLine(TEXT("Try again, You have %i lives left"), Lives);
}

bool UBullCowCartridge::IsIsogram(const FString& Guess) const
{
    //for (int32 Index{0}; Index < Guess.Len(); ++Index)
    //{
    //    for (int32 Comparision{Index+1}; Comparision < Guess.Len(); ++Comparision)
    //    {
    //        if (Guess[Index] == Guess[Comparision])
    //            return false;
    //    }
    //}

    int32 Position{0};
 
    for(int32 Index=0; Index<Guess.Len(); ++Index) 
    {
        Guess.FindLastChar(Guess[Index], Position);
        if(Position != Index) return false;
    }
     
    return true;
}
 
