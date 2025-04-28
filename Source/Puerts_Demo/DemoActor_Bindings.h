#pragma once

#include "DemoActor.h"
#include "Binding.hpp"
#include "UEDataBinding.hpp"

UsingUClass(ADemoActor)

class DemoActor_Bindings
{
	public:
		DemoActor_Bindings()
		{
			puerts::DefineClass<ADemoActor>()
				.Function("PassJsFunctionWithStd", MakeFunction(&ADemoActor::PassJsFunctionWithStd))
				.Register();
		}
};

inline DemoActor_Bindings DemoActor_Bindings_Registrar;