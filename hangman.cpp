/**********************
Project Start : 14.5.15
Coded by Mohit Bhasi
Class : XII A
Roll : 9
**********************/

#include <fstream>
#include <conio>
#include <stdio>
#include <stdlib>
#include <iomanip>
#include <windows>
#include <time>
typedef char string[100];
/*************************************
Generate random
*************************************/
int genra()
{
	//randomize();
   int a[]={0,2,4,6,8,10,12,14,16,18};
   int j, aj;
   j = random(10);
   j = random(10);
   return a[j];
}
/***************************************
Modified gets() function that limits character input
***************************************/
void mygets(char *s, int limit)
{
	void delchar(char*, int, int, int&);
   int i, curx, done;
   int col=wherex();
   for(i=0; i<limit; i++)
      cout<<' ';
   gotoxy(col, wherey());
   done=curx=i=0;
   do
   {
      char ch=char(getch());
      switch(ch)
      {
         case 0:
            ch=char(getch());
            switch (ch)
            {
               case 75:
                  if (curx>0)
                  {
                     curx--;
                     gotoxy(wherex()-1, wherey());
                  }
                  break;
               case 77:
                  if (curx<i)
                  {
                     curx++;
                     gotoxy(wherex()+1, wherey());
                  }
                  break;
               case 83:
                  if (i>0)
                  {
                     if (curx<i)
                     {
                        delchar(s, col, curx+1, i);
                        gotoxy(col+curx, wherey());
                        if (i==0)
                           s[i]=0;
                     }
                  }
            }
            break;
         case 8:
            if (curx>0)
            {
               delchar(s, col, curx, i);
               gotoxy(col+curx-1, wherey());
               curx--;
               if (i==0)
                  s[i]=0;
            }
            break;
         case 13:
            done=1;
            s[i]=0;
            break;
         case 27:
            done=1;
            s[0]=0;
            break;
         default:
            if (i<limit)
            {
               if (curx<i)
               {
                  s[curx]=ch;
                  cout<<ch;
                  curx++;
               }
               else
               {
                  s[i]=ch;
                  cout<<ch;
                  i++;
                  curx=i;
               }
            }
            else
               s[i]=0;
      }
   }
   while(!done);
   cout<<endl;
}
/*********************************************
Function to delete character
*********************************************/
void delchar(char *s, int col, int p, int &len)
{
   int i;
   for(i=p; i<len; i++)
      s[i-1]=s[i];
   gotoxy(col+p-1, wherey());
   len--;
   for(i=p-1; i<len; i++)
      cout<<s[i];
   cout<<' ';
}

/***************************************
Player class declaration
***************************************/
class player
{
	int sec , lives;
   string name;
   char difficulty[7];
   public:
   	char *retname(){return name;}
      char *retdifficulty(){return difficulty;}
		int rettime(){return sec;}
		int retlives(){return lives;}
      char *setdifficulty(char *d){strcpy(difficulty,d);}
		int setlives(int l){lives=l;}
      int settime (int s){sec=s;}
      void getname()
      {
      	Sleep(2000);
  	    	clrscr();
         cout<<"Welcome Player !\nEnter your name:";
         gets(name);
      }
}a;

/***************************************
Function displays welcome screen
***************************************/
void welcome()

