//include libraries
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

            try {
                int num = stoi(input); //convert 'input' to an int value and save it to 'num'
                if (num > 0 && num <= numChoices) {
                    return num;
                }
                else {
                    cout << "Please enter a vaild value. The value\'s type has to be \'int\' and it should be between 1 and " + to_string(numChoices) + "." << endl;
                }
            }
            catch (invalid_argument) {
                cout << "Please enter a vaild value. The value\'s type has to be \'int\' and it should be between 1 and " + to_string(numChoices) + "." << endl;
            }
        }
};
int main() {
    
    return 0;
}
