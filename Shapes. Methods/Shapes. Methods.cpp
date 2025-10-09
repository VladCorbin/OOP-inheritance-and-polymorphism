#include <iostream>
#include <string>
#include <Windows.h>

void print_q(const int* arr, int size); // функция вывода фигур

class Figure
{
protected:
    std::string name;
    int num_sides;
public:
    Figure(const std::string& n, int sides) : name(n), num_sides(sides) {}
 
    virtual bool check() const { return true; }

    virtual void print_info() 
    {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная\n" : "Неправильная\n");
        std::cout << "Количество сторон: " << num_sides << "\n";
    }
};

class Triangle : public Figure // базовый треугольник
{
protected:
    int sides[3]; // стороны
    int angles[3]; // углы
public:
    Triangle(const std::string& n, int a, int b, int c, int A, int B, int C) : Figure(n, 3)
    {
        sides[0] = a; sides[1] = b; sides[2] = c;
        angles[0] = A; angles[1] = B; angles[2] = C;
    }

    Triangle() : Figure("Треугольник", 3)
    {
        sides[0] = 10; sides[1] = 20; sides[2] = 30;
        angles[0] = 50; angles[1] = 60; angles[2] = 70;
    }

    virtual bool check() const 
    {
        return angles[0] + angles[1] + angles[2] == 180;
    }

    void print_info()
    {
        int size{ 3 }; // количество углов
        Figure::print_info();
        std::cout << "Стороны: "; print_q(sides, size);
        std::cout << "Углы: "; print_q(angles, size);
    }
};

class right_angled_triangle : public Triangle // Прямоугольный треугольник
{
public: 
    right_angled_triangle() : Triangle("Прямоугольный треугольник", 10, 20, 30, 50, 60, 90) {}
    bool check() { return Triangle::check() && angles[2] == 90; }
};

class Isosceles_triangle : public Triangle // Равнобедренный треугольник
{
public: 
    Isosceles_triangle() : Triangle("Равнобедренный треугольник", 10, 20, 10, 50, 60, 50) {}
    bool check() { return Triangle::check() && sides[0] == sides[2] && angles[0] == angles[2]; }
};

class equilateral_triangle : public Triangle // Равносторонний треугольник
{
public: 
    equilateral_triangle() : Triangle("Равносторонний треугольник", 30, 30, 30, 60, 60, 60) {}
    bool check() 
    { 
        return Triangle::check() 
            && (sides[0] == sides[1] && sides[1] == sides[2]) &&
            (angles[0] == 60 && angles[1] == 60 && angles[2] == 60);
    }
};

class Quadrilateral : public Figure // базовый четырёхугольник
{
protected:
    int sides[4]; // стороны
    int angles[4]; // углы
public:
    Quadrilateral() : Figure("Четырёхугольник", 4)
    {
        sides[0] = 10; sides[1] = 20; sides[2] = 30; sides[3] = 40;
        angles[0] = 50; angles[1] = 60; angles[2] = 70; angles[3] = 80;
    }

    Quadrilateral(const std::string& n, int a, int b, int c, int d, int A, int B, int C, int D) : Figure(n, 4)
    {
        sides[0] = a; sides[1] = b; sides[2] = c; sides[3] = d;
        angles[0] = A; angles[1] = B; angles[2] = C; angles[3] = D;
    }

    virtual bool check()
    {
        return Figure::check() && 
            (angles[0] + angles[1] + angles[2] + angles[3] == 360);
    }

    virtual void print_info()
    {
        int size{ 4 }; // количество углов
        Figure::print_info();
        std::cout << "Стороны: "; print_q(sides, size);
        std::cout << "Углы: "; print_q(angles, size);
    }
};

class Rectangl : public Quadrilateral // Прямоугольник
{
public: Rectangl() : Quadrilateral("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {}
      bool check() 
    { 
        return Quadrilateral::check()
            && (sides[0] == sides[2] && sides[1] == sides[3]) &&
            (angles[0] == 90 && angles[1] == 90 && angles[2] == 90 && angles[3] == 90);
    }
};

class quadrate : public Quadrilateral // Квадрат
{
public:
    quadrate() : Quadrilateral("Квадрат", 20, 20, 20, 20, 90, 90, 90, 90) {}
    bool check()
    {
        return Quadrilateral::check()
            && (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3])
            && (angles[0] == 90 && angles[1] == 90 && angles[2] == 90 && angles[3] == 90);
    }
};

class Parallelogram : public Quadrilateral // Параллелограмм
{
public:
    Parallelogram() : Quadrilateral("Параллелограмм", 20, 30, 20, 30, 30, 150, 30, 150) {}
    bool check()
    {
        return Quadrilateral::check()
            && (sides[0] == sides[2] && sides[1] == sides[3])
            && (angles[0] == angles[2] && angles[1] == angles[3]);
    }
};

class Rhomb : public Quadrilateral // Ромб
{
public:
    Rhomb() : Quadrilateral("Ромб", 20, 20, 20, 20, 30, 150, 30, 150) {}
    bool check()
    {
        return Quadrilateral::check()
            && (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3])
            && (angles[0] == angles[2] && angles[1] == angles[3]);
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure s_p{ "Фигура", 0 }; // стартовая точка

    Triangle tri; // базовый триугольник
    right_angled_triangle rig; // Прямоугольный треугольник
    Isosceles_triangle Iso; // Равнобедренный треугольник
    equilateral_triangle equ; // Равносторонний треугольник

    Quadrilateral quadril; // базовый четырёхугольник
    Rectangl Rec; // Прямоугольник
    quadrate qua; // Квадрат
    Parallelogram Par; // Параллелограмм
    Rhomb Rho; // Ромб

    Figure* group[10];
    group[0] = &s_p;
    group[1] = &tri; group[2] = &rig; group[3] = &Iso; group[4] = &equ;
    group[5] = &quadril; group[6] = &Rec; group[7] = &qua; group[8] = &Par; group[9] = &Rho;

    for (int i{}; i < 10; ++i)
    {
        group[i]->print_info();
        std::cout << "\n";
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