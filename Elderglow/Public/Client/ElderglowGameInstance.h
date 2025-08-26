// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RedisClient.h"
#include "Engine/GameInstance.h"
#include "ElderglowGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ELDERGLOW_API UElderglowGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	
	//Attempt to Connect to the login server and request Redis Information
	void LoginServerAttemptConnectionToRedisServer();
	void StoreCharacterAppearanceData();


	/**
	* 
	Redis Connection Managers
	*/
	
	//RedisClientConnection
	UPROPERTY(EditAnywhere)
	URedisClient* ElderglowRedisClientManager;

	UPROPERTY(EditAnywhere)
	URedisPipeline* ElderglowRedisPipeline;
	
	UPROPERTY(EditAnywhere)
	URedisTransaction* ElderglowRedis;

	//Init Connection Function
	void ConnectToRedisServer(FString RedisIPAddress, int RedisPort, FString RedisPassword, int MaxNum);
	
	//Function to Ping the Redis Server.
	void PingRedisServer();

	//Delegate Function from Ping Server, Should be called when the Redis Server returns. 
	UFUNCTION()	
	void PongFromRedisServer(bool bOk, const FString& Err, const FReplyValue& Value);

	

	
};
