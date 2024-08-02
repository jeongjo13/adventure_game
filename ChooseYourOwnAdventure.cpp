//include libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
using namespace std;

class Game {
    private: //private variables
        int choice;
        bool havewater = false;
        bool havecar = false;
        bool havecarkey = false;
        int money = 5;
        bool havefood = false;
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

        void delay(int dtime) {
            this_thread::sleep_for(chrono::seconds(dtime));
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
        
        void stopAdventure() {
            cout << "Stop Adventure" << endl;
            exit(0);
        }
        
        void error_message(string error_reason) {
            cout << "Something went wrong. If this error keeps happening, you can include the information below and make an issue at https://github.com/jeongjo13/adventure_game/issues/new." << endl;
            cout << error_reason << endl;
            exit(1);
        }
        
        void dragonEggs() {
            cout << "I found some dragon eggs! " << endl;
            cout << "1. Look for dragons" << endl;
            cout << "2. Steal the egg" << endl;
            cout << "3. Stop adventure (Quit Game)" << endl;
            choice = getInput(3);

            if (choice == 1) {
                lookfordragons();
            }
            else if (choice == 2) {
                steal("dragonegg");
            }
            else if (choice == 3) {
                stopAdventure();
            }
        }

        void lookfordragons() {
            cout << "No dragons around here. Maybe I can look for the other places." << endl;
            cout << "1. Walk around and look other places" << endl;
            cout << "2. Stop adventure" << endl;
            choice = getInput(2);

            if (choice == 1) {
                lookOtherPlaces();
            }
            else if (choice == 2) {
                cout << "Stop Adventure" << endl;
                exit(0);
            }
        }
        
        void lookOtherPlaces() {
            cout << "I found the dragon! What should I do now?" << endl;
            cout << "1. give some food to the dragon" << endl;
            cout << "2. say \'hello\' to the dragon" << endl;
            cout << "3. give some water to the dragon" << endl;
            cout << "4. stop adventure" << endl;
            
            choice = getInput(4);
            if (choice == 1) {
                givefood("dragon");
            }
            else if (choice == 2) {
                sayhello("dragon");
            }
            else if (choice == 3) {
                givewater("dragon");
            }
            else if (choice == 4) {
                stopAdventure();
            }
            else {
                error_message("Value \'choice\' should be 1~4 but it is not.");
            }
        }
        
        void givefood(string towho) {
            if (towho == "dragon") {
                cout << "I have not food for now. Maybe I can give it some water or do something else." << endl;
                cout << "1. Give dragon some water" << endl;
                cout << "2. Say \'Hello\' to it" << endl;
                cout << "3. stop adventure" << endl;
                
                choice = getInput(3);
                
                if (choice == 1) {
                    givewater("dragon");
                }
                
                else if (choice == 2) {
                    sayhello("dragon");
                }
                else if (choice == 3) {
                    stopAdventure();
                }
                else {
                    error_message("Value \'choice\' should be 1~3 but it is not.");
                }
            }
        }
        
        void sayhello(string towho) {
            if (towho == "dragon") {
                cout << towho + " does not know English. Try with another language." << endl;
                cout << "1. Korean" << endl;
                cout << "2. Chinese" << endl;
                
                choice = getInput(2);
                
                if (choice == 1) {
                    cout << "Dragon does not know \"안녕하세요\" (Hello in Korean) so maybe we can try Chinese. Press Enter key to continue" << endl;
                    string temp;
                    getline(cin, temp);
                }
                if (choice == 1 || choice == 2) {
                    cout << "Dragon does understand Nǐ hǎo (Hello in Chinese). That\'s good!" << endl;
                    cout << "1. Give some water to the dragon" << endl;
                    cout << "2. Stop Adventure" << endl;
                    
                    choice = getInput(2);
                    
                    if (choice == 1) {
                        givewater("dragon");
                    }
                    else if (choice == 2) {
                        stopAdventure();
                    }
                    else {
                        error_message("Vaule \'choice\' should be 1~2 but it is not.");
                    }
                }
                else {
                    error_message("Vaule \'choice\' should be 1~2 but it is not.");
                }
            }
        }
        
        void givewater(string towho) {
            if (towho == "dragon") {
                if (havewater == false) {
                    cout << "I don\'t have water. I think I could look around for water." << endl;
                    cout << "1. Look for water" << endl;
                    cout << "2. Just stop adventure" << endl;

                    choice = getInput(2);

                    if (choice == 1) {
                        lookforwater();
                    }
                    else if (choice == 2) {
                        stopAdventure();
                    }
                    else {
                        error_message("Vaule \'choice\' should be 1~2 but it is not.");
                    }
                }
                else if (havewater == true) {
                    cout << "giving water to the dragon. Please wait..." << endl;
                    delay(5);
                    cout << "I\'m done giving some water. Let me have some water." << endl;
                    delay(3);
                    cout << "----------" << endl;
                    havewater = false;
                    cout << "I\'m done drinking some water. What should I do know?" << endl;
                    cout << "1. Go home" << endl;
                    cout << "2. Stop adventure" << endl;

                    choice = getInput(2);

                    if (choice == 1) {
                        goHome();
                    }
                    else if (choice == 2) {
                        stopAdventure();
                    }
                    else {
                        error_message("Vaule \'choice\' should be 1~2 but it is not.");
                    }
                }
            }
        }

        void goHome() {
            cout << "Choose the way to go home." << endl;
            cout << "1. Use the car" << endl;
            cout << "2. Walk all way to home" << endl;
            cout << "3. Stop adventure" << endl;

            choice = getInput(3);

            if (choice == 1) {
                cout << "What way should I go?" << endl;
                cout << "1. Go to interstate 2" << endl;
                cout << "2. Go to interstate 10" << endl;
                cout << "3. Go to interstate 90" << endl;
                cout << "4. Go to interstate 94" << endl;

                choice = getInput(4);

                if (choice == 1 || choice == 2 || choice == 4) {
                    cout << "Wrong Way. Maybe you can search some information on google maps." << endl;
                    delay(7);
                    cout << "After you are done, you can hit Enter and continue the adventure. " << endl;
                    string temp;
                    getline(cin, temp);
                    cout << "Now that I know the way, maybe I can head home." << endl;
                    delay(1);
                }
                cout << "Heading home..." << endl;
                delay(3);
                useCar();
            }
            else if (choice == 2) {
                cout << "Walking all way home..." << endl;
                delay(3);
                cout << "My house is far away from here, so I can not walk all way home. Please try again." << endl;
                cout << "----------" << endl;
                cout << "[Error] You died!\nYou were walking all way home and you had no energy to walk all way home." << endl;
                playAgain();
            }
        }

        void level2() {
            cout << "Let\'s start level 2!" << endl;
            delay(1);
            money += 15; //give 15 dollars to the player (player should have 20 dollars after this command)
            cout << "Find some water and foods to eat while having an adventure." << endl;
            cout << "----------\n1. Look inside my house" << endl;
            cout << "2. Buy some water and foods at the Target" << endl;
            cout << "3. Stop adventure" << endl;
            
            choice = getInput(3);

            if (choice == 1) {
                cout << "There\'s no foods and water in my house! I should go to the Target and buy some of them." << endl;
                cout << "----------\n1. Go to Target and buy some of them" << endl;
                cout << "2. Stop adventure" << endl;

                choice = getInput(2);

                if (choice == 1) {
                    gotoTarget("foods");
                    gotoTarget("water");
                    start_second_adventure();
                }
                else if (choice == 2) {
                    stopAdventure();
                }
                else {
                    error_message("\'choice\' should be 1~2.");
                }
            }
            else if (choice == 2) {
                gotoTarget("foods");
                gotoTarget("water");
                start_second_adventure();
            }
            else if (choice == 3) {
                stopAdventure();
            }
            else {
                error_message("Unknown Error");
            }
        }

        void start_second_adventure() {
            cout << "----------\nNow we can start the adventure!" << endl;
            delay(2);
            cout << "----------" << endl;
            notDeveloped();
        }

        void gotoTarget(string buywhat) {
            if (buywhat == "foods") {
                cout << "I have " << money << " dollars now. The foods are sold for 15 dollars." << endl;
                cout << "1. buy it" << endl;
                cout << "2. don\'t buy it" << endl;

                choice = getInput(2);

                if (choice == 1) {
                    money -= 15;
                    cout << "I bought some foods. Now I have " << money << " dollars. " << endl;
                }
                else if (choice == 2) {
                    cout << "I\'m not buying foods." << endl;
                }
            }
            else if (buywhat == "water") {
                cout << "I have " << money << " dollars now. One bottle of water is sold for 3 dollars." << endl;
                cout << "1. buy it" << endl;
                cout << "2. don\'t buy it" << endl;

                choice = getInput(2);

                if (choice == 1) {
                    money -= 3;
                    cout << "I bought some water. Now I have " << money << " dollars. " << endl;
                }
                else if (choice == 2) {
                    cout << "I\'m not buying water." << endl;
                }
            }
        }

        void useCar() {
            if (havecar == true) {
                if (havecarkey == true) {
                    cout << "Heading home..." << endl;
                    delay(3);
                    cout << "I got to home sucessfully! This is the end of the Adventure!" << endl;
                    delay(2);
                    cout << "----------" << endl;
                    cout << "[Info] You won the game! Thanks for playing this game. Do you want to continue to the next level?" << endl;
                    cout << "----------" << endl;
                    cout << "1. Go to next level (level 2)" << endl;
                    cout << "2. Quit game" << endl;
                    
                    choice = getInput(2);

                    if (choice == 1) {
                        cout << "----------\nStarting level 2" << endl;
                        delay(2);
                        level2();
                    }
                    if (choice == 2) {
                        cout << "Quit Game" << endl;
                        exit(0);
                    }
                }
                else {
                    cout << "I do not have car key. I should find it." << endl;
                    cout << "1. Look around" << endl;
                    cout << "2. Just break the car" << endl;

                    choice = getInput(2);

                    if (choice == 1) {
                        cout << "I found the car key!" << endl;
                        havecarkey = true;
                        useCar();
                    }
                    else if (choice == 2) {
                        cout << "I can\'t break the car. " << endl;
                        cout << "----------" << endl;
                        cout << "[Error] You have no energy because you used energy breaking the car. Please start over." << endl;
                        cout << "----------" << endl;
                        playAgain();
                    }
                }
            }
            else if (havecar == false) {
                cout << "Well, I should find the car." << endl;
                cout << "1. Look for car" << endl;
                cout << "2. Just stop adventure" << endl;

                choice = getInput(2);

                if (choice == 1) {
                    cout << "I found a car." << endl;
                    havecar = true;
                    useCar();
                }
                else if (choice == 2) {
                    stopAdventure();
                }
                else {
                    error_message("Unknown error");
                }
            }
        }

        void lookforwater() {
            cout << "Where should I look?" << endl;
            cout << "1. Inside the cactus" << endl;
            cout << "2. Look for oasis" << endl;
            cout << "3. Stop adventure" << endl;

            choice = getInput(3);

            if (choice == 1) {
                cout << "There is a water inside the cactus. Now I can give some water to the dragon." << endl;
                delay(1);
                cout << "----\n[Info] Press Enter to continue.\n----" << endl;
                string temp;
                getline(cin, temp);
                havewater = true;
                givewater("dragon");
            }
            else if (choice == 2) {
                cout << "I found some oasis around here!" << endl;
                cout << "----\n[Info] Press Enter to continue\n----" << endl;
                string temp;
                getline(cin, temp);
                havewater = true;
                givewater("dragon");
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
                    delay(2);
                    cout << "I got eaten!" << endl;
                    delay(1);
                    cout << "----------\n[Info] You died! Maybe you can start over: \n----------" << endl;
                    playAgain();
                }
                else if (choice == 2) {
                    stopAdventure();
                }
            }
        }

        void getCar() {
            havecar = true;
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
            cout << "After you find some informations, you can hit Enter." << endl;
            string temp;
            getline(cin, temp);
            cout << "Now that you find some informations, you can look for dragon eggs or do another task." << endl;
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
