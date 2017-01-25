/*       STATIONARY  BILLING SYSTEM using sequential files in c++
      Project by:
              VRUSHALI R MALVADKAR(SE-B)
 */             


#include<iostream.h>
#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#define SIZE 5
class stock
{
  int pen[SIZE];
  int notebook[SIZE];
  int sacs[SIZE];
  int eraser[SIZE];
  int pencil[SIZE];
  int sharpner[SIZE];
  fstream file;
  public:
	 stock();
	 void purchase();
	 void insert();
	 void view();
	 void view_pencil();
	 void view_pen();
	 void view_notebook();
	 void view_eraser();
	 void view_sharpner();
	 void bill(int,int,int,int,int,int);
	 void clear_stk();
	 int purchase_pen();
	 int purchase_pencil();
	 int purchase_notebook();
	 int purchase_sac();
	 int purchase_sharpner();
	 int purchase_eraser();
}stk;
stock::stock()     //constructor
{

	file.open("reynolds.txt",ios::in);
	file>>pen[0];
	file.close();
	file.open("cello.txt",ios::in);
	file>>pen[1];
	file.close();
	file.open("parker.txt",ios::in);
	file>>pen[2];
	file.close();
	file.open("penother.txt",ios::in);
	file>>pen[3];
	file.close();
	file.open("ftotpen.txt",ios::in);
	file>>pen[4];
	file.close();

	file.open("natraj.txt",ios::in);
	file>>pencil[0];
	file.close();
	file.open("APSARA.txt",ios::in);
	file>>pencil[1];
	file.close();
	file.open("camel.txt",ios::in);
	file>>pencil[2];
	file.close();
	file.open("OTHERpencils.txt",ios::in);
	file>>pencil[3];
	file.close();
	file.open("totpencil.txt",ios::in);
	file>>pencil[4];
	file.close();

	file.open("APSARA_eraser.txt",ios::in);
	file>>eraser[0];
	file.close();
	file.open("NATRAJ_eraser.txt",ios::in);
	file>>eraser[1];
	file.close();
	file.open("Other_eraser.txt",ios::in);
	file>>eraser[2];
	file.close();
	file.open("toteraser.txt",ios::in);
	file>>eraser[3];
	file.close();

	file.open("APSARA_sharpner.txt",ios::in);
	file>>sharpner[0];
	file.close();
	file.open("NATRAJ_sharpner.txt",ios::in);
	file>>sharpner[1];
	file.close();
	file.open("OTHERS_sharpner.txt",ios::in);
	file>>sharpner[2];
	file.close();
	file.open("Totsharpner.txt",ios::in);
	file>>sharpner[3];
	file.close();

	file.open("NAVJYOTI_notebook.txt",ios::in);
	file>>notebook[0];
	file.close();
	file.open("CLASSMATE_notebook.txt",ios::in);
	file>>notebook[1];
	file.close();
	file.open("OTHERS_notebook.txt",ios::in);
	file>>notebook[2];
	file.close();
	file.open("Totnotebook.txt",ios::in);
	file>>notebook[3];
	file.close();

	file.open("bags.txt",ios::in);
	file>>sacs[0];
	file.close();

}

