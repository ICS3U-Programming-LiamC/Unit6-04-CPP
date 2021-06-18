// Copyright (c) 2021 Liam Csiffary All rights reserved.
//
// Created by: Liam Csiffary
// Date: June 18, 2021
// This program creates a data table the size that you
// define. It then fills it with numbers between 10, and 50
// Then it finds the average of these numbers

#include <time.h>
#include <iostream>
#include <cmath>
#include <list>

// function makes 2d array prints them out
// and returns the average of all the numbers
float ArrayMaker(int rows, int columns) {
    // make the variables needed
    int a2DArray[rows][columns];
    int aSingleRandomNumber;
    float total = 0;
    float numNums = 0;
    float average = 0.0;
    // construct the 2d array
    for (int rowElement = 0; rowElement < rows; rowElement++) {
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            // picks a random number between 10 and 50
            aSingleRandomNumber = (rand() % 40) + 10;
            // adds the number to specific spot in the array
            a2DArray[rowElement][columnElement] = aSingleRandomNumber;
            // prints it to the user
            std::cout << aSingleRandomNumber << " ";
            // adds to the total for the average
            total = total + aSingleRandomNumber;
            numNums = numNums + 1;
        }
        // goes down a line when one array is done
        std::cout << std::endl;
    }
    // calcualte and return the average
    average = total / numNums;
    return average;
}


int main() {
    std::cout << "This program makes a 2d array based on the size you input";
    std::cout << "\nit then prints it to you and finds the average.\n";
    // make the string version of the var
    std::string numRowStr;
    std::string numColumnsStr;

    int numRows;
    int numColumns;
    // get the number from the user
    std::cout << "How many rows do you want: ";
    std::cin >> numRowStr;
    std::cout << "How many colomns do you want: ";
    std::cin >> numColumnsStr;
    try {
        // try to turn it into a integer
        numRows = std::stoi(numRowStr);
        numColumns = std::stoi(numColumnsStr);
        float average;

        average = ArrayMaker(numRows, numColumns);
        std::cout << "Your average is " << average;

    // if could not turn into integer
    } catch (std::invalid_argument) {
        std::cout << "This is not a valid number";
    }
}
