#include <cmath> //gives us pow and sqrt!
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::pow;
using std::sqrt;
using std::string;

// want: a function named quadratic that will take in 3 doubles and return
// a combination of: does a solution exist, and if so, what is it?
// get radical, test if negative, return indicating no roots
//  radical = b^2 - 4ac

// otherwise get roots and return
//  root1 = (-b + sqrt(radical)) divided by 2a
//  root2 = (-b - sqrt(radical)) divided by 2a

std::pair<bool, std::pair<double, double>> quadratic(double a, double b, double c) {
    double radical = b * b - 4 * a * c;
    if (radical < 0) {
        return std::make_pair(false, std::make_pair(-1, -1));
    }

    double _sqrt_rad = std::sqrt(radical);
    double root1 = (-b + _sqrt_rad) / 2 / a;
    double root2 = (-b - _sqrt_rad) / 2 / a;

    return std::make_pair(true, std::make_pair(root1, root2));
}


int main() {
    // get 3 doubles (ax^2 + bx + c)
    double a, b, c;
    cout << "Give me 3 coefficients: " << endl;

    // This line gets 3 numbers from user input and stores them in a, b and c
    // we will learn more about cin on Thursday
    cin >> a >> b >> c;

    // some call to quadratic function!
    auto [found, roots] = quadratic(a, b, c);
    // get roots if they exist
    if (found) {
        std::cout << "root1 = " << roots.first << ", " 
                << "root2 = " << roots.second << std::endl; 
    } else {
        std::cout << "No solutions exist!" << std::endl;
    }

    // print accordingly
    return 0;
}

// Test: x^2 + 5x + 6 = 0, roots = -3, -2

// To run: first compile code --> make quadratic,
// then run the compiled code --> ./quadratic