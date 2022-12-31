#include<fstream>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<cstdlib>
#include<time.h>
#include"quiz.h"
#include"conio2.h"
using namespace std;
void Admin::create_admin(string userid,string password,string username)
{
    fstream fobj("Admin.bin",ios::in|ios::binary);
    if(fobj.fail())
    {
        fobj.open("Admin.bin",ios::out|ios::binary);
        Admin adminObj;
        adminObj.setUserDetails(userid,password,username);
        fobj.write((char*)&adminObj,sizeof(Admin));
        //cout<<"file created";
    }
   /* else
        cout<<"file already present";
   */
    fobj.close();
}
void User::setUserDetails(string userid,string pwd,string uname)
{
strcpy(this->userid,userid.c_str());
strcpy(this->pwd,pwd.c_str());
strcpy(this->uname,uname.c_str());
}
int User::input(){
    clrscr();
    gotoxy(1,1);
    textcolor(LIGHTGREEN);
     for(int i=1;i<=120;i++){
        cout<<"*";
     }
    gotoxy(1,3);
    for(int i=1;i<=120;i++){
        cout<<"*";
     }
    gotoxy(87,4);
    textcolor(WHITE);
    cout<<"press 0 to exit/go back";
    gotoxy(45,2);
    textcolor(LIGHTRED);
    cout<<"QUIZ APPLICATION";
    gotoxy(1,8);
    textcolor(YELLOW);
    for(int i=1;i<=120;i++){
        cout<<"*";
    }
    gotoxy(1,17);
     for(int i=1;i<=120;i++){
        cout<<"*";
    }
    gotoxy(60,11);
    cout<<"enter userID:";
    textcolor(WHITE);
    cin.getline(userid,20);
    if(strcmp(userid,"0")==0)
            return 0;
            char ch;
            int i=0;
            textcolor(YELLOW);
            gotoxy(60,12);
            cout<<"Enter password:";
            while(true)
            {
            ch=getch();
            if(ch==13)
            break;
              if(ch==8){
                  if(i==0)
                  continue;
                    cout<<"\b \b";
                i--;
                continue;
            }

            cout<<ch;
            delay(200);
            cout<<"\b*";
            pwd[i]=ch;
        i++;
            }
          pwd[i]='\0';
     if(strcmp(pwd,"0")==0)
        return 0;
    return 1;
}
int User::checkUserExists(string usertype)
{
if(strcmp(userid,"")==0||strcmp(pwd,"")==0)
    {
    gotoxy(45,20);
textcolor(LIGHTRED);
cout<<"both the field are mandatory";
getch();

return 0;
}
ifstream fin;
User *uptr;
if(usertype=="admin"){
    fin.open("Admin.bin",ios::in|ios::binary);
    uptr=new Admin;
}
else if(usertype=="student")
{
    fin.open("Student.bin",ios::in|ios::binary);
    uptr=new Student;
}
else{
        gotoxy(45,20);
textcolor(LIGHTRED);
cout<<"Wrong user type";
getch();
return 0;
}
bool useridfound=0,pwdfound=0;
while(1){
    fin.read((char*)uptr,sizeof(*uptr));
    if(fin.eof())
        break;
    if(strcmp(userid,uptr->userid)==0){
        if(strcmp(pwd,uptr->pwd)==0){
            useridfound=pwdfound=1;
            break;
        }
        useridfound=1;
    }
}
bool result=0;
if(useridfound==0){
    gotoxy(45,20);
    textcolor(LIGHTRED);
    cout<<"no such user exixt";
    getch();

}
else if (pwdfound==0){
    gotoxy(45,20);
       textcolor(LIGHTRED);
    cout<<"invalid password";
    getch();
}
else{
    result=1;
    strcpy(uname,uptr->uname);
}

fin.close();
return result;
}
string User::getName(){
    string USERNAME(uname);
return USERNAME;

}
string User::getUserID(){
string USERID;
USERID=userid;
return USERID;
}
void Admin::addQuestion(){
Question quesObj;
quesObj.add();
clrscr();
}
void Question::add()
{
    fstream fobj("Question.bin",ios::app|ios::binary|ios::in);
    if(!fobj)
    {
        gotoxy(45,18);
        textcolor(LIGHTRED);
        cout<<"Sorry! File cannot be opened!";
        getch();
        return;
    }
    fobj.seekg(0,ios::end);
    if(fobj.tellg()==0)
        quesid=1;
    else
    {
     fobj.seekg(-1*sizeof(*this),ios::end);
     fobj.read((char*)this,sizeof(*this));
     cout<<"Last Question ID is"<<quesid;
     quesid++;
     cout<<endl<<"New Question ID is "<<quesid;
     getch();
    }
    char uchoice;
    do
    {
        clrscr();
        textcolor(WHITE);
        gotoxy(65, 4);
        cout<<"Press 0 to Exit/Go Back";
        textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=0;i<80;i++)
            cout<<"*";
        gotoxy(37,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(LIGHTGREEN);
        gotoxy(1,3);
        for(int i=0;i<80;i++)
            cout<<"*";
        textcolor(WHITE);
        gotoxy(35,5);
        cout<<"***** ADD QUESTION DETAILS *****";
        gotoxy(1,8);
        textcolor(YELLOW);
        string str;
        cout<<"Enter question:";
        cin.ignore();
        textcolor(WHITE);
        getline(cin,str,'?');
      if(strcmp(str.c_str(),"0")==0)
        {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"Closing add question"<<endl;
            getch();
            fobj.close();
            return;
        }
        strncpy(ques,str.c_str(),499);
        textcolor(LIGHTGREEN);
        cout<<endl<<"carries Marks";
        textcolor(YELLOW);
        cin>>tot_marks;
        textcolor(LIGHTGREEN);
        cout<<endl<<"Options"<<endl<<endl;
        textcolor(YELLOW);
        cout<<"(a)";
        cin.ignore();
        textcolor(WHITE);
        getline(cin,str);
        strncpy(op1,str.c_str(),99);
        textcolor(YELLOW);
          cout<<"(b)";
        textcolor(WHITE);
        getline(cin,str);
        strncpy(op2,str.c_str(),99);
        textcolor(YELLOW);
           cout<<"(c)";
        textcolor(WHITE);
        getline(cin,str);
        strncpy(op3,str.c_str(),99);
        textcolor(YELLOW);
           cout<<"(d)";
       textcolor(WHITE);
        getline(cin,str);
        strncpy(op4,str.c_str(),99);
        bool valid ;
        do{
          gotoxy(1,19);
          textcolor(YELLOW);
          cout<<endl<<"enter correct ans(a/b/c/d):   \b";
          textcolor(WHITE);
          cin>>ans;
          if(ans>='a'&&ans<='d')
                valid=true;
                else{
                    gotoxy(24,34);
                    textcolor(LIGHTRED);
                    cout<<endl<<"invalid choice!please try again";
                }
          }while(valid==false);
          fobj.write((char*)this,sizeof(*this));
          quesid++;
          gotoxy(24,22);
          printf("\t\t\t\t\t\t\t");
          gotoxy(34,22);
          textcolor(LIGHTGREEN);
          cout<<"Qustion added succesfully";
          getch();
          gotoxy(1,24);
          textcolor(LIGHTMAGENTA);
          cout<<endl<<"Do you want to add more question";
          textcolor(WHITE);
          cin>>uchoice;

    }while(uchoice=='y'||uchoice=='Y');
    fobj.close();
}
void Admin::viewQuestion(){
Question quesObj;
quesObj.viewQuestion();
clrscr();

}
void Question::viewQuestion(){
    ifstream fin("Question.bin",ios::in|ios::binary);
    if(!fin){
        gotoxy(1,10);
        textcolor(LIGHTRED);
        cout<<"No question have been added yet!";
        getch();
        return ;

    }

    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {

        gotoxy(1,10);
        textcolor(LIGHTRED);
        cout<<"No question present in the file";
        getch();
        return ;
    }
    clrscr();
    fin.seekg(0);
    while(1){
      textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=0;i<80;i++)
            cout<<"*";
        gotoxy(37,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(LIGHTGREEN);
        gotoxy(1,3);
        for(int i=0;i<80;i++)
            cout<<"*";
        textcolor(WHITE);
        gotoxy(35,5);
        cout<<"***** Show QUESTION DETAILS *****";
         gotoxy(1,7);
         textcolor(LIGHTGREEN);
         for(int i=1;i<=80;i++){
            cout<<"*";
         }
            fin.read((char*)this,sizeof(*this));
            if(fin.eof())
            {
                cout<<endl;
                textcolor(LIGHTRED);
                gotoxy(35,10);
                cout<<"No More Question Present";
                getch();
                break;
            }
            else{
                show();
                getch();
                clrscr();
            }

         fin.close();
    }

}
void Question::show(){
cout<<endl;
cout<<"Q."<<quesid<< " ";
cout<<ques<<endl;
cout<<"Carries Marks:"<<tot_marks<<endl;
cout<<"a. "<<op1<<endl;
cout<<"b. "<<op2<<endl;
cout<<"c. "<<op3<<endl;
cout<<"d. "<<op4<<endl;
textcolor(LIGHTGREEN);
cout<<endl<<"Correct Option:"<<ans;

}
void Admin::removeQuestion()
{

    Question quesObj;
    quesObj.Remove();
    clrscr();

}
void Question::Remove(){
clrscr();
textcolor(WHITE);
gotoxy(58,4);
cout<<"Press 0 to exit/Go back";

   textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=0;i<80;i++)
            cout<<"*";
        gotoxy(37,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(LIGHTGREEN);
        gotoxy(1,3);
        for(int i=0;i<80;i++)
            cout<<"*";
        textcolor(WHITE);
        gotoxy(35,5);
        cout<<"***** Remove QUESTION DETAILS *****";
        getch();

        ifstream fin("Question.bin",ios::in|ios::binary);
        if(!fin)
        {
            gotoxy(35,10);
            textcolor(LIGHTRED);
            cout<<"Sorry!File cannot be opened";
            getch();
            return ;
        }
        fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {

        gotoxy(35,10);
        textcolor(LIGHTRED);
        cout<<"No question available for deletion ";
        getch();
        fin.close();
        return ;
    }
        getch();
        gotoxy(1,8);
        textcolor(YELLOW);
        cout<<"enter Question ID";
        bool found=false,valid;
        int id;
        ofstream fout("temp.bin",ios::out|ios::binary);
        if(!fout)
        {

            gotoxy(35,10);
            textcolor(LIGHTRED);
            cout<<"Sorry !Removal not possible";
            getch();
            fin.close();
            return ;

        }
        fin.seekg(0);
        do{
           cin>>id;
           if(id==0){
            fin.close();
            fout.close();
            remove("temp.bin");
            return ;
           }
           if(id<0){
            valid=false;
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"\t\t\t\t\t\t\t\t\t\t\rInvalid Question ID";
            getch();
            gotoxy(19,8);
            cout<<"\t\t\t\t\t\t";
            gotoxy(19,8);
            textcolor(WHITE);

           }
           else{
            while(true){
             fin.read((char*)this,sizeof(*this));
             if(fin.eof())
                    break;
             if(this->quesid==id){
                found=true;
                continue;
             }
             else{
                fout.write((char*)this,sizeof(*this));
             }

            }
            fout.close();
            fin.close();

            if(found){
            textcolor(WHITE);
            gotoxy(1,24);
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\rQuestion Remove";
            getch();
            remove("Question.bin");
            rename("temp.bin","Question.bin");
           }
           else{
            textcolor(LIGHTRED);
            gotoxy(1,24);
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\rQuestion ID not found";
            getch();
              remove("temp.bin");
            getch();
           }
           }
        }while(valid==false);
}
void Admin::addStudent()
{
Student studobj;
studobj.add();
clrscr();
}
void Student::add()
{
 char uchoice;
 int id;
 char stuid[10];
 string str;
 fstream fobj("Student.bin",ios::app|ios::in|ios::binary);
fobj.seekg(0,ios::end);
if(fobj.tellg()==0)
id=1;
else
{
  fobj.seekg(-1*sizeof(*this),ios::end);
fobj.read((char*)this,sizeof(*this));
char *pos=strchr(userid,'-');
if(pos!=NULL)
{
 id=atoi(pos+1);
 id++;
}
}
cout<<"next id is :"<<id;
getch();
fobj.seekg(0,ios::end);
do
{

    clrscr();
    textcolor(WHITE);
    gotoxy(58,4);
    cout<<"press 0 to Exit/Go back";
    gotoxy(37,2);
    textcolor(LIGHTRED);
    cout<<"QUIZ APP";
    textcolor(LIGHTGREEN);
    gotoxy(1,1);
    for(int i=1;i<=80;i++)
      cout<<"~";
     gotoxy(1,3);
    for(int i=1;i<=80;i++)
      cout<<"~";
      textcolor(WHITE);
      gotoxy(25,5);
    cout<<"********ADD STUDENT DETAILS******";
    gotoxy(1,8);
    textcolor(YELLOW);
cout<<"ENTER Student Name:";
cin.ignore();
textcolor(WHITE);
getline(cin,str);
strncpy(uname,str.c_str(),19);
if(strcmp(uname,"0")==0){
    gotoxy(1,24);
    textcolor(LIGHTRED);
    cout<<"CAncelling ADD sTuDEnt.."<<endl;
    getch();
    fobj.close();
    return ;
}
  textcolor(YELLOW);
cout<<"ENTER Student Password:";
textcolor(WHITE);
getline(cin,str);
strncpy(pwd,str.c_str(),19);
if(strcmp(pwd,"0")==0){
    gotoxy(1,24);
    textcolor(LIGHTRED);
    cout<<"CAncelling ADD sTuDEnt.."<<endl;
    getch();
    fobj.close();
    return ;
}
sprintf(stuid,"STU=%d",id);
strcpy(userid,stuid);
fobj.write((char*)this,sizeof(*this));
gotoxy(30,15);
textcolor(LIGHTGREEN);
cout<<"STUDENT ADDED SUCCESSFULLY";
cout<<endl<<"STUDENT ID IS :"<<userid;
getch();
gotoxy(1,20);
textcolor(MAGENTA);
cout<<"DO you want to add more student (Y/N)?";
cin>>uchoice;
id++;

}while(uchoice=='Y'||uchoice=='y');
fobj.close();
}
void Admin::viewStudent(){
Student studObj;
studObj.showStudentDetails();
clrscr();
}
void Student::showStudentDetails(){
    clrscr();
    ifstream fin("Student.bin",ios::in|ios::binary);
    if(!fin){
        gotoxy(1,10);
        textcolor(LIGHTRED);
        cout<<"No Student have been added yet!";
        getch();
        return ;

    }

    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {

        gotoxy(1,10);
        textcolor(LIGHTRED);
        cout<<"No student present in the file";
        getch();
        return ;
    }
    clrscr();
    fin.seekg(0);
    while(1){
      textcolor(LIGHTGREEN);
        gotoxy(1,1);
        for(int i=0;i<80;i++)
            cout<<"*";
        gotoxy(37,2);
        textcolor(LIGHTRED);
        cout<<"QUIZ APP";
        textcolor(LIGHTGREEN);
        gotoxy(1,3);
        for(int i=0;i<80;i++)
            cout<<"*";
        textcolor(WHITE);
        gotoxy(35,5);
        cout<<"***** Show STUDENT DETAILS *****";
         gotoxy(1,7);
         textcolor(LIGHTGREEN);
         for(int i=1;i<=80;i++){
            cout<<"*";
         }
            fin.read((char*)this,sizeof(*this));
            if(fin.eof())
            {
                cout<<endl;
                textcolor(LIGHTRED);
                gotoxy(35,10);
                cout<<"No More Student Present";
                getch();
                break;
            }
            else{
                show();
                getch();
                clrscr();
            }

         fin.close();
    }

}
void User::show(){
cout<<endl;
textcolor(YELLOW);
cout<<"User ID:";
textcolor(LIGHTGREEN);
cout<<userid<<endl;

textcolor(YELLOW);
cout<<"User Name:";
textcolor(LIGHTGREEN);
cout<<uname<<endl;

textcolor(YELLOW);
cout<<"PassWord:";
textcolor(LIGHTGREEN);
cout<<pwd<<endl;

}
void Student::quiz()
{
    Question quesObj;
    quesObj.startQuiz(userid);
}
void Question::startQuiz(string id)
{
    ifstream fin("question.bin",ios::in|ios::binary);
    if(fin.fail())
    {

        gotoxy(28,20);
        textcolor(LIGHTRED);
        cout<<"No Question Have Been ADded yet!";
        getch();
        return ;
    }
    vector<Question>vecQues;
    while(1)
    {

        fin.read((char*)this,sizeof(*this));
        if(fin.eof())
            break;
        vecQues.push_back(*this);
    }
    fin.close();
    vector<int>vecRand;
    srand((unsigned int) time(NULL));
    int randno;
    while(1)
    {
     randno=rand()%vecQues.size();
if(ispresent(vecRand,randno)==true)
    continue;
vecRand.push_back(randno);
if(vecRand.size()==vecQues.size())
    break;
    }
int count=0;
User userObj;
   int local_marks=0;
    int local_tot_marks=0;
string name=userObj.getName(id);
for(int i=0;i<vecQues.size();i++)
{

    int index=vecRand.at(i);
    *this=vecQues.at(index);
    clrscr();
    gotoxy(37,2);
    textcolor(LIGHTRED);
    cout<<"QUIZ  APP";
    textcolor(YELLOW);
    gotoxy(1,4);
    for(int j=1;j<=80;j++)
        cout<<"*";
    textcolor(WHITE);
    gotoxy(50,5);
    cout<<name;
    gotoxy(10,5);
    cout<<"Total question:"<<vecQues.size()<<endl;
    gotoxy(1,6);
    textcolor(YELLOW);
    for(int j=1;j<=80;j++)
        cout<<"*";
    textcolor(GREEN);
    gotoxy(1,8);
    count++;
    cout<<count<<")";
    gotoxy(4,8);
    cout<<this->ques<<endl<<endl;
    textcolor(LIGHTGRAY);
    cout<<"a."<<this->op1<<endl<<endl;
     cout<<"b."<<this->op2<<endl<<endl;
      cout<<"c."<<this->op3<<endl<<endl;
       cout<<"d."<<this->op4<<endl<<endl;
    bool valid;
    char uans;

    do{
        textcolor(YELLOW);
        cout<<"Enter your option(a/b/c/d):  \b";
        cin>>uans;
        if(uans>='a'&&uans<='d')
            valid=true;
        else{
            valid=false;
            gotoxy(24,22);
            textcolor(LIGHTRED);
            cout<<"Invalid option entered ,Try again";
            getch();
            gotoxy(24,22);
            cout<<"\t\t\t\t\t\t\t";
            gotoxy(1,18);

        }

    }while(valid==false);
    local_tot_marks+=this->tot_marks;
    if(uans==this->ans)
        local_marks+=this->tot_marks;

}
clrscr();
gotoxy(37,2);
textcolor(LIGHTGREEN);
cout<<"QUIZ APP";
textcolor(YELLOW);
gotoxy(1,4);
for(int i=1;i<=80;i++)
    cout<<"*";
gotoxy(32,10);
textcolor(LIGHTRED);
cout<<"**TEST FINISHED **";
gotoxy(22,12);
cout<<"Press any key to go back to main menu";
getch();
StudentPerformance sp;
sp.setMarksDetails(id,local_marks,local_tot_marks);
}
bool ispresent(vector<int>& v,int value){
for(int i=0;i<v.size();i++){
    if(v.at(i)==value)
        return true;
}
return false;
}
void StudentPerformance::setMarksDetails(string id,int marks,int tot_marks)
{

    strcpy(studid,id.c_str());
    this->marks=marks;
    this->tot_marks=tot_marks;
    saveMarksDetails();

}
void StudentPerformance::saveMarksDetails(){
ofstream fout("Performance.bin",ios::app|ios::binary);
if(!fout)
{
    gotoxy(1,16);
    textcolor(LIGHTRED);
    cout<<"error in creating/opening file";
    getch();
    return ;
}
fout.write((char*)this,sizeof(*this));
fout.close();

}
string User::getName(string id){
    ifstream fin("Student.bin",ios::in|ios::binary);
    while(1){
        fin.read((char*)this,sizeof(User));
        if(fin.eof()){
            cout<<"No match of record found";
            break;
        }
        int result=strcmp(this->getUserID().c_str(),id.c_str());
        if(result==0){
          fin.close();
          return this->uname;
        }
    }
    fin.close();
    return NULL;
}
