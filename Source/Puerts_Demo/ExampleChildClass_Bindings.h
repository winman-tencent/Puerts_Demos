#pragma once

#include "Binding.hpp"
#include "ExampleChildClass.h"

UsingCppType(ExampleChildClass);

class ExampleChildClass_Bindings
{
public:
	ExampleChildClass_Bindings()
	{
		puerts::DefineClass<ExampleChildClass>()
			.Constructor()
			.Extends<ExampleBaseClass>()
			.Register();
	}
};

inline ExampleChildClass_Bindings ExampleChildClass_Bindings_Registrar;