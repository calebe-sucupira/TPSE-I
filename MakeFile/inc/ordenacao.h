#ifndef ORDENACAO_H
#define ORDENACAO_H

// >> Interativos.
// Bubble Sort - ordenação crescente.
void bubbleSort(int v[], int n);
// Insertion Sort - ordenação crescente.
void insertionSort(int* v, int n);
// Selection Sort - ordenação crescente.
void selectionSort(int* v, int n);
// Função intercala para merger sort interativo e recursivo.
void merge(int* v, int p, int q, int r);
//Função auxiliar para Mergesort interativo.
int min(int x, int y);
// Merge Sort - ordenação crescente.
void mergeSortInterativo(int v[], int n);


//->Ordenação imapres e pares Interativo.

// Bubblesort - ordenação impares crescente e pares decrescente.
void bubbleSortImparPar(int v[], int n);
// Insertion Sort - ordenação impares crescente e pares decrescente.
void insertionSortImparPar(int* v, int n);
// Selection Sort - ordenação impares crescente e pares decrescente.
void selectionSortImparPar(int* v, int n);
// Funcão intercala para o MergeSortImparPar recursivo e interativo;.
void mergeImparPar(int* v, int p, int q, int r);
// Merge Sorte interativo - ordenação impares crescente e pares decrescente.
void mergeSortInterativoImparPar(int v[], int n);


// >> Recursivos.

// Bubble Sort rescutivo - ordenação crescente.
void bubbleSortRecursivo(int* v, int n);
// Insertion Sort rescutivo - ordenação crescente.
void insertionSortRecursivo(int* v, int n);
// Selection Sort rescutivo - ordenação crescente.
void selectionSortRecursivo(int v[], int ini, int fim);
// Merge Sort rescutivo - ordenação crescente.
void mergeSort(int* v, int p, int r);
// Função auxiliar quick sort.
int separa(int* v, int p, int r);
// Quick Sort rescutivo - ordenação crescente.
void quickSort(int* v, int p, int r);


//->Ordenação imapres e pares Recursivo.

// Bubblesort recursivo - ordenação impares crescente e pares decrescente.
void bubbleSortRecursivoImparPar(int* v, int n);
// Insertionsort recursivo - ordenação impares crescente e pares decrescente.
void insertionSortRecursivoImparPar(int* v, int n);
// Selectionsort recursivo - ordenação impares crescente e pares decrescente.
void selectionSortRecursivoImparPar(int v[], int ini, int fim);
// Merge Sort - ordenação impares crescente e pares decrescente.
void mergeSortImparPar(int* v, int p, int r);
// Funcão auxliar para o QuickSortImparpar.
int separaImparPar(int* v, int p, int r);
// QuickSort - ordenação impares crescente e pares decrescente.
void quickSortImaparPar(int* v, int p, int r);

// Parte 2 do trabalho:

struct aluno{
    char nome[25];
    int matricula;
};

//Função troca para o vetor de estrutura
void troca(aluno *a, aluno *b);
//Lê os dados dos alunos. n é quantidade de alunos a ser lidos.
aluno* cinAluno(aluno* alunos, int numAlunos);
//Imprime os dados dos alunos.
void coutAluno(aluno *alunos, int numAlunos);
//Ordena o vetor de estruta em ordem alfabetica: Selection Sort
void ordenaNome(aluno *alunos, int numAlunos);
//Ordena o vetor de estrura pela matricula: Selection Sort
void ordenaMatricula(aluno *alunos, int numAlunos);
// Outras funções.

//Gerar vetor aleatório.
void randomVector(int* v, int n);

//Imprime Vetor
void coutVetor(int* v, int n);

void menu();

#endif
