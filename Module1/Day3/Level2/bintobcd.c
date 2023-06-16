#include<stdio.h>
#define BCD_9  "1001"
#define BCD_8  "1000"
#define BCD_7  "0111"
#define BCD_6  "0110"
#define BCD_5  "0101"
#define BCD_4  "0100"
#define BCD_3  "0011"
#define BCD_2  "0010"
#define BCD_1  "0001"
#define BCD_0  "0000"

void convertToBCD(int num) {
	int b[5], j, dec = 0;
	int i = 0;
	while (num != 0) {
		b[i] = num % 10;
		num = num / 10;
		i++;
		dec++;
	}
	for (j = dec - 1; j >= 0; j--) {
		switch (b[j]) {
			case 9:
				printf("%s", BCD_9);
				break;
			case 8:
				printf("%s", BCD_8);
				break;
			case 7:
				printf("%s", BCD_7);
				break;
			case 6:
				printf("%s", BCD_6);
				break;
			case 5:
				printf("%s", BCD_5);
				break;
			case 4:
				printf("%s", BCD_4);
				break;
			case 3:
				printf("%s", BCD_3);
				break;
			case 2:
				printf("%s", BCD_2);
				break;
			case 1:
				printf("%s", BCD_1);
				break;
			default:
				printf("%s", BCD_0);
				break;
		}
	}
}

int main() {
	int number,bcd;
	printf("Enter decimal code: ");
	scanf("%d", &number);
	convertToBCD(number);
	return 0;
}