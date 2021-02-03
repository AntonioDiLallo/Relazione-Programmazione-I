#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"


//scacchiera [in/out]
//row[in]
//col[in]
//inizializza la scacchiera rendendola vuota
void inizializzaScacchiera(char **scacchiera, int row, int col){
    int i, j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scacchiera[i][j] = ' ';
}

//n[in]
//disegna una linea orizzontale
void drawHorizontal(int n){
    int i;
    printf("+");
    for(i=0 ; i<n ; i++)
        printf("-");
    printf("+\n");
}

//scacchiera[in/out]
//row[in]
//col[in]
//stampa la scacchiera
void printChessboard(char **scacchiera,int row, int col){
    int i, j;
    drawHorizontal(size);
    for(i=0 ; i<row ; i++){
        printf("|");
        for(j=0 ; j<col ; j++)
            printf("%c", scacchiera[i][j]);
        printf("|\n");
    }
    drawHorizontal(size);


}

//scacchiera[in/out]
//row[in]
//col[in]
//obj_Num[in]
//inserisce gli oggetti in posizioni casuali nella scacchiera
void randomObjectInsert(char **scacchiera, int row, int col, int Obj_Num){
    Punto randomPoint;

    int i = 1;
    while(i<=Obj_Num){
        randomPoint.x = rand()%(size-1);
        randomPoint.y = rand()%(size-1);
        if(scacchiera[randomPoint.y][randomPoint.x]!= 'X'){
            scacchiera[randomPoint.y][randomPoint.x] = 'X';
            i++;
        }

    }
}

//scacchiera[in/out]
//row[in]
//col[in]
//obj_Num[in]
//xC[out]
//yC[out]
//calcola il centroide della scacchiera inserita
void calcoloCentroide(char **scacchiera, int row, int col, int Obj_Num, int *xC, int *yC){
    int i, j, x_sum=0, y_sum=0;
    for(i=0;i<row;i++)
        //ciclo che calcola il centroide della scacchiera
        for(j=0;j<col;j++)
        //aggiunge le cordinate alle somme delle x e delle y solo se è un punto casuale creato in precedenza
            if(scacchiera[i][j] == 'X'){
                x_sum+=j;
                y_sum+=i;
            }
        *xC = x_sum/Obj_Num;
        *yC = x_sum/Obj_Num;

        scacchiera[*yC][*xC] = 'C';
}

//scacchiera[in/out]
//row[in]
//col[in]
//xC[in]
//yC[in]
//dist[out]
//calcola le distanze del centroide dai vari punti e le inserisce in un array
void calcoloDistanze(char **scacchiera, int row, int col, int xC, int yC, double *dist){
    int i, j, pos_Obj;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            if(scacchiera[i][j] == 'X'){
                dist[pos_Obj] = sqrt(pow((xC-i),2) + pow((yC-j),2));
                pos_Obj++;
            }
}

//v[in]
//n[in]
//i_max[out]
//i_min[out]
//funzione di ricerca dell'indice di minimo e di massimo
void max_min_ind(double *v, int n, int *i_max, int *i_min){
    int i;
    double min;
    double max;
    min = v[0];
    max = v[0];
    for(i=1 ; i<n ; i++)
        if(v[i]>max){
            *i_max = i;
            max = v[i];
        }

    for(i=1; i<n; i++)
        if(v[i]<min){
        *i_min = i;
        min = v[i];
        }



}

//scacchiera[in/out]
//row[in]
//col[in]
//dist[in]
//stampa la distanza di ogni punto dal centroide
void stampaDistanze(char **scacchiera, int row, int col, double *dist){
    int i, j, pos_Obj=0;
    int i_max, i_min;
    max_min_ind(dist, numeri, &i_max, &i_min);
    for(i=0;i<row;i++){

        for(j=0;j<col;j++){

            if(scacchiera[i][j] == 'X'){
                printf("L'oggetto alla posizione [%d - %d] ha distanza: %.2lf ", i, j, dist[pos_Obj]);

                if(pos_Obj == i_min)
                    printf("[distanza minima]\n");
                else if(pos_Obj == i_max)
                    printf("[distanza massima]\n");
                else
                    printf("\n");
                pos_Obj++;

            }
        }

    }

}


