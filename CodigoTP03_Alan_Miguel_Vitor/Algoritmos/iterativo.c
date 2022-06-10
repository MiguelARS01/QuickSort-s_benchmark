#include <stdio.h>
#include <stdlib.h>

void Particao_Iterativo(long int A[], long int Esq, long int Dir,long int *i, long int *j,  long int B[])
{
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
     B[1]++;
 }
 if (*i <= *j)
 {
 aux = A[*i]; A[*i] = A[*j]; A[*j] = aux;
 (*i)++; (*j)--;
 B[2]++;
 }
 } while (*i <= *j);

}
void Ordena_Iterativo(long int A[], long int Esq, long int Dir, long int B[])
{
    long int i, j;
    long int* pilha; //usa uma pilha para ordenar os elementos
    pilha = (long int*) malloc (Dir - Esq + 1 * sizeof(long int)); //aloca a pilha
    long int topo_pilha= -1; //define topo_pilha = -1
    pilha[++topo_pilha] = Esq;//++topo_pilha recebe esq e dir
    pilha[++topo_pilha] = Dir;
    while (topo_pilha >= 0) { //enquanto o topo pilha não for 0, ele executa a função partição, ordenando
        Dir = pilha[topo_pilha--]; 
        Esq = pilha[topo_pilha--];
        Particao_Iterativo(A, Esq, Dir, &i, &j, B);
        if (j > Esq) {
            pilha[++topo_pilha] = Esq; //aqui é onde ele "itera" e ordena
            pilha[++topo_pilha] = j;
        }
        if (i < Dir) {
            pilha[++topo_pilha] = i;
            pilha[++topo_pilha] = Dir;
        }
    }
}
void QuickSort_Iterativo(long int A[], long int n, long int B[])
{
    Ordena_Iterativo(A, 0, n-1, B);

}