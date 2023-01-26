// ****************************************************************************************************
// Alexander Brittain
// CSC275 UAT
// alexbrittain69@gmail.com
// ****************************************************************************************************

// included libraries
#include <iostream>
#include "Pirates vs Ninjas.h"
using namespace std;

// Establishing classes for the program
// This is the parent class for character creation

// This is the Game Structure class
class Game_Structure {
public:
    void virtual help() {
        cout << "\n This is the help prompt";
    }
};

class Character {
private:
    int health = 100;
public:
    // Attributes to be inherited through all child classes
    string name;

    // Constructor for the Character class -- Which is a default since we are not using it
    Character() {}

    // Setter for health value
    void set_health(int set_h) {
        health = set_h;
        // Checking to make sure the character still has health points left before setting
        // the new value to the health variable.
        if (health <= 0) {
            health = 0;
            cout << "\n Your health is " << health << ", and your character is expired.";
        }
        // Display the health to the user
        cout << "\n Your current health is " << health << endl;
    }
 
        

    // Getter for the health value
    void get_health(int get_h) {
        health = get_h;
    }

    // Basic function that will bring up a specific piece of dialogue within each child class
    void talk(string name, string dialogue) {
        cout << name << " engages in dialogue";
    }

    // Basic attack method that will be different for each class
    virtual void attack() {
        cout << "\n Your attack does 10 hp in damage!\n";
    }

};

// Child class used for the Ninja character type
class Ninja : public Character {
public:
    // constructor for the Ninja class passing in the name of the character
    Ninja(string ninja_name) {
        name = ninja_name;
    }
    // Method for the Ninja class
    void throw_stars() {
        cout << "\n The ninja " << name << " throws ninja stars at the enemy\n";
    }

    // Basic function that will bring up a specific piece of dialogue within each child class
    void talk(string name, string dialogue) {
        cout << name << " says... \" HI-YAAH, Take me to your sensai...\"";
    }

    // Attack method to do damage to the other character
    void attack() {
        cout << "\n Your katana attack deals 25 hp in damage!\n";
    }

    // help method to give the user help during the program
    void virtual help() {
        cout << "\n This is the help prompt for the Ninja class";
    }
};

// Child class used for the Pirate character type
class Pirate : public Character {
public:
    // constructor for the pirate class passing in the name of the character
    Pirate(string pirate_name) {
        name = pirate_name;
    }
    // method for the Pirate class
    void sword_attack() {
        cout << "\n The pirate " << name << " attacks with his sword\n";
    }

    // Basic function that will bring up a specific piece of dialogue within each child class
    void talk(string name, string dialogue) {
        cout << name << "\n says... \" ARRGGH, I wish to parley with yer captain...\"";
    }

    // Attack method to do damage to the other character
    void attack() {
        cout << "\n Your blunderbuss attack deals 25 hp in damage!\n";
    }

    // help method to give the user help during the program
    void virtual help() {
        cout << "\n This is the help prompt for the Pirate class";
    }

};


// Prototyping the functions that are called in the main function
void display_title();

// Main function of the program
int main()
{
    display_title();

    // Create objects from the Base Character class
    Character *player1;
    Character *player2;
    Character player3;

    // Creating objects from the Ninja and Pirate classes from above
    Ninja ninja1("Yoshi");
    Ninja ninja2("Terry Rocky");
    Pirate pirate1("Dave");
    Pirate pirate2("Alabastard");

    // Referring to the pointer of the player1 and player2 objects to use the child class
    // attack() function
    player1 = &ninja1;
    player2 = &pirate1;

    // Calling the methods of the ninja and pirate class on the objects created within them
    ninja1.throw_stars();
    pirate1.sword_attack();
    ninja2.throw_stars();
    pirate2.sword_attack();

    // Using the override attack() function from the child class using a smart pointer
    player1->attack();
    player2->attack();
    
    // Using the attack function from an object of the player class
    player3.attack();

return 0;
}

// The display title function for the user to be welcomed by the program
void display_title()
{
    // Display the title of the program to the user through the console
    cout << "\t\n *** Welcome to Pirates versus Ninjas! ***\n";
}

