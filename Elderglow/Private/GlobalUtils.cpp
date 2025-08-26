// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalUtils.h"

#include "Kismet/GameplayStatics.h"


GlobalUtils::GlobalUtils()
{
}

GlobalUtils::~GlobalUtils()
{
    
}

UElderglowGameInstance* GlobalUtils::GetElderglowGameInstance(const UWorld* WorldRef)
{
	if (IsValid(WorldRef))
	{
		UElderglowGameInstance* ElderglowGI = Cast<UElderglowGameInstance>(WorldRef->GetGameInstance());
		if (IsValid(ElderglowGI))
		{
			return ElderglowGI;
		}
		else
		{
			return nullptr;
		}
	}
	return nullptr;
}

FHitResult GlobalUtils::LineTraceForwardFromPlayerCamera(UWorld* World,
	ECollisionChannel DesiredCollisionChannel,
	float TraceDistance,
	EDrawDebugTrace::Type DebugTraceType,
	float DrawDuration,FLinearColor TraceColor)
{

	FHitResult HitResult;
	
	if (IsValid(World))
	{

		UElderglowGameInstance* SlasherGI = Cast<UElderglowGameInstance>(World->GetGameInstance());


	
		if (IsValid(SlasherGI))
		{
			TArray<AActor*> ActorsToIgnore;
			FCollisionQueryParams QueryParams;

			// Get the player controller
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
			if (!PlayerController)
			{
				UE_LOG(LogTemp, Warning, TEXT("GlobalUtils -- LineTraceForwardFromPlayerCamera -- Getter for PlayerCont Not Valid"));
				return HitResult; // Return an empty hit result if no player controller
			}

			// Get the player camera manager
			APlayerCameraManager* CameraManager = PlayerController->PlayerCameraManager;
			if (!CameraManager)
			{
				UE_LOG(LogTemp, Warning, TEXT("GlobalUtils -- LineTraceForwardFromPlayerCamera -- Getter for Camera Manager IS NOT VALID"));
				return HitResult; // Return an empty hit result if no camera manager
			}
	

			// Get the camera location and rotation
			FVector StartLoc = CameraManager->GetCameraLocation();
			FRotator CameraRotation = CameraManager->GetCameraRotation();
			FVector CameraRotForwardVector = CameraRotation.Vector() * TraceDistance;
			FVector EndLoc = StartLoc + CameraRotForwardVector;

			// Configure the query parameters
			QueryParams.AddIgnoredActor(PlayerController->GetPawn()); // Ignore the player pawn


		
		
			/*
			EDrawDebugTrace::Type TraceType = SlasherGI->bShowDebugTracesForLineTraceForwardFromCamera ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None;
			*/


		
			const bool bHit = UKismetSystemLibrary::LineTraceSingle(
				World,
				StartLoc,
				EndLoc,
				UEngineTypes::ConvertToTraceType(DesiredCollisionChannel),
				false,
				ActorsToIgnore,
				DebugTraceType, // Trace Types for Line Trace --  None, For Duration , ForOneFrame, Persistant 
				HitResult,
				true,
				TraceColor,
				FLinearColor::Green,
				DrawDuration
				);

			if (bHit)
			{
				return HitResult;
			}
		}
	}

	return HitResult;
}

/*void GlobalUtils::PlayFMODEventAtLocation(const FString& EventPath, UFMODEvent* HardEventReference, UWorld* WorldReference, const FTransform& LocationTransform,
	const FString& ErrorString)
{
	if (HardEventReference)
	{
		UFMODBlueprintStatics::PlayEventAtLocation(WorldReference,HardEventReference,LocationTransform,true);
		return;
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Red, ErrorString);
		}
	}
	
	UFMODEvent* Event = UFMODBlueprintStatics::FindEventByName(EventPath);
	if (Event)
	{
		UFMODBlueprintStatics::PlayEventAtLocation(
		WorldReference,
		Event,
		LocationTransform,
		true);
		
	}
	else
	{
		FString FMODError =  FString::Printf(TEXT("%s -- Event Not Found: %s"), *ErrorString, *EventPath);
		
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, FMODError);
		}
	}
}*/

FHitResult GlobalUtils::SphereTraceForwardFromPlayerCamera(
	UWorld* World,
	ETraceTypeQuery DesiredCollisionChannel,
	float TraceDistance,
	EDrawDebugTrace::Type DebugTraceType,
	float DrawDuration,
	FLinearColor TraceColor,
	float SphereRadius)
{
	//Creating Empty Hit Result
	FHitResult HitResult;
	

	//Check if world reference is valid
	if (IsValid(World))
	{
		
		UElderglowGameInstance* ElderglowGI = Cast<UElderglowGameInstance>(World->GetGameInstance());
		
		if (IsValid(ElderglowGI))
		{
			TArray<AActor*> ActorsToIgnore;
			FCollisionQueryParams QueryParams;

			// Get the player controller - Global Utils is only available from client, so Index 0 should always return Player
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
			if (!PlayerController)
			{
				UE_LOG(LogTemp, Warning, TEXT("GlobalUtils -- LineTraceForwardFromPlayerCamera -- Getter for PlayerCont Not Valid"));
				return HitResult; // Return an empty hit result if no player controller
			}

			// Get the player camera manager
			APlayerCameraManager* CameraManager = PlayerController->PlayerCameraManager;
			if (!CameraManager)
			{
				UE_LOG(LogTemp, Warning, TEXT("GlobalUtils -- LineTraceForwardFromPlayerCamera -- Getter for Camera Manager IS NOT VALID"));
				return HitResult; // Return an empty hit result if no camera manager
			}
	

			// Get the camera location and rotation
			FVector StartLoc = CameraManager->GetCameraLocation();
			FRotator CameraRotation = CameraManager->GetCameraRotation();
			FVector CameraRotForwardVector = CameraRotation.Vector() * TraceDistance;
			FVector EndLoc = StartLoc + CameraRotForwardVector;

			// Configure the query parameters
			QueryParams.AddIgnoredActor(PlayerController->GetPawn());

		
		
    
			// Execute sphere trace
			bool bHit = UKismetSystemLibrary::SphereTraceSingle(
			World,
			StartLoc,
			EndLoc,
			SphereRadius,
			DesiredCollisionChannel,
			false, // bTraceComplex
			ActorsToIgnore,
			DebugTraceType,
			HitResult,
			true, // bIgnoreSelf
			TraceColor,
			FLinearColor::Green, // TraceHitColor
			DrawDuration
			);

			return HitResult;
		}
	}

	return HitResult;
}