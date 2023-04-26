#include "car.h"

int main(int argc, char* argv[]) {
    Car car;

    car.DisplayInfo();
    car.Drive(10);
    std::cout << "Drive car ten miles. Current mileage is " << car.getMileage() << std::endl;
    car.Drive(-1);

    return 0;
}