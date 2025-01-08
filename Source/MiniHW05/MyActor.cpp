// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("StartPos : (%d, %d)"), static_cast<int>(start.X), static_cast<int>(start.Y));
	
	UE_LOG(LogTemp, Warning, TEXT("##################################Move Start##################################"));
	
	for(int Iter = 0; Iter < 10; ++Iter)
	{
		move();
	}
	
	UE_LOG(LogTemp, Warning, TEXT("##################################Move End##################################"));
	
	UE_LOG(LogTemp, Warning, TEXT("Total Move Distance : %5.2f, Total Event Occur Count : %d"), distance(start, FVector2D::ZeroVector), evCnt);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::move()
{
	// 이전 거리 저장
	FVector2D beforePos = start;	
	//이동은 입력을 받는게 아니고 랜덤으로 움직입니다.
	start.X += step();
	start.Y += step();
	float movedDistance = distance(start, beforePos);
	
	// 매번 이동시 현재 좌표를 출력할 수 있어야 합니다.
	UE_LOG(LogTemp, Warning, TEXT("Actor Moved.. CurrentPos : (%d , %d)/// Distance between Before Pos : %5.2f")
		, static_cast<int>(start.X)
		, static_cast<int>(start.Y)
		, movedDistance);
}

int32 AMyActor::step()
{
	int32 randomStep = rand() % 2;
	createEvent();
	
	return randomStep;
}

float AMyActor::distance(const FVector2D& first, const FVector2D& second)
{
	float length = FMath::Sqrt(FMath::Pow(second.X - first.X, 2) + FMath::Pow(second.Y - first.Y, 2));

	return length;
}

void AMyActor::createEvent()
{
	int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
	if (RandomValue <= 50)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
		++evCnt;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
	}
}

