#pragma once

class ExampleClass
{
public:
	ExampleClass() {}
	ExampleClass(int InRegularInt)
	{
		RegularInt = InRegularInt;
	}
	
	// Static
public:
	static int StaticAdd(int a, int b)
	{
		return a + b;
	}

	inline static int StaticInt{30035};

	// Non-Static
public:
	int GetRegularInt() const
	{
		return RegularInt;
	}

	int RegularInt{1337};
};