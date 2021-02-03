/*
Si vuole sviluppare un algoritmo per il calcolo del centroide. L’algoritmo considera una
scacchiera di 30x30 caselle e dispone a caso (usando la function rand) 50 oggetti (la
posizione è una coppia di numeri interi). L’algoritmo deve visualizzare la scacchiera,
mostrando un ‘ ’ per le caselle non occupate e mostrando una ‘X’ per le caselle
occupate dagli oggetti. L’algoritmo determina il centroide dell’insieme dei 50 oggetti: il
centroide è un punto della scacchiera che ha per ascissa l’intero più vicino alla media
delle ascisse di tutti gli oggetti e per ordinata l’intero più vicino alla media delle ordinate
di tutti gli oggetti. L’algoritmo deve visualizzare di nuovo la scacchiera, indicando, oltre
alle caselle vuote e a quelle occupate, anche la posizione del centroide (indicandola con
la lettera ‘C’). Infine, l’algoritmo calcola e visualizza la distanza di ognuno degli oggetti
dal centroide, e determina e visualizza sia la minima distanza (indicando anche la
posizione dell’oggetto a minima distanza) sia la massima distanza (indicando anche la
posizione dell’oggetto a massima distanza).
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"



int main()
{
    srand((unsigned)time(NULL));

    int i, xC, yC;
    char **scacchiera;
    double distanza[numeri];

    //alloco dinamicamente lo spazio richiesto per la scacchiera
    scacchiera=(int**)malloc(sizeof(char *)*size);
    for(i=0; i<size; i++)
        scacchiera[i]=(int *)malloc(sizeof(char)*size);

    //inizializzo la scacchiera in modo che abbia tutti spazi vuoti, passando in input la scacchiera stessa e le sue dimensioni
    inizializzaScacchiera(scacchiera,size,size);
    printf("Generazione scacchiera...(Premere un tasto per continuare)\n");
    getchar();

    //Stampo la scacchiera, passando in input la scacchiera stessa e le sue dimensioni
    printChessboard(scacchiera, size, size);
    printf("Premere un tasto per continuare...\n");
    getchar();

    /*posiziono gli oggetti in modo casuale sulla scacchiera, passando in input la scacchiera stessa, le sue dimensioni
     ed il numero di oggetti casuali da posizionare*/
    randomObjectInsert(scacchiera, size, size, numeri);
    printf("Inserimento oggetti casuali...(Premere un tasto per continuare)\n");
    getchar();

    //Stampo la scacchiera, passando in input la scacchiera stessa e le sue dimensioni
    printChessboard(scacchiera, size, size);

    /*calcolo il centroide dei punti inseriti casualmente in precedenza, passando in input la scacchiera stessa, le sue dimensioni,
     il numero di oggetti casuali inseriti e i due indirizzi per tenere conto delle coordinate del centroide*/
    calcoloCentroide(scacchiera, size, size, numeri, &xC, &yC);
    printf("Calcolo del centroide...(Premere un tasto per continuare)\n");
    getchar();
    printChessboard(scacchiera, size, size);
    calcoloDistanze(scacchiera, size, size, xC, yC, &distanza);
    printf("Calcolo distanza dei punti dal centroide...(Premere un tasto per continuare)\n");
    getchar();

    //stampa le distanze dei punti dal centroide indicando distanza massima e distanza minima
    stampaDistanze(scacchiera, size, size, distanza);

    return 0;
}
