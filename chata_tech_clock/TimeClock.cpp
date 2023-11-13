
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;



class TimeClock {
public:


    int hour;
    int minute;
    int second;
    string timeOfDay;

    //adds the respective times and then displays the results
    void addHour(TimeClock clock) {


        clock.hour = clock.hour + 1;
        if (clock.hour == 12) {
            if (clock.timeOfDay == "AM") {
                clock.timeOfDay = "PM";
            }
            else {
                clock.timeOfDay = "AM";
            }
        }
        if (clock.hour > 12) {
            clock.hour = 1;

        }

        hour = clock.hour;
        minute = clock.minute;
        second = clock.second;
        timeOfDay = clock.timeOfDay;

        displayTime(hour, minute, second, timeOfDay);

    }

    void addMinute(TimeClock clock) {
        clock.minute = clock.minute + 1;
        if (clock.minute > 59) {
            clock.minute = 0;
            addHour(clock);
        }
        else {
            hour = clock.hour;
            minute = clock.minute;
            second = clock.second;
            timeOfDay = clock.timeOfDay;
            displayTime(hour, minute, second, timeOfDay);
        }

    }

    void addSecond(TimeClock clock) {
        clock.second = clock.second + 1;
        if (clock.second > 59) {
            clock.second = 0;
            addMinute(clock);
        }
        else {
            hour = clock.hour;
            minute = clock.minute;
            second = clock.second;
            timeOfDay = clock.timeOfDay;
            displayTime(hour, minute, second, timeOfDay);
        }
    }


    //handles the conversion between AM and PM
    int convertTime(int hours, string timeOfDay) {


        if (timeOfDay == "AM") {
            if (hours == 12) {
                hours = 0;
            }
        }
        else {
            if (hours != 12) {
                hours = hours + 12;
            }
        }

        return hours;
    }

    //displays the time and handles the formatting of the time GUI
    void displayTime(int hours, int minutes, int seconds, string timeOfDay) {

        //26 wide
        //spacing for 4 between the clocks

        cout << endl;
   
        //line 1
        cout << setfill('*') << setw(26) << "*"; //line of stars
        cout << setfill(' ') << setw(4) << "";
        cout << setfill('*') << setw(26) << "*" << endl;

        //line 2-1
        cout << "* "; //star for the start of the line
        cout << setfill(' ') << setw(5) << " "; //spacing
        cout << "12-Hour Clock"; //put text here
        cout << setfill(' ') << setw(4) << " "; //spacing
        cout << " *"; //star for the end
        //line 2-2
        cout << setfill(' ') << setw(4) << ""; //spacing for the area between the two clocks
        cout << "* "; //star for the start of the line
        cout << setfill(' ') << setw(5) << " "; //spacing
        cout << "24-Hour Clock"; //put text here
        cout << setfill(' ') << setw(4) << " "; //spacing
        cout << " *" << endl; //star for the end

        //line 3
        cout << endl;

        //line 4-1
        cout << "* "; //star for the start of the line
        cout << setfill(' ') << setw(5) << " "; //spacing
        cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << " " << timeOfDay; //put text here
        cout << setfill(' ') << setw(6) << " "; //spacing
        cout << " *"; //star for the end
        //line 4-2
        cout << setfill(' ') << setw(4) << ""; //spacing for the area between the two clocks
        cout << "* "; //star for the start of the line
        cout << setfill(' ') << setw(5) << " "; //spacing
        cout << setfill('0') << setw(2) << convertTime(hours, timeOfDay) << ":" << setw(2) << minutes << ":" << setw(2) << seconds; //put text here
        cout << setfill(' ') << setw(9) << " "; //spacing
        cout << " *" << endl; //star for the end


        //line5
        cout << setfill('*') << setw(26) << "*"; //line of stars
        cout << setfill(' ') << setw(4) << "";
        cout << setfill('*') << setw(26) << "*" << endl;

        cout << endl;


    }

    //function called when program starts, asks for the time and ensures they don't enter any bad values.
    void inputTime() {

        int inputtedHours;
        int inputtedMinutes;
        int inputtedSeconds;
        string inputtedTimeOfDay;


        cout << "What time is it?" << endl;
        cout << endl;


        cout << "Hours: " << endl;
        cout << endl;
        //needs to be between 1-12
        cin >> inputtedHours;
        hour = inputtedHours;
        while (inputtedHours<1 || inputtedHours >12) {
            cout << "Please enter a number between 1 and 12" << endl;
            cin >> inputtedHours;
            hour = inputtedHours;
        }
        cout << endl;
        cout << "Minutes: " << endl;
        cout << endl;
        //needs to be between 0-60
        cin >> inputtedMinutes;
        minute = inputtedMinutes;
        while (inputtedMinutes < 0 || inputtedMinutes >60) {
            cout << "Please enter a number between 0 and 60" << endl;
            cin >> inputtedMinutes;
            minute = inputtedMinutes;
        }
        cout << endl;
        cout << "Seconds: " << endl;
        cout << endl;
        //needs to be between 0-60
        cin >> inputtedSeconds;
        second = inputtedSeconds;
        while (inputtedSeconds < 0 || inputtedSeconds >60) {
            cout << "Please enter a number between 0 and 60" << endl;
            cin >> inputtedSeconds;
            second = inputtedSeconds;
        }

        //makes sure user input is AM or PM
        do {
            cout << endl;
            cout << "AM or PM: " << endl;
            cout << endl;
            cin >> inputtedTimeOfDay;

        } while (!((strcmp(inputtedTimeOfDay.c_str(), "AM") == 0) ||
            (strcmp(inputtedTimeOfDay.c_str(), "PM") == 0)));


            timeOfDay = inputtedTimeOfDay;



        
        displayTime(hour, minute, second, timeOfDay);
    }





};