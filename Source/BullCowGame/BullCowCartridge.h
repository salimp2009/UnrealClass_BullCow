// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(FStringView Input) override;
	void SetupGame();
	void EndGame();
	void ProcessGuess(FStringView Guess);	// Guess=Input
	void GetValidWords(TArray<FString>& wordlist);
	bool IsIsogram(FStringView Guess) const;

	private:
		FString HiddenWord;
		int32 Lives{0};
		bool bGameOver{false};
		TArray<FString>WordList;
};
