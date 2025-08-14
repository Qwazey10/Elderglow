// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ElderglowGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ELDERGLOW_API UElderglowGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	
	//Attempt to Connect to the login server and request Redis Information
	void LoginServerAttemptConnectionToRedisServer();
	void StoreCharacterAppearanceData();
};