void stock::clear_stk()
{
	int i;
	for (i=0;i<SIZE;i++)
	{
	  pen[i]=0;
	  pencil[i]=0;
	  notebook[i]=0;
	  sacs[i]=0;
	  eraser[i]=0;
	  sharpner[i]=0;
	}

//pen related file stock set to 0

	file.open("reynolds.txt",ios::out);
	file<<0;
	file.close();
	file.open("cello.txt",ios::out);
	file<<0;
	file.close();
	file.open("parker.txt",ios::out);
	file<<0;
	file.close();
	file.open("penother.txt",ios::out);
	file<<0;
	file.close();
	file.open("ftotpen.txt",ios::out);
	file<<0;
	file.close();

	file.open("natraj.txt",ios::out);
	file<<0;
	file.close();
	file.open("APSARA.txt",ios::out);
	file<<0;
	file.close();
	file.open("camel.txt",ios::out);
	file<<0;
	file.close();
	file.open("OTHERpencils.txt",ios::out);
	file<<0;
	file.close();
	file.open("totpencil.txt",ios::out);
	file<<0;
	file.close();

	file.open("APSARA_eraser.txt",ios::out);
	file<<0;
	file.close();
	file.open("NATRAJ_eraser.txt",ios::out);
	file<<0;
	file.close();
	file.open("Other_eraser.txt",ios::out);
	file<<0;
	file.close();
	file.open("toteraser.txt",ios::out);
	file<<0;
	file.close();

	file.open("APSARA_sharpner.txt",ios::out);
	file<<0;
	file.close();
	file.open("NATRAJ_sharpner.txt",ios::out);
	file<<0;
	file.close();
	file.open("OTHERS_sharpner.txt",ios::out);
	file<<0;
	file.close();
	file.open("Totsharpner.txt",ios::out);
	file<<0;
	file.close();

	file.open("NAVJYOTI_notebook.txt",ios::out);
	file<<0;
	file.close();
	file.open("CLASSMATE_notebook.txt",ios::out);
	file<<0;
	file.close();
	file.open("OTHERS_notebook.txt",ios::out);
	file<<0;
	file.close();
	file.open("Totnotebook.txt",ios::out);
	file<<0;
	file.close();

	file.open("bags.txt",ios::out);
	file<<0;
	file.close();

}

