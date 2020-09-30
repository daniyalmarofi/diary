#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct note {
    string date;
    string text;
};

//** this function gets the other part of note and concatenates with the first
// part of note
string get_note(string user_input) {
    string temp;
    getline(cin, temp);
    return user_input + temp;
}

//** this function shows the summary of a note.
void show_summary(note note) {
    cout << note.date << endl;
    if (note.text.length() < 20)
        cout << note.text << endl;
    else {
        for (int i = 0; i < 20; i++) cout << note.text[i];
        cout << "..." << endl;
    }
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
        } else if (!userinput.compare("show_day")) {
            string date;
            // get the date that user wants to see
            cin >> date;
            for (auto note : notes)
                if (!note.date.compare(date)) cout << note.text << endl;
        } else {
            // user wants to add a new note so we push back the note to the
            // notes vector
            string text = get_note(userinput);
            note temp;
            temp.date = today;
            temp.text = text;
            notes.push_back(temp);
        }
    }

    return 0;
}