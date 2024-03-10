#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CALLS 1000

typedef struct {
    char phone_number[15]; // Assez grand pour contenir un numéro de téléphone international
    char call_type[10];    // "entrant" ou "sortant"
    char correspondent_name[50]; // nom du correspondant 
} CallRecord;


CallRecord calls[MAX_CALLS]; // Tableau pour stocker les enregistrements d'appels

int readCallsFromFile(const char *filename) {
    
    FILE *file = fopen("TP Police scientifique - releve telephonique.txt", "r");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return -1;
    }

    int i = 0;
    while (i < MAX_CALLS && fscanf(file, "%[^,],%[^,],%[^\n]\n", calls[i].phone_number, calls[i].call_type, calls[i].correspondent_name) == 3) {
        i++;
    }

    fclose(file);
    return i; // Retourne le nombre d'appels lus
}

int main() {
    const char *filename = "TP Police scientifique - releve telephonique.txt";
    int count = readCallsFromFile(filename);

    if (count <= 0) {
        printf("Aucun appel lu du fichier.\n");
        return 1;
    }

    // Affichage des appels triés (pour tester)
    for (int i = 0; i < count; i++) {
        printf("%s, %s, %s\n", calls[i].phone_number, calls[i].call_type, calls[i].correspondent_name);
    }

    return 0;
}
 
