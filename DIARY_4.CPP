#include<stdio.h>

#include<stdlib.h>

#include<iostream>

using namespace std;

#include<conio.h>

#include<string.h>

#include<fstream>

#include<windows.h>

void addrecord();
void viewrecord();
void editrecord();
void deleterecord();
int checkpass();
//this function prints all the records.
void printAll(); //my function (extra)
//this functions delete's all records.
void deleteAll();
int main();
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

class record {
  private:
    char date[12];
  char time[6];
  char name[30];
  char ppl[100];
  char place[25];
  char duration[20];
  char note[500];
  public:
    char * retName();	//added this to get name of the record (Title)
  int timecheck(char ent[]);
  void input();
  void output();
  void setdate(char ent[]);
  void settime(char ent[]);
  void setname(char ent[]);
  void setppl(char ent[]);
  void setplace(char ent[]);
  void setdur(char ent[]);
  void setnote(char ent[]);
  int datecheck(char ent[]);
  int namecheck(char ent[]);
  int pplcheck(char ent[]);
  int placecheck(char ent[]);
  int durcheck(char ent[]);
  char * retdate() {
    return date;
  }
  char * rettime();
  char * retname() {
    return name;
  }
};
char * record::retName() {
  return name;
}
char * record::rettime() {
  return time;
}

int record::datecheck(char ent[]) {
  if (strcmp(date, ent) == 0) {
    return 1;
  } else
    return 0;
}

int record::namecheck(char ent[]) {
  char ch2[30];
  int i1=0;
  int i2=0;
  int j=0;
  int n=strlen(ent);
  int k;
  if (strcmpi(name,ent)==0)
  {	return 1;	}
  else
  {
  while(name[i1]!='\0'&&i1<30)
  { while(name[i1]!=' '&&i2<n)
      {ch2[i2]=name[i1];
	k=++i2;
	++i1;}
	ch2[k]='\0';
	i2=0;
	while(name[i1]!=' '&&name[i1]!='\0')
	{  i1++;
		    }
	 if(name[i1]!='\0');
	 {i1++;}
  if (strcmpi(ch2, ent) == 0) {
  
    ++j;
    return 1;
    }   }
    if(j==0)
    {return 0;}}
    }

int record::pplcheck(char ent[])
{
  char ch2[30];
  int i1=0;
  int i2=0;
  int j=0;
  int n=strlen(ent);
  int k;
  if(strcmpi(ppl,ent)==0)
  { return 1;}
  else
  {
  while(ppl[i1]!='\0'&&i1<100)
  {

	while(ppl[i1]!=' '&&i2<n)
      {
	ch2[i2]=ppl[i1];
	k=++i2;
	++i1;}
	ch2[k]='\0';
	i2=0;
	while(ppl[i1]!=' '&&ppl[i1]!='\0')
	{
		i1++;
		    }
	 if(ppl[i1]!='\0')
	 { i1++; }
	if(strcmpi(ent,ch2)==0)
	{
	 ++j;
	 return 1;
		   }
	}
      if(j==0)
    {return 0;}}
    }
 

int record::placecheck(char ent[]) {
  if (strcmpi(place, ent) == 0) {
    return 1;
  } else
    return 0;
}

int record::durcheck(char ent[]) {
  if (strcmpi(duration, ent) == 0) {
    return 1;
  } else
    return 0;
}

void record::setdate(char ent[]) {
  strcpy(date, ent);
}

void record::settime(char ent[]) {
  strcpy(time, ent);
}

void record::setname(char ent[]) {
  strcpy(name, ent);
}

void record::setppl(char ent[]) {
  strcpy(ppl, ent);
}

void record::setplace(char ent[]) {
  strcpy(place, ent);
}

void record::setdur(char ent[]) {
  strcpy(duration, ent);
}

void record::setnote(char ent[]) {
  strcpy(note, ent);
}

void record::input() {
  cout << "\nENTER TITLE[<=30 characters]:";
  fflush(stdin);
  gets(name);
  cout << "\nENTER NAME OF PEOPLE INVOLVED:";
  fflush(stdin);
  gets(ppl);
  cout << "\nENTER PLACE [<=25 characters]:";
  gets(place);
  cout << "\nENTER DURATION:";
  gets(duration);
  cout << "\nNOTES:";
  gets(note);
  
}

