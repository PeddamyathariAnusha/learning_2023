#include <stdio.h>

int main() {
    int array[100],length,max,min;
    printf("Enter size of the array : ");
    scanf("%d",&length);
    printf("Enter elements in array : ");
    for(int i=0; i<length; i++)
    {
        scanf("%d",&array[i]);
    }
    min=max=array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];  
        }

        if (array[i] > max) {
            max = array[i];  
        }
    }
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
