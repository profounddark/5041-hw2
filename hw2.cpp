#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


const int UNSIGNED_MAXIMUM_VALUE = 65535;
const int SIGNED_MAXIMUM_VALUE = 32767;
const int SIGNED_MINIMUM_VALUE = -32768;

/**
 * positiveBinaryConvert converts a positive integer into a 16-bit binary
 * string.
 * @param numberToConvert the positive integer to convert
 * @return a string representation of a 16-bit binary number
 */
std::string positiveBinaryConverter(unsigned int numberToConvert);

std::string signedBinaryConverter(int numberToConvert);

/**
 * Prints an introductory message to the user.
 */
void printIntroMessage();

/**
 * getBoundedInteger prompts the user for an integer and returns it. If the
 * user enters an integer that is out of range, it will prompt again.
 * @return the integer that the user entered.
 */
int getBoundedInteger();




std::string positiveBinaryConverter(unsigned int numberToConvert) {
    std::string outputString = "";

    for (int i = 0; i < 16; i++) {
        outputString = std::to_string(numberToConvert % 2) + outputString;
        numberToConvert = numberToConvert / 2;
    }

    return outputString;
}

void printIntroMessage() {
    cout << "This program converts decimal integers into binary. The first "
        << "prompt will" << endl;
    cout << "convert a positive, unsigned integer and the second prompt will "
        << "convert a signed" << endl;
    cout << "integer to 2s complement." << endl;
}

int getBoundedInteger(const int& minInteger, const int& maxInteger) {
    int inputInteger;
    cout << "Please enter an integer between " << minInteger << " and "
        << maxInteger << " to be converted to binary: ";
    cin >> inputInteger;

    // this guards against out of range input
    while ((inputInteger < minInteger)
        || (inputInteger > maxInteger)) {
        cout << "Value out of range." << endl;
        cout << "Please enter a valid integer between "
            << minInteger << " and "
            << maxInteger << ":";
        cin >> inputInteger;
    }

    return inputInteger;
}

std::string signedBinaryConverter(int numberToConvert) {

    std::string resultString = "";

    if (numberToConvert >= 0) {
        resultString = positiveBinaryConverter(numberToConvert);
    } else {
        numberToConvert = -numberToConvert;
        bool isFlipped = false;
        for (int i = 0; i < 16; i++) {
            if (isFlipped) {
                resultString = std::to_string((numberToConvert + 1) % 2);
            } else {
                resultString = std::to_string(numberToConvert % 2)
                        + resultString;
                if ((numberToConvert % 2) == 1) {
                    isFlipped = true;
                }
            }
            numberToConvert = numberToConvert / 2;

        }
    }


    return resultString;
}

int main() {
    int integerToConvert = 0;

    printIntroMessage();

    // unsigned integer test
    integerToConvert = getBoundedInteger(0,
                                         UNSIGNED_MAXIMUM_VALUE);
    cout << integerToConvert << " in unsigned binary is 0b" <<
        positiveBinaryConverter(integerToConvert) << endl;

    cout << endl;


    // 2s complement signed integer test
    integerToConvert = getBoundedInteger(SIGNED_MINIMUM_VALUE,
                                         SIGNED_MAXIMUM_VALUE);
    cout << integerToConvert << " in signed 2s complement binary is 0b" <<
        signedBinaryConverter(integerToConvert) << endl;


    return 0;
}
