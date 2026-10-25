#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

node_t3c* charger(const char *chemin_fichier) {
    FILE *fp = fopen(chemin_fichier, "r");
    if (fp == NULL) {
        fprintf(stderr, "Erreur : Impossible d'ouvrir la table T3C %s\n", chemin_fichier);
        exit(1);
    }
    node_t3c *tete = NULL;
    char ligne[1024];

    while (fgets(ligne, sizeof(ligne), fp) != NULL) {
        ligne[strcspn(ligne, "\r\n")] = 0;
        char *separateur = strchr(ligne, ':');

        if (separateur != NULL) {
            *separateur = '\0';
            char *hash_lu = ligne;
            char *chaine_lue = separateur + 1;

            node_t3c *nouveau = malloc(sizeof(node_t3c));

            strncpy(nouveau->hash, hash_lu, 32);
            nouveau->hash[32] = '\0';

            nouveau->chaine = malloc(strlen(chaine_lue) + 1);
            strcpy(nouveau->chaine, chaine_lue);

            nouveau->next = tete;
            tete = nouveau;
        }
    }
    fclose(fp);
    return tete;
}

void recherche(node_t3c *tete) {
    char hash_cible[256];

    while (fgets(hash_cible, sizeof(hash_cible), stdin) != NULL) {
        hash_cible[strcspn(hash_cible, "\r\n")] = 0;

        if (strlen(hash_cible) == 0) continue;
        node_t3c *courant = tete;
        int trouve = 0;

        while (courant != NULL) {
            if (strcmp(courant->hash, hash_cible) == 0) {
                printf("%s\n", courant->chaine);
                trouve = 1;
                break;
            }
            courant = courant->next;
        }

        if (!trouve) {
            printf("\n");
        }
    }
}

void free_liste(node_t3c **tete) {
    node_t3c *courant = *tete;
    while (courant != NULL) {
        node_t3c *temp = courant;
        courant = courant->next;
        free(temp->chaine); // Libère la chaîne dynamique
        free(temp);         // Libère la structure
    }
    *tete = NULL;
}