{
	char letter;
	for (int intro_letter = 1 ; intro_letter<=7 ; intro_letter++)
   {
   	switch (intro_letter)
      {
      	case 1:
         	letter = 'H';
            break;
         case 2:
         	letter = 'A';
            break;
         case 3:
         	letter = 'N';
            break;
         case 4:
         	letter = 'G';
            break;
      	case 5:
         	letter = 'M';
            break;
         case 6:
         	letter = 'A';
            break;
         case 7:
         	letter = 'N';
            break;
      }
      for (int slider = 1 ; slider<=10 ; slider++)
      {
         gotoxy(35+intro_letter,slider);
      	Sleep(50);
         if (slider==10)
         	printf("%c",letter);
      }
   }
   Sleep(60);
   cout<<"\n\n\n                               By: Mohit Bhasi";
}
/*************************************
Function to display levels
**************************************/
void displaylvl()
{
	clrscr();
	// system("color f3");
	char d[2];
   while (true)
   {
   	cout<<"Levels:\n\n";
   	cout<<"1.Easy\n";
   	cout<<"2.Medium\n";
   	cout<<"3.Hard\n";
		cout<<"Choose your difficulty:";
   	mygets(d,1);
	   if (d[0]=='1')
   	{
      	a.setdifficulty("Easy");
      	break;
      }
   	else
   	if (d[0]=='2')
      {
   		a.setdifficulty("Medium");
      	break;
      }
   	else
		if (d[0]=='3')
      {
       	a.setdifficulty("Hard");
      	break;
      }
   	else
		{
			gotoxy(0,2);
   		cout<<"Enter 1 , 2 or 3 only!\n";
         Sleep(1200);
		   clrscr();
		}
   }
}
/***********************************************
Function to get a word from file
***********************************************/
char *getword(int k)
{
	string word;
   string wordlist[20];
   if (strcmpi(a.retdifficulty(),"easy")==0)
   {
   	int x = 0;
		ifstream fin("easy.txt");
      while (fin.getline(wordlist[x++],100));
      return wordlist[k];
   }
   if (strcmpi(a.retdifficulty(),"medium")==0)
      {
   	int x = 0;
		ifstream fin("medium.txt");
      while (fin.getline(wordlist[x++],100));
      return wordlist[k];
   }
   if (strcmpi(a.retdifficulty(),"hard")==0)
   {
   	int x = 0;
		ifstream fin("hard.txt");
      while (fin.getline(wordlist[x++],100));
      return wordlist[k];
   }
}
/*****************************************
Linear search function
******************************************/
int search(char a,char *b,int &pos)
{
	int x = 0;
   for (int j = 0 ; b[j] ; j++)
   	if (a==b[j])
      {
      	x++;
      	pos=j;
   	}
   return x;
}
int search(char a,char *b)
{
	int x = 0;
   for (int j = 0 ; b[j] ; b++)
   	if (a==b[j])
      	x++;
   return x;
}

