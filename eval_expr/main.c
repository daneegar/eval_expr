//
//  main.c
//  eval_expr
//
//  Created by Denis Garifyanov on 16/03/2019.
//  Copyright © 2019 Denis Garifyanov. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>

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
    printf("If 0 is coorect: %i\n", is_correct_nested(argv[1]));
    return 0;
}
