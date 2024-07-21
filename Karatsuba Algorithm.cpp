/*
This program implements basic arithmetic operations (addition and multiplication) for numbers
represented in a specified base using functions that handle conversion, addition, subtraction,
left shift, and multiplication using the Karatsuba algorithm. The input consists of two numbers
and a base, and the output includes the sum, product, and a placeholder value.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

// Convert a decimal value to a string representation in a specified number base
std::string conDecimal(int deciVal, int numberBase) {
    std::string output = "";
    while (deciVal > 0 || output.empty()) {
        int remVal = deciVal % numberBase;
        output = std::to_string(remVal) + output;
        deciVal /= numberBase;
    }
    return output;
}

// Add two numbers represented in a specified base
std::string addBO(const std::string &firstNumber, const std::string &secondNumber, int numberBase) {
    std::string output = "";
    int carOver = 0;

    // Lengths of input numbers
    int lengthFirst = firstNumber.length();
    int lengthSecond = secondNumber.length();
    // Maximum length
    int maxLength = std::max(lengthFirst, lengthSecond);

    // Addition
    int i = 0;
    while (i < maxLength || carOver) {
        int dF = i < lengthFirst ? firstNumber[lengthFirst - 1 - i] - '0' : 0;
        int dS = i < lengthSecond ? secondNumber[lengthSecond - 1 - i] - '0' : 0;
        int sum = dF + dS + carOver;
        carOver = sum / numberBase;
        output.push_back(sum % numberBase + '0');
        ++i;
    }
    std::reverse(output.begin(), output.end());
    return output;
}

// Subtract two numbers represented in a base
std::string subString(const std::string &firstNumber, const std::string &secondNumber, int numberBase) {
    std::string output = "";
    int brrow = 0;

    int lengthFirst = firstNumber.length();
    int lengthSecond = secondNumber.length();
    int maxLength = std::max(lengthFirst, lengthSecond);

    int i = 0;
    // Subtraction loop
    while (i < maxLength) {
        int dF = i < lengthFirst ? firstNumber[lengthFirst - 1 - i] - '0' : 0;
        int dS = i < lengthSecond ? secondNumber[lengthSecond - 1 - i] - '0' : 0;
        int difference = dF - dS - brrow;
        if (difference < 0) {
            difference += numberBase;
            brrow = 1;
        } else {
            brrow = 0;
        }
        output.push_back(difference + '0');
        ++i;
    }

    // Remove leading zeros
    while (output.size() > 1 && output.back() == '0') {
        output.pop_back();
    }

    // Reverse result to get correct order
    std::reverse(output.begin(), output.end());
    return output;
}

// Shift the digits of a number to the left by a given number of positions
std::string leftS(const std::string &num, int positions) {
    std::string shiftedNumber = num;
    int i = 0;
    while (i < positions) {
        shiftedNumber.push_back('0');
        ++i;
    }
    return shiftedNumber;
}

// Multiply two numbers using the Karatsuba algorithm in a specific base
std::string karatsubaMult(const std::string &firstNumber, const std::string &secondNumber, int numberBase) {
    int lengthFirst = firstNumber.length();
    int lengthSecond = secondNumber.length();

    // Recursion: when both numbers are single digits, perform simple multiplication
    if (lengthFirst == 1 && lengthSecond == 1) {
        int product = (firstNumber[0] - '0') * (secondNumber[0] - '0');
        return conDecimal(product, numberBase);
    }

    // Calculate maximum and half lengths
    int maxLength = std::max(lengthFirst, lengthSecond);
    int halfLength = maxLength / 2;

    // Divide numbers into halves
    std::string firstHalfNum1 = lengthFirst <= halfLength ? "0" : firstNumber.substr(0, lengthFirst - halfLength);
    std::string secondHalfNum1 = lengthFirst <= halfLength ? firstNumber : firstNumber.substr(lengthFirst - halfLength);

    std::string firstHalfNum2 = lengthSecond <= halfLength ? "0" : secondNumber.substr(0, lengthSecond - halfLength);
    std::string secondHalfNum2 = lengthSecond <= halfLength ? secondNumber : secondNumber.substr(lengthSecond - halfLength);

    // Recursively calculate products
    std::string productFirstHalf = karatsubaMult(firstHalfNum1, firstHalfNum2, numberBase);
    std::string productSecondHalf = karatsubaMult(secondHalfNum1, secondHalfNum2, numberBase);
    std::string temporaryProduct = karatsubaMult(addBO(firstHalfNum1, secondHalfNum1, numberBase),
                                                addBO(firstHalfNum2, secondHalfNum2, numberBase), numberBase);

    // Calculate cross product
    std::string crossProduct = subString(temporaryProduct, addBO(productFirstHalf, productSecondHalf, numberBase), numberBase);

    // Combine for final product
    std::string output = addBO(addBO(leftS(productFirstHalf, 2 * halfLength), leftS(crossProduct, halfLength), numberBase),
                               productSecondHalf, numberBase);

    return output;
}

int main() {
    std::string firstNumber, secondNumber;
    int numberBase;

    // Input
    std::cin >> firstNumber >> secondNumber >> numberBase;

    // Calculation
    std::string resultSum = addBO(firstNumber, secondNumber, numberBase);
    std::string resultProduct = karatsubaMult(firstNumber, secondNumber, numberBase);

    // Remove leading zeros from product result
    resultProduct.erase(0, std::min(resultProduct.find_first_not_of('0'), resultProduct.size() - 1));

    // If resultProduct is empty, set it to "0"
    if (resultProduct.empty()) {
        resultProduct = "0";
    }

    // Output
    std::cout << resultSum << " " << resultProduct << " " << 0 << std::endl;
    return 0;
}
