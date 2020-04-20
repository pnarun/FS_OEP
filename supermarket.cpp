#include<iostream>                //header files
#include<stdlib.h>
#include<math.h>
#include<string>
#include<fstream>
#include<windows.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<time.h>
using namespace std;

void load();

int id[20][20];
long int total=0;
void cardpay()
{
    system("cls");
    int rnum,ernum;
    char cardno[20];
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tEnter your 16 digit card number:";
    cin>>cardno;
    int c=0;
    do
    {
        if(c!=0)
            cout<<"Invalid OTP."<<endl;
        srand(time(NULL));
        cout<<"\n\n\n\n\t\t\t\t\t\t\t\tNOTE:Enter OTP (ONE TIME PASSWORD) sent to your registered mobile number.(ASSUME and enter the same on screen)"<<endl;
        rnum=rand();
        cout<<"\t\t\t\t\t\t\t\tYour OTP is "<<rnum<<endl;
        cout<<"\t\t\t\t\t\t\t\t(Don't share the OTP with others.)"<<endl;
        cout<<"\t\t\t\t\t\t\t\tEnter OTP:";
        cin>>ernum;
        c++;
    }while(rnum!=ernum);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPAYMENT SUCCESSFULL"<<endl;
    delay(5000);
}
void cashpay()
{
    system("cls");
    system("COLOR 80");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tCash received...Happy shopping!"<<endl;

    delay(5000);
}
void fetchdata()
{
    char ch=254;
    system("cls");
    delay(500);
    //system("COLOR 10");
    delay(500);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t                  FETCHING YOUR DATA....."<<endl;
    for(int i=0;i<67500;i++);
    cout<<"                                                                                       ";
    for(int i=0;i<30;i++)
    {
        Sleep(200);
        system("COLOR FC");
        cout<<ch;
    }
    system("cls");
    //system("COLOR 5");
    system("cls");
}
class welcome                   //base class welcome definition
{
    protected:char user_id[20];           //user_id
              char password[20];          //password
              char ch;
              int i=0;
    public:void read()          //member function to read user_id and password
           {
                system("COLOR F0");
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t\t\t\tEnter user ID                :       ";
                cin>>user_id;
                cin.ignore();
                cout<<endl<<endl<<endl<<"\t\t\t\t\t\t\t\tInstruction:-"<<endl;
                cout<<"\t\t\t\t\t\t\t\t1.password must be of 10 characters."<<endl;
                cout<<"\t\t\t\t\t\t\t\t2.password should not contains any spaces."<<endl;
                cout<<"\t\t\t\t\t\t\t\t3.password should contain characters, digits and one special characters."<<endl;
                cout<<"\t\t\t\t\t\t\t\tPassword                     :       ";
                cin>>password;
           }
};
class purchase:public welcome
{
    protected:int idindex;
              int id[10][10];
    public: friend void addtohistory(purchase &pu);
            friend void displaypurchase(purchase &pu);
            friend void viewhistory(purchase &pu);

