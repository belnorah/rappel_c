#include <openssl/md5.h>

void generate_t3c(char *input, char *output, char *algo) {
    if (strcmp(algo, "md5") != 0) {
        fprintf(stderr, "Erreur, il y'a que l'algorithme md5\n");
        return 1;
    }
    //Ouverture des fichiers
    FILE *fin = fopen(input, "r");
    if (fin == NULL) {
        fprintf(stderr, "Erreur, nous ne pouvons ouvrir le fichier %s\n", input);
        return 1;
    }
    FILE *fout = fopen(output, "w");
    if (fout == NULL) {
        fprintf(stderr, "Erreur, nous ne pouvons creer le fichier %s\n", output);
        fclose(fin);
        return 1;
    }

    fclose(fin);
    fclose(fout);
}