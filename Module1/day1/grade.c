#include <stdio.h>

int main() {
    int score;   
    char grade;   

    printf("Enter your test score: ");
    scanf("%d", &score);

    if (score >= 90) {
        grade = 'A';
    } else if (score >= 75) {
        grade = 'B';
    } else if (score >= 60) {
        grade = 'C';
    } else if (score >= 50) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    printf("Your grade is %c\n", grade);

    return 0;
}
