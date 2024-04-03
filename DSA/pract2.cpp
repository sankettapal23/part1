#include<iostream>
using namespace std;

int cost[50][50];
string city[50];
int ans;
int n,i,j;
void test()
{
    int i,j;
    cout<<"Enter total no of cities"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter name of city";
        cin>>city[i];
    }
}

void getdata()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                    cost[i][j]=0;
            }
            else
            {
                cout<<"\n Is their any flight between cities "<<city[i]<<" and "<<city[j]<<endl;
                cout<<"\n 1.yes \n 2.no ";
                cin>>ans;

                switch(ans)
                {
                    case 1:
                            cout<<"The cost of Flight Between "<<city[i]<<" and "<<city[j]<<endl;
                            cin>>cost[i][j];
                            break;

                    case 2:
                            cost[i][j]=0;
                            break;

                    default:
                            cout<<"Invalid choice "<<endl;
                            cout<<"Please Enter Right Choice"<<endl;
                            break;                
                }
            }
        }
    }

}

void show()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {

            }
            else if(cost[i][j]==0)
            {
                cout<<"\n Sorry!!! Their is No flight between "<<city[i]<<" and "<<city[j]<<endl;

            }
            else
            {
                cout<<"Cost for flight between "<<city[i]<<" and "<<city[j]<<" is ="<<cost[i][j]<<endl;
            }
        }
    }
}

int main()
{
    void test();
    void getdata();
    void show();
    return 0;
}