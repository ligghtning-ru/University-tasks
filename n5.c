#include <stdio.h>
#include <math.h>

int main(){
    double x, res;
    printf("Enter x:\n");
    scanf("%lf", &x);
    if (x < 0.2){
        res = exp(x) + tan(x) + 0.1;
    }
    else if (x > 0.8){
        res = (pow(x, 2))/(double)(1 + cbrt(x));
    }
    else if (x >= 0.2 && x <= 0.8){
        res = cbrt(pow(x, 3) + 0.515);
    }

    printf("res for some case, res = %lf", res);
    
    return 0;
}