void record::output() {
  cout << "\nTITLE:" << name;
  cout << "\nDATE:" << date;
  cout << "\nTIME:" << time;
  cout << "\nWITH:" << ppl;
  cout << "\nAT:" << place;
  cout << "\nDURATION:" << duration;
  cout << "\nNOTE:" << note;
  cout << "\n";
}

int record::timecheck(char ent[]) {
  if (strcmp(time, ent) == 0) {
    return 1;
  } else return 0;
}

void login() {
  char pass[10];
  char ch;
  int i = 0;
  gotoxy(27, 11);
  cout << "Personal Diary Management";
  gotoxy(27, 12);
  cout << "Enter Password:";
  ch = getch();
  while (ch != 13) { //character 13 is enter
    pass[i] = ch;
    cout << '*';
    ch = getch();
    i++;
  }
  pass[i] = '\0';
  if (strcmp("pass", pass) == 0) {
    gotoxy(27,14);
    cout << "Access Granted";
    getch();
    system("cls");;
    return;
  } else {
    gotoxy(27,13);
    cout << "\nAccess Aborted...\n";
    getch();
    exit(1);
  }
}

int checkpass() {
 system("cls");;
  char pass[10];
  char ch;
  int i = 0;
  cout << "Enter Password:";
  ch = getch();
  while (ch != 13) { //character 13 is enter
    pass[i] = ch;
    cout << '*';
    ch = getch();
    i++;
  }
  pass[i] = '\0';
  if ((strcmp(pass, "pass")) == 0) {
    return 0;
  } else
    return 1;
}

void viewbydate() {
  record e;
  int i = 1;
  char date[12], title[30], time[6];
  cout << "\nENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:";
  fflush(stdin); 
  gets(date);
  ifstream fin("stories.dat", ios::binary);
  if (fin.fail()) {
    puts("\nSYSTEM ERROR! UNABLE TO OPEN FILE\n");
    cout << "PRESS ANY KEY TO EXIT...";
    getch();
    return;
  }
  cout << "\nRECORDS ON THIS DATE:-";
  while (fin.read((char * ) & e, sizeof(e))) {
    if (e.datecheck(date)) {
      cout<<'\n';
      cout << "\n.TITLE:" << e.retname();

      cout << "\n.TIME:" << e.rettime();
      i++;
    }
  }
  if (i == 1) {
    cout << "\nNO RECORDS ON THIS DATE";
    getch();
    return;
  } else {
    i = 2;
    cout << "\nENTER TIME FROM ABOVE OPTIONS:";
    gets(time);
    fin.close();	//replaced seekg with this. get's to the file start as seekg did.
    fin.open("stories.dat", ios::binary);
    while (fin.read((char * ) & e, sizeof(e))) {
      if (e.datecheck(date) && e.timecheck(time)) {
	e.output();
	i = 3;
      }
    }
    fin.close();
    if (i == 2) {
      cout << "\nYOU TYPED SOMETHING ELSE";
      cout << "\nPRESS ANY KEY TO RETURN TO VIEW MENU...";
      getch();
      return;
    } else
      getch();
  }
}

void viewbyppl() {
  record e;
  int i = 1;
  char ppl[30], title[30];
  cout << "\nENTER NAME OF PERSON: ";
  fflush(stdin);
  gets(ppl);

  ifstream fin("stories.dat", ios::binary);
  if (fin.fail()) {
    puts("\nSYSTEM ERROR! UNABLE TO OPEN FILE\n");
    cout << "PRESS ANY KEY TO EXIT...";
    getch();
    return;
  }
  cout << "\nRECORDS WITH THIS PERSON:-";
  while (fin.read((char * ) & e, sizeof(e))) {
    if (e.pplcheck(ppl)) {
      cout<<'\n';
      cout << "\n.TITLE:" << e.retname();
      cout << "\n.DATE:" << e.retdate();
      cout << "\n.TIME:" << e.rettime();
      i++;
    }
  }
  if (i == 1) {
    cout << "NO RECORDS WITH THIS PERSON";
    getch();
    return;
  } else {
    i = 2;
    cout << "\nENTER TITLE FROM ABOVE OPTIONS:";
    gets(title);

    fin.close();	//replaced seekg with this. get's to the file start as seekg did.
    fin.open("stories.dat", ios::binary);
    // fin.seekg(0, ios::beg);
    while (fin.read((char * ) & e, sizeof(e))) {

      if (e.pplcheck(ppl) && e.namecheck(title)) {
	e.output();
	i = 3;
      }
    }
    fin.close();
    if (i == 2) {
      cout << "\nYOU TYPED SOMETHING ELSE";
      cout << "\nPRESS ANY KEY TO RETURN...";
      getch();
      return;
    } else
      getch();
  }
}

