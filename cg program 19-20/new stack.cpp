#include<iostream>
#include<cstdlib>
#include<graphics.h>
#define MAX_SIZE 10
using namespace std;
class Stack{
    private:
        int item[MAX_SIZE];
        int BOS;
    public:
        Stack()
	{
            BOS = 0;
        }
void push(int data)
{
for(int i=BOS; i>0; i--)
{
     item[i] = item[i-1];
}
item[0] = data;
++BOS;
}
int pop()
{
            int temp = item[0];
for(int i = 0; i<BOS; i++)
{
            item[i] = item[i+1];
 }
BOS--;
return temp;
}
void display()
{
char str[10];
int gd=DETECT, gm=VGAMAX;
 initgraph(&gd, &gm, 0);
int j=300;
for(int i = BOS-1; i>=0; i--)
{
delay(100);
rectangle(10,10+j,60,60+j);
delay(1000);
sprintf(str,"%d",item[i]);
outtextxy(20,25+j,str);
delay(1000);
j=j-50;
}
delay(10000);
closegraph();
cout<<endl;
}
bool isEmpty()
{
  if(BOS == 0)
{
   return true;
}
else
{
   return false;
}
 }  
bool isFull()
{
 if(BOS == MAX_SIZE)
{
                return true;
}
else
{
 return false;
            }
        }
};

int main(){
    int choice, data;
    Stack stack;
    while(true){
        cout<<"1. Push a Data"<<endl;
        cout<<"2. Pop a Data"<<endl;
        cout<<"3. Display All Element of Stack"<<endl;
        cout<<"4. Quit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                if(!stack.isFull()){
                    cout<<"Enter the data to push: ";
                    cin>>data;
                    stack.push(data);
                    cout<<endl;
                }else{
                    cout<<"STACK IS FULL!!"<<endl;
                }
                break;
            case 2:
                if(!stack.isEmpty()){
                    cout<<"The data popped is "<<stack.pop()<<endl;
                }else{
                    cout<<"THE STACK IS EMPTY"<<endl;
                }
                break;
            case 3:
                if(!stack.isEmpty()){
                    stack.display();
                }else{
                    cout<<"STACK IS EMPTY"<<endl;
                }
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return 0;
}
