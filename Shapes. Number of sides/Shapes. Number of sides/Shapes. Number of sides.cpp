#include <iostream>
#include <string>
#include <Windows.h>

class Figure
{
protected:
	
	std::string Fig;
	int sides_count;

public:
	Figure() : Fig("Фигура"), sides_count(0) {}
	Figure(std::string figure, int sides) : Fig(figure), sides_count(sides) {}

	void print_sides() const
	{
		std::cout << Fig << ": " << sides_count << std::endl;
	}

};

class Triangle : public Figure
{
public:
	
	Triangle() : Figure("Треугольник", 3) {};

	
};

class Quadrangle : public Figure
{
public:

	Quadrangle() : Figure("Четырёхугольник", 4) {};
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure s_p; // starting_point
	Triangle tri;
	Quadrangle qua;
	
	std::cout << "Количество сторон:" << std::endl;

	s_p.print_sides();
	tri.print_sides();
	qua.print_sides();
	
	return EXIT_SUCCESS;
}