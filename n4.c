#include <stdio.h>
#include <math.h>

int main(void){
    double a, b, c;
    printf("Enter 3 numbers (a, b, c) for ax^2 + bx + c:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a == 0){
        if (b == 0 && c == 0)
            printf("x is any\n");
        else if (b == 0 && c != 0)
            printf("no valid solutions\n");
        else if(b != 0){
            double res;
            res = -c / (double)b;
            printf("ax^2 + bx + c = 0 --> bx + c = 0; x = %.2f\n", res);
        }
    }
    else{
        if (b == 0 && c == 0){
            printf("x = 0");
        }
        else{
            double discr = (b * b) - (4 * a * c);
            if (discr < 0){
                printf("no valid solutions, D < 0\n");
            }
            else if (discr == 0){
                double res = -b / (double)(2 * a);
                printf("D = 0, x = %.2f\n", res);
            }
            else{
                double x1 = (-b + sqrt(discr)) / (double)(2 * a), x2 = (-b - sqrt(discr)) / (double)(2 * a);
                printf("2 solutions of ax^2 + bx + c = 0; x1 = %.2f, x2 = %.2f\n", x1, x2);
            };
        };
    };
    return 0;
}