#include <string.h>
#include <stdio.h>

void preencherMatriz(char mat[10][10]){
    int i,j;

    for(i = 0 ;i<10;i++){
        for(j = 0;j < 10;j++){
            mat[i][j] = rand()%('z' - 'A' + 1)+ 'A';
        }
    }
}

void palavraNaMatriz(char mat[10][10],char palavra[9],int L,int C,int tamanho,int primeiraLetra[2],int ultimaLetra[2]){
    int i = 0;
     if((C + tamanho) < 9)
    {
        primeiraLetra[0] = L;
        primeiraLetra[1] = C;
        while(palavra[i] !='\0')
        {
            mat[L][C] = palavra[i];
            C++;
            i++;
            ultimaLetra[0]=L;
            ultimaLetra[1] =C;

        }
    }
    else
    {
        primeiraLetra[0] = L;
        primeiraLetra[1] = C;
        while(palavra[i] !='\0')
        {
            mat[L][C] = palavra[i];
            L++;
            i++;
            ultimaLetra[0]=L;
            ultimaLetra[1] =C;
        }

    }
}


