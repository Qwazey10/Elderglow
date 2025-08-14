// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "LivingBeingCharacterBase.generated.h"

UCLASS()
class ELDERGLOW_API ALivingBeingCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALivingBeingCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*
	 * Gameplay Ability System Component
	 *
	 * The Ability System Component is created in two places, one is on the CharacterBase, One is in PlayerSTate
	 *
	 * -- The Character Base Component is for Enemies and NPCs
	 * -- The PlayerState Component is for Players.
	 *
	 * --The Reason for two components is one is locally tracked by the server for NPCs, cooldowns are reset on death/Respawn
	 * --For Playerstate its tracked globally by the server, so death will not reset long cooldowns.
	 *
	 * --GetElderglowAbilitySystemComponent is the getter which will return the pointer to the respective AbilityComponent.
	 */
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Abilities")
	UAbilitySystemComponent* ElderglowNPCAbilitySystemComponent;
	
	//Getter Function for AbilitySystemComponent
	virtual UAbilitySystemComponent* GetElderglowAbilitySystemComponent();
	
		
	
};
