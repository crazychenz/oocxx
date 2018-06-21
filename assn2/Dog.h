#include <string>

/* Note: Not using namespace std to avoid inadvertent includer collisions. */

/**
* @class Dog
* @brief Simple class to model a Dog.
*
* This assignment involves writing a program that models a dog. A dog has a name, a breed
* (which may be unknown), a gender (male or female), an age (in months), and a weight (in
* pounds). And a dog may or may not have fleas. Dog behaviors include eating ( "chomp
* chomp chomp" ), barking ( "woof woof woof" ), and scratching fleas if a dog has any ( you
* can determine what this sound should be). Design a Dog class that models the attributes
* and behaviors described above. Provide appropriate class constructors, getter methods,
* setter methods, and any other methods you think are necessary to model a dog. Write a
* program that creates at least two dogs, invokes their behaviors, and displays their
* attributes.
*
*/
class Dog
{
	public:
		/** 
		* Default constructor.
		*/
		Dog();

		/**
		* Explicit Constructor.
		* @param name Name of the Dog.
		* @param breed Breed of the Dog.
		* @param female True is Dog is female, False if Dog is male.
		* @param age Age of Dog in earth years.
		* @param lbs Weight of Dog to nearest pound.
		* @param fleas Indicate whether Dog has fleas.
		*/
		Dog(const std::string& name, const std::string& breed, 
			const bool female, const unsigned int age,
			const unsigned int lbs, const bool fleas);

		/**
		* Tell Dog to eat.
		*/
	    void eat() const;

		/**
		* Tell Dog to bark/speak.
		*/
	    void bark() const;

		/**
		* Tell Dog to scratch (if it has fleas).
		*/
	    void scratch() const;
	    
		/**
		*  Set the name of the Dog.
		*  
		*  @param name Name of the Dog.
		*/
	    void set_name(const std::string &name);

		/**
		*  Set the breed of the Dog.
		*
		*  @param breed Breed of the Dog.
		*/
	    void set_breed(const std::string &breed);

		/**
		*  Set the gender of the Dog to male.
		*/
	    void set_male();

		/**
		*  Set the gender of the Dog to female.
		*/
	    void set_female();

		/**
		*  Set the age of the Dog.
		*
		*  @param age Age of the Dog in earth years.
		*/
	    void set_age(const unsigned int age);

		/**
		*  Set the weight of the Dog.
		*
		*  @param lbs Weight of the Dog to the nearest pound.
		*/
	    void set_lbs(const unsigned int lbs);

		/**
		*  Indicate that the Dog has fleas.
		*/
	    void set_fleas();

		/**
		*  Indicate that the Dog does not have fleas.
		*/
		void unset_fleas();
	    
		/**
		*  Get the name of the Dog.
		*
		*  @return std::string Name of the Dog.
		*/
	    const std::string& get_name() const;

		/**
		*  Get the breed of the Dog.
		*
		*  @return std::string Breed of the Dog.
		*/
	    const std::string& get_breed() const;

		/**
		*  Fetch whether the Dog is female.
		*
		*  @return bool Whether the Dog is female.
		*/
	    bool is_female() const;

		/**
		*  Fetch whether the Dog is male.
		*
		*  @return bool Whether the Dog is male.
		*/
	    bool is_male() const;

		/**
		*  Get the age of the Dog in earth years.
		*
		*  @return unsigned int Age of the Dog in years.
		*/
	    unsigned int get_age() const;

		/**
		*  Get the weight of the Dog in lbs.
		*
		*  @return unsigned int Weight of Dog to nearest pound.
		*/
	    unsigned int get_lbs() const;

		/**
		*  Fetch whether the Dog has fleas.
		*
		*  @return bool Whether the Dog has fleas.
		*/
	    bool has_fleas() const;
	    
		/**
		*  Dump the current state of the Dog to console.
		*/
	    void dump() const;
	    
	private:
		/** Name of the Dog. */
		std::string name = "No Name";

		/** Breed of the Dog */
		std::string breed = "Unknown";

		/** Gender of the Dog. */
		bool is_fem = false;

		/** Age of the Dog in years. */
		int age = 0;

		/** Weight of the Dog in lbs. */
		int lbs = 0;

		/** String to print if Dog is scratching. */
		std::string scratch_str = "";

		/** Whether the Dog has fleas or not. */
		bool fleas = false;
};