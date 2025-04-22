import * as UE from 'ue'
import * as Cpp from 'cpp'
import { argv } from "puerts";

console.warn("JavaScript Entry Point Started!");

const GameInstance = argv.getByName("GameInstance") as UE.GameInstance;
const World = GameInstance?.GetWorld();

console.warn("Static Int = " + Cpp.ExampleClass.StaticInt);

const AddedResult = Cpp.ExampleClass.StaticAdd(12, 34);
console.warn("StaticAdd(12, 34) = " + AddedResult);

const ExampleClass = new Cpp.ExampleClass();
console.warn("GetRegularInt() = " + ExampleClass?.GetRegularInt());
console.warn("RegularInt = " + ExampleClass?.RegularInt);

const ExampleBaseClass = new Cpp.ExampleBaseClass();
console.warn("Base VirtualMemberFunction() = " + ExampleBaseClass?.VirtualMemberFunction());

const ExampleChildClass = new Cpp.ExampleChildClass();
console.warn("Child VirtualMemberFunction() = " + ExampleChildClass?.VirtualMemberFunction());

