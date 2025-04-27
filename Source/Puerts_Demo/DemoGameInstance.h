#pragma once

#include "CoreMinimal.h"
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
        
        JsEnv = MakeShared<puerts::FJsEnv>(
          std::make_unique<puerts::DefaultJSModuleLoader>(TEXT("JavaScript")), // Specifies the default script location (Default: "Content/JavaScript")
          std::make_shared<puerts::FDefaultLogger>(), // A logger object to catch console.log
          8080 // The port to start the debugger on (i.e. Attach to this with VSCode)
        );

        // Optionally wait for the debugger to attach
        JsEnv->WaitDebugger(1);

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