void stock::insert()
{
int ch,ch1,n=0;
char choice;
do
{
  clrscr();
  cout<<"\n  1.PEN\n  2.PENCIL\n  3.ERASER\n  4.SHARPENER\n  5.NOTEBOOKS";
  cout<<"\n  6.BAGS\n  7.CANCEL";
  cout<<"\n\nEnter choice\t";
  cin>>ch;
  switch(ch)
  {
      case 1:
	do
	{    clrscr();
	    cout<<"\n  PEN......";
	    cout<<"\n\n1.REYNOLDS\n2.CELLO\n3.PARKER\n4.OTHERS\n5.RETURN";
	    cout<<"\n\n\tWhich item do you want to add?";
	    cin>>ch1;
	    switch(ch1)
	    {
	    case 1:

		 cout<<"\n\n\tHow many items do you want to add?\t";
		 cin>>n;
		 file.open("reynolds.txt",ios::out);

		 pen[0]=pen[0]+n;
		 file<<pen[0];
		 pen[4]=pen[4]+n;
		 file.close();

		file.open("ftotpen.txt",ios::out);
		file<<pen[4];
		file.close();

		 break;
	    case 2:

		 file.open("cello.txt",ios::out);

		 cout<<"\n\nHow many items do you want to add?";
		 cin>>n;
		 pen[1]=pen[1]+n;

		 file<<pen[1];
		 file.close();
		 pen[4]=pen[4]+n;

		file.open("ftotpen.txt",ios::out);
		file<<pen[4];
		file.close();
		 break;

	    case 3:

		 cout<<"\n\nHow many items do you want to add?";
		 cin>>n;
		 pen[2]=pen[2]+n;
		 file.open("parker.txt",ios::out);

		 pen[4]=pen[4]+n;
		 file<<pen[2];

		file.open("ftotpen.txt",ios::out);
		file<<pen[4];
		file.close();

		 break;
	    case 4:

		 cout<<"\n\nHow many items do you want to add?";
		 cin>>n;
		 pen[3]=pen[3]+n;
		 pen[4]=pen[4]+n;

		file.open("penother.txt",ios::app);
		file<<pen[3];
		file.close();
		file.open("ftotpen.txt",ios::out);
		file<<pen[4];
		file.close();

		 break;
	    case 5:
		break;
	    }
	    cout<<"\n\n\nDo you want to add more items?";
	    cin>>choice;

	  }while(choice=='y'||choice=='Y');

	  break;
      case 2:
	    do
	    {
	    clrscr();
	    cout<<"\n\n1.NATRAJ\n\n2.APSARA\n\n3.CAMEL\n\n4.OTHERS";
	    cout<<"\n\n5.RETURN";
	    cout<<"\n\nWhich item do you want to add?";

	    cin>>ch1;
	    switch(ch1)
	    {
	    case 1:

		 cout<<"\n\nHow many items do you want to add?\t";
		 cin>>n;
		 pencil[0]=pencil[0]+n;
		 file.open("natraj.txt",ios::out);
		 file<<pencil[0];
		 file.close();
		 pencil[4]=pencil[4]+n;
		 file.open("totpencil.txt",ios::out);
		 file<<pencil[4];
		 file.close();
		 break;
	    case 2:
		 cout<<"\n\nHow many items do you want to add?\t";
		 cin>>n;
		 pencil[1]=pencil[1]+n;
		 pencil[4]=pencil[4]+n;
		file.open("APSARA.txt",ios::out);
		file<<pencil[1];
		file.close();
		file.open("totpencil.txt",ios::out);
		file<<pencil[4];
		file.close();

		 break;
	    case 3:
		 cout<<"\n\nHow many items do you want to add?\t";
		 cin>>n;
		 pencil[2]=pencil[2]+n;
		 pencil[4]=pencil[4]+n;

		file.open("camel.txt",ios::out);
		file<<pencil[2];
		file.close();
		file.open("totpencil.txt",ios::out);
		file<<pencil[4];
		file.close();

		 break;
	    case 4:
		 cout<<"\n\nHow many items do you want to add?\t";
		 cin>>n;
		 pencil[3]=pencil[3]+n;
		 pencil[4]=pencil[4]+n;

		file.open("OTHERpencils.txt",ios::out);
		file<<pencil[3];
		file.close();
		file.open("totpencil.txt",ios::out);
		file<<pencil[4];
		file.close();

		 break;
	    case 5:
		 break;
	    }
	    cout<<"\n\nDo you want to add more items to list?\t";
	    cin>>choice;
	    }while(choice=='y'||choice=='Y');

	    break;
      case 3:
	    do
	    {
	    clrscr();
	    cout<<"\n\n1.APSARA\n\n2.NATRAJ\n\n3.OTHERS\n\n4.RETURN";
	    cout<<"\n\nWhich item do you wnt to add?";
	    cin>>ch1;
	    switch(ch1)
	    {
	    case 1:
		 cout<<"\n\nHow many items do you want to add?\t";
		 cin>>n;
		 eraser[0]=eraser[0]+n;
		 eraser[3]=eraser[3]+n;

		file.open("APSARA_eraser.txt",ios::out);
		file<<eraser[0];
		file.close();
		file.open("toteraser.txt",ios::out);
		file<<eraser[3];
		file.close();

		  break;
	    case 2:
		 cout<<"\n\nHow many items do you want to add?\t";
		 cin>>n;
		 eraser[1]=eraser[1]+n;
		 eraser[3]=eraser[3]+n;

		file.open("NATRAJ_eraser.txt",ios::out);
		file<<eraser[0];
		file.close();
		file.open("toteraser.txt",ios::out);
		file<<eraser[3];
		file.close();

		  break;
	    case 3:
		 cout<<"\n\nHow many items do you want to add?\t";
		 cin>>n;
		 eraser[2]=eraser[2]+n;
		 eraser[3]=eraser[3]+n;

		file.open("Other_eraser.txt",ios::out);
		file<<eraser[2];
		file.close();
		file.open("toteraser.txt",ios::out);
		file<<eraser[3];
		file.close();

		  break;
	    case 4:
		   break;
		  }
	    cout<<"\n\nDo you want to add more items?\t";
	    cin>>choice;
	  }while(choice=='y'||choice=='Y');
	      break;
      case 4:
	do
	{
	clrscr();
	    cout<<"\n\n1.APSARA\n\n2.NATRAJ\n\n3.OTHERS\n\n4.RETURN\n";
	    cout<<"\n\nWhich item do you want to add?";
	    cin>>ch1;
	    switch(ch1)
	    {
	    case 1:
		 cout<<"\n\nHow many items do you want to add?";
		 cin>>n;
		 sharpner[0]=sharpner[0]+n;
		 sharpner[3]=sharpner[3]+n;

		file.open("APSARA_sharpner.txt",ios::out);
		file<<sharpner[0];
		file.close();
		file.open("Totsharpner.txt",ios::out);
		file<<sharpner[3];
		file.close();

		  break;
	    case 2:
		 cout<<"\n\nHow many items do you want to add?";
		 cin>>n;
		 sharpner[1]=sharpner[1]+n;
		 sharpner[3]=sharpner[3]+n;

		file.open("NATRAJ_sharpner.txt",ios::out);
		file<<sharpner[1];
		file.close();
		file.open("Totsharpner.txt",ios::out);
		file<<sharpner[3];
		file.close();

		  break;
	    case 3:
		 cout<<"\nHow many items do you want to add?";
		 cin>>n;
		 sharpner[2]=sharpner[2]+n;
		 sharpner[3]=sharpner[3]+n;

		file.open("OTHERS_sharpner.txt",ios::out);
		file<<sharpner[2];
		file.close();
		file.open("Totsharpner.txt",ios::out);
		file<<sharpner[3];
		file.close();

		  break;
	    case 4:
		   break;
		  }
	      cout<<"\n\nDo you want to add more items?";
	      cin>>choice;
	  }while(choice=='y'||choice=='Y');
	      break;
      case 5:
	do
	{
	     clrscr();
	    cout<<"\n\n1.NAVJYOTI\n\n2.CLASSMATE\n\n3.OTHERS\n\n4.RETURN";
	    cout<<"\n\nWhich item do you want to add?";
	    cin>>ch1;
	    switch(ch1)
	    {
	    case 1:
		 cout<<"\n\nHow many items do you want to add?";
		 cin>>n;
		 notebook[0]=notebook[0]+n;
		 notebook[3]=notebook[3]+n;

		file.open("NAVJYOTI_notebook.txt",ios::out);
		file<<notebook[0];
		file.close();
		file.open("Totnotebook.txt",ios::out);
		file<<notebook[3];
		file.close();

		  break;
	    case 2:
		 cout<<"\n\nHow many items do you want to add?";
		 cin>>n;
		 notebook[1]=notebook[1]+n;
		 notebook[3]=notebook[3]+n;

		file.open("CLASSMATE_notebook.txt",ios::out);
		file<<notebook[1];
		file.close();
		file.open("Totnotebook.txt",ios::out);
		file<<notebook[3];
		file.close();

		  break;

	    case 3:
		 cout<<"\n\nHow many items do you want to add?";
		 cin>>n;
		 notebook[2]=notebook[2]+n;
		  notebook[3]=notebook[3]+n;

		file.open("OTHERS_notebook.txt",ios::out);
		file<<notebook[2];
		file.close();
		file.open("Totnotebook.txt",ios::out);
		file<<notebook[3];
		file.close();

		  break;
	    case 4:
		   break;
		  }
		  cout<<"\n\nDo you want to add more items?";
		  cin>>choice;
	  }while(choice=='y'||choice=='Y');
	      break;

      case 6:
	      cout<<"\n\nHow many items do you want to add?";
	      cin>>n;
	      sacs[0]=sacs[0]+n;

		file.open("bags.txt",ios::out);
		file<<sacs[0];
		file.close();

	      break;
      }
}while(ch!=7);
}

