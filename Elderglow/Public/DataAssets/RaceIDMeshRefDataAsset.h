// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RaceIDMeshRefDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ELDERGLOW_API URaceIDMeshRefDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	//Head Base Mesh Reference for RaceID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display Mesh Reference")
	USkeletalMesh* HeadMeshReference;

	//Chest Base Mesh Reference for RaceID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display Mesh Reference")
	USkeletalMesh* ChestMeshReference;

	//Arms Base Mesh Reference for RaceID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display Mesh Reference")
	USkeletalMesh* ArmsMeshReference;

	//Hands Base Mesh Reference for RaceID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display Mesh Reference")
	USkeletalMesh* HandMeshReference;

	//Legs Base Mesh Reference for RaceID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display Mesh Reference")
	USkeletalMesh* LegsMeshReference;

	//Feet Base Mesh Reference for RaceID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display Mesh Reference")
	USkeletalMesh* FeetMeshReference;

	//Test to see if this is picked up by the Unreal Build Tool. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Display for TArray of Meshes")
	TArray<USkeletalMesh*> TArrayOfMeshes;
};
