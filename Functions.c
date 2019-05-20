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
void procurarPalavra(int iL,int iC,int fL,int fC){
    //teste da posição.
   printf("Onde esta sua palavra?\n");
   printf("ela inicia em qual linha, e em qual coluna?:\n  ");
   printf("você deve colocar os colchetes, ex: [ x,y ]: ");
   scanf("[%d,%d]",&iL,&iC);
   printf("%d ,%d",iL,iC);//retirar depois.
   printf("\ne em qual linha, e em qual coluna ela termina?:\n  ");
   printf("você deve colocar os colchetes, ex: [ x,y ]: ");
   fflush(stdin);
   scanf("[%d,%d]",&fL,&fC);
   printf("%d ,%d",fL,fC);//retirar depois.
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


