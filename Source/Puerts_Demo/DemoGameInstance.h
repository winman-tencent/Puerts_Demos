#pragma once

#include "CoreMinimal.h"
#include "DemoActor.h"
#include "Engine/GameInstance.h"
#include "JsEnv.h"
#include "DemoGameInstance.generated.h"

UCLASS()
class UDemoGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void OnStart() override {
		Super::OnStart();
		JsEnv = MakeShared<puerts::FJsEnv>();

		auto DemoActor = GetWorld()->SpawnActorDeferred<ADemoActor>(ADemoActor::StaticClass(), FTransform::Identity);
		
		JsEnv->Start("Entry.js", 
		{
			TPair<FString, UObject*>("DemoActor", DemoActor)
		});

		DemoActor->FinishSpawning(FTransform::Identity);
	}

	virtual void Shutdown() override {
		Super::Shutdown();
		JsEnv.Reset();
	}

protected:
	TSharedPtr<puerts::FJsEnv> JsEnv;
};
