#include <stdio.h>
#include <string.h>
#include <math.h>

float theFirstNumbers(){
     float firstNumber = 0.0f; 
    printf("Enter the first number:");
    scanf("%f",&firstNumber);
      return firstNumber;
}

float theSecondNumbers(){
    float secondNumber = 0.0f;
    printf("Enter the second number:");
     scanf("%f",&secondNumber);
     return secondNumber;
}

float square(float num1){
return num1*num1;
}

float division(float num2 , float num3){
    return (num2 / num3);
}

float multlipication (float num4 , float num5 ){
    return (num4 *num5);
}

float addition(float num6 , float num7){
return (num6+num7);
}

float subtraction (float num8 , float num9){
return (num8-num9);
}

float squareroot(float num10){
 return sqrt(num10);
}

int main (){
printf("SEMI-ADVANCED CALCULATOR PROGRAM MADE USING FUNCTIONS\n");

char oparation = '\0';

printf("What oparation would you like to use  ^(square), /(division), *(multlipication), +(addition), -(sutraction), @(squareroot)\n");
scanf(" %c",&oparation);

switch(oparation){
    case'^':
    float num1= theFirstNumbers();
    float result1 = square(num1);
    printf(" Your answer is %.2f",result1);
    break;

    case'/':
    float num2 = theFirstNumbers();
    float num3 = theSecondNumbers();
     if(num3 == 0){
        printf("SYNTAX ERROR!");
     }
     else{
          float result2 = division(num2,num3);
          printf("Your result is %.2f", result2);
     }
     break;

     case'*':
     float num4 = theFirstNumbers();
     float num5 = theSecondNumbers();
     float result3 = multlipication(num4,num5);
     printf("Your result is %.2f", result3);
     break;

     case '+':
     float num6 = theFirstNumbers();
     float num7 = theSecondNumbers();
      float result4 = addition(num6,num7); 
    printf("Your result is %.2f", result4);
    break;

     case '-':
     float num8 = theFirstNumbers();
     float num9 = theSecondNumbers();
      float result5 = subtraction(num8,num9); 
    printf("Your result is %.2f", result5);
    break;

    case'@':
    float num10 = theFirstNumbers();
      float result6 = squareroot(num10); 
    printf("Your result is %.4f", result6);
    break;
}
}