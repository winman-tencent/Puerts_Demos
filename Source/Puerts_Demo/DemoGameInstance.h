#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "JsEnv.h"
#include "DemoGameInstance.generated.h"

UCLASS()
class PUERTS_DEMO_API UDemoGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void OnStart() override {
		Super::OnStart();
		JsEnv = MakeShared<puerts::FJsEnv>();

		JsEnv->Start("Entry.js", 
		{
			TPair<FString, UObject*>("GameInstance", this)
		});
	}

	virtual void Shutdown() override {
		Super::Shutdown();
		JsEnv.Reset();
	}

protected:
	TSharedPtr<puerts::FJsEnv> JsEnv;
};