void viewbyplace() {
  record e;
  int i = 1;
  char place[25], title[30];
  cout << "\nENTER PLACE OF EVENT:";
  fflush(stdin);
  gets(place);
  ifstream fin("stories.dat", ios::binary);
  if (fin.fail()) {
    puts("\nSYSTEM ERROR! UNABLE TO OPEN FILE\n");
    cout << "PRESS ANY KEY TO EXIT...";
    getch();
    return;
  }
  cout << "\nRECORDS AT THIS PLACE:-";
  while (fin.read((char * ) & e, sizeof(e))) {
    if (e.placecheck(place)) {
      cout<<'\n';
      cout << "\n" << ".TITLE:" << e.retname();
      cout << "\n.DATE:" << e.retdate();
      cout << "\n.TIME:" << e.rettime();
      i++;
    }
  }
  if (i == 1) {
    cout << "\nNO RECORDS AT THIS PLACE";
    getch();
    return;
  } else {
    i = 2;
    cout << "\nENTER TITLE FROM ABOVE OPTIONS:";
    gets(title);
    fin.close();	//replaced seekg with this. get's to the file start as seekg did.
    fin.open("stories.dat", ios::binary);
    while (fin.read((char * ) & e, sizeof(e))) {
      if (e.placecheck(place) && e.namecheck(title)) {
	e.output();
	i = 3;
      }
    }
    fin.close();
    if (i == 2) {
      cout << "\nYOU TYPED SOMETHING ELSE";
      cout << "\nPRESS ANY KEY TO RETURN...";
      getch();
      return;
    } else
      getch();
  }
}

void viewbytime() {
  record e;
  int i = 1;
  char date[12], title[30], time[6];
  cout << "\nENTER TIME OF YOUR EVENT[hh:mm]:";
  fflush(stdin); 
  gets(time);
  ifstream fin("stories.dat", ios::binary);
  if (fin.fail()) {
    puts("\nSYSTEM ERROR! UNABLE TO OPEN FILE\n");
    cout << "PRESS ANY KEY TO EXIT...";
    getch();
    return;
  }
  cout << "\nRECORDS AT THIS TIME:-";
  while (fin.read((char * ) & e, sizeof(e))) {
    if (e.timecheck(time)) {
      cout<<'\n';
      cout << "\n" << ".TITLE:" << e.retname();
      cout << "\n" << ".DATE:" << e.retdate();
      i++;
    }
  }
  if (i == 1) {
    cout << "\nNO RECORDS AT THIS TIME";
    getch();
    return;
  } else {
    i = 2;
    cout << "\nENTER DATE FROM ABOVE OPTIONS:";
    gets(date);
    fin.close();	//replaced seekg with this. get's to the file start as seekg did.
    fin.open("stories.dat", ios::binary);
    while (fin.read((char * ) & e, sizeof(e))) {
      if (e.timecheck(time) && e.datecheck(date)) {
	e.output();
	i = 3;
      }
    }
    fin.close();
    if (i == 2) {
      cout << "\nYOU TYPED SOMETHING ELSE";
      cout << "\nPRESS ANY KEY TO RETURN...";
      getch();
      return;
    } else
      getch();
  }
}

