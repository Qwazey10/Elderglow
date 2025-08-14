// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ElderglowEnemyAnimDataAsset.h"
#include "Engine/DataAsset.h"
#include "ElderglowEnemyDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ELDERGLOW_API UElderglowEnemyDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
	public:

	//Enemy Attributes

	//Which Race or Monster ID type to load
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	int RaceID = 0.0f;

	//Sets the Scale of the Skeletal Mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	float Size = 1.0f;
	
	//Enemy Base Level, Scales with some of the damage systems. 
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Enemy Attributes")
	int Level = 1;
	
	//Base Health for the Enemy.
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Enemy Attributes")
	float BaseHealth = 20.0f;

	//Base AC value for the Enemy.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	float BaseACValue = 10.0f;

	//Base Resist Magic Value for the Enemy.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	float ResistMagic = 0.0f;
	
	//Base Resist Fire Value for the Enemy.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	float ResistFire = 0.0f;

	//Base Resist Cold Value for the Enemy.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	float ResistCold = 0.0f;

	//Base Resist Disease Value for the Enemy.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	float ResistDisease = 0.0f;

	//Base Resist Poison Value for the Enemy. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	float ResistPoison = 0.0f;

	//Make Enemy Completely Immune to Magic Damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	bool bIsImmune_Magic = false;
	
	//Make Enemy Completely Immune to Fire Damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	bool bIsImmune_Fire = false;

	//Make Enemy Completely Immune to Cold Damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	bool bIsImmune_Cold = false;

	//Make Enemy Completely Immune to Disease Damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	bool bIsImmune_Disease = false;

	//Make Enemy Completely Immune to Disease Damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Attributes")
	bool bIsImmune_Poison = false;


	//Dialog
};
