#include "car.h"

Car::Car() :
    make("Toyota"), model("Camry"), year(2022), mileage(0) {}

Car::~Car() {}

void 
Car::Drive(int distance) {
    if (distance <= 0) {
        throw std::invalid_argument("Distance needs to be positive");
    }

    this->mileage += distance;
}

void
Car::DisplayInfo() {
    std::cout << "Display the basic car Info:\n";
    std::cout << "\tMake: " << this->make << std::endl;
    std::cout << "\tModel: " << this->model << std::endl;
    std::cout << "\tYear: " << this->year << std::endl;
    std::cout << "\tmileage: " << this->mileage << "\n" << std::endl;
}


std::string& Car::getMake() {
    return this->make;
}

std::string& Car::getModel() {
    return this->model;
}

int Car::getYear() const {
    return this->year;
}

int Car::getMileage() {
    return this->mileage;
}