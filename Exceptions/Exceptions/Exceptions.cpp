// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <vector>


using namespace std;

bool do_even_more_custom_application_logic()
{

    //subtracting value1 and value 2 to see if an underflow occurs
    std::cout << "Running Even More Custom Application Logic." << std::endl;
    int value1 = 10;
    int value2 = 1000000000000000;


        if ((INT_MIN + value2) > value1)
            throw std::underflow_error("Underflow exception!");
        std::cout << (value1 - value2) << endl;

    return true;
}
void do_custom_application_logic()
{


    //wrapped the do_even_more_custom_application_logic() in a try and added a catch for an standard exception
    std::cout << "Running Custom Application Logic." << std::endl;
    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
            throw std::exception("Standard Exception");
            
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << endl;
    }

    //creating an out of range exception for the application


        std::vector<int> myVector(10);
        myVector.at(11) = 100;
        throw std::out_of_range("Out of Range Exception");


    std::cout << "Leaving Custom Application Logic." << std::endl;
    


}

float divide(float num, float den)
{

    //using a try to catch an overflow exception and reporting the error
    try {
        if (den == 0) 
            throw std::overflow_error("Divide by zero exception!");
        return (num / den);
        
    }
    catch (std::overflow_error& e) {
        std::cout << e.what() << endl;
        return (num / den);
    }
}

void do_division() noexcept
{

    float numerator = 10.0f;
    float denominator = 0;
    //created a try block to test and than catch the exception thrown by dividing by zero
    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
        if (denominator == 0) {
            throw "dividing by zero!";
        }
    } 
    catch (const char* msg) {
        std::cout << "Standard Exception: " << msg << std::endl;
    }
}

int main()
{
    try {
        std::cout << "Exceptions Tests!" << std::endl;


        do_division();
        //trying the more custome application and catching the error if any
        try {
            do_even_more_custom_application_logic();
        }
        catch (std::underflow_error& e)
        {
            std::cout << e.what() << endl;

        };
        //trying the do custome application and catching the out of range exception
        try {
            do_custom_application_logic();
        }
        catch (std::out_of_range& e) {
            std::cout << e.what() << endl;
        }
        throw uncaught_exception();
    }
    //catching all exceptions incase something is missed
    catch (...) {
        std::cout << "Catching all exceptions" << endl;

    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu