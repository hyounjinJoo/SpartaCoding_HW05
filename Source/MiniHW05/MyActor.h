// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MINIHW05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void move();
	int32 step();
	float distance(const FVector2D& first, const FVector2D& second);
	void createEvent();
		
private:
	FVector2D start = FVector2D::ZeroVector;
	int32 evCnt = 0;
	int totDist = 0;
};
