// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ElderglowExperienceStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct ELDERGLOW_API FElderglowExperienceStruct : public FTableRowBase
{

	GENERATED_BODY()

	//Level Int
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Experience Table")
	int Level = 1;

	//Experience Needed for each level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Experience Table")
	float ExperienceNeededForNextLevel = 100.0f;

	//The Amount of Experience Granted by Killing a NPC of X level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Experience Table")
	float ExperienceBaseGrantedPerLevel = 10.0f;
	
	FElderglowExperienceStruct();
	virtual ~FElderglowExperienceStruct() override;
};
