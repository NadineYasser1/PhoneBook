#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int day;
     int month;
    int year;
} date;

typedef struct
{
    char last[50];
    char name[50];
    date DOB;
    char address[100];
    char number[30];
    char email[60];
} person;

person p[200];
int count=0;

void load()
{
    FILE *f;
    f=fopen("data.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,],",p[count].last);
        fscanf(f,"%[^,],",p[count].name);
       fscanf(f,"%d-%d-%d,",&p[count].DOB.day,&p[count].DOB.month,&p[count].DOB.year);
        fscanf(f,"%[^,],",p[count].address);
        fscanf(f,"%[^,],",p[count].number);
        fscanf(f,"%s\n",p[count].email);
        count++;
    }
    fclose(f);
}
void print()
{
    int i;
    for(i=0; i<count; i++)
    {

        printf("%s,%s,%d-%d-%d,%s,%s,%s\n",p[i].last,p[i].name, p[i].DOB.day, p[i].DOB.month, p[i].DOB.year, p[i].address,p[i].number,p[i].email);
    }
}

void modify(){
    bool modifying;
    modifying = true;
    while(modifying)
    {
        int i=0,j=0;
        bool found = false;
        person s;
        printf("enter the last name of the person you want to modify\n");
        scanf(" %s",s.last);
        for(i=0;i<count;i++){
                if(strcmp(s.last,p[i].last)==0)
        {
            found=true;
            j=i;
        }
        }
        if(found)
        {

            printf("enter the new date of birth of %s %s \n",p[j].name,p[j].last);
            scanf("%d%d%d",&p[j].DOB.day,&p[j].DOB.month,&p[j].DOB.year);
            printf("enter the new address of %s %s ",p[j].name,p[j].last);
            fflush(stdin);
            char newAddress[100] ;
            scanf ("%[^\n]%*c", newAddress);
            strcpy(p[j].address,newAddress);
            printf("enter the new number of %s %s \n",p[j].name,p[j].last);
            scanf("%s",p[j].number);
            printf("enter the new email of %s %s \n",p[j].name,p[j].last);
            scanf("%s",p[j].email);
            modifying=false;
            break;
        }
        char cont;
        printf("Could not find %s, search again?(Y/N)\n",s.last);
        do{
        scanf(" %c",&cont);
        }while(tolower(cont)!='n'&&tolower(cont)!='y');
        if(tolower(cont)=='n')
        {
            modifying=false;
        }



    }

}




void sorByLname(){
    int i,j;
    int min;
    person temp;
    for(i=0;i<count;i++)
    {
        min =i;
        for(j=i+1;j<count;j++)
        {
         if(strcasecmp(p[min].last,p[j].last)>0)
         {
             min=j;
         }
        }
        temp=p[i];
        p[i]=p[min];
        p[min]=temp;
    }
}

int main()
{
    printf("\t\twelcome to the phonebook\n-------------------------------------------------------------\n");
    load();
    print();
    printf("\n\n\n");
    modify();
    //sorByLname();
    print();


    return 0;
}
