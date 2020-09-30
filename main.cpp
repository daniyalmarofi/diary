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
string get_note_text(string user_input) {
    string temp;
    getline(cin, temp);
    return user_input + temp;
}

//** This function shows the  notes of a day
void show_day(vector<note> notes) {
    string date;
    // get the date that user wants to see
    cin >> date;
    for (auto note : notes)
        if (!note.date.compare(date)) cout << note.text << endl;
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

//** This function shows the longest day
void show_the_longest_day(vector<note> notes) {
    note longest = notes[0];
    for (auto note : notes) {
        if (longest.text.length() < note.text.length()) longest = note;
    }
    show_summary(longest);
}

//** This function adds a new note to the vector
void add_note(vector<note>& notes, string today, string userinput) {
    // user wants to add a new note so we push back the note to the
    // notes vector
    string text = get_note_text(userinput);
    note temp;
    temp.date = today;
    temp.text = text;
    notes.push_back(temp);
}

int main() {
    string userinput;
    string today = "";
    vector<note> notes;

    while (cin >> userinput) {
        if (!userinput.compare("start_day")) {
            cin >> today;
        } else if (!userinput.compare("show_day")) {
            show_day(notes);
        } else if (!userinput.compare("show_the_longest_day")) {
            show_the_longest_day(notes);
        } else {
            add_note(notes, today, userinput);
        }
    }

    return 0;
}