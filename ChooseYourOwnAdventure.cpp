//include libraries
#include <iostream>
#include <string>
#include <cstdlib>
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
            cout << "2. Go get a car" << endl;
            cout << "3. Go to the highway" << endl;
            cout << "4. Search on the internet (google, mintwiki, etc.)" << endl;
            choice = getInput(5);

            if (choice == 1) {
                dragonEggs();
            }
            else if (choice == 2) {
                getCar();
            }
            else if (choice == 3) {
                gotoHighway();
            }
            else if (choice == 4) {
                searchInternet("dragon");
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
            choice = getInput(3);

            if (choice == 1) {
                cout << "Play Again: " << endl;
                new Game();
            }
            else if (choice == 2) {
                cout << "Quit Game." << endl;
                exit(0);
            }
            else {
                cout << "Invaild Vaule. Quit Game." << endl;
                exit(1);
            }
        }
        
        void notDeveloped() {
            cout << "This fuction is not developed yet. Please try again later." << endl;
            exit(1);
        }
        void dragonEggs() {
            cout << "I found some dragon eggs! ";
            cout << "1. Look for dragons" << endl;
            cout << "2. Steal the egg" << endl;
            cout << "3. Stop adventure (Quit Game)" << endl;
            choice = getInput(3);

            if (choice == 1) {
                lookfordragons();
            }
            else if (choice == 2) {
                notDeveloped();
                steal("dragonegg");
            }
            else if (choice == 3) {
                cout << "Stop adventure" << endl;
                exit(0);
            }
        }

        void lookfordragons() {
            cout << "No dragons around here. Maybe I can look for the other places." << endl;
            cout << "1. Walk around and look other places" << endl;
            cout << "2. Stop adventure" << endl;
            choice = getInput(2);

            if (choice == 1) {
                notDeveloped();
            }
            else if (choice == 2) {
                cout << "Stop Adventure" << endl;
                exit(0);
            }
        }

        void steal(string whatSteal) {
            if (whatSteal == "dragonegg") {
                cout << "I stealed the dragon\'s egg, but dragon is chasing me!" << endl;
                cout << "1. run away" << endl;
                cout << "2. stop adventure" << endl;

                choice = getInput(2);

                if (choice == 1) {
                    cout << "Dragon is faster than me! Soon, dragon will eat me!" << endl;
                    cout << "I got eaten!" << endl;
                    cout << "----------\n[Info] You died! Maybe you can start over: \n----------" << endl;
                    playAgain();
                }
                else if (choice == 2) {
                    cout << "stop adventure" << endl;
                    exit(0);
                }
            }
        }

        void getCar() {
            cout << "I found a car in the road but I have no key to take the car. Let\'s just find some dragon eggs." << endl;
            dragonEggs();
        }

        void gotoHighway() {
            cout << "I found some dragon\'s footprints!" << endl;
            cout << "1. Follow footprints" << endl;
            cout << "2. Search more information in the internet" << endl;

            choice = getInput(2);
            if (choice == 1) {
                dragonEggs();
            }
            else if (choice == 2) {
                searchInternet("dragon_footprint");
            }
        }

        void searchInternet(string keyword) {
            cout << "Where are you going to search \'" + keyword + "\'?" << endl;
            cout << "1. Google" << endl;
            cout << "2. Mintwiki" << endl;
            choice = getInput(2);
            if (choice == 1) {
                cout << "Open \'https://google.com/search?q=" + keyword + "\'." << endl;
            }
            else if (choice == 2) {
                cout << "Open \'https://mint.wikive.cc/search/" + keyword + "\'." << endl;
            }

            if (keyword == "dragon") {
                afterSearchdragon();
            }
            else if (keyword == "dragon_footprint") {
                afterSearchdragonfootprint();
            }
        }
        void afterSearchdragon() {
            cout << "After you find some informations, you can look for dragon eggs or do another task." << endl;
            cout << "1. look for dragon eggs" << endl;
            cout << "2. Go get a car" << endl;
            cout << "3. Go to the highway" << endl;
            choice = getInput(3);
            if (choice == 1) {
                dragonEggs();
            }
            else if (choice == 2) {
                getCar();
            }
            else if (choice == 3) {
                gotoHighway();
            }
        }
        void afterSearchdragonfootprint() {
            string temp;
            cout << "After you receive some information, you can hit enter." << endl;
            getline(cin, temp);
            cout << "I received some information about footprints, so I am going to follow that footprints!" << endl;
            dragonEggs();
        }
};
int main() {
    Game game1;
    return 0;
}
