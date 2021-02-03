
typedef struct{
    char *Nome;
    char *Cognome;
    char *Matricola;
} studenti;

void visualizzaSegreteria(studenti*, int);
void toString(char[], int);
void iscriviStudente(studenti*, int, int);
int ricerca(char[], studenti *, int);
void eliminaStudente(studenti*, int*);
void scambiare(studenti*, studenti*);
void massimo(studenti*, int, char[], int*);
void ordinaSegreteria(studenti*, int);

