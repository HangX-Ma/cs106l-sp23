# Practice with Classes

## Problem 1: The More Simple Problem

_**Problem**_

Implement a class Car that models a car. The class should have the following properties:

- Make: a string representing the make of the car (e.g. "Toyota")
- Model: a string representing the model of the car (e.g. "Camry")
- Year: an integer representing the year the car was manufactured
- Mileage: an integer representing the current mileage of the car

The class should have the following methods:

- Drive(distance: int): a method that increases the car's mileage by the specified distance
- DisplayInfo(): a method that displays the make, model, year, and mileage of the car
- Getters for the make, model, year, and mileage

In the main function, create an instance of the Car class and call the Drive and DisplayInfo methods to demonstrate their functionality.

## Problem 2: The More Complex Problem

_**Problem**_

Create a class called "DynamicArray" that contains the following attributes:

- A pointer to an array of integers
- Size of the array (int)

The class should have the following methods:

- A constructor that sets the size of the array and dynamically allocates memory for the array using the "new" operator.
- A destructor that frees the memory allocated for the array using the "delete" operator.
- A method that sets the value of each element in the array to the square of its index (e.g. array[0]=0, array[1]=1, array[2]=4, etc.).
- A method that displays the elements of the array.

Use the class in a program that creates an instance of the class and sets the size of the array. The program should then fill the array with the squares of the indices and display the elements of the array.

Example output: Array elements: 0 1 4 9 16 25 36 49 64 81 100
