
#include <iostream>
#include "hashtableheader.h"

using namespace std;

// Make a user interface to ask user what to do with the hashtable.
int main() {
	// Declare a new hashtable for the user to work on.
	HashTable hashtable;
	
	// Declare an integer which gets the user's choice.
	int choice;
	
	// Declare a bool which checks if the user's input is valid.
	bool valid;
	
	// Display the interface as long as the user is still using the program.
	while(true) {	
		// Display the interface as long as the user inputs choice out of menu or alphabets.
		do {
			system("cls");
			
			hashtable.display();
			
			cout << "1. Add Employee" << endl;
			cout << "2. Get Employee Name" << endl;
			cout << "3. Get Employee Position" << endl;
			cout << "4. Get Employee Mobile Number" << endl;
			cout << "5. Get Employee Employee" << endl;
			cout << "6. Update Employee Position" << endl;
			cout << "7. Update Employee Mobile Number" << endl;
			cout << "8. Update Employee Email" << endl;
			cout << "9. Remove Employee" << endl;
			cout << "10. Exit" << endl;
			
			cout << "Input choice: ";
			cin >> choice;
			
			if (choice < 1 || choice > 10 || cin.fail()) {
		        cout << "Please pick one of the choices above." << endl;
				
				system("pause");
		        
				cin.clear();
				cin.ignore(10000, '\n');
		        
				valid = false;
		    } else {
		        valid = true;
		    }
		} while(!valid);
		
		// If the user wants to add a new employee, 
		if(choice == 1) {
			// Declare an integer which gets the user's inputted id.
			int id;
			// Declare a string which gets the user's inputted name.
			string name;
			// Declare a string which gets the user's inputted position.
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
				cout << "Input employee's ID to add: ";
				cin >> id;
				
				// Check if user enters an invalid input for the employee's id.
				// If user enters a non-numeric input for the employee's id, print an error message, clear the input state and ignore this inputted line.
				// Otherwise, check if the user's inputted id exists in the hashtable.
				if(cin.fail()) {
					// Print an error message if user enters a non-numeric input for the employee's id.
					cout << "Employee's ID must be numeric!" << endl;
					
					// Clear the input state.
					cin.clear();
					// Ignore this inputted line.
		        	cin.ignore(10000, '\n');
				} else {
					// Check if the user's inputted id exists in the hashtable.
					// If it does not exist, ask the user to input the employee's name, position, and mobile number.
					// Otherwise, print an error message.
					if(hashtable.unique(id)) {
						cin.ignore(10000, '\n');
						
						// Ask the user to input the employee's name.
						cout << "Input employee's name to add: ";
						getline(cin, name);
						
						// Check if user enters an invalid input for the employee's name.
						// If user enters a blank input for the employee's name, print an error message.
						// Otherwise, ask the user to input the employee's position.
						if(name.empty()) {
							// Print an error message if user enters a blank input for the employee's name.
							cout << "Employee's name must not be blank!" << endl;
						} else {
							// Ask the user to input the employee's position.
							cout << "Input employee's position to add: ";
							getline(cin, position);
							
							// Check if user enters an invalid input for the employee's position.
							// If user enters a blank input for the employee's position, print an error message.
							// Otherwise, ask the user to input the employee's mobile number.
							if(position.empty()) {
								// Print an error message if user enters a blank input for the employee's position.
								cout << "Employee's position must not be blank!" << endl;
							} else {
								// Ask the user to input the employee's mobile number.
								cout << "Input employee's mobile number to add: ";
								cin >> mobileNumber;
								
								// Check if user enters an invalid input for the employee's mobile number.
								// If user enters a non-numeric input for the employee's mobile number, print an error message, clear the input state and ignore this inputted line.
								// Otherwise, ask the user to input the employee's email.
								if(cin.fail()) {
									// Print an error message if user enters a non-numeric input for the employee's mobile number.
									cout << "Employee's mobile number must be numeric!" << endl;
									
									// Clear the input state.
									cin.clear();
									// Ignore this inputted line.
						        	cin.ignore(10000, '\n');
								} else {
									cin.ignore(10000, '\n');
									
									// Ask the user to input the employee's email.
									cout << "Input employee's email to add: ";
									getline(cin, email);
									
									// Check if user enters an invalid input for the employee's email.
									// If user enters a blank input for the employee's email, print an error message.
									// Otherwise, add the data depending on the hash into the hashtable, then print a success message.
									if(email.empty()) {
										// Print an error message if user enters a blank input for the employee's email.
										cout << "Employee's email must not be blank!" << endl;
									} else {
										// Add the employee's data depending on the hash into the hashtable.
										hashtable.addEmployee(id, name, position, mobileNumber, email);
										
										// Print a success message.
										cout << "Employee's data has been added." << endl;
									}
								}
							}
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
			
			system("pause");
		}
		// If the user wants to get an employee's name,
		else if(choice == 2) {
			// Declare an integer which gets the user's inputted id.
			int id;
			
			// Ask the user to input the employee's id.
			cout << "Input employee's ID to get employee's name: ";
			cin >> id;
			
			// Check if user enters an invalid input for the employee's id.
			// If user enters a non-numeric input for the employee's id, print an error message, clear the input state and ignore this inputted line.
			// Otherwise, print the employee's name.
			if(cin.fail()) {
				// Print an error message if user enters a non-numeric input for the employee's id.
				cout << "Employee's ID must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				// Ignore this inputted line.
				cin.ignore(10000, '\n');
			} else {
				// If the employee's id exists, the program will print the employee's name.
				// Otherwise, the program will print an empty string for the employee's name.
				cout << "Name of employee with ID " << id << ": " << hashtable.getEmployeeName(id) << endl;
			}
			
			system("pause");
		}
		// If the user wants to get an employee's position,
		else if(choice == 3) {
			// Declare an integer which gets the user's inputted id.
			int id;
			
			// Ask the user to input the employee's id.
			cout << "Input employee's ID to get employee's position: ";
			cin >> id;
			
			// Check if user enters an invalid input for the employee's id.
			// If user enters a non-numeric input for the employee's id, print an error message, clear the input state and ignore this inputted line.
			// Otherwise, print the employee's position.
			if(cin.fail()) {
				// Print an error message if user enters a non-numeric input for the employee's id.
				cout << "Employee's ID must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				// Ignore this inputted line.
				cin.ignore(10000, '\n');
			} else {
				// If the employee's id exists, the program will print the employee's position.
				// Otherwise, the program will print an empty string for the employee's position.
				cout << "Position of employee with ID " << id << ": " << hashtable.getEmployeePosition(id) << endl;
			}
			
			system("pause");
		}
		// If the user wants to get an employee's mobile number,
		else if(choice == 4) {
			// Declare an integer which gets the user's inputted id.
			int id;
			
			// Ask the user to input the employee's id.
			cout << "Input employee's ID to get employee's mobile number: ";
			cin >> id;
			
			// Check if user enters an invalid input for the employee's id.
			// If user enters a non-numeric input for the employee's id, print an error message, clear the input state and ignore this inputted line.
			// Otherwise, print the employee's mobile number.
			if(cin.fail()) {
				// Print an error message if user enters a non-numeric input for the employee's id.
				cout << "Employee's ID must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				// Ignore this inputted line.
				cin.ignore(10000, '\n');
			} else {
				// If the employee's id exists, the program will print the employee's mobile number.
				// Otherwise, the program will print 0 for the employee's mobile number.
				cout << "Mobile number of employee with ID " << id << ": " << hashtable.getEmployeeMobileNumber(id) << endl;
			}
			
			system("pause");
		}
		// If the user wants to get an employee's email,
		else if(choice == 5) {
			// Declare an integer which gets the user's inputted id.
			int id;
			
			// Ask the user to input the employee's id.
			cout << "Input employee's ID to get employee's email: ";
			cin >> id;
			
			// Check if user enters an invalid input for the employee's id.
			// If user enters a non-numeric input for the employee's id, print an error message, clear the input state and ignore this inputted line.
			// Otherwise, print the employee's email.
			if(cin.fail()) {
				// Print an error message if user enters a non-numeric input for the employee's id.
				cout << "Employee's ID must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				// Ignore this inputted line
				cin.ignore(10000, '\n');
			} else {
				// If the employee's id exists, the program will print the employee's email.
				// Otherwise, the program will print an empty string for the employee's email.
				cout << "Email of employee with ID " << id << ": " << hashtable.getEmployeeEmail(id) << endl;
			}
			
			system("pause");
		}
		// If the user wants to update an employee's email,
		else if(choice == 6) {
			// Declare an integer which gets the user's inputted id.
			int id;
			// Declare an integer which gets the user's inputted email.
			string newPosition;
			
			// Ask the user to input the employee's id.
			cout << "Input employee's ID to update employee's position: ";
			cin >> id;
			
			// Check if user enters an invalid input for the employee's id.
			// If user enters a non-numeric input for the employee's id, print an error message, clear the input state and ignore this inputted line.
			// Otherwise, ask the user to input the employee's new position.
			if(cin.fail()) {
				// Print an error message if user enters a non-numeric input for the employee's id.
				cout << "Employee's ID must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				// Ignore this inputted line.
				cin.ignore(10000, '\n');
			} else {
				cin.ignore(10000, '\n');
				
				// Ask the user to input the new position.
				cout << "Input employee's new position to update employee's position: ";
				getline(cin, newPosition);
				
				// Check if user enters an invalid input for the employee's new position.
				// If user enters a blank input for the employee's new position, print an error message.
				// Otherwise, print the employee's position update status.
				if(newPosition.empty()) {
					// Print an error message if user enters a blank input for the employee's new position.
					cout << "Employee's new position must not be blank!" << endl;
				} else {
					// Print the employee's position update status.
					// If the employee's position update succeeds, the program will print 1.
					// Otherwise, the program will print 0.
					cout << "Employee with ID " << id << " position update status: " << hashtable.updateEmployeePosition(id, newPosition) << endl;
				}
			}
			
			system("pause");
		}
		// If the user wants to update an employee's mobile number,
		else if(choice == 7) {
			// Declare an integer which gets the user's inputted id.
			int id;
			// Declare an integer which gets the user's inputted mobile number.
			int newMobileNumber;
			
			// Ask the user to input the employee's id.
			cout << "Input employee's ID to update employee's mobile number: ";
			cin >> id;
			
			// Check if user enters an invalid input for the employee's id.
			// If user enters a non-numeric input for the employee's id, print an error message, clear the input state and ignore this inputted line.
			// Otherwise, ask the user to input the employee's new phone number.
			if(cin.fail()) {
				// Print an error message if user enters a non-numeric input for the employee's id.
				cout << "Employee's ID must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				// Ignore this inputted line.
				cin.ignore(10000, '\n');
			} else {
				// Ask the user to input the new mobile number.
				cout << "Input employee's new mobile number to update employee's mobile number: ";
				cin >> newMobileNumber;
				
				// Check if user enters an invalid input for the employee's mobile number.
				// If user enters a non-numeric input for the employee's mobile number, print an error message, clear the input state and ignore this inputted line.
				// Otherwise, print the employee's mobile number update status.
				if(cin.fail()) {
					// Print an error message.
					cout << "Employee's mobile number must be numeric!" << endl;
					
					// Clear the input state.
					cin.clear();
					// Ignore this inputted line.
		        	cin.ignore(10000, '\n');
				} else {
					// Print the employee's mobile number update status.
					// If the employee's mobile number update succeeds, the program will print 1.
					// Otherwise, the program will print 0.
					cout << "Employee with ID " << id << " mobile number update status: " << hashtable.updateEmployeeMobileNumber(id, newMobileNumber) << endl;
				}
			}
			
			system("pause");
		}
		// If the user wants to update an employee's email,
		else if(choice == 8) {
			// Declare an integer which gets the user's inputted id.
			int id;
			// Declare an integer which gets the user's inputted email.
			string newEmail;
			
			// Ask the user to input the employee's id.
			cout << "Input employee's ID to update employee's email: ";
			cin >> id;
			
			// Check if user enters an invalid input for the employee's id.
			// If user enters a non-numeric input for the employee's id, print an error message, clear the input state and ignore this inputted line.
			// Otherwise, ask the user to input the employee's new email, then print the employee's email update status.
			if(cin.fail()) {
				// Print an error message if user enters a non-numeric input for the employee's id.
				cout << "Employee's ID must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				// Ignore this inputted line.
				cin.ignore(10000, '\n');
			} else {
				cin.ignore(10000, '\n');
				
				// Ask the user to input the new email.
				cout << "Input employee's new email to update employee's email: ";
				cin >> newEmail;
				
				// Check if user enters an invalid input for the employee's new email.
				// If user enters a blank input for the employee's new position, print an error message.
				// Otherwise, print the employee's email update status.
				if(newEmail.empty()) {
					// Print an error message if user enters a blank input for the employee's new email.
					cout << "Employee's new email must not be blank!" << endl;
				} else {
				// Print the employee's email update status.
				// If the employee's email update succeeds, the program will print 1.
				// Otherwise, the program will print 0.
				cout << "Employee with ID " << id << " email update status: " << hashtable.updateEmployeeEmail(id, newEmail) << endl;
				}
			}
			
			system("pause");
		}
		// If the user wants to remove an employee,
		else if(choice == 9) {
			// Declare an integer which gets the user's inputted id.
			int id;
			
			// Ask the user to input the employee's id.
			cout << "Input employee's ID to remove employee: ";
			cin >> id;
			
			// Check if user enters an invalid input for the employee's id.
			// If user enters a non-numeric input for the employee's id, print an error message, clear the input state and ignore this inputted line.
			// Otherwise, print the employee removal status.
			if(cin.fail()) {
				// Print an error message if user enters a non-numeric input for the employee's id.
				cout << "Employee's ID must be numeric!" << endl;
				
				// Clear the input state.
				cin.clear();
				// Ignore this inputted line.
				cin.ignore(10000, '\n');
			} else {
				// Print the employee removal status.
				// If the employee removal succeeds, the program will print 1.
				// Otherwise, the program will print 0.
				cout << "Employee with ID " << id << " removal status: " << hashtable.removeEmployee(id) << endl;
			}
			
			system("pause");
		}
		// If the user wants to exit from the program,
		else if(choice == 10) {
			// Break from the infinite loop which then terminates the program.
			break;
		}
	}
	
	return 0;
}
