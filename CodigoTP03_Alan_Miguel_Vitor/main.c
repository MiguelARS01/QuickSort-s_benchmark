#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Algoritmos\recursivo.h"
#include "Algoritmos\mediana.h"
#include "Algoritmos\iterativo.h"
#include "Algoritmos\inteligente.h"
#include "Algoritmos\insertion.h"


int main( int argc, char *argv[ ] ){
    FILE *arq;
    int seed = *argv[1] - '0'; //pega a semente passada
    // srand(seed);
    arq = fopen(argv[2], "w"); //pega o nome do arquivo passado
    if(arq == NULL)
    {
    printf("Erro na abertura do arquivo!"); //verifica
    return 1;
    }
    printf("\nArquivo '%s' aberto com suceeso!", argv[2]);
    fprintf(arq,"Semente %d\n\n", seed); //escreve o valor da semente no arquivo

    long int B[3]; B[0] = 0; B[1] = 0; B[2] = 0; //tupla (tempo, movimentaçoes, copias)
    long int valores[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000}; //valores de n
    long int* A; //vetor aleatório
    long int n = 0;
    int k = 0, m = 0; //usados nos algoritmos mediana e inserção
    clock_t start;
    clock_t end;
    
    puts("\n");
    fprintf(arq, "Valor de N\t|| Recursivo\t\t\t\t|| Mediana(k=3)\t\t\t\t|| Mediana(k=5)\t\t\t\t|| Insercao(m=10)\t\t\t|| Insercao(m=100)\t\t\t|| E.Inteligente\t\t\t|| Iterativo\t\t\t\t||\n");
    printf("Analisando algoritmos");


    for(int c = 0; c < 7; c++) //analisa os algoritmos QuickSort
    {   
        //QuickSort Recursivo
        printf(".");
        srand(seed);
        B[3]; B[0] = 0; B[1] = 0; B[2] = 0; //tupla (tempo, movimentaçoes, copias)
        n = valores[c]; //pega o valor de n
        fprintf(arq, "\n\n");
        fprintf(arq, "%d\t\t", n); //ecreve o valor de n no arquivo
        A = (long int*)malloc(n * sizeof(long int)); //aloca o vetor
        srand(seed); //pega a semente
        start = clock(); //inicia a contagem de tempo
        for (long int i = 0; i < n; i++) A[i] = rand() % (n + 1 - 0) + 0; //vetor  de numeros aleatório
        QuickSort_Recursivo(A, n, B); //executa o algoritmo e analisa
        end = clock(); //finaliza a contagem de tempo
        double time_spent = (double)(end - start) / (CLOCKS_PER_SEC/1000); //calcula o tempo em ms
        B[0] = time_spent; 
        fprintf(arq, "|| (%d,%d,%d)", B[0], B[1] ,B[2]);//escreve no arquivo a tupla
        if (c < 3) fprintf(arq, "\t\t\t");
        else if (c > 4) fprintf(arq, "\t");
        else fprintf (arq, "\t\t");
    

        /* A partir daqui é os mesmos passos anteriores,
        só o algoritmo que muda*/

        //QuickSort Mediana(k=3)
        srand(seed);
        k = 3; //mediana de k elementos
        B[0] = 0; B[1] = 0; B[2] = 0;
        start = clock();
        for (long int i = 0; i < n; i++) A[i] = rand() % (n + 1 - 0) + 0;
        QuickSort_Mediana(A, n, k, B);
        end = clock();
        time_spent = (double)(end - start) / (CLOCKS_PER_SEC/1000);
        B[0] = time_spent;
        fprintf(arq, "|| (%d,%d,%d)", B[0], B[1] ,B[2]);
        if (c < 3) fprintf(arq, "\t\t\t");
        else if (c > 4) fprintf(arq, "\t");
        else fprintf (arq, "\t\t");

        //QuickSort Mediana(k=5)
        srand(seed);
        k = 5;
        B[0] = 0; B[1] = 0; B[2] = 0;
        start = clock();
        for (long int i = 0; i < n; i++) A[i] = rand() % (n + 1 - 0) + 0;
        QuickSort_Mediana(A, n, k, B);
        end = clock();
        time_spent = (double)(end - start) / (CLOCKS_PER_SEC/1000);
        B[0] = time_spent;
        fprintf(arq, "|| (%d,%d,%d)", B[0], B[1] ,B[2]);
        if (c < 3) fprintf(arq, "\t\t\t");
        else if (c > 4) fprintf(arq, "\t");
        else fprintf (arq, "\t\t");


        //QuickSort Inserção(m=10)
        srand(seed);
        m = 10;
        B[0] = 0; B[1] = 0; B[2] = 0;
        start = clock();
        for (long int i = 0; i < n; i++) A[i] = rand() % (n + 1 - 0) + 0;
        QuickSort_Insercao(A, n, m, B);
        end = clock();
        time_spent = (double)(end - start) / (CLOCKS_PER_SEC/1000);
        B[0] = time_spent;
        fprintf(arq, "|| (%d,%d,%d)", B[0], B[1] ,B[2]);
        if (c < 3) fprintf(arq, "\t\t\t");
        else if (c > 4) fprintf(arq, "\t");
        else fprintf (arq, "\t\t");

        //QuickSort Inserção(m=100)
        srand(seed);
        m = 100;
        B[0] = 0; B[1] = 0; B[2] = 0;
        start = clock();
        for (long int i = 0; i < n; i++) A[i] = rand() % (n + 1 - 0) + 0;
        QuickSort_Insercao(A, n, m, B);
        end = clock();
        time_spent = (double)(end - start) / (CLOCKS_PER_SEC/1000);
        B[0] = time_spent;
        fprintf(arq, "|| (%d,%d,%d)", B[0], B[1] ,B[2]);
        if (c < 3) fprintf(arq, "\t\t\t");
        else if (c > 4) fprintf(arq, "\t");
        else fprintf (arq, "\t\t");
        

        //QuickSort Empilha Inteligente
        srand(seed);
        B[0] = 0; B[1] = 0; B[2] = 0;
        start = clock();
        for (long int i = 0; i < n; i++) A[i] = rand() % (n + 1 - 0) + 0;
        QuickSort_EInteligente(A, n,  B);
        end = clock();
        time_spent = (double)(end - start) / (CLOCKS_PER_SEC/1000);
        B[0] = time_spent;
        fprintf(arq, "|| (%d,%d,%d)", B[0], B[1] ,B[2]);
        if (c < 3) fprintf(arq, "\t\t\t");
        else if (c > 4) fprintf(arq, "\t");
        else fprintf (arq, "\t\t");

        //QuickSort Iterativo
        srand(seed);
        B[0] = 0; B[1] = 0; B[2] = 0;
        start = clock();
        for (long int i = 0; i < n; i++) A[i] = rand() % (n + 1 - 0) + 0;
        QuickSort_Iterativo(A, n,  B);
        end = clock();
        time_spent = (double)(end - start) / (CLOCKS_PER_SEC/1000);
        B[0] = time_spent;
        fprintf(arq, "|| (%d,%d,%d)", B[0], B[1] ,B[2]);
        if (c < 3) fprintf(arq, "\t\t\t||");
        else if (c > 4) fprintf(arq, "\t||");
        else fprintf (arq, "\t\t||");

    }
    puts("\nAnalise concluida, pressione ENTER para continuar.");
    getchar();
    fclose(arq); //fecha o arquivo
    return(0);
}