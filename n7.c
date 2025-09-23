#include <stdio.h>
#include <math.h>

int main(){
    int k;
    double epsilon, range_sum, range_sum_k;

    printf("Enter k and epsilon\n");
    scanf("%d", &k);
    scanf("%lf", &epsilon);

    range_sum_k = (pow(-1, k))/(k * (pow(k, 2) + 0.25));

    while ((fabs(range_sum_k)) > epsilon){
    range_sum_k = (pow(-1, k))/(double)(k * (pow(k, 2) + 0.25));
    range_sum += range_sum_k;
    k++;
    };
    
    printf("k = %d, range_sum = %.3f", k, range_sum);
}