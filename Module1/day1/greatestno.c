#include <stdio.h>
int main(void){
int num1,num2,num3;
	printf("Enter three number ");
scanf("%d %d %d",&num1,&num2,&num3);  // Enter  numbers
if(num1>num2 && num1>num3){
  printf("Greatest number is num1: %d",num1);
}else if(num2>num3 && num2>num1){
  printf("Greatest number is num2: %d",num2);
}else if (num3>num1 && num3>num2){
printf("Greatest number is num3: %d",num3);
}
return 0;
}