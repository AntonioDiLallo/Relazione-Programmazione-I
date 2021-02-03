#define size 30
#define numeri 50

typedef struct _Punto{
    int x;
    int y;
} Punto;

void inizializzaScacchierainit_scacchiera(char**, int , int ); //inizializzo la scacchiera rendendola vuota
void drawHorizontal(int); //disegna una linea orizzontale
void printChessboard(char**, int, int); //stampa la scacchiera

void randomObjectInsert(char**, int, int, int); //inserisce gli oggetti in posizioni casuali nella scacchiera
void calcoloCentroide(char**, int, int, int, int*, int*); //calcola il centroide
void max_min_ind(double*, int, int*, int*);//funzione di ricerca dell'indice di minimo e di massimo
void calcoloDistanze(char**, int, int, int, int, double*); //calcola le distanze del centroide dai vari punti e le inserisce in un array
void stampaDistanze(char**, int, int, double*);//stampa la distanza di ogni punto dal centroide