/***********************************
Function to draw letters in place
***********************************/
void draw (char guess[],int xc)
{

	if (guess[0]=='a')
   {
     	gotoxy((xc*6)+3,15);
      cout << " ___";
   	gotoxy((xc*6)+3,16);
      cout << "|   |";
   	gotoxy((xc*6)+3,17);
      cout << "|___|";
      gotoxy((xc*6)+3,18);
      cout << "|   |";
      gotoxy((xc*6)+3,19);
      cout << "|   |";
   }
   if (guess[0]=='b')
 	{
     	gotoxy((xc*6)+3,15);
      cout << " ___";
   	gotoxy((xc*6)+3,16);
      cout << "|   \\";
   	gotoxy((xc*6)+3,17);
      cout << "|___/";
      gotoxy((xc*6)+3,18);
      cout << "|   \\";
      gotoxy((xc*6)+3,19);
      cout << "|___/";
   }
   if (guess[0]=='c')
 	{

     	gotoxy((xc*6)+3,15);
      cout << " ___";
   	gotoxy((xc*6)+3,16);
      cout << "/   \\";
   	gotoxy((xc*6)+3,17);
      cout << "|";
      gotoxy((xc*6)+3,18);
      cout << "|";
      gotoxy((xc*6)+3,19);
      cout << "\\___/";
   }
   if (guess[0]=='d')
   {
     	gotoxy((xc*6)+3,15);
      cout << " ___";
   	gotoxy((xc*6)+3,16);
      cout << "|   \\";
   	gotoxy((xc*6)+3,17);
      cout << "|   |";
      gotoxy((xc*6)+3,18);
      cout << "|   |";
      gotoxy((xc*6)+3,19);
      cout << "|___/";
   }
   if (guess[0]=='e')
   {
     	gotoxy((xc*6)+3,15);
      cout << " ____";
   	gotoxy((xc*6)+3,16);
      cout << "|";
   	gotoxy((xc*6)+3,17);
      cout << "|____";
      gotoxy((xc*6)+3,18);
      cout << "|";
      gotoxy((xc*6)+3,19);
      cout << "|____";
   }
   if (guess[0]=='f')
   {
     	gotoxy((xc*6)+3,15);
      cout << " ____";
   	gotoxy((xc*6)+3,16);
      cout << "|";
   	gotoxy((xc*6)+3,17);
      cout << "|____";
      gotoxy((xc*6)+3,18);
      cout << "|";
      gotoxy((xc*6)+3,19);
      cout << "|";
   }
   if (guess[0]=='g')
   {
     	gotoxy((xc*6)+3,15);
      cout << " ___";
   	gotoxy((xc*6)+3,16);
      cout << "/   \\";
   	gotoxy((xc*6)+3,17);
      cout << "|  __";
      gotoxy((xc*6)+3,18);
      cout << "|   |";
      gotoxy((xc*6)+3,19);
      cout << "\\___/";
   }
   if (guess[0]=='h')
   {
     	gotoxy((xc*6)+3,15);
      cout << "|   |";
   	gotoxy((xc*6)+3,16);
      cout << "|   |";
   	gotoxy((xc*6)+3,17);
      cout << "|___|";
      gotoxy((xc*6)+3,18);
      cout << "|   |";
      gotoxy((xc*6)+3,19);
      cout << "|   |";
   }
   if (guess[0]=='i')
   {
     	gotoxy((xc*6)+3,15);
      cout << "_____";
   	gotoxy((xc*6)+3,16);
      cout << "  |";
   	gotoxy((xc*6)+3,17);
      cout << "  |";
      gotoxy((xc*6)+3,18);
      cout << "  |";
      gotoxy((xc*6)+3,19);
      cout << "__|__";

   }
   if (guess[0]=='j')
   {
     	gotoxy((xc*6)+3,15);
      cout << " ____";
   	gotoxy((xc*6)+3,16);
      cout << "   | ";
   	gotoxy((xc*6)+3,17);
      cout << "   | ";
      gotoxy((xc*6)+3,18);
      cout << "   | ";
      gotoxy((xc*6)+3,19);
      cout << "\\__/ ";
   }
   if (guess[0]=='k' )
   {
     	gotoxy((xc*6)+3,15);
      cout << "|  /";
   	gotoxy((xc*6)+3,16);
      cout << "| /";
   	gotoxy((xc*6)+3,17);
      cout << "|/";
      gotoxy((xc*6)+3,18);
      cout << "| \\";
      gotoxy((xc*6)+3,19);
      cout << "|  \\";
   }
   if (guess[0]=='l' )
   {
     	gotoxy((xc*6)+3,15);
      cout << "| ";
   	gotoxy((xc*6)+3,16);
      cout << "| ";
   	gotoxy((xc*6)+3,17);
      cout << "| ";
      gotoxy((xc*6)+3,18);
      cout << "| ";
      gotoxy((xc*6)+3,19);
      cout << "|____";

   }
   if (guess[0]=='m' )
   {
     	gotoxy((xc*6)+3,15);
      cout << "      ";
   	gotoxy((xc*6)+3,16);
      cout << "|\\ /|";
   	gotoxy((xc*6)+3,17);
      cout << "| V |";
      gotoxy((xc*6)+3,18);
      cout << "|   |";
      gotoxy((xc*6)+3,19);
      cout << "|   |";
   }
   if (guess[0]=='n' )
   {
     	gotoxy((xc*6)+3,15);
      cout << "    ";
   	gotoxy((xc*6)+3,16);
      cout << "|\\  |";
   	gotoxy((xc*6)+3,17);
      cout << "| \\ |";
      gotoxy((xc*6)+3,18);
      cout << "|  \\|";
      gotoxy((xc*6)+3,19);
      cout << "|   | ";

   }
   if (guess[0]=='o' )
   {
     	gotoxy((xc*6)+3,15);
      cout << " ___";
   	gotoxy((xc*6)+3,16);
      cout << "/   \\";
   	gotoxy((xc*6)+3,17);
      cout << "|   |";
      gotoxy((xc*6)+3,18);
      cout << "|   |";
      gotoxy((xc*6)+3,19);
      cout << "\\___/";
   }
   if (guess[0]=='p' )
   {
     	gotoxy((xc*6)+3,15);
      cout << " ___";
   	gotoxy((xc*6)+3,16);
      cout << "|   \\";
   	gotoxy((xc*6)+3,17);
      cout << "|___/";
      gotoxy((xc*6)+3,18);
      cout << "|";
      gotoxy((xc*6)+3,19);
      cout << "|    ";
   }
   if (guess[0]=='q' )
   {
     	gotoxy((xc*6)+3,15);
      cout << " __";
   	gotoxy((xc*6)+3,16);
      cout << "/  \\";
   	gotoxy((xc*6)+3,17);
      cout << "|  |";
      gotoxy((xc*6)+3,18);
      cout << "|  |";
      gotoxy((xc*6)+3,19);
      cout << "\\__\\    ";
   }
   if (guess[0]=='r' )
   {
     	gotoxy((xc*6)+3,15);
      cout << " ___";
   	gotoxy((xc*6)+3,16);
      cout << "|   \\";
   	gotoxy((xc*6)+3,17);
      cout << "|___/";
      gotoxy((xc*6)+3,18);
      cout << "|  \\";
      gotoxy((xc*6)+3,19);
      cout << "|   \\";
   }
   if (guess[0]=='s' )
   {
     	gotoxy((xc*6)+3,15);
      cout << " ___";
   	gotoxy((xc*6)+3,16);
      cout << "/   \\";
   	gotoxy((xc*6)+3,17);
      cout << "\\___";
      gotoxy((xc*6)+3,18);
      cout << "    \\";
      gotoxy((xc*6)+3,19);
      cout << "\\___/";
	}
   if (guess[0]=='t' )
   {
     	gotoxy((xc*6)+3,15);
      cout << "_____";
   	gotoxy((xc*6)+3,16);
      cout << "  |";
   	gotoxy((xc*6)+3,17);
      cout << "  |";
      gotoxy((xc*6)+3,18);
      cout << "  |";
      gotoxy((xc*6)+3,19);
      cout << "  |  ";
   }
   if (guess[0]=='u' )
   {
     	gotoxy((xc*6)+3,15);
      cout << "|   |";
   	gotoxy((xc*6)+3,16);
      cout << "|   |";
   	gotoxy((xc*6)+3,17);
      cout << "|   |";
      gotoxy((xc*6)+3,18);
      cout << "|   |";
      gotoxy((xc*6)+3,19);
      cout << "\\___/";
   }
   if (guess[0]=='v' )
   {
     	gotoxy((xc*6)+3,15);
      cout <<"      ";
   	gotoxy((xc*6)+3,16);
      cout <<"      ";
   	gotoxy((xc*6)+3,17);
      cout <<"\\    /";
      gotoxy((xc*6)+3,18);
      cout <<" \\  /";
      gotoxy((xc*6)+3,19);
   	cout <<"  \\/ ";
   }
   if (guess[0]=='w' )
   {
     	gotoxy((xc*6)+3,18);
      cout <<"\\   /";
   	gotoxy((xc*6)+3,19);
      cout << " \\|/ ";
   }
   if (guess[0]=='x' )
   {
     	gotoxy((xc*6)+3,15);
      cout << "\\   /";
   	gotoxy((xc*6)+3,16);
      cout << " \\ /";
   	gotoxy((xc*6)+3,17);
      cout << "  /";
      gotoxy((xc*6)+3,18);
      cout << " / \\";
      gotoxy((xc*6)+3,19);
      cout << "/   \\";
   }
   if (guess[0]=='y' )
   {
     	gotoxy((xc*6)+3,15);
      cout << "\\   /";
   	gotoxy((xc*6)+3,16);
      cout << " \\ /";
   	gotoxy((xc*6)+3,17);
      cout << "  |";
      gotoxy((xc*6)+3,18);
      cout << "  |";
      gotoxy((xc*6)+3,19);
      cout << "  |  ";
   }
   if (guess[0]=='z' )
   {
     	gotoxy((xc*6)+3,15);
      cout << "_____";
   	gotoxy((xc*6)+3,16);
      cout << "    /";
   	gotoxy((xc*6)+3,17);
      cout << "   / ";
      gotoxy((xc*6)+3,18);
      cout << " /   ";
      gotoxy((xc*6)+3,19);
      cout << "/____";
   }
}
/*****************************************
Draw hangman
******************************************/
void drawman (int part)
{
	if (part==9)
   {
      for (int i = 52 ; i<=58 ; i++)
      {
      	gotoxy(i,22);
         cout<<"_";
      }
   }
	if (part==8)
   {
      for (int i = 4 ; i<=22 ; i++)
      {
      	gotoxy(55,i);
         cout<<"|";
      }
   }
	if (part==7)
   {
   	gotoxy(55,4);
      cout<<"______________";
   }
   if (part==6)
   {
   	gotoxy(68,5);
      cout << "|";
      gotoxy(68,6);
      cout << "|";
   }
	if (part==5)
   {
		gotoxy(60,7);
      cout << "      /   /";
      gotoxy(60,8);
      cout << "   /         /";
      gotoxy(60,9);
      cout << "  /           /";
      gotoxy(60,10);
      cout << "  /           /";
      gotoxy(60,11);
      cout << "   /         /";
      gotoxy(60,12);
      cout << "      /   /";
   }
   if (part==4)
   {
   	for(int k=0;k<7;k++)
      {
      	gotoxy(68,13+k);
         cout << "|";
      }
   }
   if (part==3)
   {
		gotoxy(65,14);
		cout << "\\";
      gotoxy(66,15);
      cout << "\\";
      gotoxy(67,16);
      cout << "\\";
   }
   if (part==2)
   {
   	gotoxy(71,14);
      cout << "/";
      gotoxy(70,15);
      cout << "/";
      gotoxy(69,16);
      cout << "/";
   }
   if (part==1)
   {
   	gotoxy(67,20);
      cout << "/";
      gotoxy(66,21);
      cout << "/";
      gotoxy(65,22);
      cout << "/";
   }
   if (part==0)
   {
   	gotoxy(69,20);
      cout << "\\";
      gotoxy(70,21);
      cout << "\\";
      gotoxy(71,22);
      cout << "\\";
   }
}
/******************************************
Display dashes
*******************************************/
void dash(int n)
{
	gotoxy(3,20);
	for (int x = 1 ; x<=n ; x++)
   	cout<<"_____ ";
}
/*****************************************
Function to check if letter is a vowel
******************************************/
int isvowel(char c)
{
	if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
   	return 1;
   else
   	return 0;
}
/******************************************
Function for the game
*******************************************/
void gamedisplay()
{
	clrscr();
	char word[50];
   int marand=genra();
   string guess="";
   string clue;
   int lives = 10, right = 0;
   strcpy(word,getword(marand));
   strcpy(clue,getword(marand+1));
   dash(strlen(word));
   gotoxy(1,1);
   printf("Try guessing your word %s ! , Good Luck %c :\n",a.retname(),char(1));
   printf("Clue: %s \n",clue);
	time_t start = time(NULL);
   int x = 0;
   while (lives!=0 && right!=strlen(word))
   {
   	gotoxy(1,3);
      clreol();
      char check[100];
      while (true)
      {
      	gotoxy(1,3);
      	clreol();
      	cout<<"Enter your guess:";
      	mygets(guess,1);
      	check[x]=guess[0];
         x++;
         if (search(guess[0],check)>1)
         	cout<<"Entered before !\n";
         else
         	break;
      }
      if (search(guess[0],word) > 0)
      {
      	if (search(guess[0],word) == 1)
         {
         	if (isvowel(guess[0]))
            	cout<<"There is an "<<guess[0]<<"   "<<endl;
            else
            	cout<<"There is a  "<<guess[0]<<"   "<<endl;
         }
         if (search(guess[0],word) > 1)
         	cout<<"There are "<<search(guess[0],word)<<" "<<guess[0]<<" 's\n";
         right+=search(guess[0],word);
			int xc=0 ;
   		search(guess[0],word,xc);
         /*
         If there appears more than one occurence of the letter
         the search will find position of last occurence of the letter.
         Hence find the occurence and simultaneously display it on the screen!
         */
         if (search(guess[0],word) > 1)
         {
         	for (int k = 0 ; word[k] ; k++)
            {
            	if (guess[0]==word[k])
               	xc = k;
   				gotoxy((xc*5)+2,15);
               draw(guess,xc);  //handles more than one occurence of a letter
            }
         }
         draw(guess,xc);  //handles one occurence of a letter
         gotoxy(1,3);
         cout<<"\n\nLetters remaining:"<<(strlen(word)-right);
      }
      else
      {
       	cout<<"Sorry,try again! \n\nLives remaining:"<<--lives<<endl;
         drawman(lives);
      }
   }
   time_t end = time(NULL) - start;
   cout<<endl;
	if (lives == 0)
   {
   	cout<<"Sorry :( game over!\n";
      printf("The word was : %s \n", word);
      a.setlives(0);
   }
   else
   {
   	cout<<"Congratulations  !\n";
   	cout<<"\nTime taken:"<<end<<"s";
      a.setlives(lives);
   }
   a.settime(end);
}
/*********************************************
Write player info into file
*********************************************/
void write()
{
	ofstream fout;
   fout.open("game.txt" , ios::app);
   fout<<"Name:"<<a.retname()<<endl;
   fout<<"Difficulty:"<<a.retdifficulty()<<endl;
   fout<<"Lives left:"<<a.retlives()<<endl;
   fout<<"Time taken:"<<a.rettime()<<" s"<<endl<<endl;
}
/*********************************************
Main function
*********************************************/
void main()
{
 	welcome();
   a.getname();
   randomize();
   displaylvl();
   gamedisplay();
   if (a.retlives()!=0)
   	write();
	getch();
}





