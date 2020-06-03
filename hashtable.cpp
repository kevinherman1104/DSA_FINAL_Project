#include <iostream>
#include <conio.h>
#include "hashtableheader.h"

using namespace std;

// Make a user interface to ask user what to do with the hashtable.
int main() {
	// Declare a new hashtable for the user to work on.
	HashTable hashtable;
	
	// Declare an integer which gets the user's choice.
	int choice;
	
	// Declare a boolean which check whther the input valid or not
	bool valid;
	
	// Display the interface as long as the user is still using the program.
	while(true) {
		// Display the interface as long as the user inputs invalid choice.
		do {
			system("cls");
			
			cout << "1. Add Employee" << endl;
			cout << "2. Get Employee Name" << endl;
			cout << "3. Get Employee Position" << endl;
			cout << "4. Get Employee Mobile Number" << endl;
			cout << "5. Get Employee Email" << endl;
			cout << "6. Update Employee Position" << endl;
			cout << "7. Update Employee Mobile Number" << endl;
			cout << "8. Update Employee Email"<< endl;
			cout << "9. Remove Employee" << endl;
			cout << "10. Exit" << endl;
			cout << "Input choice: ";
			cin >> choice;
		
			if(choice < 1 || choice > 10|| cin.fail())
			{
				cout << "Please Pick the Choices above !" << endl;
			
				getch();
			
				cin.clear();
				cin.ignore(10000,'\n');
				
				valid = false;
				
			}
			
			valid = true;
		}while(!valid);
		
		
		// If the user wants to add a new key-value pair,
		if(choice == 1) {
		// Declare an integer which gets the user's inputted id.
			int id;
			// Declare a string which gets the user's inputted name.
			string name;
			// Declare a string which gets the user's inputted date of birth.
			string position;
			// Declare an integer which gets the user's inputted mobile number.
			int mobileNumber;
			// Declare a string which gets the user's inputted email.
			string email;
			
			// Check if the hashtable is full.
			// If it is not full, ask the user to input the id.
			// Otherwise, print an error message.
			if(!hashtable.full()) {
				// Ask the user to input the employee's id.
				cout << "Input employee's ID to add: "<< endl;
				
				cin >> id;
				
				// Check if user enters an invalid input for the employee's id.
				// If user enters a non-numeric input for the employee's id, print an error message and clear the input state.
				// Otherwise, check if the user's inputted id exists in the hashtable.
				if(cin.fail()) {
					// Print an error message.
					cout << "Employee's ID must be numeric!" << endl;
					
					// Clear the input state.
					cin.clear();
		        	cin.ignore(10000,'\n');
				} else {
					// Check if the user's inputted id exists in the hashtable.
					// If it does not exist, ask the user to input the employee's name, date of birth, and mobile number.
					// Otherwise, print an error message.
					if(hashtable.unique(id)) {
						// Ask the user to input the employee's name.
						cout << "Input employee's name to add: ";
						cin >> name;
						
						// Ask the user to input the employee's date of birth.
						cout << "Input employee's position to add: ";
						cin >> position;
						
						// Ask the user to input the employee's mobile number.
						cout << "Input employee's mobile number to add: ";
						cin >> mobileNumber;
						
						// Check if user enters an invalid input for the employee's mobile number.
						// If user enters a non-numeric input for the employee's mobile number, print an error message and clear the input state.
						// Otherwise, ask the user to input the employee's email, add the data depending on the hash into the hashtable, then print a success message.
						if(cin.fail()) {
							// Print an error message.
							cout << "Employee's mobile number must be numeric!" << endl;
							
							// Clear the input state.
							cin.clear();
				        	cin.ignore(10000,'\n');
						} else {
							// Ask the user to input the employee's email.
							cout << "Input employee's email to add: ";
							cin >> email;
							
							// Add the employee's data depending on the hash into the hashtable.
							hashtable.addEmployee(id, name, email, position, mobileNumber);
							
							// Print a success message.
							cout << "Employee's data has been added." << endl;
						}
					} else {
						// Print an error message if the user's inputted id exists in the hashtable.
						cout << "Employee's ID must be unique!" << endl;
					}
				}
			} else {
				// Print an error message if the hashtable is full.
				cout << "Hash table is full!" << endl;
				
			}
			
			getch();
		}		
					
					
					
					
					
		// If the user wants to get the value from a pair,
		else if(choice == 2) {
			// Declare an integer which gets the user's desired key.
			int id;
			
			// Ask the user to input the desired key.
			cout << "Input ID to get Employee Name: ";
			cin >> id;
			
			if (cin.fail())
			{
				cout << "ID MUST BE NUMERIC !"<< endl;
				cin.clear();
				cin.ignore(10000,'\n');
			}
			else
			{
				cout << "Name of Employee with ID " << id << " is " << hashtable.getEmployeeName(id) << endl;
			}
			
			// If the key exists, the program will print the value of the key.
			// Otherwise, the program will print an empty string for the value.
		
			
			getch();
		}
		// If the user wants to update the value of a pair,
		else if(choice == 3) {
			int id;
			
			// Ask the user to input the desired key.
			cout << "Input ID to get Employee Position: ";
			cin >> id;
			
			if (cin.fail())
			{
				cout << "ID MUST BE NUMERIC !" << endl;
				cin.clear();
				cin.ignore(10000,'\n');
			}
			else
			{
				cout << "Position of Employee with ID " << id << " is " << hashtable.getEmployeePosition(id) << endl;
			}
			
			getch();
		}
		
		// If the user wants to update the value of a pair,
		else if(choice == 4) {
			int id;
			
			// Ask the user to input the desired key.
			cout << "Input ID to get Employee Mobile Number: ";
			cin >> id;
			
			if (cin.fail())
			{
				cout << "ID MUST BE NUMERIC !" << endl;
				cin.clear();
				cin.ignore(10000,'\n');
			}
			else
			{
				cout << "Mobile Number of Employee with ID " << id << " is " << hashtable.getEmployeeMobileNumber(id) << endl;
			}
			
			getch();
		}
		
		else if(choice == 5) {
			int id;
			
			// Ask the user to input the desired key.
			cout << "Input ID to get Employee Email:  ";
			cin >> id;
			
			if (cin.fail())
			{
				cout << "ID MUST BE NUMERIC !" << endl;
				cin.clear();
				cin.ignore(10000,'\n');
			}
			else
			{
				cout << "Email of Employee with ID " << id << " is " << hashtable.getEmployeeEmail(id) << endl;
			}
			
			getch();
		}
		
		
		// If the user wants to remove a key-va
		// If the user wants to remove a key-value pair,
		else if(choice == 6) {
			// Declare an integer which gets the user's desired key.
			int id;
			string newPosition;
			
			// Ask the user to input the desired key.
			cout << "Input ID to Update Position: ";
			cin >> id;
			if(cin.fail())
			{
				cout << "ID MUST BE NUMERIC !" << endl;
				cin.clear();
				cin.ignore(10000,'\n');
			}
			else
			{
				cout << "Input New Position to Update employee's Position: ";
				cin >> newPosition;
				cout << "Employee's Position Update Status : " << hashtable.updatePosition(id, newPosition) << endl;
			}
		
			getch();
		}
		else if(choice == 7) {
			// Declare an integer which gets the user's desired key.
			int id;
			int newMobileNumber;
			
			// Ask the user to input the desired key.
			cout << "Input ID to Update Position: ";
			cin >> id;
			if(cin.fail())
			{
				cout << "ID MUST BE NUMERIC !" << endl;
				cin.clear();
				cin.ignore(10000,'\n');
			}
			else
			{
				cout << "Input New Mobile Number to Update employee's Mobile Number: ";
				cin >> newMobileNumber;
				if(cin.fail())
				{
					cout << "New Phone Number MUST BE NUMERIC !" << endl;
					cin.clear();
					cin.ignore(10000,'\n');
				}
				else
				{
					cout << "Employee's Mobile Number Update Status : " << hashtable.updateMobileNumber(id, newMobileNumber) << endl;
				}
				
			}
		
			getch();
		}
		else if(choice == 8) {
			// Declare an integer which gets the user's desired key.
			int id;
			string newEmail;
			
			// Ask the user to input the desired key.
			cout << "Input ID to Update Email: ";
			cin >> id;
			if(cin.fail())
			{
				cout << "ID MUST BE NUMERIC !" << endl;
				cin.clear();
				cin.ignore(10000,'\n');
			}
			else
			{
				cout << "Input New Email to Update employee's Email: ";
				cin >> newEmail;
				cout << "Employee's Email Update Status : " << hashtable.updateEmail(id, newEmail) << endl;
			}
		
			getch();
		}
		
		else if(choice  ==  9)
		{
			int id;
			cout << "Input ID to Remove Employee : " << endl;
			cin >> id;
			
			if (cin.fail())
			{
				cout << " ID MUST BE NUMERIC !" << endl;
				cin.clear();
				cin.ignore(10000,'\n');
				
			}
			else
			{
				cout << "Remove Status for Employee" << id << " is " << hashtable.removeEmployee(id) << endl;
			}
			
		}
		// If the user wants to exit from the program,
		
		
		else if (choice == 10) {
			// Break from the infinite loop which then terminates the program.
			break;
		}
	}
	
	return 0;
}
