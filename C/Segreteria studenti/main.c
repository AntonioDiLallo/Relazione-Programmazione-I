#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define size 10

int main() {
    int choose;
    size_t iscritti = 0, cont_matricole = 0;
    studenti *profili;
    profili = (studenti*)malloc(sizeof(studenti)*size);
    do {
        printf("\n\n\n\n\n\n\n\n\n\n");
        printf("+-------------------------------+\n");
        printf("|     Segreteria studenti       |\n");
        printf("+-------------------------------+\n");
        printf("1) Visualizza studenti iscritti\n");
        printf("2) Aggiungi uno studente\n");
        printf("3) Elimina uno studente\n");
        printf("4) Esci\n");
        printf("Cosa vuoi fare?(Inserisci valore numerico dell'operazione):");
        scanf("%d%*c", &choose);

        switch (choose) {
            case 1:
                if(iscritti>0){
                    visualizzaSegreteria(profili, iscritti);
                }else
                    printf("Nessuno studente e' iscritto al corso\n");
                break;

            case 2:
                if(iscritti<10){
                    ++iscritti;
                    ++cont_matricole;
                    iscriviStudente(profili, iscritti, cont_matricole);
                }else
                    printf("Limite iscrizioni raggiunto!");
                break;

            case 3:
                if(iscritti>0){
                    eliminaStudente(profili, &iscritti);
                }else
                    printf("Nessuno studente e' iscritto al corso\n");
                break;
            default:
                if(choose!=4)
                printf("Forse hai sbagliato a digitare, Riprova!\n");
                break;
        }

    } while (choose != 4);
    return 0;
}
