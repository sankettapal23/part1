#include<iostream>
#include<fstream>
using namespace std;
int main()
 {
	string line;
	ofstream fout("a.txt");
	fout<<" This is SE class";
	fout<<"\n This is TE class";
	fout<<"\n This is BE class";
	fout.close();
	ifstream fin("a.txt");
	while(!fin.eof())
	{
 	 getline(fin,line);
	 cout<<line<<"\n";
	}
	return 0;
}