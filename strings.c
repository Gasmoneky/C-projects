#include <stdio.h>
#include <string.h>

int main(){
char name[30]="";  
char levelEducation[30]="";
char place[20]="";
char school[50]="";
float time = 0.0f;
char timeDay[5] ="";

printf("What is your full name?: ");
fgets(name,sizeof(name),stdin);

printf("Which level of education did you reach?: ");
fgets(levelEducation,sizeof(levelEducation),stdin);

printf("Where was the school located?: ");
fgets(place,sizeof(place),stdin);

printf("What was the name of the school you attended?:");
fgets(school,sizeof(school),stdin);


printf("Which time of the day were you going to school(AM/PM):");
fgets(timeDay,sizeof(timeDay),stdin);


printf("At what time where you waking up to go to school?(eg 9.00):");
scanf("%f",&time);

name[strcspn(name,"\n")]='\0';
levelEducation[strlen(levelEducation)-1]='\0';
place[strlen(place)-1]='\0';
school[strlen(school)-1]='\0';
timeDay[strlen(timeDay)-1]='\0';

printf("\nMy name is %s ,I studied at %s ,Which was my highest level of education.The school was located at %s" ,name,school,place);
printf("I used to wake up at %.2f%s and go to school",time,timeDay);

    return 0;
}