void viewbydur() {
  record e;
  int i = 1;
  char date[12], title[30], duration[20];
  cout << "\nENTER DURATION OF YOUR RECORD:";
  fflush(stdin);
  gets(duration);
  ifstream fin("stories.dat", ios::binary);
  if (fin.fail()) {
    puts("\nSYSTEM ERROR! UNABLE TO OPEN FILE\n");
    cout << "PRESS ANY KEY TO EXIT...";
    getch();
    return;
  }
  cout << "\nRECORDS WITH THIS DURATION:-";
  while (fin.read((char * ) & e, sizeof(e))) {
    if (e.durcheck(duration)) {
      cout<<'\n';
      cout << "\n" << ".TITLE" << e.retname();
      cout << "\n" << ".DATE:" << e.retdate();
      cout << "\n.TIME:" << e.rettime();
      i++;
    }
  }
  if (i == 1) {
    cout << "\nNO RECORDS ON THIS DATE";
    getch();
    return;
  } else {
    i = 2;
    cout << "\nENTER TITLE FROM ABOVE OPTIONS:";
    gets(title);
    fin.close();	//replaced seekg with this. get's to the file start as seekg did.
    fin.open("stories.dat", ios::binary);
    while (fin.read((char * ) & e, sizeof(e))) {
      if (e.durcheck(duration) && e.namecheck(title)) {
	e.output();
	i = 3;
      }
    }
    fin.close();
    if (i == 2) {
      cout << "\nYOU TYPED SOMETHING ELSE";
      cout << "\nPRESS ANY KEY TO RETURN...";
      getch();
      return;
    } else
      getch();
  }
}

void viewbytitle() {
  record e;
  int i = 1;
  char date[12], title[30];
  cout << "\nENTER TITLE OF YOUR RECORD:";
  fflush(stdin);
  gets(title);
  ifstream fin("stories.dat", ios::binary);
  if (fin.fail()) {
    puts("\nSYSTEM ERROR! UNABLE TO OPEN FILE\n");
    cout << "PRESS ANY KEY TO EXIT...";
    getch();
    return;
  }
  cout << "\nRECORDS WITH THIS TITLE:-";
  while (fin.read((char * ) & e, sizeof(e))) {
    if (e.namecheck(title)) {
      cout<<'\n';
      cout << "\n" << ".TITLE:" << e.retname();
      cout << "\n" << ".DATE:" << e.retdate();
      i++;
    }
  }
  if (i == 1) {
    cout << "\nNO RECORDS WITH THIS TITLE";
    getch();
    return;
  } else {
    i = 2;
    cout << "\nENTER DATE FROM ABOVE OPTIONS:";
    gets(date);
    fin.close();	//replaced seekg with this. get's to the file start as seekg did.
    fin.open("stories.dat", ios::binary);
    while (fin.read((char * ) & e, sizeof(e))) {
      if (e.namecheck(title) && e.datecheck(date)) {
	  e.output();
    i = 3;
	      }
    }
    fin.close();
    if (i == 2) {
      cout << "\nYOU TYPED SOMETHING ELSE";
      cout << "\nPRESS ANY KEY TO RETURN...";
      getch();
      return;
    } else
      getch();
  }
}

int main() {
  system("cls");;
  login();
  int ch;

  while (1) {
    gotoxy(23,1);
  cout << "*********************************\n";
  gotoxy(23,2);
  cout << "**DAILY DIARY MANAGEMENT SYSTEM**\n";
  gotoxy(23,3);
  cout << "*********************************\n";
    cout << "\n\nMAIN MENU:";
    cout << "\n\nADD STORY          [1]";
    cout << "\nVIEW STORY         [2]";
    cout << "\nEDIT STORY         [3]";
    cout << "\nDELETE STORY       [4]";
    cout << "\nPRINT ALL          [5]";
    cout << "\nDELETE ALL         [6]";
    cout << "\nEXIT               [7]";
    cout << "\n\nENTER YOUR CHOICE: ";
    fflush(stdin);
    cin >> ch;
    cin.ignore();

    switch (ch) {
    case 1:
      addrecord();
      break;
    case 2:
      viewrecord();
      break;
    case 3:
      editrecord();
      break;
    case 4:
      deleterecord();
      break;
    case 7:
      gotoxy(24,20);
      cout << "\n\nTHANK YOU FOR USING THE SOFTWARE";
      getch();
      exit(0);
    case 5:
      printAll();
      break;
    case 6:
      deleteAll();
      break;
    default:
      cout << "\nYOU ENTERED WRONG CHOICE";
      cout << "\nPRESS ANY KEY TO TRY AGAIN";
      getch();
      break;
    }
    system("cls");;
  }
  getch();
  return 0;
}

