#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<cstring>
#include<cstdio>
#include<conio.h>

using namespace std;
int aa;
void send_message(char *sender);
struct birth_day
{
    int day;
    int month;
    int year;
};

typedef struct birth_day birth_day;

class user
{
public:
    int count_mssg;
    char name[50];
    char email[30];
    char password[20];
    birth_day birthday;
    int user_gender;
    user *next;
    void user_option();
    user()
    {
        count_mssg=0;
    }
};

user *main_head=NULL;

class social_net
{
public:
    user *head=main_head;
    social_net()
    {

        cout<<"\n\n\n\n\n\n\t\t\t--------------------------\n\t\t\t--------------------------\n\t\t\t\tCHIT-CHAT\n\t\t\t--------------------------\n\t\t\t--------------------------\n";
        Sleep(2000);
    }
    void signup();
    void add(user *new_user) ;
    void read();
    void log_in();
    void messanger(char *sender, char *reciver,char *mssg_body)
    {
        user *temp = head;
        while(temp!=NULL)
        {

            if(!(strcmp(reciver,temp->name)))
            {
                ofstream out("Message.txt",ios::app);
                out<<"\n"<<sender<<"\n";
                out<<reciver<<"\n";
                out<<mssg_body<<"\n";
                temp->count_mssg++;
                break;
            }
            temp=temp->next;
        }
    }
} s;

void social_net::read()
{
    char a[50],b[50],c[50],g[50],h[50];
    int d,e,f;
    ifstream fin("User.txt");
    while(!fin.eof())
    {
        fin>>a>>b>>c>>d>>e>>f>>g>>h;
        user *new_user ;
        new_user=(user*)malloc(sizeof(user));
        strcpy(new_user->name,b);
        if(strcmp("Male",c))
        {
            new_user->user_gender = 1;
        }
        else
        {
            new_user->user_gender = 2;
        }

        new_user->birthday.day = d;
        new_user->birthday.month = e;
        new_user->birthday.year = f;
        strcpy(new_user->email,g);
        strcpy(new_user->password,h);
        new_user->next = NULL;
        add(new_user);
        int flag3=0;
        char str1[50],str2[50],str3[50];
        ifstream fin("Message.txt");
        while(!fin.eof())
        {
            while(!(fin.eof()))
            {
                fin>>str1>>str2>>str3;
                if(!strcmp(new_user->name,str2))
                {
                    flag3++;
                }
            }
            new_user->count_mssg= flag3;
        }
        //cout<<new_user->name<<"has "<<new_user->count_mssg<<"Messages \n";

    }
    int asdasd;
//       cin>>asdasd;
}

