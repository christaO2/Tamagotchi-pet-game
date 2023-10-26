#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "pet.h"
#include "Dog.h"
#include "Turtle.h"
#include "Monkey.h"

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void printMenu() {
    cout << "  _______                                _       _     _   _____     _      _____                      " << endl;
    cout << " |__   __|                              | |     | |   (_) |  __ \\   | |    / ____|                     " << endl;
    cout << "    | | __ _ _ __ ___   __ _  __ _  ___ | |_ ___| |__  _  | |__) |__| |_  | |  __  __ _ _ __ ___   ___ " << endl;
    cout << "    | |/ _` | '_ ` _ \\ / _` |/ _` |/ _ \\| __/ __| '_ \\| | |  ___/ _ \\ __| | | |_ |/ _` | '_ ` _ \\ / _ \\" << endl;
    cout << "    | | (_| | | | | | | (_| | (_| | (_) | || (__| | | | | | |  |  __/ |_  | |__| | (_| | | | | | |  __/" << endl;
    cout << "    |_|\\__,_|_| |_| |_|\\__,_|\\__, |\\___/ \\__\\___|_| |_|_| |_|   \\___|\\__|  \\_____|\\__,_|_| |_| |_|\\___|" << endl;
    cout << "                                __/ |                                                                      " << endl;
    cout << "                               |___/                                                                       " << endl;
    cout << "============================" << endl;
    cout << "1. Create a new pet" << endl;
    cout << "2. Load a pet" << endl;
    cout << "3. Exit" << endl;
    cout << "============================" << endl;
}

void printPetActions(Pet* pet) {
    cout << "==== " << pet->getName() << " ====" << endl;
    cout << "Hunger: " << pet->getHunger() << endl;
    cout << "Boredom: " << pet->getBoredom() << endl;
    cout << "Happiness: " << pet->getHappiness() << endl;
    cout << "Health: " << pet->getHealth() << endl;
    pet ->draw();
    cout << "==== " << pet->getName() << " ====" << endl;
    cout << "1. Play" << endl;
    cout << "2. Feed" << endl;
    cout << "3. Sleep" << endl;
    cout << "4. Save" << endl;
    cout << "5. Exit" << endl;
    cout << "============================" << endl;
}

int main() {
    srand(time(NULL));
    clearScreen();
    int choice = 0;
    Pet* pet = nullptr;
    while (choice != 3) {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        clearScreen();
        switch (choice) {
            case 1: {
                int petChoice = 0;
                cout << "Choose a pet type: " << endl;
                cout << "1. Dog" << endl;
                cout << "2. Turtle" << endl;
                cout << "3. Monkey" << endl;
                cout << "Enter your choice: ";
                cin >> petChoice;
                clearScreen();
                string name;
                cout << "Enter a name for your pet: ";
                cin >> name;
                clearScreen();
                switch (petChoice) {
                    case 1: {
                        pet = new Dog(name);
                        break;
                    }
                    case 2: {
                        pet = new Turtle(name);
                        break;
                    }
                    case 3: {
                        pet = new Monkey(name);
                        break;
                    }
                    default: {
                        cout << "Invalid choice" << endl;
                        break;
                    }
                }
                break;
            }
            case 2: {
                string name;
                cout << "Enter the name of the pet you want to load: ";
                cin >> name;
                clearScreen();
                pet = new Pet(name);
                pet->load();
                break;
            }
            case 3: {
                cout << "Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
        while (pet != nullptr) {
            printPetActions(pet);
            int petChoice = 0;
            cout << "Enter your choice: ";
            cin >> petChoice;
            clearScreen();
            switch (petChoice) {
                case 1: {
                    pet->play();
                    break;
                }
                case 2: {
                    pet->feed();
                    break;
                }                
                case 3:
                    pet->sleep();
                    break;
                case 4:
                    pet->save();
                    cout << "Pet saved." << endl;
                    break;
                case 5:
                    delete pet;
                    pet = nullptr;
                    break;
                default:
                    cout << "Invalid choice, please try again." << endl;
                    break;
            }
            if (pet != nullptr) {
                if (pet->getHunger() >= 40) {
                    cout << pet->getName() << " is hungry!" << endl;
                }
                if (pet->getBoredom() >= 40) {
                    cout << pet->getName() << " is bored!" << endl;
                }
                if (pet->getHappiness() >= 80) {
                    cout << pet->getName() << " is very happy!" << endl;
                }
                if (pet->getHealth() <= 30) {
                    cout << pet->getName() << " is very sick!" << endl;
                }
            }
        }
    } while (choice != 3);
    return 0;
}   