#pragma once

#include "Binding.hpp"
#include "ExampleBaseClass.h"

UsingCppType(ExampleBaseClass);

class ExampleBaseClass_Bindings
{
public:
	ExampleBaseClass_Bindings()
	{
		puerts::DefineClass<ExampleBaseClass>()
			.Constructor()
			.Method("VirtualMemberFunction", MakeFunction(&ExampleBaseClass::VirtualMemberFunction))
			.Register();
	}
};

inline ExampleBaseClass_Bindings ExampleBaseClass_Bindings_Registrar;