void stock::view()
{
int ch;
clrscr();
cout<<"\n1.PEN\n2.PENCIl\n3.ERASER\n4.SHARPENER\n5.NOTEBOOKS";
cout<<"\n6.BAGS\n7.RETURN\n";
cout<<"\n\n\tEnter choice\t";
cin>>ch;
switch(ch)
	{
	case 1:
		view_pen();
		getch();
		break;
	case 2:
		view_pencil();
		getch();
		break;
	case 3:
		view_eraser();
		getch();
		break;
	case 4:
		view_sharpner();
		getch();
		break;
	case 5:
		view_notebook();
		getch();
		break;
	case 6:
		cout<<"\n\nThe no of bags in stock is\t"<<sacs[0];
		getch();
		break;
	}
}


void stock::view_pen()
{
clrscr();
cout<<"\nITEM NAME\t"<<"\t"<<"QUANTITY\n\n";
cout<<"\nPens....."<<"\n\n";
cout<<"\n1.Reynolds"<<"\t\t "<<pen[0];
cout<<"\n2.Cello  "<<"\t\t "<<pen[1];
cout<<"\n3.Parker  "<<"\t\t "<<pen[2];
cout<<"\n4.Others   "<<"\t\t "<<pen[3];
}
void stock::view_pencil()
{
clrscr();
cout<<"\nITEM NAME" <<"  "<<"QUANTITY"<<" "<<"COST";
cout<<"\nPencils.........."<<"\n\n";
cout<<"1.Natraj  "<<"\t "<<pencil[0]<<"\t"<<"Rs.3";
cout<<"\n2.Apsara"<<"\t "<<pencil[1]<<"\t"<<"Rs.4";
cout<<"\n3.Camel "<<"\t "<<pencil[2]<<"\t"<<"Rs.5";
cout<<"\n4.Others"<<"\t "<<pencil[3]<<"\t"<<"Rs.2";
}
void stock::view_notebook()
{
clrscr();
cout<<"\nITEM NAME"<<"\t"<<"QUANTITY\n\n";
cout<<"\nNotebook......."<<"\n\n";
cout<<"\n1.Navjyoti    "<<"\t"<<notebook[0];
cout<<"\n2.Classmate   "<<"\t"<<notebook[1];
cout<<"\n3.Others      "<<"\t"<<notebook[2];
}
void stock::view_sharpner()
{
clrscr();
cout<<"\nITEM NAME"<<"\t"<<"QUANTITY\n\n";
cout<<"\nSharpener........."<<"\n\n";
cout<<"\n1.Natraj  "<<"\t"<<sharpner[0];
cout<<"\n2.Apsara  "<<"\t"<<sharpner[1];
cout<<"\n3.Others  "<<"\t"<<sharpner[2];
}
void stock::view_eraser()
{
clrscr();
cout<<"\nITEM NAME"<<"\t"<<"QUANTITY\n\n";
cout<<"\nEraser........."<<"\n\n";
cout<<"\n1.Natraj  "<<"\t"<<eraser[0];
cout<<"\n2.Apsara  "<<"\t"<<eraser[1];
cout<<"\n3.Others  "<<"\t"<<eraser[2];
}


