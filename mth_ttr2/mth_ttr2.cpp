/*
Title: Chapter 5 Exerise 17 - Math Tutor
File Name: mth_ttr.cpp
Programmer: Nicholas Woolston
Date: 28/03/2025 (DD/MM/YYYY)
Requirements: Write code that generates 2 random numbers to be added together. Display the numbers to the user and put a break in the code while the user
gets the answer. Have the answer be displayed after the user presses button.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h> 
using namespace std;
void DisplayMenu();
int GetChoice();

int GetRandNum();
int GetRandNumSimp();
void DisplayCalc(int choice, int n1, int n2, int n3, int n4);
int Add(int num1, int num2);
int Sub(int n1, int n2);
int Mult(int n3, int n4);
int Div(int n3, int n4);
int ChoiceSwitch(int choice, int n1, int n2, int n3, int n4);
char Repeat();
void CheckAnswer(int result);


int main()
{
    char repeat;
    do
    {
        srand(time(nullptr));
        int n1 = GetRandNum(); 
        int n2 = GetRandNum();
        int n3 = GetRandNumSimp();
        int n4 = GetRandNumSimp();
        DisplayMenu();
        int choice = GetChoice();
        int result = ChoiceSwitch(choice, n1, n2, n3, n4);
        DisplayCalc(choice, n1, n2, n3, n4);
        CheckAnswer(result);
        repeat = Repeat();

        cout << endl; //formatting so the addition display isnt smushed into the "would you like to repeat" text.
    } while (repeat == 'y');
}

int GetRandNum()
{
    int num1 = rand() % 100; //uses modulo to keep the number below 100 for ease of verification. 
    return num1;
}
int GetRandNumSimp()
{
    int num1 = rand() % 10 + 1; //uses modulo to keep the number below 10 for ease of verification. 
    return num1;
}


int Add(int num1, int num2)
{
    int total = num1 + num2;
    return total;
}

int Sub(int n1, int n2)
{
    int total = n1 - n2;
    return total;
}

int Mult(int n3, int n4)
{
    int total = n3 * n4;
    return total;
}

int Div(int n3, int n4)
{
    int total = (n3 + 10) / n4; //+10 too keep it a little interesting
    return total;
}

void DisplayCalc(int choice, int n1, int n2, int n3, int n4)
{
    switch (choice)
    {
    case 1:
        cout << "  " << n1 << endl << "+ " << n2 << "\n" << "----" << endl;
        break;
    case 2:
        cout << "  " << n1 << endl << "- " << n2 << "\n" << "----" << endl;
        break;
    case 3:
        cout << "  " << n3 << endl << "x " << n4 << "\n" << "----" << endl;
        break;
    case 4:
        cout << "  " << (n3 + 10) << endl << "÷ " << n4 << "\n" << "----" << endl;
        break;
    }

}

char Repeat()
{
    char repeat;
    cout << "\n Would you like to try another problem? (y/n) ";

    cin >> repeat;
    if (repeat == 'n')
    {
        cout << "Closing.";
    }
    return repeat;
}

void CheckAnswer(int result)
{
    int answer;
    cin >> answer;
    if (answer == result)
    {
        cout << "That's correct! Congrats! \n";
    }
    else
    {
        cout << "That's incorrect! The answer was: " << result << endl;
    }
}

void DisplayMenu()
{
    cout << "Choose an operation.\n";
    cout << right << setw(15) << "1. Addition\n";
    cout << right << setw(18) << "2. Subtraction\n";
    cout << right << setw(21) << "3. Multiplication\n";
    cout << right << setw(15) << "4. Division\n";
    cout << right << setw(11) << "5. Quit\n";
    cout << right << setw(28) << "Enter your choice (1-5): ";
}

int GetChoice()
{
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 5)
    {
        cout << "That is not an available option. Please enter a number from 1-5: ";
        cin >> choice;
    }
    return choice;
}

int ChoiceSwitch(int choice, int n1, int n2, int n3, int n4)
{
    int result = 0;
    switch (choice)
    {
    case 1:
        result = Add(n1, n2);
        break;
    case 2:
        result = Sub(n1, n2);
        break;
    case 3:
        result = Mult(n3, n4);
        break;
    case 4:
        result = Div(n3, n4);
        break;
    case 5:
        cout << "Closing.";
        exit(0);
    }
    return result;
}