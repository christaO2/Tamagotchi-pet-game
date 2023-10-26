#include "Monkey.h"

Monkey::Monkey(string name, int hunger, int boredom, int happiness, int health, int intelligence) : Pet(name, hunger, boredom, happiness, health) {
    this->intelligence = intelligence;
}

Monkey::~Monkey() {}

void Monkey::draw() {
   cout << "            __,__" << endl;
    cout << "   .--.  .\"     \"-.  .--." << endl;
    cout << "  / .. \\/  .-. .-.  \\/ .. \\" << endl;
    cout << " | |  '|  /   Y   \\  |'  | |" << endl;
    cout << " | \\   \\  \\ 0 | 0 /  /   / |" << endl;
    cout << "  \\ '- ,\\.-\"\"\"\"\"\"-./, -' /" << endl;
    cout << "   ''-' /_   ^ ^   _\\ '-'\'" << endl;
    cout << "       |  \\._   _./  |" << endl;
    cout << "       \\   \\ '~' /   /" << endl;
    cout << "        '._ '-=-' _.'," << endl;
    cout << "           '-----'" << endl;

}

void Monkey::save() {
    ofstream file(name + ".txt");
    file << name << " " << hunger << " " << boredom << " " << happiness << " " << health << " " << intelligence << endl;
    file.close();
}

void Monkey::load() {
    ifstream file(name + ".txt");
    if (file.is_open()) {
        file >> name >> hunger >> boredom >> happiness >> health >> intelligence;
        file.close();
    }
}

void Monkey::swing() {
    boredom -= 5;
    happiness += 5;
}

void Monkey::throwBanana() {
    hunger -= 10;
    happiness += 10;
}
void Monkey::play() {
    throwBanana();
    swing();
}