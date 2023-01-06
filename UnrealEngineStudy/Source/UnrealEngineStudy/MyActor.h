// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UNREALENGINESTUDY_API AMyActor : public AActor
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
	UPROPERTY(VisibleAnywhere) // 외부에서 속성 값 노출 후 수정 가능
	UStaticMeshComponent* Mesh;

	// EditAnywhere: 디테일에서 값을 수정할 수 있음
	UPROPERTY(EditAnywhere, Category = BattleStat) 
	int32 Hp;
	UPROPERTY(EditAnywhere, Category = BattleStat) 
	int32 Mp;
};
