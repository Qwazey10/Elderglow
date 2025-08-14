// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LivingBeingCharacterBase.h"

#include "Character/ElderglowPlayerstate.h"


// Sets default values
ALivingBeingCharacterBase::ALivingBeingCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ElderglowNPCAbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	
}

// Called when the game starts or when spawned
void ALivingBeingCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALivingBeingCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALivingBeingCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ALivingBeingCharacterBase::GetElderglowAbilitySystemComponent()
{
	
	if (IsValid(this) && this->ActorHasTag("Player"))
	{
		AElderglowPlayerstate* ElderglowPlayerStateRef = Cast<AElderglowPlayerstate>(GetPlayerState());
		if (IsValid(ElderglowPlayerStateRef))
		{
			return ElderglowPlayerStateRef->PlayerAbilitySystemComponent;
		}
	}
	return ElderglowNPCAbilitySystemComponent;
}
