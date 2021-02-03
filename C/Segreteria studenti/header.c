//
// Created by Jinta on 29/12/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//prof [in]
//iscr [in]
//visualizza tutti gli studenti iscritti
void visualizzaSegreteria(studenti *prof, int iscr){
    int i;
    for(i=0; i<iscr; i++){
        printf("\n");
        printf("Nome: %s\n", prof[i].Nome);
        printf("Cognome: %s", prof[i].Cognome);
        printf("Matricola: %s\n", prof[i].Matricola);
    }
}


//stringa [out]
//numero [in]
//converte un valore numerico nella stringa che lo rappresenta
void toString(char stringa[], int numero){
    int buff, i, n, size = 0;
    n = numero;
    while(n!=0){
        size++;
        n/=10;
    }
    for(i=0; i<size; i++){
        buff = numero%10;
        numero/=10;
        stringa[size-(i+1)] = buff+'0';
    }
    stringa[size] = '\0';
}

//prof[in/out]
//iscr [in]
//contatore [in]
//iscrive, quindi aggiunge uno studente alla lista
void iscriviStudente(studenti *prof, int iscr, int contatore){
    prof[iscr-1].Nome = (char*)malloc(sizeof(char)*30);
    prof[iscr-1].Cognome = (char*)malloc(sizeof(char)*30);
    prof[iscr-1].Matricola = (char*)malloc(sizeof(char)*10);

    //Inserimento del nome da parte dell'utente
    printf("Inserisci nome:");
    fgets(prof[iscr-1].Nome, 30, stdin);
    prof[iscr-1].Nome[strcspn(prof[iscr-1].Nome, "\n")] = 0;

    //Inserimento del cognome da parte dell'utente
    printf("Inserisci cognome:");
    fgets(prof[iscr-1].Cognome, 30, stdin);
    prof[iscr-1].Nome[strcspn(prof[iscr-1].Nome, "\n")] = 0;

    //Matricola auto-incrementata
    char matr[] = "124";

    //se il numero è minore di dieci converte il singolo numero in stringa, altrimenti
    //richiama la funzione per convertirlo
    if(contatore<10){
        char stud = (contatore-1) + '0';
        strncat(matr, &stud, 1);
    }else{
        char stud[2];
        toString(stud, contatore-1);
        strncat(matr, stud, 2);
    }
    strcpy(prof[iscr-1].Matricola, matr);

    //Reallocazione memoria in base alla grandezza delle stringhe inserite
    prof[iscr-1].Nome = (char*)realloc(prof[iscr-1].Nome, sizeof(char)*strlen(prof[iscr-1].Nome));
    prof[iscr-1].Cognome = (char*)realloc(prof[iscr-1].Cognome, sizeof(char)*strlen(prof[iscr-1].Cognome));
    prof[iscr-1].Matricola = (char*)realloc(prof[iscr-1].Matricola, sizeof(char)*strlen(prof[iscr-1].Matricola));


    //se il numero degli studenti iscritti è maggiore di 1 allora
    //gli studenti vengono automaticamente ordinati in ordine alfabetico
    if(iscr>1)
        ordinaSegreteria(prof, iscr);
}

//chiave [in]
//prof [in]
//n [in]
//ricerca sequenziale di stringa
int ricerca(char chiave[], studenti *prof, int n){
    int i;

    for(i=0; i<n; i++)
        if(strcmp(chiave, prof[i].Matricola)==0)
            return i;
    return -1;
}

//prof [in/out]
//iscr [in/out]
//elimina uno studente dalla lista
void eliminaStudente(studenti *prof, int *iscr){
    char *matr;
    matr = (char*)malloc(sizeof(char)*10);
    printf("Inserisci matricola dello studente da eliminare: ");
    fgets(matr,6,stdin);
    matr[strcspn(matr, "\n")] = 0;
    matr = (char*)realloc(matr, sizeof(char)*strlen(matr));

    int i, indice = ricerca(matr, prof, *iscr);
    if(indice == -1){
        printf("Matricola non corretta, riprova!");
        return;
    }else{
        printf("Eliminazione avvenuta con successo", *iscr);
        for(i=indice; i<(*iscr-1); i++) //partendo dall'elemento da eliminare sposta tutti gli elementi indietro di una posizione
            prof[i] = prof[i+1];
        *iscr = *iscr - 1;
    }
}

//a [in/out]
//b [in/out]
//scambia il primo con il secondo elemento
void scambiare(studenti* a, studenti* b){
    studenti temp;
    temp= *a;
    *a = *b;
    *b = temp;
}

//prof [in]
//iscr [in]
//max_a [in/out]
//i_max [in/out]
//funzione di ricerca del massimo
void massimo(studenti* prof, int iscr, char max_a[], int *i_max){
    int i;
    strcpy(max_a, prof[0].Cognome);
    *i_max = 0;
    for(i=1; i<iscr; i++){
        if(strcmp(max_a, prof[i].Cognome)<0){
            strcpy(max_a, prof[i].Cognome);
            *i_max = i;
        }
    }
}

//prof [in/out]
//iscr [in]
//ordinamento per selezione di massimo
void ordinaSegreteria(studenti* prof, int iscr){
    int i, i_max;
    char max_a[30];

    for(i=iscr-1; i>0; i--){
        massimo(&prof[0], i+1, &max_a, &i_max);
        scambiare(&prof[i], &prof[i_max]); //spiazzamento dell'indice
    }
}


