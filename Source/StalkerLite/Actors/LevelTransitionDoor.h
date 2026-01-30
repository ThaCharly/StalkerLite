#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelTransitionDoor.generated.h"

UCLASS()
class STALKERLITE_API ALevelTransitionDoor : public AActor
{
    GENERATED_BODY()

public:
    ALevelTransitionDoor();

    UFUNCTION()
    void Use();

    UPROPERTY(EditAnywhere, Category = "Level")
    FName TargetLevel;

    UPROPERTY(VisibleAnywhere)
    class USceneComponent* ExitPoint;


};
