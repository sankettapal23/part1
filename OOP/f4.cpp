#include<iostream>
using namespace std;
int main()
{
    enum colors{red,blue,yellow,green};
    enum suits{heart,diamond=12,club};
    enum fruit{mango=2,orange,kivi};
    enum colors c1;
    enum suits s1;
    c1= blue;
    s1= club;
    cout<<red<<"\t"<<green;
    cout<<"\n c1="<<c1;
    cout<<"\n s1="<<s1;
    cout<<"\n"<<heart<<"\t"<<diamond<<"\t"<<club;
    cout<<"\n"<<mango<<"\t"<<orange<<"\t"<<kivi;
    return(0);
}
