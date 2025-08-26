// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorTest.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BrushComponent.h"


// Sets default values
AMyActorTest::AMyActorTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Brush = CreateDefaultSubobject<UBrushComponent>("Brush");
	//Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Brush;
}

// Called when the game starts or when spawned
void AMyActorTest::BeginPlay()
{
	Super::BeginPlay();
	if (Brush == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Brush is null"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Brush is not null"));
	}
}

// Called every frame
void AMyActorTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

