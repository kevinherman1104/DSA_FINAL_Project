#ifndef HEADER_HEADER_H
#define HEADER_HEADER_H

#include <iostream>
#include <list>

using namespace std;

// Define a class which is a blueprint for declaring a hashtable which has functions for managing data inside it.
class HashTable {
	private:
		// Define a struct which is a pair of key and value to be stored in the hashtable.
		struct Pair {
			int key;
			string value;
		};
		
		// Define a list which will be the container for pairs of keys and values to be stored in the hashtable.
		// In this case, we set the list capacity to 100 since a company holds about 100 employees.
		list<Pair> container[100];
		
		// Define a hashing function for determining the place of the pair of key and value to be stored in the hashtable.
		// In this case, we use modulo division method for the hashing function.
		int hashing(int key) {
			return key % 100;
		}
		
		// Define a collision resolution function to resolve collision problems in case a new pair enters a slot which has an existing pair in the hashtable.
		// In this case, we use linear probing method for the collision resolution function.
		int probing(int hash) {
			return hash++;
		}
	
	public:
		// Define a constructor which constructs a new hashtable if user declares a new hashtable object.
		// We do this by inserting an empty list which will contain a pair of key and value for every slot in the container.
		Hashtable() {
			for(int i = 0; i < 100; i++) {
				container[i] = list<Pair>();
			}
		}
		
		// Define a function which checks if the hashtable is full.
		// We do this by iterating through the container.
		// If the pair is empty, add the counter by 1.
		// If the counter is 20, it means that the hashtable is full. Therefore, return true.
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
		
		// Define a function which checks whether a new pair has the same key as one of the existing pairs in the hashtable.
		// We do this by also iterating through the hashtable.
		// If a new pair has the same key as one of the existing pairs in the hashtable, return false.
		// Otherwise, return true.
		bool unique(int key) {
			for(int i = 0; i < 100; i++) {
				if(container[i].front().key == key) {
					return false;
				}
			}
			
			return true;
		}
		
		// Define a function to add a new pair to the hashtable.
		// Store the key and value as a pair.
		// Hash will be generated from the key. Hash determines the list index of the pair in the hashtable.
		// If the current list is empty, fill the list with the new pair.
		// Otherwise, probe the hash until it finds an empty list, then add the pair to the current list.
		void add(int key, string value) {
			Pair pair;
			
			pair.key = key;
			pair.value = value;
			
			int hash = hashing(key);
			
			if(container[hash].empty()) {
				container[hash].push_back(pair);
			} else {
				int probe = probing(hash);
				
				while(!container[probe].empty()) {
					probe = probing(probe);
					if(probe == 100) {
						probe = 0;
					}
				}
				
				container[probe].push_back(pair);
			}
		}
		
		// Define a function to get value from key in the hashtable.
		// Hash the key to get the list index of the key.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's key finds the requested key, return the iterator's value.
		// Otherwise, return an empty string.
		string get(int key) {
			int hash = hashing(key);
			list<Pair> *currentPair = &container[hash];
			
			for(list<Pair> :: iterator itr = currentPair -> begin(); itr != currentPair -> end(); itr++) {
				if(itr -> key == key) {
					return itr -> value;
				}
			}
			
			return "";
		}
		
		// Define a function to get value from key in the hashtable.
		// Hash the key to get the list index of the key.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's key finds the requested key, update the iterator's value to the new value, then return true.
		// Otherwise, return false.
		bool update(int key, string value) {
			int hash = hashing(key);
			list<Pair> *currentPair = &container[hash];
			
			for(list<Pair> :: iterator itr = currentPair -> begin(); itr != currentPair -> end(); itr++) {
				if(itr -> key == key) {
					itr -> value = value;
					
					return true;
				}
			}
			
			return false;
		}
		
		// Define a function to get value from key in the hashtable.
		// Hash the key to get the list index of the key.
		// Define a hashtable iterator that refers to that current list in the hashtable.
		// Iterate through that current list using the iterator.
		// If the iterator's key finds the requested key, remove the current pair from the list, then return true.
		// Otherwise, return false.
		bool remove(int key) {
			int hash = hashing(key);
			list<Pair> *currentPair = &container[hash];
			
			for(list<Pair> :: iterator itr = currentPair -> begin(); itr != currentPair -> end(); itr++) {
				if(itr -> key == key) {
					currentPair -> erase(itr);
					
					return true;
				}
			}
			
			return false;
		}
};

#endif
