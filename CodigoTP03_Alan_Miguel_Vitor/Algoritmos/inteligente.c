#include <stdio.h>

void Particao_EInteligente(long int Esq, long int Dir,long int *i, long int *j, long int A[], long int B[]){
 long int pivo, aux;
 *i = Esq; *j = Dir;
 
 pivo = A[(*i + *j)/2]; 
 do
 {
     B[1]++;
 while (pivo > A[*i]){
     (*i)++; 
     B[1]++;   
 } 
 B[1]++;
 while (pivo < A[*j]){
     (*j)--; 
     B[1]++;
 }
 
 if (*i <= *j)
 { 
 aux = A[*i]; 
 A[*i] = A[*j]; 
 A[*j] = aux;
 (*i)++; (*j)--;
 B[2] ++;
 }
 } while (*i <= *j);
}


void Ordena_EInteligente(long int Esq, long int Dir, long int A[],long  int B[])
{
    long int i, j;
    Particao_EInteligente(Esq, Dir, &i, &j, A, B);
    if(Esq < j) //verifica a partição
    {
        if (i >= Dir) Ordena_EInteligente(Esq, j, A, B);
        else if((j + 1) - Esq <= (Dir + 1) - i)
        {
            Ordena_EInteligente(Esq, j, A, B);
            if (i < Dir) Ordena_EInteligente(i, Dir, A, B);
        }
        else if(i < Dir)
        {
          Ordena_EInteligente(i, Dir, A, B);
          Ordena_EInteligente(Esq, j, A, B);
        }
    }
    else if (i < Dir) Ordena_EInteligente(i, Dir, A, B);
}


void QuickSort_EInteligente(long int A[], long int n,long int B[])
{
 Ordena_EInteligente(0, n-1, A, B);
}
