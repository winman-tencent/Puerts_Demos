import * as UE from 'ue'
import * as Puerts from 'puerts'

const GameInstance = Puerts.argv.getByName("GameInstance") as UE.GameInstance;
const World = GameInstance?.GetWorld();

// Mixin With C++ Class
{
    interface ExtendedMixinActor extends UE.ExampleMixinActor {};
    class ExtendedMixinActor implements ExtendedMixinActor {
        ExampleFunction(): void 
        {
            console.warn("ExtendedMixinActor::ExampleFunction() Executed");
        }
    }

    // Generate The Mixin Class
    const GeneratedClass = Puerts.blueprint.mixin(UE.ExampleMixinActor, ExtendedMixinActor, {
        inherit: true // 'true' generated a new class object instead of applying mixin globally
    }).StaticClass();

    // Spawn the actor from mixin class
    const SpawnedActor = UE.GameplayStatics.BeginDeferredActorSpawnFromClass(World, GeneratedClass, UE.Transform.Identity) as ExtendedMixinActor;
    UE.GameplayStatics.FinishSpawningActor(SpawnedActor, UE.Transform.Identity);

    SpawnedActor?.ExampleFunction();
}

// Mixin With Blueprint Class
{
    interface ExtendedMixinBlueprint extends UE.Game.ExampleMixinBlueprint.ExampleMixinBlueprint_C {};
    class ExtendedMixinBlueprint implements ExtendedMixinBlueprint {
        ExampleBlueprintFunction(): void {
            console.warn("ExtendedMixinBlueprint::ExampleBlueprintFunction() Executed");
        }
    }
    
    // Load In The Class To Extend
    let BlueprintClass = UE.Class.Load('/Game/ExampleMixinBlueprint.ExampleMixinBlueprint_C');
    const InterperatedBlueprintClass = Puerts.blueprint.tojs(BlueprintClass);

    // Generate The Mixin Class
    const GeneratedClass = Puerts.blueprint.mixin(InterperatedBlueprintClass, ExtendedMixinBlueprint, {
        inherit: true // 'true' generated a new class object instead of applying mixin globally
    }).StaticClass();

    // Spawn the actor from mixin class
    const SpawnedActor = UE.GameplayStatics.BeginDeferredActorSpawnFromClass(World, GeneratedClass, UE.Transform.Identity) as ExtendedMixinBlueprint;
    UE.GameplayStatics.FinishSpawningActor(SpawnedActor, UE.Transform.Identity);
    
    SpawnedActor?.ExampleBlueprintFunction();
}

// Mixin with `Super` keyword
{
    interface ExampleMixinActor extends UE.ExampleMixinActor {};
    class ExampleMixinActor implements ExampleMixinActor {}
    Object.setPrototypeOf(ExampleMixinActor.prototype, UE.ExampleMixinActor.prototype);

    class ExtendedMixinActor extends ExampleMixinActor {
        ExampleFunction(): void 
        {
            console.warn("ExtendedMixinActor: Attempting to call Super.ExampleFunction()");
            super.ExampleFunction();
        }
    }

    // Generate The Mixin Class
    const GeneratedClass = Puerts.blueprint.mixin(UE.ExampleMixinActor, ExtendedMixinActor, {
        inherit: true // 'true' generated a new class object instead of applying mixin globally
    }).StaticClass();

    // Spawn the actor from mixin class
    const SpawnedActor = UE.GameplayStatics.BeginDeferredActorSpawnFromClass(World, GeneratedClass, UE.Transform.Identity) as ExtendedMixinActor;
    UE.GameplayStatics.FinishSpawningActor(SpawnedActor, UE.Transform.Identity);

    SpawnedActor?.ExampleFunction();
}