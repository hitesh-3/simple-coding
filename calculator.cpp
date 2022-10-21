/*
 * calculator.cpp
 *
 * @details
  This menu-driven programme executes various calculation operations, such as arithmetic operations, trigonometric operations, logarithmic operations, and powers. It accepts operands from the user and executes the selected operator on those operands to produce the desired result.
 * Author: [Sahil Kandhare](https://github.com/SahilK-027)
 * Created on 21/10/2002
 *
 *
 * Calculator in cpp
 *
 * Compiled in Visual Studio Code
 *
 */

#include <iostream> /// iostream provides basic input and output services for C++ programs
#include <math.h>   /// for basic mathematical operations.
#define Pi 3.142    /// for creating constants that represent number value of pi
using namespace std;
/**
 * @brief Class ArithmeaticValue
 */
class ArithmeaticValue
{
public:
    float value1, value2;
    /**
     * @brief   Takes the values of numbers
     * @returns void
     */
    void values()
    {
        cout << "Enter the first digit : ";
        cin >> value1;
        cout << "Enter the second digit : ";
        cin >> value2;
    }
};

// class Arithmatic_calculation publically inherits class ArithmeaticValue
class Arithmatic_calculation : public ArithmeaticValue
{
public:
    float result;

    /**
     * @brief   function which performs the calculations
     * @returns void
     */
    void operation(int val)
    {

        switch (val)
        {
        case 1:
            result = value1 + value2;
            break;
        case 2:
            result = value1 / value2;
            break;
        case 3:
            result = value1 * value2;
            break;
        case 4:
            result = value1 - value2;
            break;
        default:
            cout << "Wrong Entry.";
        }
    }
    /**
     * @brief   function to display the result
     * @returns void
     */
    void display()
    {
        cout << "Result : " << result << endl;
    }
};

/**
 * @brief Class TrignometricValue
 */
class TrignometricValue
{
public:
    int angle;
    /**
     * @brief   Takes the values of angles
     * @returns void
     */
    void angles()
    {
        cout << "Enter the angle: ";
        cin >> angle;
    }
};

// class Trignometric_calculation publically inherits class TrignometricValue
class Trignometric_calculation : public TrignometricValue
{
public:
    float result;
    /**
     * @brief   function which performs the calculations
     * @returns void
     */
    void operation(int val)
    {

        switch (val)
        {
        case 1:
            result = sin(angle);
            break;
        case 2:
            result = cos(angle);
            break;
        case 3:
            result = tan(angle);
            break;

        default:
            cout << "Wrong Entry.";
        }
    }
    /**
     * @brief   function to display the result
     * @returns void
     */
    void display()
    {
        cout << "Result : " << result << endl;
    }
};

/**
 * @brief Class logarithmicValue
 */
class logarithmicValue
{
public:
    int number;

    /**
     * @brief   Takes the value of number for which log is to be calculated
     * @returns void
     */
    void numbers()
    {
        cout << "Enter the number to find log: ";
        cin >> number;
    }
};

// class Logarithmic_calculation publically inherits class logarithmicValue
class Logarithmic_calculation : public logarithmicValue
{
public:
    float result;
    /**
     * @brief   function which performs the calculations
     * @returns void
     */
    void operation(int val)
    {

        switch (val)
        {
        case 1:
            result = log(number);
            break;
        case 2:
            result = log10(number);
            break;
        default:
            cout << "Wrong Entry.";
        }
    }
    /**
     * @brief   function to display the result
     * @returns void
     */
    void display()
    {
        cout << "Result : " << result << endl;
    }
};

/**
 * @brief Class UnaryValue
 */
class UnaryValue
{
public:
    int numb, power;
    /**
     * @brief   Takes the value of number for which power is to be calculated
     * @returns void
     */
    void number()
    {
        cout << "Enter the number to find power: ";
        cin >> numb;
    }
    void Power()
    {
        cout << "Enter the exponent ";
        cin >> power;
    }
};

// class Exponent_calculation publically inherits class UnaryValue
class Exponent_calculation : public UnaryValue
{
    char ans;

public:
    float result;
    /**
     * @brief   function which performs the calculations
     * @returns void
     */
    void operation(int val)
    {

        switch (val)
        {
        case 1:
            result = pow(numb, power);
            break;
        case 2:
            result = sqrt(numb);
            break;
        default:
            cout << "Wrong Entry.";
            break;
        }
    }
    /**
     * @brief   function to display the result
     * @returns void
     */
    void display()
    {
        cout << "Result : " << result << endl;
    }
};

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    int choice, choice2, choice3, choice4;
    Arithmatic_calculation calc;
    Trignometric_calculation calc2;
    Logarithmic_calculation calc3;
    Exponent_calculation calc4;

    int flag = 1;
    while (flag)
    {
        cout << endl << endl;
        cout << "What do you want to perform\n";
        cout << "1) Arithmatic Operations\n";
        cout << "2) Trigonometric Oprerations\n";
        cout << "3) Logarithmic Operations\n";
        cout << "4) Powers\n";
        cout << "5) Exit\n";
        cout << "Enter your choice" << endl;
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            calc.values();
            cout << "Enter\n'1' for addition\n'2' for division\n'3' for multiplication\n'4' for subtraction";
            cout << "\nEnter the choice: ";
            cin >> choice;
            calc.operation(choice);
            calc.display();
            break;
        case 2:
            calc2.angles();
            cout << "Enter\n'1' for sin\n'2' for cos\n'3' for tan\n";
            cout << "\nEnter the choice: ";
            cin >> choice2;
            calc2.operation(choice2);
            calc2.display();
            break;
        case 3:
            calc3.numbers();
            cout << "Enter\n'1' for natural log\n'2' common log";
            cout << "\nEnter the choice: ";
            cin >> choice3;
            calc3.operation(choice3);
            calc3.display();
            break;
        case 4:
            calc4.number();
            calc4.Power();
            cout << "Enter\n'1' for finding power\n'2' for square root\n";
            cout << "\nEnter the choice: ";
            cin >> choice4;
            calc4.operation(choice4);
            calc4.display();
            break;
        case 5:
            flag = 0;
        default:
            break;
        }
    }
    return 0;
}
