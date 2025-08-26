// Fill out your copyright notice in the Description page of Project Settings.


#include "Extensions.h"
#include "Kismet/GameplayStatics.h"

Extensions::Extensions()
{
}

Extensions::~Extensions()
{
}

TArray<AActor*> Extensions::GetAllActorsWithTag(UWorld* World, FName Tag)
{
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsWithTag(World, Tag, actors);
	return actors;
}

FString Extensions::BoolToString(bool bValue)
{
	return bValue ? "true" : "false";
}
