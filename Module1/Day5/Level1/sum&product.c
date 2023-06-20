#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

struct Complex readComplex();
void writeComplex(struct Complex num);
struct Complex addComplex(struct Complex num1, struct Complex num2);
struct Complex multiplyComplex(struct Complex num1, struct Complex num2);

int main() {
    struct Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    num1 = readComplex();

    printf("Enter the second complex number:\n");
    num2 = readComplex();

    sum = addComplex(num1, num2);
    printf("Sum of the complex numbers: ");
    writeComplex(sum);

    product = multiplyComplex(num1, num2);
    printf("Product of the complex numbers: ");
    writeComplex(product);

    return 0;
}

struct Complex readComplex() {
    struct Complex num;
    printf("Real part: ");
    scanf("%f", &num.real);
    printf("Imaginary part: ");
    scanf("%f", &num.imaginary);
    return num;
}

void writeComplex(struct Complex num) {
    if (num.imaginary >= 0)
        printf("%.2f + %.2fi\n", num.real, num.imaginary);
    else
        printf("%.2f - %.2fi\n", num.real, -num.imaginary);
}

struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex sum;
    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;
    return sum;
}

struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex product;
    product.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    product.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
    return product;
}

