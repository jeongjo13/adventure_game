#include <iostream>
#include <string>
using namespace std;

class Game {
    private: //private variables

    public:
        Game() {

        }
    private: //private methods
        int getInput(int numChoices) {
            string input;
            getline(cin, input);

            return stoi(input); //convert 'input' to int and then return it
        }
};
int main() {
    
    return 0;
}