void addrecord() {
  system("cls");
  ifstream fin;
  ofstream fout;
  char another = 'Y', time[6];

  char date[12];
  int choice;

  choice = checkpass();
  if (choice != 0) {
    return;
  }
  system("cls");;
  gotoxy(26,1);
  cout << "***************************\n";
  gotoxy(26,2);
  cout << "****WELCOME TO THE MENU****\n";
  gotoxy(26,3);
  cout << "***************************\n";

  while (another == 'Y' || another == 'y') {
    record e;
    fin.open("stories.dat", ios::binary);
    if (fin.fail() || fout.fail()) {
      puts("\nSYSTEM ERROR! UNABLE TO OPEN FILE\n");
      cout << "PRESS ANY KEY TO EXIT...";
      getch();
      return;
    }

    cout << "\n\nENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:";
    fflush(stdin);
    gets(date);
    choice = 0;
    fflush(stdin);
    cout << "\nENTER TIME:[hh:mm]:";
    cin >> time;
    while (fin.read((char * ) & e, sizeof(e))) {
      if (e.timecheck(time) && e.datecheck(date)) {
	cout << "\n\nTHE RECORD ALREADY EXISTS.\n";
	choice = 1;
      }
    }
    fin.close();
    fout.open("stories.dat", ios::binary | ios::app);
    if (choice == 0) {
	    e.setdate(date);
      e.settime(time);
      e.input();
      fout.write((char * ) & e, sizeof(e));
    }
    cout << "\nADD ANOTHER STORY? (Y/N) ";
    fflush(stdin);
    another = getche();
    fout.close();
  }
  cout << "\n\nPRESS ANY KEY TO EXIT...";
  getch();
}

void viewrecord() {

  system("cls");;
  record toview;
  char time[6], choice, date[12];
  int ch;
  gotoxy(25,1);
  cout << "******************************\n";
  gotoxy(25,2);
  cout << "  * HERE IS THE VIEW MENU *";
  gotoxy(25,3);
  cout << "******************************\n";;
  choice = checkpass();
  if (choice != 0) {
    return;
  }
  system("cls");;
  do {

    system("cls");;
    cout << "\nHOW WOULD YOU LIKE TO VIEW:\n";
    cout << "\n1.VIEW BY DATE.";
    cout << "\n2.VIEW BY PEOPLE INVOLVED.";
    cout << "\n3.VIEW BY PLACE";
    cout << "\n4.VIEW BY TIME";
    cout << "\n5.VIEW BY DURATION";
    cout << "\n6.VIEW BY TITLE";
    cout << "\n\nENTER YOUR CHOICE:";
    cin >> ch;
    switch (ch) {
    case 1:
      system("cls");;
      viewbydate();
      break;
    case 2:
      system("cls");;
      viewbyppl();
      break;
    case 3:
      system("cls");;
      viewbyplace();
      break;
    case 4:
      system("cls");;
      viewbytime();
      break;
    case 5:
      system("cls");;
      viewbydur();
      break;
    case 6:
      system("cls");;
      viewbytitle();
      break;
    default:
      cout << "\nYOU TYPED SOMETHING ELSE...\n";
      break;
    }
    cout << "\n\nWOULD YOU LIKE TO CONTINUE VIEWING? (Y/N):";
    fflush(stdin);
    cin >> choice;
  }
  while (choice == 'Y' || choice == 'y');

  return;
}

