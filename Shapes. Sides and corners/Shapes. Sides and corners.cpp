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
    Triangle(const std::string& n, int a, int b, int c, int A, int B, int C) : Figure(n)
    {
        sides[0] = a; sides[1] = b; sides[2] = c;
        angles[0] = A; angles[1] = B; angles[2] = C;
    }

    Triangle() : Figure("Треугольник")
    {
        sides[0] = 10; sides[1] = 20; sides[2] = 30;
        angles[0] = 50; angles[1] = 60; angles[2] = 70;
    }

    virtual void print_info()
    {
        int size{ 3 }; // количество углов
        std::cout << name << ":\n";
        std::cout << "Стороны: "; print_q(sides, size);
        std::cout << "Углы: "; print_q(angles, size);
    }
};

class right_angled_triangle : public Triangle // Прямоугольный треугольник
{ public: right_angled_triangle() : Triangle("Прямоугольный треугольник", 10, 20, 30, 50, 60, 90) {} };

class Isosceles_triangle : public Triangle // Равнобедренный треугольник
{ public: Isosceles_triangle() : Triangle("Равнобедренный треугольник", 10, 20, 10, 50, 60, 50) {} };

class equilateral_triangle : public Triangle // Равносторонний треугольник
{ public: equilateral_triangle() : Triangle("Равносторонний треугольник", 30, 30, 30, 60, 60, 60) {} };

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
        std::cout << "Углы: "; print_q(angles, size);
    }
};

class Rectangl : public Quadrilateral // Прямоугольник
{ public: Rectangl() : Quadrilateral("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {} };

class quadrate : public Quadrilateral // Квадрат
{ public: quadrate() : Quadrilateral("Квадрат", 20, 20, 20, 20, 90, 90, 90, 90) {} };

class Parallelogram : public Quadrilateral // Параллелограмм
{ public: Parallelogram() : Quadrilateral("Параллелограмм", 20, 30, 20, 30, 30, 40, 30, 40) {} };

class Rhomb : public Quadrilateral // Ромб
{ public: Rhomb() : Quadrilateral("Ромб", 20, 30, 20, 30, 30, 40, 30, 40) {} };

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangle tri; // базовый триугольник
    right_angled_triangle rig; // Прямоугольный треугольник
    Isosceles_triangle Iso; // Равнобедренный треугольник
    equilateral_triangle equ; // Равносторонний треугольник

    Quadrilateral quadril; // базовый четырёхугольник
    Rectangl Rec; // Прямоугольник
    quadrate qua; // Квадрат
    Parallelogram Par; // Параллелограмм
    Rhomb Rho; // Ромб

    Figure* group[9];
    group[0] = &tri; group[1] = &rig; group[2] = &Iso; group[3] = &equ;
    group[4] = &quadril; group[5] = &Rec; group[6] = &qua; group[7] = &Par; group[8] = &Rho;

    for (int i{}; i < 9; ++i)
    {
        group[i]->print_info();
    }

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