void social_net::log_in()
{

    while(1)
    {
        user *temp2 = head;
        char user[20], pass[10];
        int s,i=0;
        system("cls");
        cout<<"\n\n\n\n\t\t\tUsername: ";
        cin>>user;
        fflush(stdin);
        cout<<"\n\t\t\tPassword: ";
        char ch;
        do
        {

            if((ch=getch()) == 13)
            {
                pass[i]='\0';
                break;
            }
            {
                pass[i]=ch;
                i++;
                printf("*");
                fflush(stdin);
            }
        }
        while(1);

        fflush(stdin);
        int t;
        while(temp2!=NULL)
        {

            if(!(strcmp(user,temp2->name)))
                break;

            temp2=temp2->next;
        }
        if(temp2!=NULL)
        {
            if(!(strcmp(pass,temp2->password)))
            {
                temp2->user_option();
                break;
            }
        }
        else
        {
            cout<<"\n\t\tUsername or Password is Incorrect\n"<<endl;
            cout<<" ------------\t\t\t\t\t-----------\n | 1. Retry |\t\t\t\t\t| 2. Back |\n ------------\t\t\t\t\t-----------\n";
            cout<<"                          ";
            cin>>s;
            if (s==2)
                return;
        }
    }
}
void user :: user_option()
{

    int flag3=0,ciii;
    char str1[20], str2[20], str3[300];
    while(1)
    {
        system("cls");
        cout<<"\t\t\t\t\t\t\t\tHi "<<name<<" \1"<<endl;
        cout <<"Enter your choice : \n";
        cout<<"\n\t\t-------------------\n\t\t|  1.NEW MESSAGE  |\n\t\t-------------------";
        cout<<"\n\t\t-------------------\n\t\t|     2.INBOX     |\n\t\t-------------------";
        cout<<"\n\t\t-------------------\n\t\t| 3.SENT MESSAGES |\n\t\t-------------------";
        cout<<"\n\t\t-------------------\n\t\t|    4.LOGOUT     |\n\t\t-------------------";
        int x;
        cout<<"\n\t\t          ";


        fflush(stdin);
        cin>>x;

        fflush(stdin);
        if(x==1)
        {
            send_message(name);
        }
        //fflush(stdin);
        else if (x==2)
        {
            ifstream fin1("Message.txt");
            while(!(fin1.eof()))
            {
                fin1>>str1>>str2>>str3;
                system("cls");
                if(!strcmp(name,str2))
                {
                    flag3++;

                }
            }
            fin1.close();
            //cout <<count_mssg<<endl;
            cout<<"\n\n\n\n\tYour have total "<<flag3<<" messages\n"<<endl;

            cout<<"\n\n-----------\t\t\t\t\t-----------\n| 1. View |\t\t\t\t\t| 2. Back |\n-----------\t\t\t\t\t-----------";;
            cout<<"\n                          ";


            int asd;
            cin>>asd;
            system("cls");
            if(asd==1)
            {
                ifstream fin("Message.txt");

                while(!(fin.eof()))
                {
                    fin>>str1>>str2>>str3;
                    if(!strcmp(name,str2))
                    {
                        fflush(stdin);
                        cout<<"From: "<<str1<<endl<<str3<<endl<<endl;
                    }
                }
                cout<<"\n\n            \t\t\t\t\t-----------\n            \t\t\t\t\t| 1. Back |\n            \t\t\t\t\t-----------";
                cout<<"\n                          ";
                //count_mssg= flag3;
                int asd;
                cin>>asd;
                if (asd==1)
                    user_option();
            }
            else if(asd==2)
                user_option();
        }
        //fflush(stdin);
        else if (x==3)
        {
            ifstream in("Message.txt");
            system("cls");
            while(!(in.eof()))
            {
                in>>str1>>str2>>str3;

                if(!strcmp(name,str1))
                {
                    cout<<"To: "<<str2<<endl<<str3<<endl<<endl;
                }
            }
            cout<<"\n\n            \t\t\t\t\t-----------\n            \t\t\t\t\t| 1. Back |\n            \t\t\t\t\t-----------";
            cout<<"\n                          ";
            int asd;
            cin>>asd;
            if (asd==1)
                user_option();
        }
        //fflush(stdin);
        else if (x==4)
            break;
    }
}
void social_net::signup()
{
    user *new_user;
    char temp1[20], temp2[20];
    new_user=new user;
    int s;
    system("cls");
    cout<<"\n\n\t\t\t\tCHIT-CHAT\n\n\n\tSignup Form\n\n";
    cout<<"\n\tEnter Name\t\t:";
    cin>>new_user->name;
    cout<<"\n\tChoose Gender  \t\t: 1.Male      2.Female\n\t\t\t\t";
    cin>>new_user->user_gender;
    cout<<"\n\tEnter Birthday\t\t:"<<endl;
    while(1)
    {
        cout<<"\t              \t\tDay  : ";
        cin>>new_user->birthday.day;
        if(new_user->birthday.day>0 && new_user->birthday.day<32)
        {
            break;
        }
        cout<<"\t              \t\tWrong Input!!\n\t              \t\tPlease Re-enter"<<endl;
    }
    while(1)
    {
        cout<<"\t                   \t\tMonth  : ";
        cin>>new_user->birthday.month;
        if(new_user->birthday.month>0 && new_user->birthday.month<13)
        {
            break;
        }
        cout<<"\t                   \t\tWrong Input!!\n\t                   \t\tPlease Re-enter"<<endl;
    }
    while(1)
    {
        cout<<"\t                            \t\tYear  : ";
        cin>>new_user->birthday.year;
        if(new_user->birthday.year>1915 && new_user->birthday.year<2016)
        {
            break;
        }
        cout<<"\t                            \t\tWrong Input!!\n\t                            \t\tPlease Re-enter"<<endl;
    }
    cout<<"\n\tEnter Email\t\t:";
    cin>>new_user->email;
    while(1)
    {
        cout<<"\n\tEnter Password\t\t:";
        cin>>temp1;
        cout<<"\n\tConfirm your password\t:";
        cin>>temp2;
        if (!strcmp(temp1,temp2))
        {
            strcpy(new_user->password,temp2);
            break;
        }
        cout<<"\tPassword do not match!!"<<endl<<"\tPlease Re-enter:"<<endl;
    }
    cout<<"\nI do agree to CHIT-CHAT terms and policies\n";
    cout<<"-----------\t\t\t\t\t-----------\n| 1. Save |\t\t\t\t\t| 2. Back |\n-----------\t\t\t\t\t-----------";
    cin>>s;
    if (s==1)
    {
        ofstream out("User.txt",ios::app);
        out<<"#\n";
        out<<new_user->name<<"\n";
        if (new_user->user_gender==1)
            out<<"Male"<<"\n";
        else
            out<<"Female\n";
        out<<new_user->birthday.day<<"\n";
        out<<new_user->birthday.month<<"\n";
        out<<new_user->birthday.year<<"\n";
        out<<new_user->email<<"\n";
        out<<new_user->password<<"\n";
        out<<"\n";
        new_user->next = NULL;
        add(new_user);
        cout<<"Congratulations!!!\nYou have registered successfully.\n";
    }
    else if (s==2)
        return;
}