//made major changes into this function.
//replaced seekg, tellp functionality with temp.dat file
//works like what was done with delete.
void editrecord() {
  system("cls");;
  int p;
  char date[12];
  char time[6];
  char title[30];
  char ppl[30];
  char place[25];
  char duration[20];
  char note[500];
  ifstream fin("stories.dat", ios::binary);

  if (fin.fail()) {
    cout << "\nSYSTEM ERROR:";
    cout << "\nPRESS ANY KEY TO GO BACK";
    getch();
    return;
  }
  fin.close();

  record e;
  record another;
  int choice;
  int num, count = 0, check;
  gotoxy(24,1);
  cout << "*******************************\n";
  gotoxy(24,2);
  cout << "* WELCOME TO THE EDITING MENU *\n";
  gotoxy(24,3);
  cout << "*******************************\n\n";
  choice = checkpass();
  if (choice != 0) {
    return;
  }
  system("cls");;
  do {

    // fin.close();
    fin.open("stories.dat", ios::binary);
    cout << "\nENTER THE DATE OF RECORD TO BE EDITED:[yyyy-mm-dd]:";
    fflush(stdin);
    gets(date);
    cout << "\nENTER TIME:[hh:mm]:";
    gets(time);
    ofstream tempfout("temp.dat", ios::binary | ios::trunc);	//temporary.
    while (fin.read((char * ) & e, sizeof(e))) {

      if (e.timecheck(time) && e.datecheck(date)) {
	cout << "\nYOUR OLD RECORD WAS AS:";
	e.output();
	cout << "\n\nWHAT WOULD YOU LIKE TO EDIT..";
	cout << "\n1.DATE.";
	cout << "\n2.TIME.";
	cout << "\n3.TITLE.";
	cout << "\n4.PEOPLE INVLOLVED.";
	cout << "\n5.PLACE.";
	cout << "\n6.DURATION.";
	cout << "\n7.NOTE.";
	cout << "\n8.WHOLE RECORD.";
	cout << "\n9.GO BACK TO MAIN MENU.";

	do {
	  check = 0;
	  cout << "\n\nENTER YOUR CHOICE:";
	  fflush(stdin);
	  cin >> num;
	  cin.ignore();
	  fflush(stdin);
	  switch (num) {
	  case 1:
	    cout << "\nENTER THE NEW DATE:[yyyy-mm-dd]:";

	    gets(date);
	    e.setdate(date);
	    check++;
	    break;
	  case 2:
	    cout << "\nENTER NEW TIME:[hh:mm]:";

	    gets(time);
	    e.settime(time);
	    check++;
	    break;
	  case 3:
	    cout << "\nENTER THE NEW TITLE:";

	    gets(title);
	    e.setname(title);
	    check++;
	    break;
	  case 4:
	    cout << "\nENTER THE NEW PEOPLE:";

	    gets(ppl);
	    e.setppl(ppl);
	    check++;
	    break;
	  case 5:
	    cout << "\nENTER THE NEW PLACE:";

	    gets(place);
	    e.setplace(place);
	    check++;
	    break;
	  case 6:
	    cout << "\nENTER THE NEW DURATION:";
	    gets(duration);
	    e.setdur(duration);
	    check++;
	    break;
	  case 7:
	    cout << "\nENTER THE NEW NOTE:";
	    gets(note);
	    e.setnote(note);
	    check++;

	    break;
	  case 8:
	    cout << "\nENTER NEW DATA:";
	    e.input();
	    check++;
	    break;

	  case 9:
	    cout << "\nYOU EXITED...";
	    getch();
	    return;
	  default:
	    cout << "\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n";
	    break;
	  }
	}
	while (num < 1 || num > 8);
	if (check != 0) {
	  // p = fin.tellg() - sizeof(e);
	  // ofstream fout("stories.dat", ios::binary);
	  // fout.seekp(p, ios::beg);
	  another = e;
	  tempfout.write((char * ) & e, sizeof(e));
	  choice = 5;
	}
	else
	{
		tempfout.write((char*)&e, sizeof(e));
	}

      }
      else
      {
	tempfout.write((char*)&e, sizeof(e));
      }
    }
    if (choice == 5) {
      system("cls");;
      cout << "\nEDITING COMPLETED...\n";
      cout << "--------------------\n";
      cout << "THE NEW RECORD IS:\n";
      cout << "--------------------\n";
      // fin.seekg(p, ios::beg);
      // fin.read((char * ) & e, sizeof(e));
      another.output();
      cout << "\n\nWOULD YOU LIKE TO EDIT ANOTHER RECORD? (Y/N)";
      choice = getche();
      count++;
    } else {
      cout << "\nTHE RECORD DOES NOT EXIST:\n";
      cout << "\nWOULD YOU LIKE TO TRY AGAIN? (Y/N)";
      choice = getche();
    }
    fin.close();
	  tempfout.close();
  }
  while (choice == 'Y' || choice == 'y');
  // fin.close();
  if (count == 1)
    cout << '\n' << count << " FILE IS EDITED...\n", count;
  else if (count > 1)
    cout << '\n' << count << " FILES ARE EDITED..\n", count;
  else
    cout << "\nNO FILES EDITED...\n";
  cout << "PRESS ENTER TO EXIT EDITING MENU.";
  getch();

  fin.open("temp.dat", ios::binary);
  ofstream fout;
  fout.open("stories.dat", ios::binary | ios::trunc);

  while(fin.read((char*)&e, sizeof(e)))
  {
	fout.write((char*)&e,sizeof(e));
  }

  fin.close();
  fout.close();
  fflush(stdin);
  // return;
}

