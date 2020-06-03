#ifndef HEADER_HEADER_H
#define HEADER_HEADER_H

#include <iostream>
#include <list>

using namespace std;

// Define a class which is a blueprint for declaring a hashtable which has functions for managing data inside it.
class HashTable {
	private:
		/// Define a struct which is an employee data to be stored in the hashtable.
		struct Data {
			int id;
			string name;
			string email;
			string position;
			int mobileNumber;
		};
		
		// Define a list which will be the container for employee data to be stored in the hashtable.
		// In this case, we set the list capacity to 100 since a company holds about 100 employees.
		list<Data> container[100];
		
		// Define a hashing function for determining the place of employee data to be stored in the hashtable.
		// In this case, we use modulo division method for the hashing function.
		int hashing(int id) {
			return id % 100;
		}
		
		// Define a collision resolution function to resolve collision problems in case a new employee data enters a slot which has an existing employee data in the hashtable.
		// In this case, we use linear probing method for the collision resolution function.
		int probing(int hash) {
			return hash++;
		}
	
	public:
		// Define a constructor which constructs a new hashtable if user declares a new hashtable object.
		// We do this by inserting an empty list which will contain an employee data for every slot in the container.
		Hashtable() {
			for(int i = 0; i < 100; i++) {
				container[i] = list<Data>();
			}
		}
		
		// Define a function which checks if the hashtable is full.
		// We do this by iterating through the container.
		// If the list is empty, add the counter by 1.
		// If the counter is 100, it means that the hashtable is full. Therefore, return true.
		// Otherwise, the hashtable is not full. Thus, return false.
		bool full() {
			int pairCounter = 0;
					
			for(int i = 0; i < 100; i++) {
				if(!container[i].empty()) {
					pairCounter++;
				}
			}
			
			if(pairCounter == 100) {
				return true;
			} else {
				return false;
			}
		}
		
		// Define a function which checks whether a new employee data has the same id as one of the existing employee data in the hashtable.
		// We do this by also iterating through the hashtable.
		// If a new employee data has the same id as one of the existing employee data in the hashtable, return false.
		// Otherwise, return true.
		bool unique(int id) {
			for(int i = 0; i < 100; i++) {
				if(container[i].front().id == id) {
					return false;
				}
			}
			
			return true;
		}
		
		/// Define a function to add a new employee data to the hashtable.
		// Store the employee data.
		// Hash will be generated from the id. Hash determines the list index of the employee data in the hashtable.
		// If the current list is empty, fill the list with the new employee data.
		// Otherwise, probe the hash until it finds an empty list, then add the employee data to the current list.
		void addEmployee(int id, string name, string email, string position, int mobileNumber) {
			Data data;
			
			data.id = id;
			data.name = name;
			data.email = email;
			data.position = position;
			data.mobileNumber = mobileNumber;
			
			int hash = hashing(id);
			
			if(container[hash].empty()) {
				container[hash].push_back(data);
			} else {
				int probe = probing(hash);
				
				while(!container[probe].empty()) {
					probe = probing(probe);
					if(probe == 100) {
						probe = 0;
					}
				}
				
				container[probe].push_back(data);
			}
		}
		
		// Define a function to get an employee name from id in the hashtable.
		// Hash the id to get the list index of the id.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's id finds the requested id, return the iterator's name.
		// Otherwise, return an empty string.
		string getEmployeeName(int id) {
			int hash = hashing(id);
			list<Data> *currentData = &container[hash];
			
			for(list<Data> :: iterator itr = currentData -> begin(); itr != currentData -> end(); itr++) {
				if(itr -> id == id) 
				{
					return itr -> name;
				}
			}
					
			
			return "";
		}
		
		// Define a function to get an employee Position in the Company from id in the hashtable.
		// Hash the id to get the list index of the id.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's id finds the requested id, return the iterator's Position.
		// Otherwise, return an empty string.
		string getEmployeePosition(int id) {
			int hash = hashing(id);
			list<Data> *currentData = &container[hash];
			
			for(list<Data> :: iterator itr = currentData -> begin(); itr != currentData -> end(); itr++) {
				if(itr -> id == id) {
					return itr -> position;
				}
				
			}

			return "";
		}
		
		// Define a function to get an employee email from id in the hashtable.
		// Hash the id to get the list index of the id.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's id finds the requested id, return the iterator's email.
		// Otherwise, return an empty string.
		string getEmployeeEmail(int id) {
			int hash = hashing(id);
			list<Data> *currentData = &container[hash];
			
			for(list<Data> :: iterator itr = currentData -> begin(); itr != currentData -> end(); itr++) {
				if(itr -> id == id) {
						return itr -> email;
			
				}
				
			}
			
			return "";
		}
		
	// Define a function to get an employee mobile number from id in the hashtable.
		// Hash the id to get the list index of the id.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's id finds the requested id, return the iterator's mobile number.
		// Otherwise, return 0.
		int getEmployeeMobileNumber(int id) {
			int hash = hashing(id);
			list<Data> *currentData = &container[hash];
			
			for(list<Data> :: iterator itr = currentData -> begin(); itr != currentData -> end(); itr++) {
				if(itr -> id == id) {
					return itr -> mobileNumber;
				}		
			}
			
			return 0;
		}
		
		
		
		
		// Define  a function to update an employee position from id in the hashtable.
		// Hash the id to get the list index of the id.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's id finds the requested id, update the iterator's positoion to the new position, then return true.
		// Otherwise, return false.
		bool updatePosition(int id, string newPosition) {
			int hash = hashing(id);
			list<Data> *currentData = &container[hash];
			
			for(list<Data> :: iterator itr = currentData -> begin(); itr != currentData -> end(); itr++) {
				if(itr -> id == id) {
					itr -> position = newPosition;
					
					return true;
				}
			}
			
			return false;
		}
		
		// Define a function to update an employee mobile number from id in the hashtable.
		// Hash the id to get the list index of the id.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's id finds the requested id, update the iterator's mobile number to the new mobile number, then return true.
		// Otherwise, return false.
		bool updateMobileNumber(int id, int newMobileNumber) {
			int hash = hashing(id);
			list<Data> *currentData = &container[hash];
			
			for(list<Data> :: iterator itr = currentData -> begin(); itr != currentData -> end(); itr++) {
				if(itr -> id == id) {
					itr -> mobileNumber = newMobileNumber;
					
					return true;
				}
			}
			
			return false;
		}
		
		// Define a function to update an employee email from id in the hashtable.
		// Hash the id to get the list index of the id.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's id finds the requested id, update the iterator's email to the new email, then return true.
		// Otherwise, return false.
		bool updateEmail(int id, string newEmail) {
			int hash = hashing(id);
			list<Data> *currentData = &container[hash];
			
			for(list<Data> :: iterator itr = currentData -> begin(); itr != currentData -> end(); itr++) {
				if(itr -> id == id) {
					itr -> email = newEmail;
					
					return true;
				}
			}
			
			return false;
		}
		
		
		
		// Define a function to get value from id in the hashtable.
		// Hash the id to get the list index of the id.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's id finds the requested id, remove the current employee data from the list, then return true.
		// Otherwise, return false.
		bool removeEmployee(int id) {
			int hash = hashing(id);
			list<Data> *currentData = &container[hash];
			
			for(list<Data> :: iterator itr = currentData -> begin(); itr != currentData -> end(); itr++) {
				if(itr -> id == id) {
					currentData -> erase(itr);
					
					return true;
				}
			}
			
			return false;
		}
};

#endif
