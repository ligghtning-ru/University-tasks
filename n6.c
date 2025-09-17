#include <stdio.h>
#include <math.h>
#include <stdbool.h>


bool ortangle(double hyp, double cat1, double cat2){
    double value = pow(hyp, 2) - pow(cat1, 2) - pow(cat2, 2);
    if (value >= 0 && value <= pow(10, -6)){
        return true;
    }
    else{
        return false;
    };
}

int indicate_triangle(bool param1, bool param2, bool param3){
    if (param1 && param2){
        return 1;
    }
    else if (param3){
        return 2;
    }
    else if (param2){
        return 3;
    }
    else if (param1){
        return 4;
    }
}

double find_max(double a, double b, double c){
    if (a > b && a > c){
        return a;
    }
    else if (b > a && b > c){
        return b;
    }
    else{
        return c;
    };
}


int main(){
    double a, b, c;
    bool is_ortangle = false, is_isosceles = false, is_equilateral = false;

    
    printf("Enter 3 sides of triangle:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    if ((a + b > c) && (a + c > b) && (b + c > a)){
        if (a == b && a == c && b == c){
            is_equilateral = true; 
        }
        else if ((a == b) || (a == c) || (b == c)){
            is_isosceles = true;
        }
        double max_side = find_max(a, b, c), cathetus1, cathetus2;

        if (max_side != a && max_side != b){
            cathetus1 = a;
            cathetus2 = b;
        }
        else if(max_side != c && max_side != a){
            cathetus1 = c;
            cathetus2 = a;
        }
        else if(max_side != b && max_side != c){
            cathetus1 = b;
            cathetus2 = c;
        }
        is_ortangle = ortangle(max_side, cathetus1, cathetus2);
        short what_triangle = indicate_triangle(is_ortangle, is_isosceles, is_equilateral);

        if (what_triangle == 1){
            printf("Triangle is ortangle and isosceles");
        }
        else if (what_triangle == 2){
            printf("Triangle is equilateral");
        }
        else if (what_triangle == 3){
            printf("Triangle is isosceles");
        }
        else if (what_triangle == 4){
            printf("Triangle is ortangle");
        }
        else{
            printf("Triangle not ortangle, isosceles or equilateral");
        };
    }

    else{
        printf("Triangle with sides: %.3f, %.3f, %.3f does not exist", a, b, c);
    };
    return 0;
}