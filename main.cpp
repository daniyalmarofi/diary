#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct note {
    string date;
    string text;
};

//** this function gets the other part of note and concatenates with the first part of note
string get_note(string user_input) {
    string temp;
    getline(cin, temp);
    return user_input + temp;
}

int main() {
    string userinput;
    string today = "";
    vector<note> notes;

    while (cin >> userinput) {
        if (!userinput.compare("start_day")) {
            char temp;
            // get today
            cin >> today;
        } else {
            // user wants to add a new note so we push back the note to the notes vector
            string text = get_note(userinput);
            note temp;
            temp.date = today;
            temp.text = text;
            notes.push_back(temp);
        }
    }

    return 0;
}