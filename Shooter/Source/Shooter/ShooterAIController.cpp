// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAIController::BeginPlay() {
	
	Super::BeginPlay();

	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	
	StartLocation = GetPawn()->GetActorLocation();
	
	RunBehaviorTree(AIBehavior);
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), StartLocation);

}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	/*APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	

	FVector PawnView;
	FRotator PawnRotationView;
	GetActorEyesViewPoint(PawnView, PawnRotationView);

	if (AIBehavior) {
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), StartLocation);

		if (LineOfSightTo(PlayerPawn, PawnView)) {
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
			GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
		}
		else {
			GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
		}

		

		
	}*/

}

bool AShooterAIController::IsDead() const{

	AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
	if (ControlledCharacter) {
		return ControlledCharacter->IsDead();
	}

	return true;
}