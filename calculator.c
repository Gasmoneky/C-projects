#include <stdio.h>

int main (){
printf("CALCULATOR PROGRAM BY RYAN\n");


float firstNumber = 0.0f;
float secondNumber = 0.0f;
char oparator = '\0';
float result = 0.0f;

printf("What oparator would you like to use( +  -  /  *)");
scanf("%c" ,&oparator);

printf("What is the first number \n");
scanf("%f",&firstNumber);

printf("What is the second number \n");
scanf("%f",&secondNumber);

switch(oparator){
 case '+':
 result = firstNumber + secondNumber;
 break;

 case '-':
 result = firstNumber - secondNumber;
break;

case'/':
if(secondNumber == 0){
      printf("You cannot divide by 0");
}
else{
      result = firstNumber / secondNumber;
}
break;

case'*':
result = firstNumber * secondNumber;
break;
}

printf("Result:%.2f",result);

      return 0;
}