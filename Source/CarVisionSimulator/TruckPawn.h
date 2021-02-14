// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"

#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "WheeledVehicleMovementComponent4W.h"

#include "TruckPawn.generated.h"

/**
 * 
 */
UCLASS()
class CARVISIONSIMULATOR_API ATruckPawn : public AWheeledVehicle
{
	GENERATED_BODY()
	
public:

	ATruckPawn();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	//  Throttle/Steering
	void ApplyThrottle(float val);
	void ApplySteering(float val);

	//Look Around
	void LookUp(float val);
	void Turn(float val);

	//handbrake
	void OnHandbrakePressed();
	void OnHandbrakeReleased();

	//Camera
protected:

	UPROPERTY(Category = Camera, EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	UPROPERTY(Category = Camera, EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;
};

