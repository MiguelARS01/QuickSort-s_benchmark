#include <stdio.h>

void Particao_Recursivo(long int Esq, long int Dir,long int *i, long int *j, long int A[]){
 long int pivo, aux;
 *i = Esq; *j = Dir;
 
 pivo = A[(*i + *j)/2]; /* obtem o pivo x */
 do
 {
     
 while (pivo > A[*i]){
     (*i)++; 
        
 } 
 
 while (pivo < A[*j]){
     (*j)--; 
     
 }
 
 if (*i <= *j)
 { 
 aux = A[*i]; 
 A[*i] = A[*j]; 
 A[*j] = aux;
 (*i)++; (*j)--;

 }
 } while (*i <= *j);
}


void Ordena_Recursivo(long int Esq, long int Dir, long int A[])
{
    long int i, j;
 Particao_Recursivo(Esq, Dir, &i, &j, A);
 if (Esq < j) Ordena_Recursivo(Esq, j, A);
 if (i < Dir) Ordena_Recursivo(i, Dir, A);
}

void QuickSort_Recursivo(long int A[], long int n)
{
    
 Ordena_Recursivo(0, n-1, A);
 
}
int main()
{
    long int v[] = {1,1,1,1,1};
    long int n = 5;
    QuickSort_Recursivo(v, n);
    for(int i = 0; i<n; i++) printf("%d", v[i]);
}