void stock::purchase()
{
int c=0,c1=0,c2=0,c3=0,c4=0,c5=0;
int ch;
char choice;
clrscr();
do
{

cout<<"\n\n1.Pen\n2.Pencil\n3.Eraser\n4.Sharpener\n5.Notebook";
cout<<"\n6.Sac\n7Exit\n";
cout<<"\n\n\tEnter the items code  purchased:\t";
cin>>ch;
switch (ch)
	{
	case 1:
		c=c+purchase_pen();
		break;
	case 2:
		c1=c1+purchase_pencil();
		break;
	case 3:
		 c2=c2+purchase_eraser();
		break;
	case 4:
		 c3=c3+purchase_sharpner();
		break;
	case 5:
		 c4=c4+purchase_notebook();
		break;
	case 6:
		 c5=c5+purchase_sac();
		break;
	}
cout<<"\n\nDo you want to purchase more items\t";
cin>>choice;
}while(choice=='y'||choice=='Y');
bill(c,c1,c2,c3,c4,c5);
getch();

}


void stock::bill(int pn,int pncl,int er,int sh,int nt,int sc)
{
clrscr();
int tot_amt=0.0;
int sr=1;
tot_amt=pn+pncl+er+sh+nt+sc;
cout<<"\n\n  *****  SAMRUDHHA SUPER MARKET  ****";
cout<<"\n\nYou have purchase........\n\n";
if(pn!=0)
	{
	cout<<"\n"<<sr<<". Pen\t   "<< pn;
	sr++;
	}
if(pncl!=0)
	{
	cout<<"\n"<<sr<<". Pencil\t"<<pncl;
	sr++;
	}
if(er!=0)
	{
	cout<<"\n"<<sr<<". Eraser\t\t"<<er;
	sr++;
	}
if(sh!=0)
	{
	cout<<"\n"<<sr<<". Sharpner     \t"<<sh;
	sr++;
	}
if(nt!=0)
	{
	cout<<"\n"<<sr<<". Notebook    \t"<<nt;
	sr++;
	}
if(sc!=0)
	{
	cout<<"\n"<<sr<<". Sac    \t\t"<<sc;
	sr++;
	}
cout<<"\n\n\t\tTOTAL BILL\t:  "<<tot_amt;
}


