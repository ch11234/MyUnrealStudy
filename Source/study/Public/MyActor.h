// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STUDY_API UMyActor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyActor();
	UPROPERTY(EditAnywhere, Category = "Setup")
	UBrushComponent* Brush;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(AActor* actor, AActor* other);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
