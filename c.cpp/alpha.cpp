#include<iostream>
using namespace std;
int main()
{   cout<<"Welcome to Frank's cleaning service "<<endl;
    cout<<endl;
    cout<<"How many small rooms would you like cleaned?"<<endl;
    int small_rooms;
    cin>>small_rooms;
    cout<<"How many large rooms would you like to clean?"<<endl;
    int large_rooms;
    cin>>large_rooms;

    const int price_smallroom=25;
    const int price_largeroom=35;
    const double tax=0.06;
    int expiry=30;

    cout<<"number of small rooms to be cleaned ="<<small_rooms<<endl;
    cout<<"number of large rooms to be cleaned ="<<large_rooms<<endl<<endl;
    double cost_small,cost_large,total_cost,total_tax;
    cost_small=(price_smallroom*small_rooms)+(price_smallroom*small_rooms*tax);
    cost_large=(price_largeroom*large_rooms)+(price_largeroom*large_rooms*tax);
    total_cost=cost_small+cost_large;
    cout<<"total cost of cleaning the rooms="<<total_cost<<endl;
    total_tax=(price_smallroom*small_rooms*tax)+(price_largeroom*large_rooms*tax);
    cout<<"total tax="<<total_tax<<endl;
    cout<<"the estimate expiry for cleaning is valid for "<<expiry<<" days"<<endl;
    return 0;
    }