int stock::purchase_sac()
{
int code,q;
int price=0;
cout<<"\nCost\tRs.350";
cout<<"\n\nEnter  quantity";
cin>>q;
		if(q>sacs[0])
		{
			cout<<"\nTransaction not possible" ;
			return(0);
		}
		price=(350*q) ;
		sacs[0]=sacs[0]-q;


file.open("bags.txt",ios::out);
file<<sacs[0];
file.close();

 return(price);
}


int stock::purchase_notebook()
{
  int code,q;
  char choice;
  int price=0;
  clrscr();
  do
  {
	cout<<"ITEM NAME"<<"    \t    "<<"COST\n" ;
	cout<<"1.Navneet  "<<"   \t    "<<"Rs.40\n";
	cout<<"2.Classmate"<<"   \t    "<<"Rs.35\n";
	cout<<"3.Others   "<<"   \t    "<<"Rs.25";
	cout<<"\n\n2Enter item code and quantity";
	cin>>code>>q;
	switch(code)
	{
	case 1:

		if(q>notebook[0])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}
		price=price+(40*q) ;
		notebook[0]=notebook[0]-q;

notebook[3]=notebook[3]-q;

file.open("NAVJYOTI_notebook.txt",ios::out);
file<<notebook[0];
file.close();

file.open("Totnotebook.txt",ios::out);
file<<notebook[3];
file.close();


		break;
	case 2: if(q>notebook[1])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}


		price=price+ (35*q);
		notebook[1]=notebook[1]-q;

notebook[3]=notebook[3]-q;

file.open("CLASSMATE_notebook.txt",ios::out);
file<<notebook[1];
file.close();

file.open("Totnotebook.txt",ios::out);
file<<notebook[3];
file.close();
		break;
	case 3:
		if(q>notebook[2])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}

		price=price + (25*q);
		notebook[2]=notebook[2]-q;

notebook[3]=notebook[3]-q;

file.open("OTHERS_notebook.txt",ios::out);
file<<notebook[2];
file.close();

file.open("Totnotebook.txt",ios::out);
file<<notebook[3];
file.close();
		break;
	case 4:
		break;
	}
	 cout<<"\n\nDo you want to purchase more notebooks?\t" ;
	 cin>>choice;
}while(choice=='y'||choice=='y');
return(price);
}

int stock::purchase_pen()
{
int code,q;
char choice;
int price=0;
do
{
	cout<<"ITEM NAME"<<"    \t    "<<"COST\n" ;
	cout<<"\n1.Reynolds"<<"   \t    "<<"Rs.7\n";
	cout<<"\n2.Cello   "<<"   \t    "<<"Rs.10\n";
	cout<<"\n3.Parker  "<<"   \t    "<<"Rs.50\n";
	cout<<"\n4.Others  "<<"   \t    "<<"Rs.5";
	cout<<"\n\nEnter item code and quantity";
	cin>>code>>q;
	switch(code)
	{
	case 1:

		if(q>pen[0])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}
		price=price+(7*q) ;
//pen[0] is for renolyds.
		pen[0]=pen[0]-q;
//pen[4] is total
		pen[4]=pen[4]-q;

file.open("reynolds.txt",ios::out);
file<<pen[0];
file.close();

file.open("ftotpen.txt",ios::out);
file<<pen[4];
file.close();
		break;
	case 2: if(q>pen[1])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}

		price=price+ (10*q);
		pen[1]=pen[1]-q;
pen[4]=pen[4]-q;
file.open("cello.txt",ios::out);
file<<pen[1];
file.close();

file.open("ftotpen.txt",ios::out);
file<<pen[4];
file.close();
		break;
	case 3:
		if(q>pen[2])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}
		price=price + (50*q);
		pen[2]=pen[2]-q;
pen[4]=pen[4]-q;
file.open("parker.txt",ios::out);
file<<pen[2];
file.close();

