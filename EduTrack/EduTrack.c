#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#define Student struct Stud

void add(FILE * fp);
void modify(FILE * fp);
void display(FILE * fp);
void Indivisual(FILE *fp);
void password();
FILE * del(FILE * fp);
void printChar(char ch,int n);
void title();
FILE *tp;
void login();
void loading();
void menu();
void welcomeMessage();
//for cursorposition handeling
void gotoxy(int x,int y)
{
    COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

COORD coordinates = {0,0};
//for gotoxy handeling
void gotocoordinate(int x,int y)
{
    coordinates.X=x;
    coordinates.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

/*We are Using setcolor function for Maintaining Text color */
void setcolor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);

    }
}
struct pass
{
    char pass[25];
} pa;
//for structure
struct Stud
{
    char name[100];
    char fathername[100];
    char mothername[100];
    char dept[50];
    int intake;
    char sec;
    int roll;
    float sgpa[12];
    float cgpa;
};
//Fast loading page
void loading()
{
    SetConsoleTitle("EduTrack || BUBT");
    int r,q;
    gotoxy(40,10);
    setcolor(3);
    printf ("EduTrack \n");
    gotoxy(50,15);
    setcolor(3);
    printf("LOADING......");
    gotoxy(36,12);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",177);
    }
    system("cls");
}
//This is welcome message
void welcomeMessage()
{
    SetConsoleTitle("EduTrack || BUBT");
    system("cls");
    setcolor(9);
    printf("\n\n\n\n\n");
    printf("\n\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=");
    printf("\n\t\t      =                   WELCOME              =");
    printf("\n\t\t      =                     TO                 =");
    printf("\n\t\t      =                   EduTrack             =");
    printf("\n\t\t      =                   A STUDENT            =");
    printf("\n\t\t      =              RECORD MANAGEMENT         =");
    printf("\n\t\t      =                   SYSTEM               =");
    printf("\n\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
//For loging function
void login()
{
    system("cls");
    int valid=0;
    int n,p;
    int i=0;
    char username[20],a;
    char password[10];
    //gotoxy(20,8);
    SetConsoleTitle("EduTrack || BUBT");
    printf("\n\n\n\t\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-");
    printf("\n\t\t\t\t=                                           =");
    printf("\n\t\t\t\t=   *************LOGIN PAGE**************   =");
    printf("\n\t\t\t\t=                                           =");
    printf("\n\t\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-\n");
    printf("\n\n\t\tPlease Enter Your Valid User-Name & Password\n");
    printf("\n\n\t\tUser-Name:  ");
    scanf("%s",username);
    printf("\n\t\tPassword:  ");
    while(1)
    {
        a = getch();
        if(a ==13)
        {
            break;
        }
        printf("*");
        password[i] = a;
        i++;
    }
    password[i]='\0';

    n = strcmp("admin",username);
    p = strcmp("1234",password);
    if(n == 0 && p == 0)
    {
        menu();

    }

    else
    {
        setcolor(12);
        printf("\n\n\t!!!! ERROR !!!!Wrong Password Or User Name.");

        printf("\n\n\t");
        system("pause");
        login();
    }

}


//Main funtion
int main()
{
    system("COLOR F2");
    loading();
    welcomeMessage();
    login();
    menu();
}
// Menu function

void menu()
{
    system("COLOR F1");
    int ch,id,k,i;
    char c,pas[50];
    SetConsoleTitle("EduTrack || BUBT");

    FILE * fp;
    Student s;
    int option;
    char another;

    if((fp=fopen("information.txt","rb+"))==NULL)
    {
        if((fp=fopen("information.txt","wb+"))==NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }
    while(1)
    {
        title();
        printf("\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\t1. Add Student");
        printf("\n\n\t\t\t\t2. Modify Student");
        printf("\n\n\t\t\t\t3. Show All Student");
        printf("\n\n\t\t\t\t4. Individual View");
        printf("\n\n\t\t\t\t5. Remove Student");
        printf("\n\n\t\t\t\t6. Logout\n\t");
        printChar('*',64);
        printf("\n\n\t\t\tEnter Your Option :-->  ");
        scanf("%d",&option);

        switch(option)
        {
        case 1:
            add(fp);
            break;
        case 2:
            modify(fp);
            break;
        case 3:
            display(fp);
            break;
        case 4:
            Indivisual(fp);
            break;
        case 5:
            fp=del(fp);
            break;
        case 6:
            exit(0);
        default:
            printf("\n\t\tNo Action Detected");
            printf("\n\t\tPress Any Key........\n");
            getch();
            system("pause");
        }
    }


    return 1;
}
void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

void title()
{
    system("cls");
    system("COLOR F1");
    printf("\n\n\t");
    printChar('=',19);
    printf(" EduTrack ");
    printChar('=',19);
    printf("\n");
}


//Insert at end
//case 1

void add(FILE *fp)
{
    title();
    char another='y';
    Student s;
    int i;
    float cgpa;
    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {

        printf("\n\n\t\tEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';
        printf("\n\t\tEnter Father Name: ");
        fflush(stdin);
        fgets(s.fathername,100,stdin);
        s.fathername[strlen(s.fathername)-1]='\0';
        printf("\n\t\tEnter Mother Name: ");
        fflush(stdin);
        fgets(s.mothername,100,stdin);
        s.mothername[strlen(s.mothername)-1]='\0';
        printf("\n\t\tEnter Department Name: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';
        printf("\n\t\tEnter Intake: ");
        scanf("%d",&s.intake);
        printf("\n\t\tEnter Section: ");
        scanf("%d",&s.sec);
        printf("\n\t\tEnter Roll: ");
        scanf("%d",&s.roll);


        fwrite(&s,sizeof(s),1,fp);
        printf("\n\n\t\tAdd another student?(Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}

//Delete function cas3 3
FILE * del(FILE * fp)
{
    title();
    Student s;
    int flag=0,tempRoll,siz=sizeof(s);
    FILE *ft;
    if((ft=fopen("temp.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }
    printf("\n\n\tEnter Roll number of Student to Delete the Record");
    printf("\n\t\t\tRoll No. : ");
    scanf("%d",&tempRoll);
    rewind(fp);
    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            printf("\n\tRecord Deleted for");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.name,s.fathername,s.mothername,s.dept,s.intake,s.sec,s.roll);
            continue;
        }

        fwrite(&s,siz,1,ft);
    }


    fclose(fp);
    fclose(ft);

    remove("information.txt");
    rename("temp.txt","information.txt");

    if((fp=fopen("information.txt","rb+"))==NULL)
    {
        printf("ERROR");
        return  NULL;
    }

    if(flag==0) printf("\n\n\t\tNO STUDENT FOUND WITH THE INFORMATION\n\t");

    printChar('-',65);
    printf("\n\t");
    system("pause");
    return fp;
}

// case 2 Modify
void modify(FILE *fp)
{
    title();

    Student s;
    int i,flag=0,tempRoll,siz=sizeof(s);
    float cgpa;

    printf("\n\n\tEnter Roll Number of Student to MODIFY the Record : ");
    scanf("%d",&tempRoll);
    rewind(fp);
    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        fseek(fp,-siz,SEEK_CUR);
        printf("\n\n\t\t\t\tRecord Found\n\t\t\t");
        printChar('=',38);
        printf("\n\t\tStudent Name: %s",s.name);
        printf("\n\t\tEnter Father Name: %s",s.fathername);
        printf("\n\t\tEnter Mother Name: %s",s.mothername);
        printf("\n\t\tDepartment: %s",s.dept);
        printf("\n\t\tIntake: %d",s.intake);
        printf("\n\t\tSection: %d",s.sec);
        printf("\n\t\tRoll: %d\n\t\t\t",s.roll);
        printChar('=',38);
        printf("\n\n\t\tEnter New Data for the student");
        printf("\n\n\t\tEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';
        printf("\n\t\tEnter Father Name: ");
        fflush(stdin);
        fgets(s.fathername,100,stdin);
        s.fathername[strlen(s.fathername)-1]='\0';
        printf("\n\t\tEnter Mother Name: ");
        fflush(stdin);
        fgets(s.mothername,100,stdin);
        s.mothername[strlen(s.mothername)-1]='\0';
        printf("\n\t\tEnter Department: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';
        printf("\n\t\tEnter Intake: ");
        scanf("%d",&s.intake);
        printf("\n\t\tEnter Section: ");
        scanf("%d",&s.intake);
        printf("\n\t\tEnter Roll: ");
        scanf("%d",&s.roll);

        fwrite(&s,sizeof(s),1,fp);
    }

    else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    printf("\n\n\t");
    system("pause");

}
//For Display show
void display(FILE * fp)
{
    title();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\t\tFather Name: %s",s.fathername);
        printf("\n\t\tMother Name: %s",s.mothername);
        printf("\n\t\tDepartment : %s",s.dept);
        printf("\n\t\tIntake: %d",s.intake);
        printf("\n\t\tSection: %d",s.sec);
        printf("\n\t\tROLL : %d\n",s.roll);

        printChar('-',65);
    }
    printf("\n\n\n\t");
    printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

//For indivisual case 4
void Indivisual(FILE *fp)
{
    title();

    int tempRoll,flag,siz,i;
    Student s;
    char another='y';

    siz=sizeof(s);

    while(another=='y'||another=='Y')
    {
        printf("\n\n\tEnter Roll Number: ");
        scanf("%d",&tempRoll);

        rewind(fp);

        while((fread(&s,siz,1,fp))==1)
        {
            if(s.roll==tempRoll)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\n\t\tNAME : %s",s.name);
            printf("\n\t\tFather Name: %s",s.fathername);
            printf("\n\t\tMother Name: %s",s.mothername);
            printf("\n\t\tDepartment : %s",s.dept);
            printf("\n\t\tIntake: %d",s.intake);
            printf("\n\t\tSection: %d",s.sec);
            printf("\n\t\tROLL : %d",s.roll);
            printf("\n\tSGPA: ");


            printChar('-',65);

        }
        else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");
        printf("\n\n\t\tShow another student information? (Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}
