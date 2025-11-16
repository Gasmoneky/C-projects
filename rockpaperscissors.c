#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int personsChoice(int personChoice);
int machineChoice(int randomNumber);
int winner(int personChoice,int computerReturn){

if(personChoice == computerReturn){
printf("YOU HAVE TIED");
}
else if(personChoice==1 && computerReturn==3 || personChoice==2 && computerReturn==1 || personChoice==3 && computerReturn==2){
printf("\nYOU HAVE WON");
}
else{
    printf("\nYOU LOSE");
}

}


int main(){

srand(time(NULL));
int randomNumber = rand();
int personChoice = 0;

printf("-----------------------------------------\n");
printf("ROCK PAPER SCISSORS GAME MADE BY RYAN\n");
printf("-----------------------------------------\n");


printf("Please pick a number that you would like to play with:\n");
printf("1.ROCK\n");
printf("2.PAPER\n");
printf("3.SCISSORS\n");
printf("Enter Your Choice:");


scanf("%d",&personChoice);
if (personChoice <1 || personChoice>3){
    printf("invalid input program closing");
    
}

   else{ 
int personReturn = personsChoice(personChoice);
int computerReturn = machineChoice(randomNumber);
int theWinner = winner(personChoice,computerReturn);

   

}
    return 0;

}

int personsChoice(int personChoice){
switch(personChoice){
case 1:
printf("YOU HAVE CHOSEN ROCK\n");
break;

case 2:
printf("YOU HAVE CHOSEN PAPER\n");
break;

case 3:
printf("YOU HAVE CHOSEN SCISSORS\n");
break;
}


}
int machineChoice(int randomNumber){
int min = 1;
int max = 3;
int purifiedRandom = rand() % (max - min) + 1;

switch(purifiedRandom){
    case 1:
    printf("THE OVERLORD CHOSE ROCK\n");
    break;
    case 2:
    printf("THE OVERLORD CHOSE PAPER\n");
    break;
     case 3:
    printf("THE OVERLORD CHOSE SCISSORS\n");
    break; 
}
return purifiedRandom;
}