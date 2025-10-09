#include <iostream>
#include <string>
#include <Windows.h>

void print_q(const int* arr, int size); // функция вывода фигур

class Figure 
{
protected:
	std::string name;
public:
	Figure(const std::string& n) : name(n) {}
	virtual void print_info() = 0;
};

class Triangle : public Figure // базовый треугольник
{
protected:
	int sides[3]; // стороны
	int angles[3]; // углы
public:
	Triangle() : Figure("Треугольник")
	{
		sides[0] = 10; sides[1] = 20; sides[2] = 30;
		angles[0] = 50; angles[1] = 60; angles[2] = 70;
	}
	Triangle(const std::string& n, int a, int b, int c, int A, int B, int C) : Figure(n) 
	{
		sides[0] = a; sides[1] = b; sides[2] = c;
		angles[0] = A; angles[1] = B; angles[2] = C;
	}
	virtual void print_info() 
	{
		int size{ 3 }; // количество углов
		std::cout << name << ":\n";
		std::cout << "Стороны: "; print_q(sides, size);
		std::cout << "Углы: "; print_q(sides, size);
	}
};

class right_angled_triangle : public Triangle
{
public:

	// Конструктор прямоугольного треугольника
	right_angled_triangle() : Triangle("Прямоугольный треугольник") 
	{
		// Инициализация сторон и углов
		sides[0] = 10; sides[1] = 20; sides[2] = 30;
		angles[0] = 50; angles[1] = 60; angles[2] = 90;
	}
};


class Quadrilateral : public Figure // базовый четырёхугольник
{
protected:
	int sides[4]; // стороны
	int angles[4]; // углы
public:
	Quadrilateral() : Figure("Четырёхугольник")
	{
		sides[0] = 10; sides[1] = 20; sides[2] = 30; sides[3] = 40;
		angles[0] = 50; angles[1] = 60; angles[2] = 70; angles[3] = 80;
	}
	Quadrilateral(const std::string& n, int a, int b, int c, int d, int A, int B, int C, int D) : Figure(n)
	{
		sides[0] = a; sides[1] = b; sides[2] = c; sides[3] = d;
		angles[0] = A; angles[1] = B; angles[2] = C; angles[3] = D;
	}
	virtual void print_info()
	{
		int size{ 4 }; // количество углов
		std::cout << name << ":\n";
		std::cout << "Стороны: "; print_q(sides, size);
		std::cout << "Углы: "; print_q(sides, size);
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	Triangle tri;
	Quadrilateral qua;

	qua.print_info();
	tri.print_info();
	

	return EXIT_SUCCESS;
}

void print_q(const int* arr, int size)
{
	for (int j{ 0 }; j < size; ++j)
	{
		if (j == 0) { std::cout << "A="; }
		else if (j == 1) { std::cout << "B="; }
		else if (j == 2) { std::cout << "C="; }
		else if (j == 3) { std::cout << "D="; }

		std::cout << arr[j] << " ";
	}
	std::cout << std::endl;
}