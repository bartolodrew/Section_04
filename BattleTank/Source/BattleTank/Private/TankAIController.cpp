// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Classes/GameFramework/Actor.h"
#include "Engine/World.h"
#include "Tank.h"
//depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (ensure(PlayerTank))
	{
		//move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);//TODO check radius is in cm

		//aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		ControlledTank->Fire();//TODO limit firing rate
	}
}
