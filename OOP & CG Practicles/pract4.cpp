#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    string line;
    float p;

    ofstream fout("a.txt");

    cout<<"Enter your roll num:";
    cin>>n;
    fout<<n;
    cout<<"Enter your name:";
    cin>>line;
    fout<<line;
    cout<<"Enter your percentage:";
    cin>>p;
    fout<<p;

    fout.close();

    ifstream fin("a.txt");

    fin>>n;
    cout <<"\n1) The roll num is "<<n;
    fin>>line;
    cout <<"\n2) The name is "<<line;
    fin>>p;
    cout <<"\n3) The marks is " << p;

    fin.close();

    return 0;
}