void social_net::add(user *new_user)
{
    if (head==NULL)
        head=new_user;
    else
    {
        user *temp=head;
        if(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_user;
    }
}

void send_message(char *sender)
{
    char reciver[50],messg[300];
    int x, y=0;
    char a[50],b[50],c[50],g[50],h[50];
    int d,e,f;
    ifstream fin("User.txt");
    system("cls");
    cout<<"\n Enter Message Recipant :";
    cin>>reciver;
    fflush(stdin);
    while(!fin.eof())
    {
        fin>>a>>b>>c>>d>>e>>f>>g>>h;
        if(!(strcmp(reciver,b)) && strcmp(reciver,sender))
        {
            cout<<"\n\n Write your Message here:";
            cin.get(messg,300);
            cout<<" -----------\t\t\t\t\t-----------\n | 1. Send |\t\t\t\t\t| 2. Back |\n -----------\t\t\t\t\t-----------\n";
            cout<<"                          ";
            while(1)
            {
                cin>>x;
                if (x==1)
                {
                    s.messanger(sender,reciver,messg);
                    break;
                }
                else if (x==2)
                    return;
                else
                    cout <<"Wrong Input\n";
            }
            y=1;
            break;
        }
    }
    if (y==0)
    {
        cout<<"Enter a valid Recipient\n";
        Sleep(1000);
        send_message(sender);
    }
}

int main()
{
    int choice;
    s.read();
    while(1)
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\t\t----------------\t\t\t----------------\n\t\t|  1. Sign Up  |\t\t\t|  2. Sign In  |\n\t\t----------------\t\t\t----------------\n\t\t\t\t\t";;
        cin>>choice;
        if (choice==1)
        {
            s.signup();
        }
        else if (choice== 2)
        {
            s.log_in();
        }
        else
        {
            cout<<"Wrong Input.";
            Sleep(2000);
        }
    }
    return 0;
}

