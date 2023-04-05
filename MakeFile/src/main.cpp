#include <iostream>
#include <chrono>
#include<cstdlib>
#include <bits/stdc++.h>
#include "../inc/ordenacao.h"
using namespace std;


int main(){
    
    
    
    int op = 0;
    while(1){
        menu();
        cout << "OPÇÃO: ";
        cin >> op;

        if(op == 1){
        int n;
        cout << "Digite a quantidade de elementos do vetor do bubblesort: " << endl;
        cin >> n;

        //bubble sort - ordenação em impares e pares e recursivo crescente.
        cout << "*BUBBLE SORT*" << endl;
        int* v1 = new int[n];
        randomVector(v1, n);
        cout << "VETOR GERADO:" << endl;
        coutVetor(v1, n);
        cout << endl<<endl;
        bubbleSortImparPar(v1, n);
        cout << "VETOR ORDENADO EM IMAPRES CRESCENTE E PARES DECRESCENTE" << endl;
        coutVetor(v1, n);
        cout << endl<<endl;
        cout << "VETOR ORDENADO CRESCENTE RECURSIVO" << endl;
        bubbleSortRecursivo(v1, n);
        coutVetor(v1, n);
        cout << endl<<endl;
        delete v1;

        cout << "----------------------------------------------------------------------------" << endl;

        int n2;
        cout << "Digite a quantidade de elementos do vetor do insertionsort: " << endl;
        cin >> n2;
        //insertion sort - ordenação em impares e pares e recursivo crescente.
        cout << "*INSERTION SORT*" << endl;
        int* v2 = new int[n2];
        randomVector(v2, n2);
        cout << "VETOR GERADO:" << endl;
        coutVetor(v2, n2);
        cout << endl<<endl;
        insertionSortImparPar(v2, n2);
        cout << "VETOR ORDENADO EM IMAPRES CRESCENTE E PARES DECRESCENTE" << endl;
        coutVetor(v2, n2);
        cout << endl<<endl;
        cout << "VETOR ORDENADO CRESCENTE RECURSIVO" << endl;
        insertionSortRecursivo(v2, n2);
        coutVetor(v2, n2);
        cout << endl<<endl;
        delete v2;

        cout << "----------------------------------------------------------------------------" << endl;
        
        int n3;
        cout << "Digite a quantidade de elementos do vetor do selectionsort: " << endl;
        cin >> n3;
        //selection sort - ordenação em impares e pares e recursivo crescente.
        cout << "*SELECTION SORT*" << endl;
        int* v3 = new int[n3];
        randomVector(v3, n3);
        cout << "VETOR GERADO:" << endl;
        coutVetor(v3, n3);
        cout << endl<<endl;
        selectionSortImparPar(v3, n3);
        cout << "VETOR ORDENADO EM IMAPRES CRESCENTE E PARES DECRESCENTE" << endl;
        coutVetor(v3, n3);
        cout << endl<<endl;
        cout << "VETOR ORDENADO CRESCENTE RECURSIVO" << endl;
        selectionSortRecursivo(v3, 0, n3-1);
        coutVetor(v3, n3);
        cout << endl<<endl;
        delete v3;

        cout << "----------------------------------------------------------------------------" << endl;

        int n4;
        cout << "Digite a quantidade de elementos do vetor do mergesort: " << endl;
        cin >> n4;
        //merge sort - ordenação em impares e pares e recursivo crescente.
        cout << "*MERGE SORT*" << endl;
        int* v4 = new int[n4];
        randomVector(v4, n4);
        cout << "VETOR GERADO:" << endl;
        coutVetor(v4, n4);
        cout << endl<<endl;
        mergeSortImparPar(v4, 0, n4-1);
        cout << "VETOR ORDENADO EM IMAPRES CRESCENTE E PARES DECRESCENTE" << endl;
        coutVetor(v4, n4);
        cout << endl<<endl;
        cout << "VETOR ORDENADO CRESCENTE INTERATIVO" << endl;
        mergeSortInterativo(v4, n4);
        coutVetor(v4, n4);
        cout << endl<<endl;
        delete v4;

        cout << "----------------------------------------------------------------------------" << endl;

        int n5;
        cout << "Digite a quantidade de elementos do vetor do quicksort: " << endl;
        cin >> n5;
        //quick sort - ordenação em impares e pares e recursivo crescente.
        cout << "*QUICK SORT*" << endl;
        int* v5 = new int[n5];
        randomVector(v5, n5);
        cout << "VETOR GERADO:" << endl;
        coutVetor(v5, n5);
        cout << endl<<endl;
        quickSortImaparPar(v5, 0, n5-1);
        cout << "VETOR ORDENADO EM IMAPRES CRESCENTE E PARES DECRESCENTE" << endl;
        coutVetor(v5, n5);
        cout << endl<<endl;
        cout << "VETOR ORDENADO CRESCENTE" << endl;
        quickSort(v5, 0, n5-1);
        coutVetor(v5, n5);
        cout << endl<<endl;
        delete v5;

        cout << "----------------------------------------------------------------------------" << endl;
        break;
        }else{
            //vetor de estrutura
            aluno *alunos = 0;
            int num_alunos = 0;
            cout << "DIGITE A QUATIDADE DE ALUNOS A SER INSERIDO" << endl;
            cin >> num_alunos;
            alunos = (aluno*)malloc(sizeof(aluno)*num_alunos);
            cout << endl<<endl;
            cout << "INSIRA O NOME E MATRICULA DE CADA ALUNO" << endl;
            alunos = cinAluno(alunos, num_alunos);
            cout << "----------------------------------------------------------------------------" << endl << endl;
            //ordena em ordem alfabetica
            cout << "VETOR DE ESTRUTURA EM ORDEM ALFABETICA" << endl;
            ordenaNome(alunos, num_alunos);
            coutAluno(alunos, num_alunos);
            cout << "----------------------------------------------------------------------------" << endl << endl;
            cout << "VETOR DE ESTRUTURA EM ORDEM NUMERICA POR MATRICULA" << endl;
            ordenaMatricula(alunos, num_alunos);
            coutAluno(alunos, num_alunos);
            delete alunos;
            break;
        }

    }
    
}