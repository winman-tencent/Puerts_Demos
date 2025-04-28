#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DemoActor.generated.h"

DECLARE_DYNAMIC_DELEGATE(FBasicNotify);
DECLARE_DYNAMIC_DELEGATE_OneParam(FNotifyWithRefString, FString&, InStringRef);
DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(FString, FNotifyWithStringRet, FString, InString);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMulticastNotifyWithInt, int32, InInt);

UCLASS()
class ADemoActor : public AActor
{
	GENERATED_BODY()
	
public:	
	virtual void BeginPlay() override {
		// DECLARE_DYNAMIC_DELEGATE
		BasicNotify.ExecuteIfBound();

		// DECLARE_DYNAMIC_DELEGATE_OneParam
		if (NotifyWithRefString.IsBound())
		{
			FString StringReference = "Example String...";
			NotifyWithRefString.Execute(StringReference);
		}

		// DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam
		if (NotifyWithStringRet.IsBound())
		{
			FString ReturnedString = NotifyWithStringRet.Execute("Example string");
			UE_LOG(LogTemp, Warning, TEXT("ReturnedString: %s"), *ReturnedString); // "Example string" + " with some extra characters"
		}

		// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam
		MulticastNotifyWithInt.Broadcast(1337);
	}

	UFUNCTION()
	void PassJsFunctionAsDelegate(FBasicNotify Callback)
	{
		Callback.ExecuteIfBound();
	}

public:
	UPROPERTY()
	FBasicNotify BasicNotify;

	UPROPERTY()
	FNotifyWithRefString NotifyWithRefString;

	UPROPERTY()
	FNotifyWithStringRet NotifyWithStringRet;
	
	UPROPERTY()
	FMulticastNotifyWithInt MulticastNotifyWithInt;
};
