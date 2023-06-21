#include<stdio.h>

struct student{
    int marks;
}
std[100];
void main() {
    int i,n;
    float total=0,avgmarks;
    printf("Enter the number of students in class:");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Enter student %d marks :",i+1);
        scanf("%d",&std[i].marks);
    }
    for(i=0;i<n;i++) {
        total = total + std[i].marks;
    }
    avgmarks=total/n;
    printf("\nAverage marks = %.2f",avgmarks);
    for(i=0;i<n;i++) {
        if(std[i].marks>=avgmarks) {
            printf("\n student %d marks = %d above average",i+1,std[i].marks);
        }
        else {
            printf("\n student %d marks = %d below average",i+1,std[i].marks);
        }
    }
}