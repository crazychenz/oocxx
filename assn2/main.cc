#include <iostream>

#include "Dog.h"

using namespace std;

int main()
{

	// Create dog with default constructor.
	Dog dog = Dog();
	
	// Dump default dog behaviors and attributes to console.
	dog.dump();
	
	// Configure dog object with setters.
	dog.set_name("Spot");
	dog.set_breed("Dalmatien");
	dog.set_female();
	dog.set_age(2);
	dog.set_lbs(60);
	dog.set_fleas();
	
	// Dump dog behaviors and attributes to console.
	dog.dump();
	
	// Create dog with explicit constructor.
	Dog banks = Dog("Banks", "Lab", false, 7, 80, false);
	
	// Dump dog behaviors and attributes to console.
	banks.dump();
	
	return 0;
}