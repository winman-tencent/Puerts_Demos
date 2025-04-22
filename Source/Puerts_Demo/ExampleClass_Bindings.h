#pragma once

#include "Binding.hpp"
#include "ExampleClass.h"

UsingCppType(ExampleClass);

class ExampleClass_Bindings
{
public:
	ExampleClass_Bindings()
	{
		puerts::DefineClass<ExampleClass>()
			.Constructor(
				CombineConstructors(
					MakeConstructor(ExampleClass),
					MakeConstructor(ExampleClass, int)
				))
			.Function("StaticAdd", MakeFunction(&ExampleClass::StaticAdd))          // Static Function
			.Variable("StaticInt", MakeVariable(&ExampleClass::StaticInt))          // Static Variable
			.Method("GetRegularInt", MakeFunction(&ExampleClass::GetRegularInt))    // Member Function
			.Property("RegularInt", MakeProperty(&ExampleClass::RegularInt))        // Member Variable
			.Register();
	}
};

inline ExampleClass_Bindings ExampleClass_Bindings_Registrar;
