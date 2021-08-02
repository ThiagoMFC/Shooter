// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay() {
	
	Super::BeginPlay();

	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	
	

}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	

	FVector PawnView;
	FRotator PawnRotationView;
	GetActorEyesViewPoint(PawnView, PawnRotationView);

	if (LineOfSightTo(PlayerPawn, PawnView)) {
		SetFocus(PlayerPawn);
		MoveToActor(PlayerPawn, AccpetanceRadius);
	}
	else {
		ClearFocus(EAIFocusPriority::Gameplay);
		StopMovement();
	}
}