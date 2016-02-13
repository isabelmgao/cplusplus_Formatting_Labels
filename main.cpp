//  Filename: MP4.cpp
//  Programming Assignment 4 for CPS 171
//  Created by Isabel Gao  on 3/11/15.
//  **********************************
//  This program reads from an input of addresses and
//  outputs formatted addressed based on the print selection
//  classifications (either 1, 2, or 3). For every address
//  the program echos the data and depending on the selection
//  will either output one of the following combinations:
//  1 -- prints address without formatting
//  2 -- prints the package label format
//  3 -- prints the address without formatting AND in package label format
//  Any other print selection will result in an invalid selection. 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

    // global input variable
ifstream infile;
int valid;

    // function definitions
int GetPrintSelection();
void GetAddress(string& line0, string& line1, string& line2, string& line3);
void PrintAddress (string line1, string line2, string line3);
void PrintPackageLine (string line1, string line2, string line3);
void PrintPackageAddress (string line1, string line2, string line3);



int main()
{
    string line1, line2, line3, line0;
    int printSelection;
    
    infile.open("Input.txt");
    cout << "Student: Isabel Gao" << endl << endl;
    
    infile >> valid;
    
      while(infile)
    {
    
    printSelection = GetPrintSelection();
        
            // call value-returning GetAddress function
    GetAddress(line0, line1, line2, line3);
        
        // next series of cout statements echo the input address
    cout << '\n' << '\n' << "Echoing the address:" << endl << endl;
    cout << "1: " << line1 << '\n';
    cout << "2: " << line2 << '\n';
    cout << "3: " << line3 << '\n' << endl;
    
            // if else loop reads the int value from GetPrintSelection function (stored in int variable 'printSelection') and determines whether or not selection is valid
        if (printSelection == -1)
        {
            cout << "Your print selection is invalid." << endl << endl;
        }
        else
        {
            cout << "Your print selection is: " << printSelection << endl << endl;
            
                // embedded if else-if loop to determine which void function to call
            if (printSelection == 1)
            {
                PrintAddress(line1, line2, line3);
            }
            else if (printSelection == 2)
            {
                PrintPackageAddress(line1, line2, line3);
            }
            else if (printSelection == 3)
            {
                PrintAddress(line1, line2, line3);
                PrintPackageAddress (line1, line2, line3);
            }
        }
       
        infile >> valid;

    }
    
    cout << "Thank you for using the label printing company" << endl;
    infile.close();
    
    return 0;
}
    // value-returning function that has no calling parameters, reads the input file for printing choice (1, 2, 3) and returns an integer value; if invalid returns -1
int GetPrintSelection()
{
    if (valid >= 1 && valid <= 3)
    {
          return valid;
    }
    else
        return -1;
    
}

    // void function that reads in the three address lines and returns them in three string parameters, skips blank file lines and keeps reading until it gets three valid address lines
void GetAddress (string& line0, string& line1, string& line2, string& line3)
{
    getline(infile, line0);             // reads the first print selection line
    getline(infile, line1);
    getline(infile, line2);
    getline(infile, line3);
    
        // if else-if to determine whether there are blank lines and ignore if so
    if (line1.length () == 0)
    {
        line2 = line1;
    }
    else if (line2.length() == 0)
    {
        line3 = line2;
    }
    else if (line3.length() == 0)
    {
        getline(infile, line3);
    }
}

    // void function that prints out all three lines of the address without formatting
void PrintAddress (string line1, string line2, string line3)
{
    cout << line1 << endl;
    cout << line2 << endl;
    cout << line3 << endl;
}

    // void function that prints each address line with a vertical bar at the front and end of the line, padding the text
void PrintPackageLine (string line1, string line2, string line3)
{
    cout << '\n' << "| " << left << setw(58) << setfill(' ') << line1 << right << setw(2) << "|" << endl;
    cout << "| " << left << setw(58) << line2 << right << setw(2) << "|" << endl;
    cout << "| " << left << setw(58) << line3 << right << setw(2) << "|" << endl;
}

    // void function that prints all three lines of address with package formatting
void PrintPackageAddress (string line1, string line2, string line3)
{
    cout << setw(63) << setfill('*') << endl;
    
    PrintPackageLine (line1, line2, line3);
    
    cout << setw(63) << setfill('*') << '\n';
}
