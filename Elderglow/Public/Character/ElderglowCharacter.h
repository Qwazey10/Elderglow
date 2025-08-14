// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/LivingBeingCharacterBase.h"
#include "DataAssets/RaceIDMeshRefDataAsset.h"
#include "ElderglowCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ELDERGLOW_API AElderglowCharacter : public ALivingBeingCharacterBase
{
	GENERATED_BODY()
	
	public:

	/*
	 * RaceID, this will govern which race we assign from an array of naked base mesh references. 
	 * RaceID References:
	 *
	 * This data will come from the PlayerState
	 *
	 * Human = 0;
	 * Woodelf = 1;
	 * Ogre = 3
	 */

	//RaceID Base Mesh References, this holds the references of base meshes used per race. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RaceID Data Asset", meta=(AllowPrivateAccess=true))
	URaceIDMeshRefDataAsset* RaceIDMeshRefData;

	//Function to switch on race and assign the respective DataAsset. RaceID is stored in the PlayerState.
	void AssignMeshDataAsset();
	
	//Skeletal Mesh Component to act as the Primary Pose Component Target, this is the Chest mesh.  
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Parent Mesh - Chest", meta=(AllowPrivateAccess=true))
	USkeletalMeshComponent* CharacterNPCDisplayMesh;

	USkeletalMeshComponent* GetElderglowCharacterNPCDisplayMesh() const {return CharacterNPCDisplayMesh;}


	
};
