#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to swap two variables of any type
void swap(void *a, void *b, size_t size) {
    char *temp = (char *)malloc(size);  // Create temporary memory block
    
    // Copy contents of 'a' to temporary memory block
    memcpy(temp, a, size);
    
    // Copy contents of 'b' to 'a'
    memcpy(a, b, size);
    
    // Copy contents of temporary memory block to 'b'
    memcpy(b, temp, size);
    
    free(temp);  // Free the temporary memory block
}

int main() {
    int a;
    int b;
    printf("Enter values of a and b:");
    scanf("%d %d",&a,&b);
    printf("Before swapping: a = %d, b = %d\n", a, b);
    
    // Swap 'a' and 'b'
    swap(&a, &b, sizeof(int));
    
    printf("After swapping: a = %d, b = %d\n", a, b);
    
    float x ;
    float y;
    printf("Enter values of x and y");
    scanf("%f %f",&x,&y);
    printf("Before swapping: x = %.2f, y = %.2f\n", x, y);
    
    // Swap 'x' and 'y'
    swap(&x, &y, sizeof(float));
    
    printf("After swapping: x = %.2f, y = %.2f\n", x, y);
    
    return 0;
}