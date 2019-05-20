#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Functions.c"
int main()
{
    setlocale(LC_ALL,"");
    char mat[10][10];
    char palavra[9];

    int primeiraLetra[2];
    int ultimaLetra[2];
    int i,j,inicioL,inicioC,fimL,fimC;;
    int horizontal = 0;
    int vertical = 0;
    srand(time(0));

    printf("digite sua palavra: ");
    gets(palavra);
    while(strlen(palavra) >=9)
    {
        printf("palavra muito grande, maximo de 9 caracteres\n");
        printf("digite sua palavra: ");
        gets(palavra);
    }

    int tamanho = strlen(palavra);
    //Jogo comeca aqui.
    preencherMatriz(mat);

    int L = rand()%(9 - 0 +1)+0;
    int C = rand()%(9 - 0 +1)+0;
    while(L > 0 && (L + tamanho > 9) || C > 0 && (C+tamanho) >9 )
    {
        L = rand()%(9 - 0 +1)+0;
        C = rand()%(9 - 0 +1)+0;
    }

    i = 0;
    palavraNaMatriz(mat,palavra,L,C,tamanho,primeiraLetra,ultimaLetra);


    printf("Primeira Letra L:%d C:%d, ultima Letra L:%d C:%d",primeiraLetra[0],primeiraLetra[1],ultimaLetra[0],ultimaLetra[1]);

    //teste de orientação
    if(primeiraLetra[0] < ultimaLetra[0]){
        vertical = 1;
    }
    else{
        horizontal = 1;
    }

    //imprimir matriz.
    for(i = 0; i < 10; i++)
    {
        printf("\t");
        printf("\n");
        for(j = 0; j < 10; j++)
        {
            printf("%c ",mat[i][j]);

        }

    }
//teste da posição.
printf("\n");
   procurarPalavra(inicioL,inicioC,fimL,fimC);


    return 0;
}
