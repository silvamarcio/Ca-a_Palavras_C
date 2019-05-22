#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Functions2.c"
int main()
{
    setlocale(LC_ALL,"");
    char mat[10][10];
    char palavra[10];
    char opcao;
    int jogar = 0;

    int tentativas = 0;
    int primeiraLetra[2];
    int ultimaLetra[2];
    int i,j;
    int inicioL= 0;
    int inicioC,fimL,fimC = 0;
    int horizontal = 0;
    int vertical = 0;
    srand(time(0));


    printf("digite sua palavra: ");
    gets(palavra);
    while(strlen(palavra) >=10)
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
 int acertou = 0;
 while(acertou == 0){
   printf("\nOnde esta sua palavra?\n");
   printf("ela inicia em qual linha, e em qual coluna?:\n  ");
   printf("você deve separar os valores por espaco ex:  x y : ");
   scanf("%d %d",&inicioL,&inicioC);

   printf("\ne em qual linha, e em qual coluna ela termina?:\n  ");
   printf("você deve separar os valores por espaco ex:  x y : ");
   scanf("%d %d",&fimL,&fimC);


   tentativas++;

   if(inicioL == primeiraLetra[0] && inicioC == primeiraLetra[1]
      && fimL == ultimaLetra[0] && fimC == ultimaLetra[1]){
        acertou = 1;
        printf("acertou\n");
        printf("Numero de tantativas: %d",tentativas);
        printf("\nJogar novamente? (1 = sim / 0 = não): ");
        scanf("%d",&jogar);

   }
   else{
        fflush(stdin);
        printf("Você errou!!\n");
        printf("Continuar ou Sair( C/S): ");
        scanf("%c",&opcao);
        if(opcao =='s' || opcao == 'S'){
            printf("Desistiu com %d tentativas",tentativas);
            acertou = 1;
        }

     }
   }

    return 0;
 }





