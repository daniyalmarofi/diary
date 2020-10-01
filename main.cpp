#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct note {
    string date;
    string text;
};

//** This function gets the other part of note and concatenates with the first part of note
string get_note_text(string user_input) {
    string temp;
    getline(cin, temp);
    return user_input + temp;
}

//** This function adds a new note to the vector
void add_note(vector<note>& notes, string today, string userinput) {
    // user wants to add a new note so we push back the note to the
    // notes vector
    bool flag = false;
    string text = get_note_text(userinput);
    for (auto note : notes) {
        if (!note.date.compare(today)) {
            text = note.text + "\n" + text;
            flag = true;
        }
    }
    if (flag) notes.pop_back();

    note temp;
    temp.date = today;
    temp.text = text;
    notes.push_back(temp);
}

//** This function shows the  notes of a day
void show_day(vector<note> notes) {
    string date;
    // get the date that user wants to see
    cin >> date;
    for (auto note : notes)
        if (!note.date.compare(date)) cout << note.text << endl;
}

//** This function shows the summary of a note.
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

//** This function reads the positive words
vector<string> read_positive_words() {
    vector<string> positive_words;
    ifstream fin;
    fin.open("positive-words.txt");
    string temp;
    while (fin >> temp) positive_words.push_back(temp);
    fin.close();
    return positive_words;
}

//** This function counts the number of occurrence of a word in a text
int count_occurrence(string text, string word) {
    int occurrence = 0;
    int offset = text.find(word);
    while (offset != string::npos) {
        if ((offset + word.length() == text.length() ||
             text[offset + word.length()] == ' ' ||
             text[offset + word.length()] == '\n') &&
            (offset == 0 || (offset > 0 && text[offset - 1] == ' ') ||
             (offset > 0 && text[offset - 1] == '\n')))
            occurrence++;
        offset = text.find(word, offset + word.length());
    }
    return occurrence;
}

//** This function counts the positive words
int count_positives(string text, vector<string> positive_words) {
    // here i want to count the number of positive words.
    int count = 0;
    for (auto word : positive_words) {
        count += count_occurrence(text, word);
    }
    return count;
}

//** This function shows the best day
void show_the_best_day(vector<note> notes, vector<string> positive_words) {
    note best = notes[0];
    for (auto note : notes) {
        if (count_positives(best.text, positive_words) <
            count_positives(note.text, positive_words))
            best = note;
    }
    show_summary(best);
}

int main() {
    string userinput;
    string today = "";
    vector<note> notes;
    vector<string> positive_words = read_positive_words();

    while (cin >> userinput) {
        if (!userinput.compare("start_day")) {
            cin >> today;
        } else if (!userinput.compare("show_day")) {
            show_day(notes);
        } else if (!userinput.compare("show_the_longest_day")) {
            show_the_longest_day(notes);
        } else if (!userinput.compare("show_the_best_day")) {
            show_the_best_day(notes, positive_words);
        } else {
            add_note(notes, today, userinput);
        }
    }

    return 0;
}