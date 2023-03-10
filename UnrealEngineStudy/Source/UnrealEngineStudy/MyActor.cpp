// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// TEXT로 감싸주면 빌드 플랫폼에 따라 자동으로 인코딩을 해준다.
	// 메쉬 컴포넌트를 생성
	// Mesh가 UPROPERTY 특성을 들고 있기 때문에 이렇게 메모리에 객체를 생성해도 언리얼에서 알아서 메모리 관리를 해준다.
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));

	// 해당 액터의 mesh는 RootComponent로 넣어줘야 한다 -> 규칙
	RootComponent = Mesh;
	
	// 경로 복사를 할 때는 오브젝트 오른쪽 클릭 > 레퍼런스 경로 복사를 해줘야 한다.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));
	if (SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 시작

	// 카테고리, 로깅 수준, 형식, 인자
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 3);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.f, RotateSpped * DeltaTime, 0.f));
}

