#include "MyGameModeBase.h"
#include "MyPawn.h"

AMyGameModeBase::AMyGameModeBase()
{
    // StaticClass -> 언리얼에서 관리하는 클래스를 가지고 오는 방식
    DefaultPawnClass = AMyPawn::StaticClass();
    
}