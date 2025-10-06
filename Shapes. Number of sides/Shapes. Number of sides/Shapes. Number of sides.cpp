#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

class Address
{
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    Address(const std::string& c, const std::string& s, int h, int a)
        : city(c), street(s), house(h), apartment(a) {
    }

    std::string get_output_address() const
    {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }
};





int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   







    return EXIT_SUCCESS;
}
