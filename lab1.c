#include <stdio.h>
#include <math.h>

typedef struct Complex
{
    float real;
    float imag;
} complex;

void addNumbers(complex c1, complex c2, complex *result);
void subtractNumbers(complex c1, complex c2, complex *result);
void multuplyNumbers(complex c1, complex c2, complex *result);
void divideNumbers(complex c1, complex c2, complex *result);
void abcolute(complex c1, complex c2, complex *result);

void addNumbers(complex c1, complex c2, complex *result)
{
    result->real = c1.real + c2.real;
    result->imag = c1.imag + c2.imag; 
}

void subtractNumbers(complex c1, complex c2, complex *result)
{
    result->real = c1.real - c2.real;
    result->imag = c1.imag - c2.imag; 
}

void multiplyNumbers(complex c1, complex c2, complex *result)
{
    result->real = (c1.real * c2.real) - (c1.imag * c2.imag);
    result->imag = (c1.real * c2.imag) + (c1.imag * c2.real);
}

void divideNumbers(complex c1, complex c2, complex *result)
{
    result->real = (c1.real * c2.real + c1.imag * c2.imag) / (pow(c2.real, 2) + pow(c2.imag, 2));
    result->imag = (c2.real * c1.imag - c1.real * c2.imag) / (pow(c2.real, 2) + pow(c2.imag, 2));
}

double absolute(complex c)
{
    double result = sqrt(pow(c.real, 2) + pow(c.imag, 2)); 
    return result;
}

int main()
{
    complex c1, c2, addRes, subRes, mulRes, divRes;
    printf("First number,\n");
    printf("Enter real part: ");
    scanf("%f", &c1.real);
    printf("Enter imaginary part: ");
    scanf("%f", &c1.imag);

    printf("Second number, \n");
    printf("Enter real part: ");
    scanf("%f", &c2.real);
    printf("Enter imaginary part: ");
    scanf("%f", &c2.imag);

    addNumbers(c1, c2, &addRes);
    printf("\nAdd result = %.1f + %.1fi\n", addRes.real, addRes.imag);
     
    subtractNumbers(c1, c2, &subRes);
    printf("\nSub result = %.1f + %.1fi\n", subRes.real, subRes.imag);

    multiplyNumbers(c1, c2, &mulRes);
    printf("\nMul result = %.2f + %.2fi\n", mulRes.real, mulRes.imag);

    divideNumbers(c1, c2, &divRes);
    printf("\nDiv result = %.2f + %.2fi\n", divRes.real, divRes.imag);

    double absRes1 = absolute(c1); 
    printf("\nAbsolute of c1 = %.1f\n", absRes1);

    double absRes2 = absolute(c2); 
    printf("\nAbsolute of c2 = %.1f\n", absRes2);

    double atanRes1 = atan2(c1.real, c1.imag); 
    printf("\natan of c1 = %.1f\n", atanRes1);

    double atanRes2 = atan2(c2.real, c2.imag); 
    printf("\natan of c2 = %.1f\n", atanRes2);
    
    return 0;
}