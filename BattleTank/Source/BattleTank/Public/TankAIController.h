// Copyright to Andrew Bartolo for my own purposes and mine alone.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	//how close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")// consider EditDefaultsOnly
	float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void OnPossessedTankDeath();
};
