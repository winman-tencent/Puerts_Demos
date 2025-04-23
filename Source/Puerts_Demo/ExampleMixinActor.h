#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExampleMixinActor.generated.h"

UCLASS()
class AExampleMixinActor : public AActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent)
	void ExampleFunction();
	void ExampleFunction_Implementation()
	{
		UE_LOG(LogTemp, Warning, TEXT("AExampleMixinActor::ExampleFunction() Executed"));
	}
};
