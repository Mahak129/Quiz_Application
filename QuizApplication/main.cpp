#include <iostream>
#include"conio2.h"
#include"quiz.h"

using namespace std;

int main()
{
    int type,c,choice;
   textcolor(LIGHTGREEN);
   for(int i=1;i<=120;i++){
        cout<<"*";

   }
   textcolor(LIGHTRED);
   gotoxy(50,2);
   cout<<"QUIZ APPLICATION";
   gotoxy(1,3);
   textcolor(LIGHTGREEN);
   for(int i=1;i<=120;i++){
     cout<<"*";
    textcolor(YELLOW);
   }

    gotoxy(40,10);
    cout<<"WELCOME TO TECH TEST-QUIZ APPLICATION";
    textcolor(LIGHTGREEN);
    gotoxy(40,14);
    cout<<"TEST YOUR SKILL! IMPROVE YOUR KNOWLEDGE";
    textcolor(WHITE);
    gotoxy(1,20);
    cout<<"press any key to continue"<<endl;
    getch();
    Admin::create_admin("uadmin","abc","Mahak");
  do{
   clrscr();

   textcolor(LIGHTGREEN);
   for(int i=1;i<=120;i++)
   cout<<"*";
   textcolor(LIGHTRED);
   gotoxy(45,2);
   cout<<"QUIZ APPLICATION";
   gotoxy(1,3);
   textcolor(LIGHTGREEN);
   for(int i=1;i<=120;i++){
     cout<<"*";
   }
     gotoxy(97,4);
     textcolor(WHITE);
     cout<<"press 0 to exit/go back";
     gotoxy(1,8);
     textcolor(YELLOW);
     for(int i=1;i<=120;i++){
        cout<<"*";
     }
     gotoxy(1,18);
     for(int i=1;i<=120;i++){
        cout<<"*";
     }
     gotoxy(50,12);
     cout<<"1.ADMIN: ";
     gotoxy(50,14);
     cout<<"2.STUDENT: ";
     gotoxy(50,16);
     textcolor(WHITE);
     cout<<"3.select your role: ";
     cin>>type;
     if(type==0)
      break;
     cin.ignore();

     if(type==1){
        Admin adminObj;
        do{
            c=adminObj.input();
        if(c==0){
            gotoxy(62,14);
            textcolor(LIGHTRED);
            cout<<"login Cancelled";
            gotoxy(1,20);
            textcolor(WHITE);
            cout<<"press any key to continue";
            getch();
            break;
        }
        //check userExist();
        c=adminObj.checkUserExists("admin");
        if(c==1){
                gotoxy(45,18);
        textcolor(LIGHTGREEN);
        cout<<"login Accepted";
        gotoxy(45,20);
        cout<<"welcome "<<adminObj.getName();
        gotoxy(45,22);
        textcolor(WHITE);
        cout<<"press any key to continue";
        getch();
        while(1){
            clrscr();
            gotoxy(1,1);
            textcolor(LIGHTGREEN);
            for(int i=1;i<120;i++)
                cout<<"*";
            gotoxy(1,3);
            for(int i=1;i<=120;i++)
                cout<<"*";
                textcolor(LIGHTRED);
            gotoxy(48,2);
            cout<<"QUIZ APPICATION";
            textcolor(LIGHTGREEN);
            gotoxy(48,6);
            cout<<"Admin Menu"<<endl;
            textcolor(YELLOW);
            for(int i=1;i<=120;i++)
                cout<<"*";
            gotoxy(45,8);
            cout<<"1. Add Quuestion :";
            gotoxy(45,9);
            cout<<"2.Add Student :";
            gotoxy(45,10);
            cout<<"3.show Question :";
            gotoxy(45,11);
            cout<<"4.Show Students :";
            gotoxy(45,12);
            cout<<"5.Remove Question :";
            gotoxy(45,13);
            cout<<"6.Remove Student :";
            gotoxy(45,14);
            cout<<"7.Exit";
            gotoxy(45,16);
            cout<<"enter your choice :";
            textcolor(WHITE);
            cin>>choice;
            switch(choice)
            {
            case 1:
                clrscr();
                adminObj.addQuestion();
                break;
            case 2:
                clrscr();
                adminObj.addStudent();
                break;
            case 3:
                clrscr();
                adminObj.viewQuestion();
                break;
            case 4:
                clrscr();
                adminObj.viewStudent();
                break;
            case 5:
                clrscr();
                adminObj.removeQuestion();
                break;
            case 6:
                clrscr();
              //  adminObj.removeStudent();
                break;
            case 7:
                clrscr();

                break;
            default:
            textcolor(LIGHTRED);
            gotoxy(45,18);
            cout<<"wrong Choice,Try Again";
            }
            if(choice==7)
                break;
                getch();


        }

             getch();
        }

        }while(c==0);
     }
     else if(type==2){
        //student
                Student studObj;
        do{
            c=studObj.input();
        if(c==0){
            gotoxy(62,14);
            textcolor(LIGHTRED);
            cout<<"login Cancelled";
            gotoxy(1,20);
            textcolor(WHITE);
            cout<<"press any key to continue";
            getch();
            break;
        }
        //check userExist();
        c=studObj.checkUserExists("student");
    if(c==1)
    {
        gotoxy(45,18);
        textcolor(LIGHTGREEN);
        cout<<"login Accepted";
        gotoxy(45,20);
        cout<<"welcome "<<studObj.getName();
        gotoxy(45,22);
        textcolor(WHITE);
        cout<<"press any key to continue";
        getch();
        while(1){
        clrscr();
        gotoxy(1,1);
            textcolor(LIGHTGREEN);
            for(int i=1;i<120;i++)
                cout<<"*";
            gotoxy(1,3);
            for(int i=1;i<=120;i++)
                cout<<"*";
                textcolor(LIGHTRED);
            gotoxy(48,2);
            cout<<"QUIZ APPICATION";
            textcolor(LIGHTGREEN);
            gotoxy(48,6);
            cout<<"Student Menu"<<endl;
            textcolor(YELLOW);
            for(int i=1;i<=120;i++)
                cout<<"*";
            gotoxy(32,9);
            cout<<"1.Start Quiz";
            gotoxy(32,10);
            cout<<"2.View Performancet";
            gotoxy(32,11);
            cout<<"3.Exit";
            gotoxy(32,13);
            cout<<"enter your choice";
            textcolor(WHITE);
            cin>>choice;
            switch(choice)
            {
            case 1:
                clrscr();
                 studObj.quiz();
                break;
            case 2:
                clrscr();
               //studObj.viewPerformance();
                break;
            case 3:
                clrscr();
                break;
                default:
            textcolor(LIGHTRED);
            gotoxy(45,18);
            cout<<"wrong Choice,Try Again";
            }
            if(choice==3)
                break;
                getch();


        }

             getch();
        }

        }while(c==0);
     }
     else{
        gotoxy(48,16);
        textcolor(LIGHTRED);
        cout<<"\t\t\t\t\t\t\t\t\t";
        gotoxy(48,16);
        textcolor(LIGHTRED);
        cout<<"invalid user type";
        getch();
        textcolor(WHITE);
        clrscr();
     }

  }while(1);

    return 0;
}