           void readpurchase()
           {
               purchase p;
               //system("COLOR 40");
                    char filehistory[30];
                    char idchoice;
                    p.idindex=0;
                    int cost=0;
                    do
                    {
                        cout<<endl<<endl<<endl<<endl;
                        cout<<"\t\t\t\t\t\tEnter item-id:";
                        cin>>p.id[p.idindex][0];
                        cout<<"\t\t\t\t\t\tQuantity:";
                        cin>>p.id[p.idindex][1];
                        cin.ignore();
                        p.idindex++;
                        cout<<endl<<endl<<"\t\t\t\t\t\tMore items to enter?(y/n)";
                        cin>>idchoice;
                    }while(idchoice=='y'||idchoice=='Y');
                    system("cls");
                    system("COLOR 03");
                    system("cls");
                    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter password   :\t";
                    cin>>p.password;
                    system("cls");
                    strcpy(filehistory,p.password);
                    addtohistory(p);
                    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\tINVOICE:"<<endl;
                    displaypurchase(p);
                    cout<<"\t\t\t\t\t\t\t__________________________________________________________________________________"<<endl;
                    cout<<"\t\t\t\t\t\t\t|TOTAL                                                              :"<<left<<setw(12)<<total<<"|"<<endl;
                    cout<<"\t\t\t\t\t\t\t|G.S.T. (GOODS AND SERVICE TAXES)                                   :10%         |"<<endl;
                    cout<<"\t\t\t\t\t\t\t|GRAND TOTAL                                                        :"<<left<<setw(12)<<total+(total*10/100)<<"|"<<endl;
                    cout<<"\t\t\t\t\t\t\t|________________________________________________________________________________|"<<endl;
                    cout<<endl<<endl<<endl<<"\t\t\t\t\t\t\t\tDO YOU WANT TO PROCEED WITH PAYMENT...(y/n):";
                    char yp;
                    cin>>yp;
                    int pmod;
                    if(yp=='y'||yp=='Y')
                    {
                        system("cls");
                        system("COLOR F0");
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1.CARD PAYMENYT\t\t\t\t\t\t\t\t\t2.CASH ON DELIVERY"<<endl<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter your choice for payment:";
                        cin>>pmod;
                        switch(pmod)
                        {
                            case 1 :cardpay();
                                    break;
                            case 2 :cashpay();
                                    break;
                        }
                    }
                    else
                    {
                        cout<<"\t\t\t\t\t\t\t\tThank you for using our application."<<endl;
                        exit(0);
                    }
                    system("cls");
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  Do you want to view your billing history...(y/n):";
                    char phistory;
                    cin>>phistory;
                    system("cls");
                    if(phistory=='y'||phistory=='Y')
                    {
                        cout<<endl<<endl<<"\t\t\t\t\t\t\t\tBILLING HISTORY:"<<endl;
                        viewhistory(p);
                    }
                    delay(15000);
           }
};
class items                                     //class to feed data for shopping portal
{
    public:   char itemname[25];
              float itemid;
              float itemprice;
              float itemrating;
              void display()
           {
                fstream fp;
                fp.open("itemfeed.dat");
                items it;
                fp.read((char*)&it,sizeof(it));
                while(!fp.eof())
                {
                    cout<<"\t\t\t\t\t\t\t\t|"<<left<<setw(5)<<it.itemid<<"|"<<left<<setw(20)<<it.itemname<<"|"<<setw(13)<<it.itemprice<<"|"<<left<<setw(17)<<it.itemrating<<"|"<<endl;
                    cout<<"\t\t\t\t\t\t\t\t|_____|____________________|_____________|_________________|"<<endl;
                    fp.read((char*)&it,sizeof(it));
                }
                fp.close();
           }
           friend void displaypurchase(purchase &pu);

};

