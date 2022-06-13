/*Ticket Window is a simple program to show the implementaion of
QUEUE.
Program takes as input number of tickets required and ENQUEUE them.
Only two tickets are allowed at one time.If more than two tickets are
demanded,
two are given and the remaining is enqueued again for its turn*/

#include <iostream>
#include <conio.h>
#include <process.h>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

class ticketqueue{
private:
   //Data Members
		 int q[5];
		 int front, rear, noe;  //noe..to store number of elements

public:
   //Member Functions
		 ticketqueue(){ noe = rear = front = 0;} //Constructor
		 void enqueue(int);
		 void ticketchecker();
		 void print();
		 int isempty();
		 void queuebuilder();
		 void menu();
};
/////////////////////
void ticketqueue :: enqueue(int a)
{
		 		 q[rear] = a;
		 		 rear++;
		 		 noe++;
		 		 if (rear == 5)
		 		 		 rear = 0;
		 		 cout<<""<<a<<" Is Enqeueued....."<<endl;
}
/////////////////////
void ticketqueue :: ticketchecker()
{
system("CLS");
		 int nott=0,rt=0;
		 if ( !isempty() )
		 		 {
		 		 		 nott = q[front];
		 		 		 if (nott > 2)
		 		 		 		 {
		 		 		 		 		 rt = nott - 2;
		 		 		 		 		 if ( rt > 0 )
		 		 		 		 		 		 {
		 		 		 		 		 		 		 enqueue(rt);
		 		 		 		 		 		 		 front++;
		 		 		 		 		 		 		 cout<<""<<nott<<"# Tickets were demanded. 2 Tickets are given."<<"Enqueued again for next go to get remaining #"<<rt<<"Tickets"<<endl;
		 		 		 		 		 		 }
		 		 		 		 		 else if ( rt <= 0 )
		 		 		 		 		 		 front++;
		 		 		 		 		 		 noe--;

		 		 		 		 }
		 		 		 else if ( nott <= 2 )
		 		 		 		   {
		 		 		 		 		  front++;
		 		 		 		 		  noe--;
		 		 		 		 		 cout<<""<<nott<<"# tickets are given...."<<endl;
		 		 		 		   }
		 		 		 }
		 else
		 		 cout<<"!!! NO REQUEST IN THE QUEUE " <<endl;

getch();
system("CLS");
menu();
}
/////////////////////
void ticketqueue :: print()
{
system("CLS");
		 int i = front;
		 if ( noe > 0 )
		 		 {
		 		 		 cout<<"REQUESTS ENQUEUED ARE :" ;
		 		 		 do
		 		 		 		 {
		 		 		 		 		 cout<<q[i]<<" ";
		 		 		 		 		 i++;
		 		 		 		 		 if ( i == 5 )
		 		 		 		 		 		 i = 0;
		 		 		 		 }
		 		 		 while ( i != rear );
		 		 }
		 else
		 		 cout<<"NO REQUEST IN QUEUE...QUEUE IS EMPTY ";
getch();
system("CLS");
menu();
}
//////////////////

//Utility Fuction
int ticketqueue :: isempty()
{
		 if ( noe == 0 )
		 		 return 1;
		 else
		 		 return 0;
}
/////////////////

//This Function takes input from the user and shows Queue graphically

void ticketqueue::queuebuilder(){
   system("CLS");
   int tickets, z = 0, i = 0, x = 20, y = 10, g = 1, h = 17;
   char c;
   cout<<"Enter number of tickets to purchase... "<<endl;
   while (!(c == 'E' || c == 'e'))
		 {
		 		  if ( z > 4)
		 		 		 {
		 		 		 		 system("CLS");
		 		 		 		 cout<<" ERROR!!! Queue Size Violation...Exiting Now  "<<endl;
		 		 		 		 getch();
		 		 		 		 system("CLS");
		 		 		 menu();
		 		 		 }

		 		  else
		 		 		 {
		 		 		 		 cout<<"Enter : ";
		 		 		 		 cin>>tickets;
		 		 		 		 enqueue(tickets);
		 		 		 		 z++;
		 		 		 		 gotoxy(17,10);
		 		 		 		 cout<<"->";
		 		 		 		 gotoxy(20,9);
		 		 		 		 cout<<"----------------------------------";
		 		 		 		 gotoxy(x,y);
		 		 		 		 cout<<q[i];
		 		 		 		 x+=2;
		 		 		 		 gotoxy(20,11);
		 		 		 		 cout<<"----------------------------------";
		 		 		 		 gotoxy(g,h);
		 		 		 		 cout<<"PRESS C/c to CONTINUE E/e to END: ";
		 		 		 		 cin>>c;
		 		 		 		 h += 6;

		 		 		 		 i++;
		 		 		 }
		 }
getch();
system("CLS");
menu();
}
//////////////////
void ticketqueue::menu()
{
int b;
gotoxy(15,5);
 cout<<"Press 1................ENTER NO OF TICKETS";
gotoxy(15,8);
		  cout<<"Press 2................TICKET CHECKER";
gotoxy(15,11);
		 cout<<"Press 3................ALL TICKET REQUESTS";
gotoxy(15,15);
		 cout<<"Press 4................EXIT";
gotoxy(15,18);
		 cout<<"NOW ENTER : ";

		 cin>>b;

if ( b == 1 )
		 queuebuilder();
else if ( b == 2 )
		 ticketchecker();
else if ( b == 3 )
		 print();
else if ( b == 4 )
		 exit(1);
}
//////////////////


int main()
{
system("CLS");
ticketqueue t;
t.menu();
getch();
}
