#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Particao_Mediana(long int Esq, long int Dir,long int *i, long int *j, long int A[], int k, long int n,long int B[]){
    
    long int num, aux, pivo;
    long int *vet_median; //declara o vetor
    vet_median = (long int *) malloc(sizeof(long int) * k); //aloca dinamicamente
    *i = Esq; *j = Dir;
    for(long int c=0; c<k; c++){
        num = (rand() % (Dir - Esq + 1)) + Esq ; //gera os elementos aleatórios de A
        vet_median[c] = A[num];
    }
    for(long int p=1; p<k; p++){ //ordena o vet_median
        aux = vet_median[p];
        long int h = p-1;
        
        while((h >= 0) && (aux < vet_median[h])){
            vet_median[h+1] = vet_median[h];
            h--;
        }
    vet_median[h+1]  = aux;
    }
    long int f = (k / 2); //calcula a mediana
    pivo = vet_median[f]; //escolhe o pivô
    do
    {   
        B[1] ++;
         while (pivo > A[*i]) {
             (*i)++;
             B[1] ++;}
        B[1] ++;
        while (pivo < A[*j]) {
            (*j)--;
            B[1]++;
            }
        if (*i <= *j)
    {
        aux = A[*i]; A[*i] = A[*j]; A[*j] = aux;
        (*i)++; (*j)--;
        B[2] ++;
    }
    } while (*i <= *j);
}


void Ordena_Mediana(long int Esq, long int Dir, long int A[],int k, long int n,long int B[])
{
long int i,j;
 Particao_Mediana(Esq, Dir, &i, &j, A, k, n, B);
 if (Esq < j) Ordena_Mediana(Esq, j, A, k,n, B);
 if (i < Dir) Ordena_Mediana(i, Dir, A, k,n, B);
}


void QuickSort_Mediana(long int A[], long int n, long int k, long int B[])
{
 Ordena_Mediana(0, n-1, A, k, n, B);
 
}