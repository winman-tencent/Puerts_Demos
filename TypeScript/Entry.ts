import * as UE from 'ue'
import { argv } from "puerts";

const DemoActor = argv.getByName("DemoActor") as UE.DemoActor;

// DECLARE_DYNAMIC_DELEGATE
function OnNotifyBasic(): void {
    console.warn("BasicNotify Callback Executed.");
}
DemoActor.BasicNotify.Bind(OnNotifyBasic);
 
// DECLARE_DYNAMIC_DELEGATE_OneParam
import { $set, $unref } from "puerts";

DemoActor.NotifyWithRefString.Bind((InStringRef) => {
    console.warn("NotifyWithRefString: " + $unref(InStringRef)); // Print the value

    $set(InStringRef, "Some new string!"); // Update the value by reference
});

// DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam
DemoActor.NotifyWithStringRet.Bind((InString) => {
    return InString + " with some extra characters.";
});

// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam
function OnMulticast(InInt: number): void {
    console.warn("Multicast Callback 1: " + InInt);
}
DemoActor.MulticastNotifyWithInt.Add(OnMulticast);
DemoActor.MulticastNotifyWithInt.Add((InInt: number) => {
    console.warn("Multicast Callback 2: " + InInt);
});

// Create delegate handle owned by UObject
import {toDelegate} from 'puerts';

function PrintHelloWorld() : void {
    console.warn("Hello World!");
}
const NewDelegate = toDelegate(DemoActor, PrintHelloWorld); // toDelegate(owOwnerner: UE.Object, Func:Function)
DemoActor.PassJsFunctionAsDelegate(NewDelegate);

// Delegate handle with no owner (Manual Cleanup)
import {toManualReleaseDelegate, releaseManualReleaseDelegate} from 'puerts';

const NewManualReleaseDelegate = toManualReleaseDelegate(PrintHelloWorld); // toManualReleaseDelegate(Func:Function)
DemoActor.PassJsFunctionAsDelegate(NewManualReleaseDelegate);
releaseManualReleaseDelegate(PrintHelloWorld); // Release to prevent memory leak