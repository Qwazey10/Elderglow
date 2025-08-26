// Fill out your copyright notice in the Description page of Project Settings.

#include "ReplyValue.h"
#include "Client/ElderglowGameInstance.h"


void UElderglowGameInstance::LoginServerAttemptConnectionToRedisServer()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green,
			"Elderglow Game Instance -- Attempt connection to Redis Server for character information");
	}
}

void UElderglowGameInstance::StoreCharacterAppearanceData()
{
	//Get the data from the Redis server that corresponds to which RaceID we are and which Weapons and Equipment
	//We currently have equipped. 
}

void UElderglowGameInstance::ConnectToRedisServer(FString RedisIPAddress, int RedisPort, FString RedisPassword, int MaxNum)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow,"Elderglow Game Instance, Attempting Connection to Redis Server");
	}
	if (ElderglowRedisClientManager)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green,"Elderglow Redis Client Manage is Valid");
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green,"Elderglow Redis Client Manage is Valid");
			PingRedisServer();
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red," Redis Client Manage is NULL, Attempting New Construct");
			ElderglowRedisClientManager = URedisClient::NewRedisClient(MaxNum, RedisIPAddress,RedisPort,RedisPassword);
			
		}
	}
}

void UElderglowGameInstance::PingRedisServer()
{
	if (ElderglowRedisClientManager)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "Redis Client is Valid, Attempting Ping!");
		}

		FRedisTaskDoneDelegate Delegate;
		Delegate.BindDynamic(this, &UElderglowGameInstance::PongFromRedisServer);

		ElderglowRedisClientManager->Ping(Delegate);
		
		
	}
}



void UElderglowGameInstance::PongFromRedisServer(bool bOk, const FString& Err, const FReplyValue& Value)
{
	if (bOk)
	{
		FString ReplyMessage;

		switch (Value.Type)
		{
		case EReplyValueType::EString:
			ReplyMessage = Value.String;
			break;

		case EReplyValueType::EStatus:
			ReplyMessage = Value.Status;
			break;

		case EReplyValueType::EInt:
			ReplyMessage = FString::Printf(TEXT("%d"), Value.Integer);
			break;

		case EReplyValueType::EList:
			ReplyMessage = FString::Printf(TEXT("List with %d entries"), Value.List.Num());
			break;

		case EReplyValueType::ENil:
		default:
			ReplyMessage = TEXT("<Nil or Unexpected Reply>");
			break;
		}

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1, 5, FColor::Green,
				FString::Printf(TEXT("Redis Pong received: %s"), *ReplyMessage)
			);
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1, 5, FColor::Red,
				FString::Printf(TEXT("Redis Ping failed: %s"), *Err)
			);
		}
	}
}