class registeruser:public welcome               //derived class register user definition
{
    protected:char name[30],contno[20],mailid[30];       //data members
            char address[50];
    public:void readuser()                      //member function to read the details of the user
           {
               fstream file1;
               file1.open("userdata.dat",ios::app);
               file1.close();
               registeruser r;
               system("COLOR F1");
               cout<<"\t\t\t\t\t\t\t\t\t\t*****USER DETAILS*****"<<endl<<endl<<endl;
                cout<<"\t\t\tNAME                         :       ";
                cin>>name;
                cout<<"\t\t\tMOBILE NUMBER                :       ";
                do
                {
                    cout<<"+91 ";
                    cin>>contno;
                    if(strlen(contno)!=10||contno[0]==0)                        //checking the validity of the phone number
                    {
                        cout<<"\t\t\tInvalid contact number"<<endl;
                        cout<<"\t\t\tRe-enter                     :      ";
                    }
                    else
                        break;
                }while(1);
                cout<<"\t\t\tADDRESS                      :       ";
                cin>>address;
                cout<<"\t\t\tE-MAIL ID                    :       ";
                int c=0;
                int k,l,i;
                do
                {
                    if(c!=0)
                    {
                        cout<<"\t\t\tInvalid e-mail id. Please enter valid e-mail id"<<endl;
                        cout<<"\t\t\tE-MAIL ID                    :       ";
                    }
                    cin>>mailid;
                    c=1;
                    k=bruteforce(mailid,"@gmail.com");      //checking validity for gmail.com
                    l=bruteforce(mailid,"@yahoo.com");      //checking validity for yahoo.com
                    i=bruteforce(mailid,"@sit.ac.in");      //checking validity for sit.ac.in
                }while(k&&l&&i);
                read();
                ifstream file;
                file.open("userdata.dat",ios::in);
                file.read((char *)&r,sizeof(r));
                int check_existance=0;
                if(!file.eof())
                {
                    file.close();
                    do
                    {
                        if(check_existance==1)
                            read();
                        check_existance=1;
                        int k=checkuser_id();
                        cout<<"k="<<k;      //calling checkuser_id() to check the existance of the user_id
                        if(k==1)
                        cout<<"\t\t\tUser ID is already exist."<<endl<<"Please enter another User ID."<<endl;
                        int l=checkpassword();
                        cout<<"l="<<l;     //calling checkpassword() to check the existence of the password
                        if(l==1)
                        cout<<"\t\t\tPassword is already exist."<<endl<<"Please enter another password."<<endl;
                    }while(!(k||l));
                }
                file.close();


           }
           int checkpassword()                       //member function to check the existence of the password
           {
               registeruser r1;                      //creating object
               ifstream f;
               f.open("userdata.dat");               //opening the file
               int found=0;
               f.read((char *)&r1,sizeof(r1));       //reading the data
               while(!f.eof())
               {
                    if(strcmp(password,r1.password)==0)    //comparing the user entered password with the passwords present in the file
                    {
                        found=1;
                        break;
                    }
                    f.read((char *)&r1,sizeof(r1));        //reading the data
               }
               f.close();           //closing the file
               return(found);
           }
           int checkuser_id()         //member function to check the existance of the user_id
           {
               registeruser r2;
               int flag=0;                      //creating object
               ifstream f;
               f.open("userdata.dat");          //opening the file
               int found=0;
               f.read((char *)&r2,sizeof(r2));       //reading the data
               while(!f.eof())
               {
                    flag++;
                    if(strcmp(user_id,r2.user_id)==0)    //comparing the user entered user_id with the user_id present in the file
                    {
                        found=1;
                        break;
                    }
                    f.read((char *)&r2,sizeof(r2));       //reading the data
               }
               if(flag==0)

               f.close();           //closing the file
               return(found);
           }
           int bruteforce(char t[],char p[])        //member function to checking validity for mail id
           {
                int n=strlen(t);                    //finding the length of the user entered mail id
                int m=strlen(p);                    //finding the length of the check pattern [@gmail.com or @yahoo.com or @sit.ac.in]
                int j;
                for(int i=0;i<=n;i++)
                {
                    j=0;
                    while((j<m)&&(p[j]==t[i+j]))      //checking for string match
                        j++;
                    if((j==m)&&(i==n-m))
                        return(0);                      //if match occurs return 0
                }
                return(1);                              //if match does not occurs return 1
            }
};
class login:public registeruser          //derived class login definition
{
    protected:                      //data member
    public:int searchdata()         //member function to search the user from the file
           {
               int found;
               read();              //calling the read function
               fetchdata();
               //cout<<"Userid="<<user_id<<endl<<"Password:"<<password;
               //delay(5000);
               login l;         //creating the object
               ifstream f;
               f.open("userdata.dat",ios::in);      //opening the file
               found=0;
               f.read((char *)&l,sizeof(l));        //reading the data
               while(!f.eof())
               {
                    if((strcmp(password,l.password)==0)&&(strcmp(user_id,l.user_id)==0))           //comparing the user entered password with the password in the file
                    {
                        system("cls");
                        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tWelcome "<<l.name<<" ."<<endl;
                        delay(8000);
                        found++;
                        f.close();
                        return(1);              //if exist return 1
                    }
                     f.read((char *)&l,sizeof(l));        //reading the txta
               }
               if(found==0)
               {
                   f.close();                      //closing the file
                   return (-1);                //if not exist return -1
               }
           }
};
void load()
{
    char ch=219;
    system("cls");
    //delay(500);
    //system("COLOR 10");
    delay(1000);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t  CREATING YOUR ACCOUNT....."<<endl;
    for(int i=0;i<67500;i++);
    cout<<"                                                                          \t";
    for(int i=0;i<30;i++)
    {
        Sleep(200);
        system("COLOR 0B");
        cout<<ch;
    }
    system("cls");
    cout<<endl<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t  YOUR ACCOUNT HAS BEEN SUCESSFULLY CREATED...\n";
    delay(3000);
    system("cls");
}
void loginload()
{
    char ch=219;
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t   LOGGING YOU IN....."<<endl;
    for(int i=0;i<67500;i++);
    cout<<"                                                                               \t\t";
    for(int i=0;i<27;i++)
    {
        Sleep(200);
        system("COLOR 03");
        cout<<ch;
    }
    system("cls");
    cout<<endl<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   YOU HAVE SUCCESSFULLY LOGGED IN TO YOUR ACCOUNT....."<<endl;
    delay(3000);
    system("cls");
}
void displaypurchase(purchase &pu)
{
    fstream fp;
    items it;
    cout<<"\t\t\t\t\t\t\t__________________________________________________________________________________"<<endl;
    cout<<"\t\t\t\t\t\t\t| ID  |        NAME        |PRICE(in Rs.)|RATTING(out of 5)|Quantity|cost(in Rs.)|"<<endl;
    cout<<"\t\t\t\t\t\t\t|_____|____________________|_____________|_________________|________|____________|"<<endl;
    for(int i=0;i<(pu.idindex+1);i++)
    {
         fp.open("itemfeed.dat");
         fp.read((char*)&it,sizeof(it));
         while(!fp.eof())
         {
             if(it.itemid==pu.id[i][0])
            {
                int cost;
                cost=it.itemprice*pu.id[i][1];
                cout<<"\t\t\t\t\t\t\t|"<<left<<setw(5)<<it.itemid<<"|"<<left<<setw(20)<<it.itemname<<"|"<<setw(13)<<it.itemprice<<"|"<<left<<setw(17)<<it.itemrating<<"|"<<left<<setw(8)<<pu.id[i][1]<<"|"<<setw(12)<<cost<<"|"<<endl;;
                cout<<"\t\t\t\t\t\t\t|_____|____________________|_____________|_________________|________|____________|"<<endl;
                total=total+cost;
                //cout<<"Total ===="<<total<<endl;
                break;
            }
                fp.read((char*)&it,sizeof(it));
         }
         fp.close();
    }
}
void addtohistory(purchase &pu)
{
    char fileopen[30];
    strcpy(fileopen,pu.password);
    strcat(fileopen,".dat");
    ofstream fp;
    fp.open(fileopen,ios::app);
    fp.write((char *)&pu,sizeof(pu));
    fp.close();
}
void viewhistory(purchase &pu)
{
    int count=0;
    char file[30];
    strcpy(file,pu.password);
    strcat(file,".dat");
    purchase phist;
    ifstream fp1;
    fp1.open(file,ios::in);
    if(fp1.eof())
        cout<<"File not opened..";
    fp1.read((char *)&phist,sizeof(phist));
    while(!fp1.eof())
    {
       count++;
       displaypurchase(phist);
       fp1.read((char *)&phist,sizeof(phist));
    }
    fp1.close();
    if(count==0)
       cout<<"No purchase yet..";

}
int main()                                               //main function
{
   int ch;                                               //variable to read the user choice
   system("COLOR FC");
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t                                                                          ";
   char a[]={'*','*','*','*','*','*','S','U','P','E','R','M','A','R','K','E','T','*','*','*','*','*','*'};
    for(int i=0;i<22;i++)
    {
        delay(500);
        cout<<a[i];
    }
    delay(2000);
    system("COLOR F0");
    system("cls");
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t  1.NEW-EMPLOYEE\t\t\t\t\t\t\t\t\t2.LOGIN"<<endl<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t  Enter your choice:";
   cin>>ch;
   system("cls");
   switch(ch)                                               //switch block
   {
       case 2:do                                            //case for existing user
              {
                 login l;                                   //creating the object
                 int dataexist;
                 dataexist=l.searchdata();                                    //calling searchdata()
                 if(dataexist==-1)                              //if entered data is invalid loop
                 {
                     system("cls");
                     cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t\t\t\t\t\t\tInvalid USERID or PASSWORD"<<endl;
                     cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter valid details:"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                 }
                 else
                    break;                                   //if entered is valid come out of the loop
              }while(1);
              loginload();
              break;

       default:cout<<"\t\t\t\t\t\t\t\t\t\t\tInvalid Choice"<<endl;
               exit(0);break;
       case 1:registeruser r;
              r.readuser();
              ofstream f("userdata.dat",ios::app);  //opening the file in append mode
              f.write((char *)&r,sizeof(r));
              f.close();
              load();
              break;
   }
    /*system("cls");
    system("COLOR F0");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tWelcome to SHOPPER-SPOT..."<<endl;
    delay(2000);*/
    system("cls");
    system("COLOR F0");
    cout<<"\t\t\t\t\t\t\t\t\t\t\t****SHOPPER-SPOT****"<<endl;
    items i;
    cout<<"\t\t\t\t\t\t\t\t___________________________________________________________"<<endl;
    cout<<"\t\t\t\t\t\t\t\t| ID  |        NAME        |PRICE(in Rs.)|RATTING(out of 5)|"<<endl;
    cout<<"\t\t\t\t\t\t\t\t|_____|____________________|_____________|_________________|"<<endl;
    i.display();
    purchase pur;
    pur.readpurchase();
    system("cls");
    return(0);
}



