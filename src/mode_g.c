#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

void generate_t3c(char *input, char *output, char *algo) {
    if (strcmp(algo, "md5") != 0) {
        fprintf(stderr, "Erreur, il y'a que l'algorithme md5\n");
        exit(1);
    }
    //Ouverture des fichiers
    FILE *fin = fopen(input, "r");
    if (fin == NULL) {
        fprintf(stderr, "Erreur, nous ne pouvons ouvrir le fichier %s\n", input);
        exit(1);
    }
    FILE *fout = fopen(output, "w");
    if (fout == NULL) {
        fprintf(stderr, "Erreur, nous ne pouvons creer le fichier %s\n", output);
        fclose(fin);
        exit(1);
    }
    char line[256];
    unsigned char md5[MD5_DIGEST_LENGTH]; // Correction
    while (fgets(line, sizeof(line), fin) != NULL) {
        line[strcspn(line, "\r\n")] = 0;
        MD5((unsigned char*)line, strlen(line), md5);

        char hash_str[MD5_DIGEST_LENGTH * 2 + 1]; // Correction
        for (int i = 0; i < MD5_DIGEST_LENGTH; i++) { // Correction
            sprintf(&hash_str[i * 2], "%02x", (unsigned int)md5[i]);
        }
        fprintf(fout, "%s\t%s\n", line, hash_str);
    }

    fclose(fin);
    fclose(fout);
}