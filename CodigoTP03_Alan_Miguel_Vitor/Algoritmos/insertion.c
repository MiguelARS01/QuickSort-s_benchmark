#include <stdio.h>

void Insertion_Sort(long int A[], long int Esq, long int n, long int B[]){
    long int aux, j;
    
    
    for(long int i = Esq+1; i < n+1; i++){
        aux = A[i];
        j = i;
        B[1] ++;
        while((j>Esq) && (A[j-1]>aux)){
            A[j] = A[j-1];
            j--;
            B[1] ++;
        }
        A[j] = aux;
        B[2] ++;
    }
}

void Particao_Insertion(long int Esq, long int Dir,long int *i, long int *j, long int A[],  long int B[]){
 long int pivo, aux;
 *i = Esq; *j = Dir;
 
 pivo = A[(*i + *j)/2]; 
 do
 {
     B[1] ++;
 while (pivo > A[*i]) {
     (*i)++;
     B[1] ++;
 }
 B[1] ++;
 while (pivo < A[*j]) {
     (*j)--;
     B[1] ++;
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

 
void Ordena_Insertion(long int Esq, long int Dir,long int A[], long int m,  long int B[])
{
    long int i,j;
    if (Dir-Esq  +1<= m) Insertion_Sort(A, Esq, Dir, B); //executa o insertion sort
    else  //executa o recursive Quick Sort
    { 
        Particao_Insertion(Esq, Dir, &i, &j, A,B);
        if (Esq < j) Ordena_Insertion(Esq, j, A, m,B);
        if (i < Dir) Ordena_Insertion(i, Dir, A,m, B);
     }
     
 
}
void QuickSort_Insercao(long int A[], long int n, long int m, long int B[])
{
    Ordena_Insertion(0, n-1, A,  m, B);
}