// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorTest2.generated.h"

UCLASS()
class STUDY_API AMyActorTest2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActorTest2();
	UPROPERTY(EditAnywhere, Category = "Setup")
	UBrushComponent* Brush;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(AActor* Actor, AActor* Other);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
