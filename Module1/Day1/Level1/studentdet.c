#include <stdio.h>
#include <string.h>

void main()
{
    int rollno,phy,che,math,total;
    float per;
    char initial[30],name[30],div[10];
    printf("Input the Roll Number of the student :");
    scanf("%d",&rollno);
    printf("Input the Name of the Student :");
    scanf("%s %s",initial, name);
    printf("Input  the marks of Physics, Chemistry and Maths : ");
    scanf("%d %d %d",&phy,&che,&math);
    total = phy+che+math;
    per = total/3.0;
    if (per>=60)
	 strcpy(div,"First");
    else
	if (per<60&&per>=48)
	    strcpy(div,"Second");
	else
	    if (per<48&&per>=36)
		strcpy(div,"Pass");
	     else
		strcpy(div,"Fail");

       printf("\nRoll No : %d\nName of Student : %s %s\n",rollno,initial,name);
       printf("Marks in Physics : %d\nMarks in Chemistry : %d\nMarks in maths : %d\n",phy,che,math);
       printf("Total Marks = %d\nPercentage = %5.2f\nDivision = %s\n",total,per,div);
}
