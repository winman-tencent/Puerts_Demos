#pragma once

#include "ExampleBaseClass.h"

class ExampleChildClass : public ExampleBaseClass
{
public:
	virtual int VirtualMemberFunction() override
	{
		return 1337;
	}
};
