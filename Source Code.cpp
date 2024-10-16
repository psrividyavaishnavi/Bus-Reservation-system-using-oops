#include<bits/stdc++.h>
using namespace std;

/* p variable keeps track of number of bus available at the moment.*/

int p = 0;


class a
{
  /*Note: Don't use space in input.
  *busPlateNum can store a input upto length 7 and so on for other attributes.
  *Here seatNumber is no. of seats in a bus, seatNumber is matrix type char i.e, seatNumber[8][4] have 4 columns and 8 rows i.e,
  8*4=32 seats in total, while seatNumber[8][4][10] means each of the seatNumber can store a nameOfPassenger with 10 characters each*/
  char busn[10], driver[25], arrival[15], depart[15], from[25], to[25], seat[8][4][10];

public:

  void addNewBus();

  void allotmentOfSeatToPassenger();

  void empty();

  void showAvailableBusSeats();

  void showAvailableBuses();

  void showReservedBusSeats(int i);

}
bus[25];


void vline(char ch)
{

  for (int i=100;i>0;i--){
    cout<<ch;
  }
  cout<<endl;

}

void a::addNewBus()
{

  cout<<"Enter bus no: ";

  cin>>bus[p].busn;

  cout<<"\nEnter Driver's name: ";

  cin>>bus[p].driver;

  cout<<"\nArrival time : ";

  cin>>bus[p].arrival;

  cout<<"\nDeparture: ";

  cin>>bus[p].depart;

  cout<<"\nFrom: ";

  cin>>bus[p].from;

  cout<<"\nTo: ";

  cin>>bus[p].to;

  bus[p].empty(); // Fill all the seats with 'empty'

  p++; //Number of buses(index of array bus) increase

}


void a::allotmentOfSeatToPassenger()

{

  int seat;

  char number[5];//Bus number in which you want to reserve seat

  string a,g;

  top:

  cout<<"Bus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0) //Check if bus number exist or not, if exist n will be the index of array bus

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32) //Can't allocate as there are only 32 seats
    {

      cout<<"\nThere are only 32 seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0) // used to break the seat number in row-column basis, If empty then allocate passenger

      {

        cout<<"Enter passanger's name, age and gender : ";

        cin>>bus[n].seat[seat/4][(seat%4)-1]>>a>>g;

        break;

      }

    else

      cout<<"The seat number is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct bus no.\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}



void a::showAvailableBusSeats()

{

  int n;

  char number[5];

  cout<<"Enter bus no: ";

  cin>>number;

//Finds the bus number matched with input bus number
  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0) // if matched the n will be the index of bus

    break;

  }

while(n<=p)

{

  vline('*');
  cout<<"\nBus no: \t"<<bus[n].busn

  <<"\nDriver: \t"<<bus[n].driver<<"\t\t\t\t\tArrival time: \t"

  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart

  <<"\nFrom: \t\t"<<bus[n].from<<"\t\t\t\t\tTo: \t\t"<<

  bus[n].to<<"\n";

  vline('*');

  bus[0].showReservedBusSeats(n); //Checks for reserved seats in the current bus( nth bus)

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct bus no: ";

}


void a::showReservedBusSeats(int l)
{

  int s=0,h=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          h++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<"Reserved";

        }

      }

    }

  cout<<"\n\nThere are "<<h<<" seats empty in Bus No: "<<bus[l].busn;

  }


void a::showAvailableBuses()

{

  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"Bus no: "<<bus[n].busn<<"\n\nDriver: "<<bus[n].driver

    <<"\t\t\tArrival time: "<<bus[n].arrival<<"\t\tDeparture Time: "

    <<bus[n].depart<<"\n\nFrom: "<<bus[n].from<<"\t\tTo: "

    <<bus[n].to<<"\n";

    vline('*');

    vline('_');

  }

}


int main()

{


  int choice;
  vline('-');
  cout<<"\t\t\t\t****SRM Bus Reservation System****"<<endl<<endl;
  vline('-');
  while(1)
  {



  cout<<endl;
  vline('*');
  cout<<"\n\n";

  cout<<"\t\t\t1.Add new Bus Details:\n\t\t\t"

  <<"2.Reserve your seats:\n\t\t\t"

  <<"3.Show the available seats in a bus:\n\t\t\t"

  <<"4.Buses Available Now: \n\t\t\t"

  <<"5.Exit";
  cout<<endl;
  vline('*');
  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>choice;
  vline('*');

  switch(choice)

  {

    case 1:  bus[p].addNewBus();

      break;

    case 2:  bus[p].allotmentOfSeatToPassenger();

      break;

    case 3:  bus[0].showAvailableBusSeats();

      break;

    case 4:  bus[0].showAvailableBuses();

      break;

    case 5:  {
      cout<<"Successfully Logged out from the Application. Visit Again!"<<endl<<"< Thank You :) >"<<endl<<"Created by Prishitha, Vaishnavi, Hima and Mahitha."<<endl;
      exit(0);
    };

  }

}

return 0;

}


