//include libraries
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Game {
    private: //private variables
        int choice;
    public:
        Game() {
            /*
            Prompt
            option 1
            option 2
            option 3
            ...
            */

            cout << "Find a dragon" << endl;
            cout << "1. Look for dragon eggs" << endl;
            cout << "2. Ask directions" << endl;
            cout << "3. Go get a car" << endl;
            cout << "4. Go to the highway" << endl;
            cout << "5. Search on the internet (google, mintwiki, etc.)" << endl;
            choice = getInput(5);

            if (choice == 1) {
                //dragonEggs();
            }
            else if (choice == 2) {
                //askDirections("dragon");
            }
            else if (choice == 3) {
                //getCar();
            }
            else if (choice == 4) {
                //gotoHighway();
            }
            else if (choice == 5) {
                //searchInternet("dragon");
            }

            playAgain();
        }
    private: //private methods
        int getInput(int numChoices) {
            while (true) {
                string input;
                cout << "Select one option from above: ";
                getline(cin, input);

                try {
                    int num = stoi(input); //convert 'input' to an int value and save it to 'num'
                    if (num > 0 && num <= numChoices) {
                        return num;
                    }
                    else {
                        cout << "Invaild Value. The value\'s type has to be \'int\' and it should be between 1 and " + to_string(numChoices) + ". Try again: " << endl;
                    }
                }
                catch (invalid_argument) {
                    cout << "Invaild Value. The value\'s type has to be \'int\' and it should be between 1 and " + to_string(numChoices) + ". Try again: " << endl;
                }
            }
        }

        void playAgain() {
            cout << endl;
            cout << "Would you like to play this game again?" << endl;
            cout << "1. Yes!" << endl;
            cout << "2. No." << endl;
            choice = getInput(2);

            if (choice == 1) {
                cout << "Play Again: " << endl;
                new Game();
            }
            else if (choice == 2) {
                cout << "Quit Game." << endl;
            }
            else {
                cout << "Invaild Vaule. Quit Game." << endl;
            }
        }
};
int main() {
    
    return 0;
}
