#include <iostream>
#include <string>
#include <system_error>

class Car {
public:
    Car();
    ~Car();

    void Drive(int distance);
    void DisplayInfo();

    // getters
    std::string& getMake();
    std::string& getModel();
    int getYear() const;
    int getMileage();

private:
    std::string make;
    std::string model;
    int year;
    int mileage;
};