//
//  main.c
//  eval_expr
//
//  Created by Denis Garifyanov on 16/03/2019.
//  Copyright © 2019 Denis Garifyanov. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int        ft_atoi(char *str, int *end)
{
    int i;
    int nbr;
    int negative;
    
    nbr = 0;
    negative = 0;
    i = 0;
    while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
           (str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
        i++;
    if (str[i] == '-')
        negative = 1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
    {
        nbr *= 10;
        nbr += (int)str[i] - '0';
        i++;
    }
    *end = i;
    if (negative == 1)
        return (-nbr);
    else
        return (nbr);
}

int mult(int a, int b)
{
    return (a * b);
}

int modulo(int a, int b)
{
    return (a % b);
}

int dev(int a, int b)
{
    return (a / b);
}

int minus(int a, int b)
{
    return (a - b);
}

int sum(int a, int b)
{
    return (a + b);
}

int try_to_solve(char *exp)
{
    int i;
    //int operands[2];
    //int (*action)(int,int);
    printf("%s\n",exp);
    char *sub_exp;
    int j = 0;
    int k = 0;
    i = 0;
    while(exp[i] != '\0')
    {
          if (exp[i] == '(')
          {
              k = i;
              sub_exp = malloc(sizeof(char) * i);
              while (exp[++k] != '\0')
                  sub_exp[j++] = exp[k];
              return i + (try_to_solve(sub_exp));
          }
        i++;
    }
    return i;
}

int     is_correct_nested(char *exp)
{
    int is_correct_if_zero;
    int inc;

    inc = -1;
    is_correct_if_zero = 0;
    while(exp[++inc] != '\0')
    {
        if (exp[inc] == '(')
            is_correct_if_zero++;
        else if (exp[inc] == ')')
            is_correct_if_zero--;
    }
    return (is_correct_if_zero);
}


void ft_putchar(char c)
{
    write (1,&c, 1);
}

int main(int argc, char **argv) {
    
    int i = -1;
    while (argv[1][++i] != '\0')
        printf("%c", argv[1][i]);
    ft_putchar('\n');
    printf("resolve: %i\n", 3 + (42 * (1 - (2 / 7) - (1 % 21))) + 1);
    int a = 2/7;
    printf("2/7: %i\n", a);
    int b = 1 % 21;
    printf("If 1 mod 21: %i\n", b);
    int c = 1 - a;
    printf("1 - 2/7: %i\n", c);
    int d = c - b;
    printf("1 - 2/7 - 1 mod 21: %i\n", d);
    int e = d+1;
    printf("1 - 2/7 - 1 mod 21 + 1 : %i\n", e);
    int f = 42 * e;
    printf("42 * 1 - 2/7 -1 mod 21 + 1 : %i\n", f);
    int g = 3 +f;
    printf("If 0 is coorect: %i\n", g);
    
    printf("i=%i\n", try_to_solve(argv[1]));
    
    return 0;
}