file.open("ftotpen.txt",ios::out);
file<<pen[4];
file.close();
		break;
	case 4:
		if(q>pen[3])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}
		price=price +(5*q);
		pen[3]=pen[3]-q;
pen[4]=pen[4]-q;

file.open("penother.txt",ios::out);
file<<pen[3];
file.close();

file.open("ftotpen.txt",ios::out);
file<<pen[4];
file.close();
		break;
	}
	 cout<<"\n\nDo you want to purchase more pens?\t" ;
	 cin>>choice;
}while(choice=='y'||choice=='y');
return(price);
}

int stock::purchase_eraser()
{
int code,q;
char choice;
int price=0;
do
{
	cout<<"ITEM NAME"<<"    \t    "<<"COST\n" ;
	cout<<"1.APSARA "<<"   \t    "<<"Rs.3\n";
	cout<<"2.Natraj "<<"   \t    "<<"Rs.4\n";
	cout<<"3.Others "<<"   \t    "<<"Rs.2";
	cout<<"\n\nEnter item code and quantity";
	cin>>code>>q;
	switch(code)
	{
	case 1:
		if(q>eraser[0])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}
		price=price+(3*q) ;
		eraser[0]=eraser[0]-q;
eraser[3]=eraser[3]-q;
file.open("APSARA_eraser.txt",ios::out);
file<<eraser[0];
file.close();

file.open("toteraser.txt",ios::out);
file<<eraser[3];
file.close();
		break;
	case 2: if(q>eraser[1])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}
		price=price+ (4*q);
		eraser[1]=eraser[1]-q;
		eraser[3]=eraser[3]-q;

		file.open("NATRAJ_eraser.txt",ios::out);
file<<eraser[1];
file.close();

file.open("toteraser.txt",ios::out);
file<<eraser[3];
file.close();
		break;
	case 3:
		if(q>eraser[2])
		{
			cout<<"\nTransaction not possible" ;
			break;
		}

		price=price + (2*q);
		eraser[2]=eraser[2]-q;
		eraser[3]=eraser[3]-q;

		file.open("Other_eraser.txt",ios::out);
		file<<eraser[2];
		file.close();

		file.open("toteraser.txt",ios::out);
		file<<eraser[3];
		file.close();

		break;
	  }
	 cout<<"\n\nDo you want to purchase more erasers?\t" ;
	 cin>>choice;
   }while(choice=='y'||choice=='y');
   return(price);
}

int stock::purchase_pencil()
{
int code,q;
char choice;
int price=0;
do
{
	cout<<"ITEM NAME"<<"    \t    "<<"COST\n" ;
	cout<<"1.Natraj"<<"   \t    "<<"Rs.3\n";
	cout<<"2.Apsara"<<"   \t    "<<"Rs.4\n";
	cout<<"3.Camel "<<"   \t    "<<"Rs.5\n";
	cout<<"4.Others  "<<"   \t    "<<"Rs.2";
	cout<<"\n\nEnter item code and quantity";
	cin>>code>>q;
	switch(code)
	{
	case 1:

		if(q>pencil[0])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}
		price=price+(3*q) ;
		pencil[0]=pencil[0]-q;
		pencil[4]=pencil[4]-q;


file.open("natraj.txt",ios::out);
file<<pencil[0];
file.close();

file.open("totpencil.txt",ios::out);
file<<pencil[4];
file.close();
		break;
	case 2: if(q>pencil[1])
		{
			cout<<"\nTransaction not possible" ;
			break;
		}

		price=price+ (4*q);
		pencil[1]=pencil[1]-q;

		pencil[4]=pencil[4]-q;


file.open("APSARA.txt",ios::out);
file<<pencil[0];
file.close();

file.open("totpencil.txt",ios::out);
file<<pencil[4];
file.close();
		break;
	case 3:
		if(q>pencil[2])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}

		price=price + (5*q);
		pencil[2]=pencil[2]-q;

pencil[4]=pencil[4]-q;
file.open("camel.txt",ios::out);
file<<pencil[0];
file.close();

file.open("totpencil.txt",ios::out);
file<<pencil[4];
file.close();
		break;
	case 4:
		if(q>pencil[3])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}
		price=price +(2*q);
		pencil[3]=pencil[3]-q;
		pencil[4]=pencil[4]-q;

