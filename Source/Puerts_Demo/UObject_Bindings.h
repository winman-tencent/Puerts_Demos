#pragma once

#include "Binding.hpp"
#include "UEDataBinding.hpp"

UsingUClass(UObject)
UsingUClass(UWorld)
UsingUClass(UClass)

class UObject_Bindings
{
public:
	UObject_Bindings()
	{
		puerts::DefineClass<UObject>()
			.Method("GetWorld", MakeFunction(&UObject::GetWorld))
			.Method("GetClass", MakeFunction(&UObject::GetClass))
			.Method("IsValid", MakeFunction(&UObject::IsValidLowLevel))
			.Register();
	}
};

inline UObject_Bindings UObject_Bindings_Registrar;
