// Fill out your copyright notice in the Description page of Project Settings.


#include "Client/ElderglowGameInstance.h"


void UElderglowGameInstance::LoginServerAttemptConnectionToRedisServer()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green,
			"Elderglow Game Instance -- Attempt connection to Redis Server for character information");
	}
}

void UElderglowGameInstance::StoreCharacterAppearanceData()
{
	//Get the data from the Redis server that corresponds to which RaceID we are and which Weapons and Equipment
	//We currently have equipped. 
}
