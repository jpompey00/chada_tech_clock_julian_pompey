
#include <iostream>
#include <string>
#include "TimeClock.cpp"

using namespace std;


class CLI {
public:
    TimeClock clock;
    
    //the logic that interacts with the clock Class that does the main logic.
    void commandLineInterface() {
        int input;
        bool active = true;
        clock.inputTime();
        while (active) {

            mainMenu();


            cin >> input;
            switch (input) {
            case 1:

                if (confirmation(1)) {
                    clock.addHour(clock);
                    break;
                }
                else {
                    clock.displayTime(clock.hour, clock.minute, clock.second, clock.timeOfDay);
                    break;
                }
            case 2:
                if (confirmation(2)) {
                    clock.addMinute(clock);
                    break;
                }
                else {
                    clock.displayTime(clock.hour, clock.minute, clock.second, clock.timeOfDay);
                    break;
                }
            case 3:
                if (confirmation(3)) {
                    clock.addSecond(clock);
                    break;
                }
                else {
                    clock.displayTime(clock.hour, clock.minute, clock.second, clock.timeOfDay);
                    break;
                }
               
            case 4:
                if (confirmation(4)) {
                    active = false;
                }
                else {
                    clock.displayTime(clock.hour, clock.minute, clock.second, clock.timeOfDay);
                    break;
                }
            }
        }

        



    }

    //Handles the logic behind the Y/N confirmation
    bool confirmation(int response) {
        string input;


        do {
            switch (response) {
            case 1:
                cout << endl;
                cout << "Add an Hour? Y/N" << endl;
                cout << endl;
                break;
            case 2:
                cout << endl;
                cout << "Add a Minute? Y/N" << endl;
                cout << endl;
                break;
            case 3:
                cout << endl;
                cout << "Add a Second? Y/N" << endl;
                cout << endl;
                break;
            case 4:
                cout << endl;
                cout << "End? Y/N" << endl;
                cout << endl;
                break;
            }
            cin >> input;
        } while (!((strcmp(input.c_str(), "Y") == 0) ||
            (strcmp(input.c_str(), "N") == 0)));

        if ((strcmp(input.c_str(), "Y") == 0)) {
            return true;
        }
        else {
            return false;
        }
    }

    // The formatting of the Main Menu
    void mainMenu() {

        cout << setfill('*') << setw(26) << "*" << endl; //line of stars
        cout << "* "; //star for the start of the line
        cout << "1 - Add One Hour";
        cout << setfill(' ') << setw(6) << " "; //spacing
        cout << " *" << endl; //star for the end

        cout << "* "; //star for the start of the line
        cout << "2 - Add One Minute";
        cout << setfill(' ') << setw(4) << " "; //spacing
        cout << " *" << endl; //star for the end

        cout << "* "; //star for the start of the line
        cout << "3 - Add One Second";
        cout << setfill(' ') << setw(4) << " "; //spacing
        cout << " *" << endl; //star for the end

        cout << "* "; //star for the start of the line
        cout << "4 - Exit Program";
        cout << setfill(' ') << setw(6) << " "; //spacing
        cout << " *" << endl; //star for the end
        cout << setfill('*') << setw(26) << "*" << endl; //line of stars
        cout << endl;

   


    }


};
