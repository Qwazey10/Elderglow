// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ElderglowItemStruct.generated.h"
/**
 * 
 */

USTRUCT(BlueprintType)
struct ELDERGLOW_API FElderglowItemStruct : public FTableRowBase
{
	GENERATED_BODY()

	//Race ID Lookup int
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Item Attributes")
	int ItemID = 0;
	//Race Name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Item Attributes")
	FString ItemName = "Unassigned";
	//Corresponding AnimationDataAsset.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Item Attributes")
	FString ItemDescription = "Unassigned";
	
	//Appearance

	// Item Display Static Mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	UStaticMesh* ItemDisplayMesh = nullptr;
	//Set to true to apply Custom Material to the ItemDisplayMesh, will use CustomItemDisplayMaterial and Apply it. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	bool bUseCustomDisplayMaterial = false;
	//Apply this custom material to the item if bUseCustomDisplayMaterial = true.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	UMaterial* CustomItemDisplayMaterial = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	UTexture2D* ItemInventoryIcon = nullptr;

	//Ability System Attribute Data
	
	//Boolean to determine if we destroy the item on use. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	bool bDestroyItemOnUse = false;
	//AbilityID to PERMANENTLY to PlayerAbility List on Use 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	int OnUseGrantAbilityID = 0;
	//Ability ID which will be activated on ItemUse
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	int OnUseDoAbilityID = 0;


	
	FElderglowItemStruct();
	virtual ~FElderglowItemStruct() override;
};