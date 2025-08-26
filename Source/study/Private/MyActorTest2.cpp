// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorTest2.h"
#include "Kismet/GameplayStatics.h"
#include "Extensions.h"

// Sets default values
AMyActorTest2::AMyActorTest2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	OnActorBeginOverlap.AddDynamic(this, &AMyActorTest2::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AMyActorTest2::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Start"));
}

void AMyActorTest2::OnOverlapBegin(AActor * Actor, AActor * Other)
{
	//UE_LOG(LogTemp, Warning, TEXT("OtherName : %s"), *Other->Owner.GetFName().ToString());
	if (Other->ActorHasTag("Player"))
	{
		UE_LOG(LogTemp, Warning, TEXT("HasTag"));

		auto actors = Extensions::GetAllActorsWithTag(GetWorld(), "TargetObject");
		for (auto* actor : actors) 
		{
			UE_LOG(LogTemp, Warning, TEXT("ActorFound"));
			actor->GetComponentByClass(UActorComponent::StatiClass());
			auto fncName = TEXT("SetActiveActor");
			auto targetFnc = actor->FindFunction(fncName);
			if (targetFnc)
			{
				UE_LOG(LogTemp, Warning, TEXT("FoundFnc"));

				FStructOnScope ParamStruct(targetFnc);
				auto ParamMemory = ParamStruct.GetStructMemory();
				auto Struct = ParamStruct.GetStruct();
				bool bActiveSelf = actor->IsValidLowLevel();

				auto Property = Struct->FindPropertyByName("SetActive");
				auto BoolProperty = CastField<FBoolProperty>(Property);
				BoolProperty->SetPropertyValue(ParamMemory, !bActiveSelf);
				actor->ProcessEvent(targetFnc, &ParamStruct);
				UE_LOG(LogTemp, Warning, TEXT("bActiveSelf : %s"), *Extensions::BoolToString(bActiveSelf));
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TagNotFound"));
	}
}


// Called every frame
void AMyActorTest2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

