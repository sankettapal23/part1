#include <iostream>
#include <string>

using namespace std;

class Publication {
public:
    string title;
    float price;

    void get_data() {
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Price: ";
        cin >> price;
    }

    void put_data() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
public:
    int pages;

    void get_data() {
        Publication::get_data();
        cout << "Enter Page Count: ";
        cin >> pages;
    }

    void put_data() {
        Publication::put_data();
        if (pages < 0) {
            cout << "Error: Pages not valid" << endl;
            pages = 0;
        }
        cout << "Pages: " << pages << endl;
    }
};

class Tape : public Publication {
public:
    float playtime;

    void get_data() {
        Publication::get_data();
        cout << "Enter Play Time Of Cassette: ";
        cin >> playtime;
    }

    void put_data() {
        Publication::put_data();
        if (playtime < 0.0) {
            cout << "Error: Invalid Playtime" << endl;
            playtime = 0.0;
        }
        cout << "Playtime: " << playtime << " minutes" << endl;
    }
};

int main() {
    Book b[10];
    Tape t[10];
    int bookCount = 0, tapeCount = 0;

    while (true) {
        int choice;
        cout << "-----------------------\n";
        cout << "1. Add Book\n";
        cout << "2. Add Tape\n";
        cout << "3. Display Books\n";
        cout << "4. Display Tapes\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add Book:\n";
                b[bookCount].get_data();
                bookCount++;
                break;

            case 2:
                cout << "Add Tape:\n";
                t[tapeCount].get_data();
                tapeCount++;
                break;

            case 3:
                cout << "\n(Books):\n";
                for (int j = 0; j < bookCount; j++) {
                    b[j].put_data();
                }
                break;

            case 4:
                cout << "\n(Tapes):\n";
                for (int j = 0; j < tapeCount; j++) {
                    t[j].put_data();
                }
                break;

            case 5:
                cout << "Program Exited Successfully\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}