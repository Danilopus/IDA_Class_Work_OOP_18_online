//class template version 5.0 //07.07.2023//
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//My own headers
#include "Service functions.h"
#include "Task_1.h"



// Class Work 10.07.2023 online -------------------------------------------	

// Умные указатели

// Сферы использования обычных (сырых) указателей:
/*
1. Оперировать данными, а не копиями (лучше подходят ссылки)
2. Хранение местоположений блоков памяти (важное свойство типа данных указатель)
3. Управлением временем жизни объектов (использование new / delete)
4. Полиморфные вызовы

#include <memory> библиотека умных указателей

std::unique_ptr;
используется для полиморфного и прямого хранения полей класса в куче

std::shared_ptr;
std::weak_ptr;
std::auto_ptr; // C++17 - deprecated / C++ - deleted


// Создание собственных умных указателей:
1. Собственные менеджеры памяти для программы
2. Нестандартное поведение указателей



//Менеджеры памяти

std::vector <int, allocator <traits>> vector_1;
 allocator: 
 - правильно выделяет память под нужные типы
 - содержит модель работы с памятью





*/


#include <memory>
//#include <>

//Task 1
void F01(std::unique_ptr<Object>& obj) {}
//void F02(const Object& obj) {}

void Task_1()
{
	//потенциально опасный элемент
	//std::auto_ptr<int> auto_ptr;

	std::unique_ptr<Object> p_uniq = std::make_unique<Object>(3, 0.3);

	//auto p_uniq_2 = std::make_unique<Object>(3, 0.3); уже не дает создать

	// auto p_uniq_3 = p_uniq // Конструктор копирования удален

	F01(p_uniq);
	//F02(*p_uniq);

	std::vector<Object> vector;
	vector.push_back(Object(2, .5));
	vector.push_back(Derived(2, .5)); //утечка  памяти - из-за хранения объектов как родительский класс у Derived не будет вызван конструктор

	vector.emplace_back(2, .5);
	vector.emplace_back(Derived(2, .5)); 

}





//Task 2
void Task_2()
{
	std::vector<std::unique_ptr<Object>> vector;
	
	std::unique_ptr<Object> uniq_ptr = std::make_unique<Object>(5, .5);
	
	vector.push_back(std::make_unique<Object>(2, .5));
	vector.push_back(std::make_unique<Derived>(2, .5));

	vector.emplace_back(std::make_unique<Object>(2, .5));
	vector.emplace_back(std::make_unique<Derived>(2, .5));


}
//Task 3
void Task_3()
{

}


// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
srand(time(NULL));
		
	
Task_1();
Task_2();
Task_3();





std::cout << "\n\n";
//system("pause");	
_getch();
}


