#include <iostream>
#include <string>

#include "Dog.h"

using namespace std;

/**
* Default constructor.
*/
Dog::Dog()
{
	// Note: Defaults are given in class Dog with C++11 initializers.
}

/**
* Explicit Constructor.
* @param name Name of the Dog.
* @param breed Breed of the Dog.
* @param female True is Dog is female, False if Dog is male.
* @param age Age of Dog in earth years.
* @param lbs Weight of Dog to nearest pound.
* @param fleas Indicate whether Dog has fleas.
*/
Dog::Dog(const string& name, const string& breed, const bool female, const unsigned int age, const unsigned int lbs, const bool fleas)
{
    set_name(name);
    set_breed(breed);
    female ? set_female() : set_male();
    set_age(age);
    set_lbs(lbs);
    fleas ? set_fleas() : unset_fleas();
}

/**
* Tell Dog to eat.
*/
void Dog::eat() const
{
	cout << "chomp chomp chomp" << endl;
}

/**
* Tell Dog to bark/speak.
*/
void Dog::bark() const
{
	cout << "woof woof woof" << endl;
}

/**
* Tell Dog to scratch (if it has fleas).
*/
void Dog::scratch() const
{
	// Avoiding code branch by storing 'behavior' in string.
	cout << scratch_str;
}

/**
*  Set the name of the Dog.
*
*  @param name Name of the Dog.
*/
void Dog::set_name(const string &name)
{
	this->name = name;
}

/**
*  Set the breed of the Dog.
*
*  @param breed Breed of the Dog.
*/
void Dog::set_breed(const string &breed)
{
	this->breed = breed;
}

/**
*  Set the gender of the Dog to male.
*/
void Dog::set_male()
{
	this->is_fem = false;
}

/**
*  Set the gender of the Dog to female.
*/
void Dog::set_female()
{
	this->is_fem = true;
}

/**
*  Set the age of the Dog.
*
*  @param age Age of the Dog in earth years.
*/
void Dog::set_age(const unsigned int age)
{
	this->age = age;
}

/**
*  Set the weight of the Dog.
*
*  @param lbs Weight of the Dog to the nearest pound.
*/
void Dog::set_lbs(const unsigned int lbs)
{
	this->lbs = lbs;
}

/**
*  Indicate that the Dog has fleas.
*/
void Dog::set_fleas()
{
	scratch_str = "scratch scratch scratch\n";
	fleas = true;
}

/**
*  Indicate that the Dog does not have fleas.
*/
void Dog::unset_fleas()
{
	scratch_str = "";
	fleas = false;
}

/**
*  Get the name of the Dog.
*
*  @return std::string Name of the Dog.
*/
const string& Dog::get_name() const
{
	return name;
}

/**
*  Get the breed of the Dog.
*
*  @return std::string Breed of the Dog.
*/
const string& Dog::get_breed() const
{
	return breed;
}

/**
*  Fetch whether the Dog is female.
*
*  @return bool Whether the Dog is female.
*/
bool Dog::is_female() const
{
	return is_fem;
}

/**
*  Fetch whether the Dog is male.
*
*  @return bool Whether the Dog is male.
*/
bool Dog::is_male() const
{
	return !is_fem;
}

/**
*  Get the age of the Dog in earth years.
*
*  @return unsigned int Age of the Dog in years.
*/
unsigned int Dog::get_age() const
{
	return age;
}

/**
*  Get the weight of the Dog in lbs.
*
*  @return unsigned int Weight of Dog to nearest pound.
*/
unsigned int Dog::get_lbs() const
{
	return lbs;
}

/**
*  Fetch whether the Dog has fleas.
*
*  @return bool Whether the Dog has fleas.
*/
bool Dog::has_fleas() const
{
	return fleas;
}

/**
*  Dump the current state of the Dog to console.
*/
void Dog::dump() const
{
	cout << endl << "Name: " << this->get_name() << endl;
	cout << "Breed: " << this->get_breed() << endl;
	cout << "Gender: " << (this->is_female() ? "Female" : "Male") << endl;
	cout << "Age: " << this->get_age() << endl;
	cout << "Lbs: " << this->get_lbs() << endl;
	cout << "Has Fleas: " << (this->has_fleas() ? "Yes" : "No") << endl;
	eat();
	bark();
	scratch();
}
	    
