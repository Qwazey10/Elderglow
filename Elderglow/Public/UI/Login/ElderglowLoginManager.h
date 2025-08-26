// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElderglowLoginManager.generated.h"

UCLASS()
class ELDERGLOW_API AElderglowLoginManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElderglowLoginManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Function Called on Tick to Display the Main ImGui Menu. 
	void LoginImGuiMenuDisplay();

	UPROPERTY(EditAnywhere)
	FString RedisConnectionStatus = "No Redis Connection";

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ServerAttributes")
	FString RedisTargetIPAddress = "127.0.0.1";
	

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ServerAttributes")
	FString ElderglowInputUserName;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ServerAttributes")
	FString ElderglowInputPassword;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ServerAttributes")
	FString ElderglowInputIPAddress;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ServerAttributes")
	int32 ElderglowInputPort;


	// ImGui buffers (UTF-8)
	char UserNameBuffer[256];
	char PasswordBuffer[256];
	char IPAddressBuffer[256];
	int32 PortBuffer;

	// Initialize ImGui buffers from FString values
	void InitializeBuffers();
};
