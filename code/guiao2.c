/**
 * @file guiao2.c
 * @brief Operacoes do guiao 2
 * 
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//! Converte o topo da stack para DOUBLE
int convertParaDouble (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "f") == 0)
    {
        DATA x = pop (s);

        if (x.tipo == LONG)
        {
            push (s, cria_Double (x.elem.d));
            r = 1;
        }

        if (x.tipo == DOUBLE)
        {
            push (s, x);
            r = 1; 
        }

        if (x.tipo == CHAR)
        {
            push (s, cria_Double (x.elem.c));
            r = 1; 
        }

        if (x.tipo == STRING)
        {
            push (s, cria_Double (atof (x.elem.str)));
            r = 1;
        }
    }
    return r;
}

//! COnverte o topo da stack para INTEIRO
int convertParaInt (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "i") == 0)
    {
        DATA x = pop (s);

        if (x.tipo == LONG)
        {
            push (s, x);
            r = 1;
        }

        if (x.tipo == DOUBLE)
        {
            push (s, cria_Long (x.elem.d));
            r = 1;
        }

        if (x.tipo == CHAR)
        {
            push (s, cria_Long (x.elem.c));
            r = 1;
        }

        if (x.tipo == STRING)
        {
            push (s, cria_Long (atof (x.elem.str)));
            r = 1;
        }
    }
    return r;
} 

//! Ler linha
int lerLinha (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "l") == 0)
    {
        char *a1 = malloc (10240 * sizeof(char));
        assert (fgets(a1, 10240, stdin) != NULL);
        int x = strlen(a1);
        char *a2 = malloc ((x+1) * sizeof(char));
        strcpy(a2,a1);
        push (s, cria_string (a2));
        free(a1);
        r = 1;
    }
    return r;
}

//! Transforma o numero no topo da stack num char 
/*!
 * input: 79 c 108 c 97 c \n
 * output: Ola
 */
int intParaChar (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "c")==0)
    {
        DATA x = pop (s);
        if (x.tipo == LONG)
        {
            DATA w = cria_Char (x.elem.l);
            push (s, w);
            r = 1;
        }
    }
    return r;
}

//! Trocar os dois elementos do topo da stack
/*!
 * input: 1 2 3 \ \n
 * output: 132
 */
int troca2Topo (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "\\")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        push (s, x);
        push (s, y);
        r = 1;   
    }
    return r;
}

//! Copia n-ésimo elemento para o topo da stack (0 e o topo da stack)
/*!
 * input: 7 2 3 2 $ (n = 2) \n
 * output: 7237
 */
int copiaNesimo (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "$")==0)
    {
        DATA n = pop (s);
        int x = n.elem.l;
        DATA y = s -> stack[s -> sp - x];
        push (s, y);
        r = 1;
    }
    return r;
}

//! Realiza a operacao pop
/*!
 * input: 1 2 3 ; \n
 * output: 12
 */
int popG2 (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, ";")==0)
    {
        pop (s);
        r = 1;
    }
    return r;
}

//! Duplica um numero e coloca-o no topo da stack
/*!
 * input: 2 _ \n
 * output: 22
 * 
 * input: 1 2 _ \n
 * output: 122 
 */
int duplicar (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "_")==0)
    {
        DATA x = pop (s);
        push (s, x);
        push (s, x);
        r = 1;
    }
    return r;
}

//! roda os 3 elementos no topo da stack
/*!
 *  input: 1 2 3 @ \n
 *  output: 231
 */
int rodar3 (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "@")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        DATA z = pop (s);
        push (s, y);
        push (s, x);
        push (s, z);
        r = 1;
    }
    return r;
}