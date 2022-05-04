/**
 * @file parser.c
 * @brief Atribui tipos aos tokens e decide a operação
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <stdio.h>

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handleG1 (STACK *s, char *token)
{
    if (notBit (s, token) || xorBit (s, token) || orBit (s, token) || andBit (s, token) || modulo (s, token) || divisao (s, token) || multiplicacao (s, token) || exponencializacao (s, token) || incrementar (s, token) || decrementar (s, token) || add (s, token) || sub (s, token)) return 1;
    else return 0;
}

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handleG2 (STACK *s, char *token)
{
    if (intParaChar (s, token) || troca2Topo (s, token) || copiaNesimo (s, token) || popG2 (s, token) || duplicar (s, token) || rodar3 (s, token)) return 1;
    else return 0;
}

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handleG3 (STACK *s, char *token)
{
    if (capB (s, token) || capA (s, token) || menorDosDois (s, token) || maiorDosDois (s, token) || menor (s, token) || maior (s, token) || nao (s, token) || ouShortcut (s, token) || eShortcut (s, token) || buscaPorIndice (s, token) || IfThenElse (s, token)) return 1;
    else return 0;
}

int handleG4 (STACK *s, char *token)
{
    if (range (s, token)) return 1;
    else return 0;
}

//! Funcao handle principal
int mainHandle (STACK *s, char *token)
{
    if (handleG3 (s, token) || handleG2 (s, token) || handleG1 (s, token) || handleG4 (s, token)) return 1;
    else return 0;
}

void parser (STACK *s, char *token)
{
    char *sobra;

    long val_i = strtol (token, &sobra, 10);
    if (strlen (sobra) == 0)
    {
        DATA p = cria_Long (val_i);
        push (s, p);
    }

    else
    {
        double val_d = strtod (token, &sobra);
        if (strlen (sobra) == 0)
        {
            DATA p = cria_Double (val_d);
            push (s, p);
        }

        else 
        {
            if ((strstr("+-*/()%#&|^~e&e|_;\\@$clifts<>=!?e<e>,", token) != NULL)) mainHandle(s, token);
        }
    }
} 
