// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include <Runtime\Engine\Classes\PhysicsEngine\PhysicsHandleComponent.h>
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

private:
	//How far ahead of the player 
	float Reach = 100.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	//Ray-Cast and grab what's in reach
	void Grab();

	//Called when grab is released
	void Release();

	//Find attached physics handle
	void FindPhysicsHandleComponent();

	void SetUpInputComponent();

	const FHitResult GetFirstPhysicsBodyInReach();

	//Return Current End of Reach Line
	FVector GetReachLineStart();

	FVector GetReachLineEnd();

};


