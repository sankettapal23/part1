#include<iostream>
using namespace std;
struct node
{
      int data;
      struct node *next, *prev;
};
class cBinary
{
      struct node *head,*rear;
      public:
      cBinary()
      {
           head=NULL;
		   rear=NULL;
      }
      struct node * create();
      void display();
      void ocomp();
	  void oocomp();
	  void add(struct node*,struct node*);
};

struct node* cBinary::create()
{
           head=NULL;
		   rear=NULL;
      int n,rem;
      struct node *nn;
      cout<<"\n Enter number : ";
      cin>>n;
      while(n!=0)       
      {
            rem=n%2;
            n=n/2;
            nn=new node;
            nn->prev=NULL;
            nn->next=NULL;
            nn->data=rem;
            if(head==NULL)
            {
                  rear=head=nn;
            }
            else
            {
                  head->prev=nn;
                  nn->next=head;
                  head=nn;
            }
            
      }
	  return rear;
}


void cBinary::display()
{
      struct node *temp;
      temp=head;
      while(temp!=NULL)
      {
            cout<<temp->data;
            temp=temp->next;
      }
}

void cBinary::ocomp()
{
      struct node *temp;
      temp=head;
      while(temp!=NULL)
      {
           if(temp->data==1)
           {
                temp->data=0;
           }
           else
           {
                temp->data=1;
           }
           temp=temp->next;
      }
	  cout<<"your one's complemnt is \n";
	  display();
}

void cBinary::oocomp()
{ struct node *temp;
  temp=rear;
  int carry;
  carry=1;
  while(temp!=NULL)
  { 
	
	if(temp->data==1 && carry==0)
	{
	 temp->data=1;
	 carry=0;
	 
	}
	else if(temp->data==0 && carry==0 )
	{
	 temp->data=0;
	}
	else if(temp->data==0 && carry==1)
	{
	 temp->data=1;
	 carry=0;
	}
	else if(temp->data==1 && carry==1)
	{
	 temp->data=0;
	 
	}
    temp=temp->prev;

  }

     cout<<"your two's complement is";
   display();

}
void cBinary::add(struct node *head1, struct node *head2) {
    int carry = 0;
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *head3 = NULL;
    struct node *temp3 = NULL;

    while (temp1 != NULL || temp2 != NULL) {
        int sum = carry + (temp1 ? temp1->data : 0) + (temp2 ? temp2->data : 0);
        carry = sum / 2;
        sum %= 2;
        struct node *p = new node;
        p->data = sum;
        p->next = NULL;
        p->prev = NULL;

        if (head3 == NULL) {
            temp3 = head3 = p;
        } else {
            p->next = temp3;
            temp3->prev = p;
            temp3 = p;
        }

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

    if (carry > 0) {
        struct node *p = new node;
        p->data = carry;
        p->next = NULL;
        p->prev = NULL;

        if (head3 == NULL) {
            temp3 = head3 = p;
        } else {
            p->next = temp3;
            temp3->prev = p;
            temp3 = p;
        }
    }

    head3 = temp3;
    temp3 = head3;
    cout << "\n";
    while (temp3->next != NULL) {
        cout << " " << temp3->data;
        temp3 = temp3->next;
    }
    cout << " " << temp3->data << "\n";
}




int main()
{
       cBinary b,c;
       int ch;

	   struct node * a,*p;
	   
       cout<<"\n1.CREATE \n2.DISPLAY \n3.ONE'S COMP \n4.Two's complement \n 5.exit";
       while(ch!=6)
       {
           cout<<"\n\nEnter the choice : ";
           cin>>ch;
           switch(ch)
           {
                 case 1:
                 b.create();
                 break;
                 
                 case 2:
                 b.display();
                 break;
                 
                 case 3:
                 b.ocomp();
                 break;
                 
				 case 4:
				b.oocomp();
				break;

                 case 5:
                 a=b.create();
					     p=c.create();
						 b.add(a, p);
             
                 break;
				 
				 case 6: 
				     cout<<"EXIT";
						 break;
                 
                 default:
                 cout<<"\n!!!!!!!Wrong Choice!!!!!";
                 break;
           }
       }
}
