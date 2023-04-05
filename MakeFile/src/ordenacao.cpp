#include <iostream>
#include <time.h>
#include<cstdlib>
#include <bits/stdc++.h>
#include "../inc/ordenacao.h"
using namespace std;


// >> Interativos.

// Bubble Sort - ordenação crescente.
void bubbleSort(int v[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1; j > i; j--){
            if(v[j] < v[j - 1]){
                swap(v[j], v[j - 1]);
            }
        } 
    }
}

// Insertion Sort - ordenação crescente.
void insertionSort(int* v, int n){
    int j, key;
    for(int i = 1; i < n; i++){
        key = v[i];
        j =  i -1;
        while(j >= 0 && v[j] > key){

            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

// Selection Sort - ordenação crescente.
void selectionSort(int* v, int n){
    int comparacoes = 0;
    for(int i = 0; i < n - 1; i++){
        int indexMin = i;
        for(int j = i+1; j < n; j++){
            comparacoes++;
            if(v[j] < v[indexMin]){
                indexMin = j;
            }
        }
        swap(v[i], v[indexMin]);
    }
}

// Função intercala para merger sort interativo e recursivo.
void merge(int* v, int p, int q, int r){
    int* w = new int[r-p+1];
    int i = p;
    int j = q+1;
    int k = 0;

    while(i <= q && j<=r){
        if(v[i] < v[j]){
            w[k] = v[i];
            k++;
            i++;
        }else{
            w[k] = v[j];
            k++;
            j++;
        }
    }

    while(i <= q){
        w[k] = v[i];
        k++;
        i++;
    }

    while(j<=r){
        w[k] = v[j];
        k++;
        j++;
    }

    for(int i = p; i <= r; i++){
        v[i] = w[i-p];
    }

    delete w;
}

//Função auxiliar para Mergesort interativo.
int min(int x, int y){ 
    if(x<y) return x;
    return y;
}

//Merge Sort Interativo;
void mergeSortInterativo(int v[], int n){
    for(int b = 1; b < n; b *= 2){
        for(int p = 0; p < n - 1; p += 2 * b){
            int q = min(p + b - 1, n -1);
            int r = min(p + 2 * b - 1, n - 1);
           merge(v, p, q, r);
        }
    }

}


//->Ordenação imapres e pares Interativo.

// Bubblesort - ordenação impares crescente e pares decrescente.
void bubbleSortImparPar(int v[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = n-1; j >i; j--){
            if(v[j] % 2 == 0 && v[j-1] % 2 == 0){
                if(v[j] > v[j-1]){
                    swap(v[j], v[j-1]);
                }
            }
            else if(v[j] % 2 != 0 && v[j-1] % 2 ==0){
                swap(v[j], v[j-1]);
            }
            else if(v[j] % 2 != 0 && v[j-1] % 2 != 0){
                if(v[j] < v[j-1]){
                    swap(v[j], v[j-1]);
                }
            }
        } 
    }
}

// Insertion Sort - ordenação impares crescente e pares decrescente.
void insertionSortImparPar(int* v, int n){
    int j, key;                             
    for(int i = 1; i < n; i++){             
        key = v[i];                         
        j =  i -1;                           
        while(j >= 0){                       
            if(key % 2 != 0 && v[j] % 2 == 0){
                v[j+1] = v[j];
                j--;
                v[j+1] = key;

            }
            else if(key % 2 == 0 && v[j] % 2 ==0){
                if(key > v[j]){
                    v[j+1] = v[j];
                    j--;
                    v[j+1] = key;
                }else{
                    j--;
                }
            }
            else if(key % 2 != 0 && v[j] % 2 !=0){
                if(key < v[j]){
                    v[j+1] = v[j];
                    j--;
                    v[j+1] = key;
                }else{
                    j--;
                }
            }else{
                j--;
            }
        }
    }
}

// Selection Sort - ordenação impares crescente e pares decrescente.
void selectionSortImparPar(int* v, int n){ 
    int aux = n-1;
    for(int i =0; i < aux;){
        int indexMin = i;
        for(int j = i+1; j <= aux; j++){
            if(v[j] < v[indexMin]){
                indexMin = j;
            }
        }
        if(v[indexMin] % 2 != 0){
            swap(v[i], v[indexMin]);
            i++;
        }else{
            swap(v[indexMin], v[aux]);
            aux--;
        }
    }
}

// Funcão intercala para o MergeSortImparPar recursivo e interativo;.
void mergeImparPar(int* v, int p, int q, int r){
    int* w = new int[r-p+1];
    int i = p;
    int j = q+1;
    int k = 0;

    while(i <= q && j<=r){              
        if(v[i] % 2 != 0 && v[j] % 2 != 0){
            if(v[i] < v[j]){
                w[k] = v[i];
                k++;
                i++;
            }else{
                w[k] = v[j];
                k++;
                j++;
            }
        }
        else if(v[i] % 2 == 0 && v[j] % 2 == 0){
            if(v[i] > v[j]){
                w[k] = v[i];
                k++;
                i++;
            }else{
                w[k] = v[j];
                k++;
                j++;
            }
            
        }
        else if(v[i] % 2 != 0 && v[j] % 2 == 0){
            w[k] = v[i];
            k++;
            i++;
        }
        else if(v[i] % 2 == 0 && v[j] % 2 != 0){
            w[k] = v[j];
            k++;
            j++;
        }
    
    }

    while(i <= q){
        w[k] = v[i];
        k++;
        i++;
        
    }

    while(j <= r){
        w[k] = v[j];
        k++;
        j++;
    }

    for(int i = p; i <= r; i++){
        v[i] = w[i-p];
    }

    delete w;

}

// Merge Sorte interativo - ordenação impares crescente e pares decrescente.
void mergeSortInterativoImparPar(int v[], int n){
    for(int b = 1; b < n; b *= 2){
        for(int p = 0; p < n - 1; p += 2 * b){
            int q = min(p + b - 1, n -1);
            int r = min(p + 2 * b - 1, n - 1);
           mergeImparPar(v, p, q, r);
        }
    }

}



// >> Recursivos.
// Bubble Sort rescutivo - ordenação crescente.
void bubbleSortRecursivo(int* v, int n){
    if(n == 1){
        return;
    }

    for(int i = 0; i < n -1 ; i++){
        if(v[i] > v[i+1]){
            swap(v[i], v[i+1]);
        }

    }
    bubbleSortRecursivo(v, n-1);
}

// Insertion Sort rescutivo - ordenação crescente.
void insertionSortRecursivo(int* v, int n){
    if (n <= 1){
        return;
    }
 
    insertionSortRecursivo(v, n-1);

    int key = v[n-1];
    int j = n-2;
 
    while (j >= 0 && v[j] > key)
    {
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = key;

}

// Selection Sort rescutivo - ordenação crescente.
void selectionSortRecursivo(int v[], int ini, int fim){
    int indxMin;
    int j;
    if(ini == fim){
        return;
    }

    indxMin = ini;
    for(j =  ini + 1; j <= fim; j++){
        if(v[j] < v[indxMin]){
            indxMin = j;
        }
    }
        if(ini != indxMin){
            swap(v[indxMin], v[ini]);
        }
    
    selectionSortRecursivo(v, ini + 1, fim);
}

// Merge Sort rescutivo - ordenação crescente.
void mergeSort(int* v, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        mergeSort(v, p, q);
        mergeSort(v,q+1,r);
        merge(v,p,q,r);
    }
}

//Função separa do quick sort para ordenação crescente.
int separa(int* v, int p, int r){
    int pivo = v[r];
    int q = p;
    for(int i = p; i < r; i++){
        if(v[i] <= pivo){
            swap(v[i], v[q]);
            q++;
        }
    }
    v[r] = v[q];
    v[q] = pivo;
    return q;
}

//Quick Sort - ordenação crescente recursivo.
void quickSort(int* v, int p, int r){
    if(p<r){
        int q = separa(v,p,r);
        quickSort(v, p , q-1);
        quickSort(v, q+1, r);
    }
}



//->Ordenação imapres e pares Recursivo.

// Bubblesort recursivo - ordenação impares crescente e pares decrescente.
void bubbleSortRecursivoImparPar(int* v, int n){
    if(n == 1){
        return;
    }

    for(int i = 0; i < n -1 ; i++){
        if(v[i] % 2 == 0 && v[i+1] % 2 == 0){
            if(v[i] < v[i+1]){
                swap(v[i], v[i+1]);
            }
        }
        else if(v[i] % 2 == 0 && v[i+1] % 2 != 0){
            swap(v[i], v[i+1]);
        }
        else if(v[i] % 2 != 0 && v[i+1] % 2 != 0){
            if(v[i] > v[i+1]){
                swap(v[i], v[i+1]);
            }
        }

    }
    bubbleSortRecursivoImparPar(v, n-1);
}

// Insertionsort recursivo - ordenação impares crescente e pares decrescente.
void insertionSortRecursivoImparPar(int* v, int n){
    if (n <= 1){
        return;
    }
 
    insertionSortRecursivoImparPar(v, n-1);

    int key = v[n-1];
    int j = n-2;
 
    while (j >= 0){
        if(key % 2 != 0 && v[j] % 2 == 0){
            v[j+1] = v[j];
            j--;
            v[j+1] = key;

        }
        else if(key % 2 == 0 && v[j] % 2 ==0){
            if(key > v[j]){
                v[j+1] = v[j];
                j--;
                v[j+1] = key;
            }else{
                j--;
            }
        }
         else if(key % 2 != 0 && v[j] % 2 !=0){
            if(key < v[j]){
                v[j+1] = v[j];
                j--;
                v[j+1] = key;
            }else{
                j--;
            }
        }else{
            j--;
        }
    }
}

// Selectionsort recursivo - ordenação impares crescente e pares decrescente.
void selectionSortRecursivoImparPar(int v[], int ini, int fim){
    if(ini == fim){
        return;
    }

    int indxMin = ini;
    for(int j =  ini + 1; j <= fim; j++){
        if(v[j] < v[indxMin]){
            indxMin = j;
        }
    }

    if(v[indxMin] % 2 != 0){
        swap(v[ini], v[indxMin]);
        ini++;
    }else{
        swap(v[indxMin], v[fim]);
        fim--;
    }

    selectionSortRecursivoImparPar(v, ini, fim);
}

// Mergesort recursivo - ordenação impares crescente e pares decrescente.
void mergeSortImparPar(int* v, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        mergeSortImparPar(v, p, q);
        mergeSortImparPar(v,q+1,r);
        mergeImparPar(v,p,q,r);
    }
}

// Função separa para o Quicksort ordenação impares crescente e pares decrescente.
int separaImparPar(int* v, int p, int r){
    int pivo = v[r];
    int q = p;
    for(int i = p; i < r; i++){
        if(pivo % 2 == 0 && v[i] % 2 == 0){
            if(v[i] > pivo){
               swap(v[i], v[q]);
                q++;
            }
        }
        else if(pivo % 2 == 0 && v[i] % 2 != 0){
            swap(v[i], v[q]);
            q++;
        }
        else if(pivo % 2 != 0 && v[i] % 2 != 0){
            if(v[i] < pivo){
                swap(v[i], v[q]);
                q++;
            }
        }
    }
    v[r] = v[q];
    v[q] = pivo;
    return q;
}

//Quicksort - ordenação impares crescente e pares decrescente.
void quickSortImaparPar(int* v, int p, int r){
    if(p<r){
        int q = separaImparPar(v,p,r);
        quickSortImaparPar(v, p , q-1);
        quickSortImaparPar(v, q+1, r);
    }
}


// Parte 2 do trabalho:

aluno* alunos = 0;
int numAlunos = 0;
//Função troca para o vetor de estrutura
void troca(aluno *a, aluno *b){
    aluno aux;
    strcpy(aux.nome, a->nome);
    aux.matricula = a->matricula;
    strcpy(a->nome, b->nome);
    a->matricula = b->matricula;
    strcpy(b->nome, aux.nome);
    b->matricula = aux.matricula;

}

//Lê os dados dos alunos. n é quantidade de alunos a ser lidos.
aluno* cinAluno(aluno* alunos, int numAlunos){
    for(int i = 0; i < numAlunos; i++){
        cout << "Nº: " << i+1 << endl; 
        cout << "NOME: ";
        cin.ignore();
        cin.get(alunos[i].nome, 25);
        cout << "MATRICULA: ";
        cin >> alunos[i].matricula;
    }
    return alunos;
}

//Imprime os dados dos alunos.
void coutAluno(aluno *alunos, int numAlunos){
    for(int i = 0; i < numAlunos; i++){
        cout << "Nº: " << i+1 << endl; 
        cout <<  "Nome: " << alunos[i].nome;
        cout << "    Matricula: " << alunos[i].matricula << endl;
    }
}

//Ordena o vetor de estruta em ordem alfabetica: Selection Sort
void ordenaNome(aluno *alunos, int numAlunos){
    for(int i = 0; i < numAlunos-1; i++){
        int indxMin = i;
        for(int j = i + 1; j < numAlunos; j++){
            if(strcoll(alunos[j].nome, alunos[indxMin].nome) < 0){
                indxMin = j;
            }
        }
        troca(&alunos[i], &alunos[indxMin]);
    }
}

//Ordena o vetor de estrura pela matricula: Selection Sort
void ordenaMatricula(aluno *alunos, int numAlunos){
    for(int i = 0; i < numAlunos-1; i++){
        int indxMin = i;
        for(int j = i + 1; j < numAlunos; j++){
            if(alunos[j].matricula < alunos[indxMin].matricula){
                indxMin = j;
            }
        }
        troca(&alunos[i], &alunos[indxMin]);
    }
}



// outras funções.

//criar vetor aleatorio.
void randomVector(int* v, int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v[i] = rand() % 100;
        
    }
}

//Imprime Vetor
void coutVetor(int* v, int n){
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}

void menu(){
    cout << "ESCOLHA UMA DAS OPÇÕES ABAIXO" << endl << endl;
    cout << "OPÇÃO 1 : PARTE I DO TRABALHO - ORDENAÇÃO DE ELEMENTOS" << endl << endl;
    cout << "OPÇÃO 2 : PARTE II DO TRABALHO - ORDENAÇÃO DE VETOR DE ESTRUTURA" << endl << endl;
}