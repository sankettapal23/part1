#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class person {
public:
    int id;
    string name; // Using string instead of char array

    void getdata() {
        cout << "ENTER THE ID AND NAME:";
        cin >> id >> name;
    }

    void show() {
        cout << "ID:" << id << " NAME:" << name << endl;
    }

    bool operator==(const person& p1) const {
        return (id == p1.id);
    }
};

bool cheak1(const person& p1, const person& p2) {
    return (p1.id < p2.id);
}

int main() {
    vector<person> v;
    int n;
    int i = 0;
    person p;
    cout << "\n ENTER NUM OF PERSONS:";
    cin >> n;
    for (i = 0; i < n; i++) {
        p.getdata();
        v.push_back(p);
    }
    cout << "\nDATA:\n";
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        itr->show();
    }

    cout << "\nENTER ID TO SEARCH:";
    cin >> p.id;
    auto itr = find(v.begin(), v.end(), p);
    if (itr != v.end()) {
        cout << "\nRECORD FOUND";
        cout << "\nID: " << itr->id << " NAME: " << itr->name << endl;
    }
    else
        cout << "\n RECORD NOT FOND";

    sort(v.begin(), v.end(), cheak1);
    cout << "SORTED DATA";
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        itr->show();
    }

 return(0);
}
