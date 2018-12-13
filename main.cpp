#include<conio.h>
#include<iostream>
#include<process.h>
#include<stdlib.h>


 using namespace std;
//   Creating a NODE Structure
struct node
{
   int nopunggung;
   string nama;
   string posisi;
   struct node *next;
};

// Creating a class QUEUE
class queue
{
   struct node *frnt,*rear;
   public:
      queue() // constructure
      {
	 frnt=rear=NULL;
      }
      void insert(); // to insert an element
      void del();  // to delete an element
      void show(); // to show the stack
};
// Insertion
void queue::insert()
{
   int value;
   string value1;
   string value2;
   struct node *ptr;
   cout<<"\nInsertion\n";
   cout<<"no punggung: ";
   cin>>value;
   cout<<"nama :";
   cin>>value1;
   cout<<"posisi :";
   cin>>value2;
   ptr=new node;
   ptr->nopunggung=value;
   ptr->nama=value1;
   ptr->posisi=value2;
   ptr->next=NULL;
   if(frnt==NULL)
      frnt=ptr;
   else
      rear->next=ptr;
   rear=ptr;
   cout<<"\new item sukses!!!";
   getch();
}

// Deletion
void queue::del()
{
   if(frnt==NULL)
   {
      cout<<"\nQueue is empty!!";
      getch();
      return;
   }
   struct node *temp;
   temp=frnt;
   frnt=frnt->next;
   cout<<"\nDeletion Operation........\nDeleted value is "<<temp->nopunggung<<temp->nama<<temp->posisi;
   delete temp;
   getch();
}

// Show Queue
void queue::show()
{
   struct node *ptr1=frnt;
   if(frnt==NULL)
   {
      cout<<"The Queue is empty!!";
      getch();
      return;
   }
   cout<<"\nThe Queue is\n";
   while(ptr1!=NULL)
   {
      cout<<ptr1->nopunggung<<" ->"; cout<<endl;

      cout<<ptr1->nama<<" ->"; cout<<endl;

      cout<<ptr1->posisi<<" ->";
      ptr1=ptr1->next;
   }
   cout<<"END";
   getch();
}

// Main function
int main()
{
   system("cls");
   queue q;
   int choice;
   while(1)
   {
      cout<<"\n-----------------------------------------------------------";
      cout<<"\n\t\tQUEUE USING LINKED LIST\n\n";
      cout<<"1:INSERTION\n2:DELETION\n3:DISPLAY QUEUE\n4:EXIT";
      cout<<"\nEnter your choice(1-4): ";
      cin>>choice;
      switch(choice)
      {
       case 1:
	  q.insert();
	  break;
       case 2:
	  q.del();
	  break;
       case 3:
	  q.show();
	  break;
       case 4:
	  exit(0);
	  break;
       default:
	  cout<<"Please enter correct choice(1-4)!!";
	  getch();
	  break;
       }
   }
   return 0;
}
