#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


const int MAXIMUM_VALUE = 65536;

std::string positiveBinaryConverter(unsigned int numberToConvert);
std::string signedBinaryConverter(int numberToConvert);



std::string positiveBinaryConverter(unsigned int numberToConvert) {
    std::string outputString = "";

    while (numberToConvert > 0) {
        outputString = std::to_string(numberToConvert % 2) + outputString;
        numberToConvert = numberToConvert / 2;

    }

    return outputString;
}

std::string signedBinaryConverter(int numberToConvert) {
    std::string outputString = "";

    if (numberToConvert > 0) {
        outputString = positiveBinaryConverter(numberToConvert);
    }
    else {
        numberToConvert = -numberToConvert;
        bool hasFlipped = false;
        while (numberToConvert != 0) {
            char nextBit;
            if (hasFlipped) {
                nextBit = (numberToConvert + 1) % 2;
            } else {
                nextBit = numberToConvert % 2;
                if (nextBit == '1') {
                    hasFlipped = true;
                }
            }


            outputString = std::to_string(nextBit) + outputString;
            numberToConvert = numberToConvert / 2;

        }
    }

    return outputString;
}


int main() {
    unsigned int positiveInputValue;
    cout << "Please enter a positive integer less than "
        << MAXIMUM_VALUE << ": ";
    cin >> positiveInputValue;
    cout << "The binary conversion of that number is "
         << positiveBinaryConverter(positiveInputValue)
         << "." << endl;


/*
 *  THIS DOES NOT WORK
 *  int signedInputValue;
 *  cout << "Please enter an integer (positive or negative!): ";
 *  cin >> signedInputValue;
 *  cout << "The 2s complement binary conversion of that number is "
 *      << signedBinaryConverter(signedInputValue) << endl;
 *      */


    return 0;
}
