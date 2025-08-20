// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorController.h"

// Sets default values for this component's properties
UActorController::UActorController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActorController::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UActorController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UActorController::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OverlappedActor->ActorHasTag("Player"))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player overlapped!"));

	}
}

