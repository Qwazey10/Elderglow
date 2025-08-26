// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Login/ElderglowLoginManager.h"

#include "GlobalUtils.h"
#include "imgui.h"


// Sets default values
AElderglowLoginManager::AElderglowLoginManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AElderglowLoginManager::BeginPlay()
{
	Super::BeginPlay();

	//Init the Buffers for ImGui Text
	InitializeBuffers();
	
}

// Called every frame
void AElderglowLoginManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LoginImGuiMenuDisplay();

}

void AElderglowLoginManager::LoginImGuiMenuDisplay()
{

	static FString InputTextUsername;
	

	ImGui::Begin("Elderglow Main Menu");
	ImGui::BeginMenu("Elderglow Login Manager");
	ImGui::Text("Login");
	ImGui::Text("Username: %s", TCHAR_TO_UTF8(*ElderglowInputUserName));
	ImGui::Text("Password: %s", TCHAR_TO_UTF8(*ElderglowInputPassword));
	ImGui::Separator();
	ImGui::Text("IP Address: %s", TCHAR_TO_UTF8(*ElderglowInputIPAddress));
	ImGui::Text("Port: %d", ElderglowInputPort);


	// Input for UserName
	ImGui::Text("Username");
	if (ImGui::InputText("##Username", UserNameBuffer, sizeof(UserNameBuffer)))
	{
		ElderglowInputUserName = FString(UTF8_TO_TCHAR(UserNameBuffer));
	}

	// Input for Password
	ImGui::Text("Password");
	if (ImGui::InputText("##Password", PasswordBuffer, sizeof(PasswordBuffer), ImGuiInputTextFlags_Password))
	{
		ElderglowInputPassword = FString(UTF8_TO_TCHAR(PasswordBuffer));
	}

	// Input for IP Address
	ImGui::Text("IP Address");
	if (ImGui::InputText("##IPAddress", IPAddressBuffer, sizeof(IPAddressBuffer)))
	{
		ElderglowInputIPAddress = FString(UTF8_TO_TCHAR(IPAddressBuffer));
	}
	ImGui::Text("Port");
	if (ImGui::InputInt("##Port", &PortBuffer))
	{
		ElderglowInputPort = PortBuffer;
	}

	
	ImGui::Separator();
	
	if (ImGui::Button("Attempt Redis Connection"))
	{
		//Attempt to connect to the Redis Server
		UWorld* World = GetWorld();
		if (World)
		{
			UElderglowGameInstance* ElderglowGI = GlobalUtils::GetElderglowGameInstance(World);
			if (IsValid(ElderglowGI))
			{
				ElderglowGI->ConnectToRedisServer(ElderglowInputIPAddress, ElderglowInputPort, ElderglowInputPassword, 3);
			}	
		}
	}
	
	ImGui::End();
}

void AElderglowLoginManager::InitializeBuffers()
{
	
	// Convert FString to UTF-8 and copy to ImGui buffers safely
	FTCHARToUTF8 ConvertedUserName(*ElderglowInputUserName);
	FMemory::Memset(UserNameBuffer, 0, sizeof(UserNameBuffer));
	FMemory::Memcpy(UserNameBuffer, ConvertedUserName.Get(), FMath::Min(ConvertedUserName.Length() + 1, (int32)sizeof(UserNameBuffer)));

	FTCHARToUTF8 ConvertedPassword(*ElderglowInputPassword);
	FMemory::Memset(PasswordBuffer, 0, sizeof(PasswordBuffer));
	FMemory::Memcpy(PasswordBuffer, ConvertedPassword.Get(), FMath::Min(ConvertedPassword.Length() + 1, (int32)sizeof(PasswordBuffer)));

	FTCHARToUTF8 ConvertedIPAddress(*ElderglowInputIPAddress);
	FMemory::Memset(IPAddressBuffer, 0, sizeof(IPAddressBuffer));
	FMemory::Memcpy(IPAddressBuffer, ConvertedIPAddress.Get(), FMath::Min(ConvertedIPAddress.Length() + 1, (int32)sizeof(IPAddressBuffer)));

	PortBuffer = ElderglowInputPort;

}

