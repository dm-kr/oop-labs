#include <stdio.h>
#include <math.h>

class Complex
{
    private:
        float r;
        float i;

    public:
        Complex(float real = 0, float imaginary = 0) {
            r = real;
            i = imaginary;
        }

        void addNumbers(Complex &num)
        {
            Complex answer;
            answer.r = r + num.r;
            answer.i = i + num.i; 
            printf("\nAdd result = %.1f + %.1fi\n", answer.r, answer.i);
        }

        void subtractNumbers(Complex &num)
        {
            Complex answer;
            answer.r = r - num.r;
            answer.i = i - num.i; 
            printf("\nAdd result = %.1f + %.1fi\n", answer.r, answer.i); 
        }

        void multiplyNumbers(Complex &num)
        {
            Complex answer;
            answer.r = (r * num.r) - (i * num.i);
            answer.i = (r * num.i) + (i * num.r); 
            printf("\nAdd result = %.1f + %.1fi\n", answer.r, answer.i);
        }

        void divideNumbers(Complex &num)
        {
            Complex answer;
            answer.r = (r * num.r + i * num.i) / (pow(num.r, 2) + pow(num.i, 2));
            answer.i = (num.r * i - r * num.i) / (pow(num.r, 2) + pow(num.i, 2)); 
            printf("\nAdd result = %.1f + %.1fi\n", answer.r, answer.i);
        }

        void absolute()
        {
            double result = sqrt(pow(r, 2) + pow(i, 2)); 
            printf("\nAbsolute of c1 = %.1f\n", result);
        }

        void tan()
        {
            double result = atan2(i, r); 
            printf("\nTan of c2 = %.1f\n", result);
        }
};

int main()
{
    Complex c1(1, 0), c2(0, 1);
    // printf("First number,\n");
    // printf("Enter real part: ");
    // scanf("%f", &c1.r);
    // printf("Enter imaginary part: ");
    // scanf("%f", &c1.i);

    // printf("Second number, \n");
    // printf("Enter real part: ");
    // scanf("%f", &c2.r);
    // printf("Enter imaginary part: ");
    // scanf("%f", &c2.i);

    c1.addNumbers(c2);
    c1.subtractNumbers(c2);
    c1.multiplyNumbers(c2);
    c1.divideNumbers(c2);
    c1.absolute();
    c2.tan();

    return 0;
}
