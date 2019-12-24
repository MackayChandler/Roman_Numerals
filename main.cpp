#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

//Converts each character in the string to a number
int Values(char c) {
    
    if (c == 'I') {
        return 1;
    }
    else if (c == 'V') {
        return 5;
    }
    else if (c == 'X') {
        return 10;
    }
    else if (c == 'L') {
        return 50;
    }
    else if (c == 'C') {
        return 100;
    }
    else if (c == 'D') {
        return 500;
    }
    else if (c == 'M') {
        return 1000;
    }
    
    return -1;
}


int RomanNumeralsToInt(string str) {
    int i = 0;
    int product = 0;
    for (i = 0; i < str.length(); i++) {
        int val1 = Values(str[i]);
        if (i + 1 < str.length()) {
            int val2 = Values(str[i + 1]);
            
            if (val1 >= val2) {
                product += val1;
            }
            else {
                product += abs(val1 - val2);
                i++;
            }
        }
        else {
            product = product + val1;
        }
    }
    return product;
}

void IntToRomanNumeral(int num) {
    int number[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int index = 12;
    
    while (num > 0) {
        int res = num / number[index];
        
        num = num % number[index];
        
        while (res--) {
            cout << symbol[index];
        }
        index--;
    }
}

void PrintMenu() {
    cout << "-----Welcome to the Roman Numeral Converter-----" << endl;
    cout << "Please choose an option:" << endl;
    cout << "1) Convert Roman Numerals to integer" << endl;
    cout << "2) Convert Integer to Roman Numerals" << endl;
    cout << "3) Exit" << endl;
}
//Handles the rules for the Roman Numerals
bool VerifyRomNum(string str) {
    if (str.length() > 1) {
        for (int i = 0; i < str.length(); i++) {
            if (i > 0) {
                if (str[i] == 'C') {
                    if ((str[i - 1] == 'I') || (str[i - 1] == 'V')) {
                        return false;                }
                    else {
                        return true;
                    }
                }
                else if (str[i] == 'X') {
                    if (str[i - 1] == 'V') {
                       return false;
                    }
                    else {
                        return true;
                    }
                }
                else if (str[i] == 'M') {
                    if ((str[i - 1] == 'I') || (str[i - 1] == 'V') || (str[i - 1] == 'X')) {
                        return false;
                    }
                    else {
                        return true;
                    }
                }
                else {
                    return true;
                }
            }
        }
    }
    else {
        return true;
    }
}

int main() {
    int choice = 0;
    
    while (choice != 3) {
        PrintMenu();
        cout << "Enter option number: ";
        cin >> choice;
        while (1) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Invalid Input!" << endl;
                cout << "Enter option number: ";
                cin >> choice;
            }
            if (!cin.fail()) {
                break;
            }
        }
        cout << endl;
        
        if (choice == 1) {
            string romNum;
            cout << "Enter the Roman Numeral to convert: ";
            cin >> romNum;
            while (1) {
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid Input!" << endl;
                    cout << "Enter the Roman Numeral to convert: ";
                    cin >> romNum;
                }
                if (!cin.fail()) {
                    break;
                }
            }
            cout << endl;
            if (VerifyRomNum(romNum)) {
                
            cout << "The value of the Roman Numerals is " << RomanNumeralsToInt(romNum) << endl << endl;
            }
            else {
                cout << "Invalid input" << endl;
            }
        }
        else if (choice == 2) {
            int input;
            cout << "Enter the integer to convert: ";
            cin >> input;
            while (1) {
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid Input!" << endl;
                    cout << "Enter the integer to convert: ";
                    cin >> input;
                }
                if (!cin.fail()) {
                    break;
                }
            }
            cout << endl;
            
            cout << "The Roman Numerals of the integer are: ";
            IntToRomanNumeral(input);
            cout << endl << endl;
            
        }
        else if (choice == 3) {
            cout << "Goodbye" << endl;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }
    return 0;
}