void deleterecord() {


  record e;
  char date[12], another = 'Y', time[6];
  int choice, check, count = 0;
  check = checkpass()      ;
  system("cls");;
  gotoxy(27,1);
  cout << "*************************\n";
  gotoxy(27,2);
  cout << "* WELCOME TO DELETE MENU*";
  gotoxy(27,3);
  cout << "*************************\n\n";
  if (check == 1) {
    return;
  }
  while (another == 'Y' || another == 'y') {

    ifstream fin("stories.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary | ios::trunc);
    if (fin.fail() || fout.fail()) {
      puts("\nSYSTEM ERROR! UNABLE TO OPEN FILE\n");
      cout << "PRESS ANY KEY TO EXIT...";
      getch();
      return;
    }
    cout << "\n\nHOW WOULD YOU LIKE TO DELETE:";
    cout << "\n\n#DELETE WHOLE RECORD\t\t\t[1]";
    cout << "\n#DELETE A PARTICULAR RECORD BY TIME\t[2]";
    do {
      count=0;
      cout << "\nENTER YOU CHOICE:";
      cin >> choice;
      cin.ignore();
      switch (choice) {
      case 1:
	cout << "\nENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:";
	// fflush(stdin);
	gets(date);
	while (fin.read((char * ) & e, sizeof(e))) {
	  if (e.datecheck(date) == 0) {
	    fout.write((char * ) & e, sizeof(e));
	    // count++;
	  }
	  else
	  {
		count++;
	  }
	}
	if (count == 0) {
	  cout << "\nRECORD DOESN'T EXIST";
	} else {
	  cout << "\nDELETED SUCCESFULLY...";
	  fin.close();
	  fout.close();
	  remove("stories.dat");
	  rename("temp.dat", "stories.dat");
	}
	break;
      case 2:
	cout << "\nENTER THE DATE OF RECORD:[yyyy-mm-dd]:";
	fflush(stdin);
	gets(date);
	cout << "\nENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:";
	fflush(stdin);
	gets(time);

	while (fin.read((char * ) & e, sizeof(e))) {
	  if (e.timecheck(time) == 1 && e.datecheck(date) == 1)
	  {
	  }
	  else{
	    fout.write((char * ) & e, sizeof(e));

	  }
	}
	fin.close();
	fout.close();
	remove("stories.dat");
	rename("temp.dat", "stories.dat");
	cout << "\nDELETED SUCCESFULLY...";
	break;
      default:
	cout << "\nYOU ENTERED WRONG CHOICE";
	break;
      }
    } while (choice < 1 || choice > 2);
    // cout << "\nPLEASE RECREATE temp.dat AT THE LOCATION WHERE PROGRAM FILE IS IN ORDER TO DELETE ANY FURTHER FILES";
    // cout << "\nOTHERWISE YOU MIGHT LOSE ALL RECORDS";
    fflush(stdin);
    fout.open("temp.dat", ios::binary | ios::trunc);	//creating temp so that you don't have to print this above error. :)
    fout.close();
    cout << "\n\nDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):";
    another = getche();
    cin.ignore();
  }
  cout << "\n\nPRESS ANY KEY TO EXIT...";
  getch();
}

void printAll() {
  int choice = checkpass();
  if (choice != 0) {
    return;
  }
  system("cls");
  ifstream fin("stories.dat", ios::binary);
  if (fin.fail()) {
    puts("\nSYSTEM ERROR! UNABLE TO OPEN FILE!\n");
    getch();
    return;
  }

  cout << "ALL RECORDS:\n";
  record e;
  while (fin.read((char * ) & e, sizeof(e))) {
    e.output();
  }
  fin.close();
  getch();
}

void deleteAll()
{
  int xyz = checkpass();
  if (xyz != 0) {
    return;
  }
  system("cls");
  cout << "Are you sure you want to delete all records?(Y/N)";
  char choice = getche();
  if (choice != 'Y' && choice != 'y')
  {
    cout << "\n\nDidn't delete anything.\n";
    cout << "Press enter to go back.";
    getch();
    return ;
  }
  else
  {
    //creates an empty file.
    ofstream fout("temp.dat", ios::binary | ios::trunc);
    fout.close(); //closes it.
    remove("stories.dat");  //removes the file that has the data.
    rename("temp.dat", "stories.dat");  //renames the empty file to data file.
    cout << "\n\nEverything was deleted.";
    cout << "Press enter to go back.";
    getch();
  }
}