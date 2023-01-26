// ****************************************************************************************************
// Alexander Brittain
// CSC275 UAT
// alexbrittain69@gmail.com
// ****************************************************************************************************

// This program will simulate the functionality of a printer
// Since I wanted to show multiple examples of exceptions, some of the code in the main function will need
// to be commented out so that the catch can be observed following the previously demonstrated ones
// See the comments above the methods called in the main function

// included libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Base class
class Printer {
    string _name;
    int available_paper;
public:
    // Constructor
    Printer(string name, int paper) {
        _name = name;
        available_paper = paper;
        // Checking that the user did not put a negative number into the paper argument
        if (paper < 0)
            throw "You can not have a negative amount of paper!";
        
    }
    // Method for printing
    void print(string txt_doc) {
        // This variable will calculate the length of whatever the txt_doc variable is in characters
        // after it has been divided by 5. This simulates that for every 5 characters that are displayed
        // the program will use one sheet of paper
        int print_required_paper = txt_doc.length() / 5;
        if (print_required_paper > available_paper)
            // This THROWS text if the conditions of the IF statement are true
            // The THROW will end the execution of the function
            throw "Not enough paper for the job.";
        cout << "Printing..." << txt_doc << endl;
        // Calculating the new amount of pages of paper that are left
        available_paper -= print_required_paper;
    }
    // Method for copying
    void copy(string copy_text, int num_copies) {
        int copy_required_paper = num_copies;
        // Checking to see that there is enough paper to print the requested number of copies
        if (copy_required_paper > available_paper)
            // Throwing an integer type exception
            throw 211;
        cout << "Copying..." << copy_text << "... " << num_copies << " times" << endl;
        // While loop that will continue to print the copies of the given text until the number of copies is
        // reduced to zero.
        while (num_copies >= 0)
        {
            cout << copy_text << endl;
            num_copies -= 1;
        }
    }
    // Method for scanning
    void scan(int num_pages) {
        int scan_required_paper = num_pages;
        if (scan_required_paper > available_paper)
            // Throwing a string type exception
            throw std::string("There is not enough paper to scan all of the pages");
        // Displaying that the function is working without an exception if it reaches this line
        cout << "Scanning... " << num_pages << " pages into the datbase." << endl;
    }
};

// Main function of the program
int main()
{
    try
    {
        // Creating and object of the printer class
        Printer my_printer1("Hp Deskjet 999", 25);
        // Throwing an error from the constructor of the Printer class
        Printer my_printer2("The Thing", -10);

        // This is the scan() method working without catching an exception
        my_printer1.scan(10);
        // This is the scan() method catching a string exception that is thrown
        my_printer1.scan(50);

        // This is the copy() method working without catching an exception
        my_printer1.copy("You suck bruh", 10);
        // This is the copy() method working but catching an integer execption that is thrown from within the method
        my_printer1.copy("Stop copying me", 30);

        // Four attempts to print the same text until the printer runs our of paper, throwing a const char * exception
        my_printer1.print("Hello, my name is Alexander. I am a Software Engineer.");
        my_printer1.print("Hello, my name is Alexander. I am a Software Engineer.");
        my_printer1.print("Hello, my name is Alexander. I am a Software Engineer.");
        my_printer1.print("Hello, my name is Alexander. I am a Software Engineer.");
        
    }
    // This catch will get any of the throws from the above methods that are in quotations that aren't declared as strings
    catch (const char * txt_exception) {
        cout << "Exception: " << txt_exception << endl;
    }
    // This catch will get any integer exception that are thrown by the methods above
    catch (int ex_code) {
        cout << "Exception: " << ex_code << endl;
    }
    // This catch will catch and string exceptions that are thrown by any of the methods above
    catch (string str_exception) {
        cout << "Exception: " << str_exception << endl;
    }
    // This is a default exception handler. It will catch any type of exception that is thrown
    catch (...) {
        cout << "Exception happened!" << endl;
    }
    
    return 0;
}