file.open("OTHERpencils.txt",ios::out);
file<<pencil[0];
file.close();

file.open("totpencil.txt",ios::out);
file<<pencil[4];
file.close();
		break;
	}
	 cout<<"\n\nDo you want to purchase more pencils?\t" ;
	 cin>>choice;
}while(choice=='y'||choice=='y');
return(price);
}

int stock::purchase_sharpner()
{
int code,q;
char choice;
int price=0;
do
{
	cout<<"ITEM NAME"<<"    \t   "<<"COST\n" ;
	cout<<"1.APSARA "<<"   \t    "<<"Rs.5\n";
	cout<<"2.Natraj "<<"   \t    "<<"Rs.7\n";
	cout<<"3.Others "<<"   \t    "<<"Rs.3";
	cout<<"\n\nEnter item code and quantity";
	cin>>code>>q;
	switch(code)
	{
	case 1:

		if(q>sharpner[0])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}
		price=price+(5*q) ;
		sharpner[0]=sharpner[0]-q;

sharpner[3]=sharpner[3]-q;

file.open("APSARA_sharpner.txt",ios::out);
file<<sharpner[0];
file.close();

file.open("Totsharpner.txt",ios::out);
file<<sharpner[3];
file.close();
		break;
	case 2: if(q>sharpner[1])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}

		price=price+ (7*q);
		sharpner[1]=sharpner[1]-q;

sharpner[3]=sharpner[3]-q;

file.open("NATRAJ_sharpner.txt",ios::out);
file<<sharpner[1];
file.close();

file.open("Totsharpner.txt",ios::out);
file<<sharpner[3];
file.close();
		break;
	case 3:
		if(q>sharpner[2])
			{
				cout<<"\nTransaction not possible" ;
				break;
			}

		price=price + (3*q);
		sharpner[2]=sharpner[2]-q;

sharpner[3]=sharpner[3]-q;

file.open("OTHERS_sharpner.txt",ios::out);
file<<sharpner[2];
file.close();

file.open("Totsharpner.txt",ios::out);
file<<sharpner[3];
file.close();
		break;
	case 4:
		break;
	}
	 cout<<"\nDo you want to purchase more pens?\t" ;
	 cin>>choice;
}while(choice=='y'||choice=='y');
return(price);
}

void main()
{
char choice;
int ch,i,j,ch1;
do
{
   clrscr();
   cout<<"\n\n\t\t****   SUMMRUDHHA SUPER MARKET   ****\n";
   cout<<"\n\n\t-------------------------------------------------";
   cout<<"\n\n\t1.COSTOMER \n\t2.SHOP KEEPER \n\t3.CANCEL";
   cout<<"\n\n\t--------------------------------------------------";
   cout<<"\n\n\tEnter choice\t:  ";
   cin>>ch;
   switch(ch)
   {
	case 1:
		do
		{
		  clrscr();
		  cout<<"\n\n\t-----------------";
		  cout<<"\n\t1.VIEW ITEMS \n\t2.PURCHASE & BILL \n\t3.RETURN";
		  cout<<"\n\n\t------------------";
		  cout<<"\n\tEnter the chioce\t";
		  cin>>ch1;

		  switch(ch1)
		  {
		  case 1:
			stk.view();
			break;
		  case 2:
			stk.purchase();
			break;
		   case 3:
			break;
		  }
		}while(ch1!=3);
	break;
	case 2:
	do
	{
	clrscr();
	cout<<"\n\t--------------";
	cout<<"\n\t1.ADD STOCK \n\t2.VIEW STOCK ";
	cout<<"\n\t3.CLEAR STOCK \n\t4.RETURN";
	cout<<"\n\t--------------";
	cout<<"\n\tEnter the chioce\t";
	cin>>ch1;
		switch(ch1)
		  {
		  case 1:
			stk.insert();
			break;
		  case 2:
			stk.view();
			break;
		  case 3:
			stk.clear_stk();
			break;
		  case 4:
			break;
		  }
	}while(ch1!=4);
	break;
	case 3:
		break;
	}
   }while(ch!=3);
getch();
}
