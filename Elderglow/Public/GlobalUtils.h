// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "imgui.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Client/ElderglowGameInstance.h"

/**
 * 
 */
class ELDERGLOW_API GlobalUtils
{
	
public:
	
	GlobalUtils();
	~GlobalUtils();

	/**
	* Get the Elderglow Game Instance, this function is to be used on clients only 
	 * @param WorldRef				World Context Object to get GameInstance from. 
	 */
	
	static UElderglowGameInstance* GetElderglowGameInstance(const UWorld* WorldRef);

	/**
	* Performs a line trace (raycast) forward from the player's camera perspective
	 * 
	 * @param World						World context object for the trace
	 * @param DesiredCollisionChannel	Which collision channel to trace against (defaults to Visibility)
	 * @param TraceDistance				Maximum distance of the trace in world units (default 1000uu)
	 * @param DebugTraceType			Whether/how to visualize the trace (default None)
	 * @param DrawDuration				Duration to display debug visualization (if enabled)
	 * @param TraceColor				Color to draw the debug trace (default Red)
	 * 
	 * @return						FHitResult containing hit information (check bBlockingHit for success)
	 */
	
	static FHitResult LineTraceForwardFromPlayerCamera(
		UWorld* World,
		ECollisionChannel DesiredCollisionChannel = ECC_Visibility,
		float TraceDistance = 1000.0f,
		EDrawDebugTrace::Type DebugTraceType = EDrawDebugTrace::None,
		float DrawDuration = 5.0f,
		FLinearColor TraceColor = FColor::Red);

	/**
	 * Performs a spherical sweep trace forward from the player's camera perspective
	 * 
	 * @param World						World context object for the trace
	 * @param DesiredCollisionChannel	Which trace channel to test against (via TraceTypeQuery)
	 * @param TraceDistance				Maximum distance of the trace in world units
	 * @param DebugTraceType			Whether/how to visualize the trace
	 * @param DrawDuration				Duration to display debug visualization
	 * @param TraceColor				Color to draw the debug trace
	 * @param SphereRadius				Radius of the sphere used for collision testing
	 * 
	 * @return						FHitResult containing hit information (check bBlockingHit for success)
	 */
	
	static FHitResult SphereTraceForwardFromPlayerCamera(
		UWorld* World,
		ETraceTypeQuery DesiredCollisionChannel,
		float TraceDistance,
		EDrawDebugTrace::Type DebugTraceType,
		float DrawDuration,
		FLinearColor TraceColor,
		float SphereRadius);

	//Need to add the FMOD Library before I can use this function
	/*static void PlayFMODEventAtLocation(const FString& EventPath, UFMODEvent* HardEventReference, UWorld* WorldReference, const FTransform& LocationTransform, const
									FString& ErrorString);*/


	/**
	 * ImGui Static Colors to Use
	 */
	static constexpr ImVec4 ImGui_COLOR_RED = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // Full red
	static constexpr ImVec4 ImGui_COLOR_GREEN = ImVec4(0.0f, 1.0f, 0.0f, 1.0f); // Full green
	static constexpr ImVec4 ImGui_COLOR_BLUE = ImVec4(0.0f, 0.0f, 1.0f, 1.0f); // Full blue
	static constexpr ImVec4 ImGui_COLOR_YELLOW = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow (red + green)
	static constexpr ImVec4 ImGui_COLOR_CYAN = ImVec4(0.0f, 1.0f, 1.0f, 1.0f); // Cyan (green + blue)
	static constexpr ImVec4 ImGui_COLOR_MAGENTA = ImVec4(1.0f, 0.0f, 1.0f, 1.0f); // Magenta (red + blue)
	static constexpr ImVec4 ImGui_COLOR_WHITE = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // White
	static constexpr ImVec4 ImGui_COLOR_BLACK = ImVec4(0.0f, 0.0f, 0.0f, 1.0f); // Black
	static constexpr ImVec4 ImGui_COLOR_GRAY = ImVec4(0.5f, 0.5f, 0.5f, 1.0f); // Gray
	static constexpr ImVec4 ImGui_COLOR_LIGHT_GRAY = ImVec4(0.8f, 0.8f, 0.8f, 1.0f); // Light gray
	static constexpr ImVec4 ImGui_COLOR_DARK_GRAY = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
	
};
