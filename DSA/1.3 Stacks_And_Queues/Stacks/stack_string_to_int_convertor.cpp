#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

// Function to convert a string representing an integer to numeric format
int stringToInt(const string &str) {
    int num = 0;
    for (char c : str) {
        num = num * 10 + (c - '0');  // Convert character to integer
    }
    return num;
}

// Function to convert a string representing a decimal number to numeric format using a stack
double stringToDecimal(const string &str) {
    stack<char> digitStack;
    int decimalPos = str.find('.');  // Find the position of the decimal point

    // Push the integer part (before the decimal point) onto the stack
    for (int i = 0; i < decimalPos; i++) {
        digitStack.push(str[i]);
    }

    // Convert integer part
    double integerPart = 0;
    double placeValue = 1;  // Track the place value (units, tens, hundreds, etc.)
    while (!digitStack.empty()) {
        integerPart += (digitStack.top() - '0') * placeValue;
        placeValue *= 10;
        digitStack.pop();
    }

    // Convert decimal part
    double decimalPart = 0;
    double fractionalPlaceValue = 0.1;
    for (int i = decimalPos + 1; i < str.size(); i++) {
        decimalPart += (str[i] - '0') * fractionalPlaceValue;
        fractionalPlaceValue /= 10;
    }

    return integerPart + decimalPart;  // Combine integer and decimal parts
}

int main() {
    string input;
    
    // Read input from the user
    cout << "Enter a positive integer or a positive decimal number: ";
    cin >> input;

    // Check if the input contains a decimal point
    if (input.find('.') == string::npos) {
        // No decimal point, treat it as an integer
        int result = stringToInt(input);
        cout << "Converted number (integer): " << result << endl;
    } else {
        // Input contains a decimal point, convert to decimal
        double result = stringToDecimal(input);
        cout << "Converted number (decimal): " << result << endl;
    }

    return 0;
}
