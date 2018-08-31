// Copyright to Andrew Bartolo for my own purposes and mine alone.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force and to apply forces to the tank. 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	//max force per track in nuetons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000;//assume 40 tonne tank, and 1g acceleration

private:
	UTankTrack();

	TArray<class ASprungWheel*> GetWheels() const;

	void DriveTrack(float CurrentThrottle);
};
