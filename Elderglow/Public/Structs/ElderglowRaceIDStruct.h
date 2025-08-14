// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/ElderglowEnemyAnimDataAsset.h"
#include "Engine/DataTable.h"
#include "ElderglowRaceIDStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct ELDERGLOW_API FElderglowRaceIDStruct : public FTableRowBase
{

	GENERATED_BODY()
	
	//Race ID Lookup int
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elderglow")
	int RaceID = 0;
	//Race Name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elderglow")
	FString RaceName = "Unassigned";
	//Corresponding AnimationDataAsset.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elderglow")
	UElderglowEnemyAnimDataAsset* ElderglowAnimDataAsset = nullptr;
	
	FElderglowRaceIDStruct();
	virtual ~FElderglowRaceIDStruct() override;
};

