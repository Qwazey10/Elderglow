// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "ElderglowPlayerstate.generated.h"

/**
 * 
 */
UCLASS()
class ELDERGLOW_API AElderglowPlayerstate : public APlayerState
{
	GENERATED_BODY()
	
public:

	//RaceID for the Character Appearance Data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
	int RaceID = 0;

	//Character Ability System Component 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability Component")
	UAbilitySystemComponent* PlayerAbilitySystemComponent;

	//Character Quest Flags, This is where NPCs will add Perm or Temp Quest flags to the character. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest Flags")
	TArray<FString> CharacterQuestFlags;

	//Character Access Flags, This is where Perm or Temp Access Flags will be stored on the Character.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest Flags")
	TArray<FString> CharacterAccessFlags;

	
	
};
