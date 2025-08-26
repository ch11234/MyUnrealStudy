// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class STUDY_API Extensions
{
public:
	Extensions();
	~Extensions();

	static TArray<AActor*> GetAllActorsWithTag(UWorld* World, FName Tag);
	static FString BoolToString(bool bValue);
};
