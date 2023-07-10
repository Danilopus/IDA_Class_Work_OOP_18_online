#pragma once
#include <vector>
#include <string>

#include "Service functions.h"

class Auto_ptr
{
	int* _data;
public:
	Auto_ptr(int* data): _data(data) {}
	~Auto_ptr() { delete _data; }
};

//class SomeClass {};

class Object
{
	int _a;
	float _b;

	// такое поле позволяет хранить наследников (для использования полиморфизма)
	// контролирует время жизни объекта
	// std::unique_ptr <SomeClass> p_obj;

public:
	Object() = default;
	//Object() {std::cout <<;
	Object(int a, float b): _a(a), _b(b) {}
	~Object() = default;
	//virtual ~Object() = default;
};

class Derived : public Object
{
	int* p;
public:
	Derived(int val1, float val2) : Object(3, .3){}
};
