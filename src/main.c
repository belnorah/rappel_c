//
// Created by ICY JANE
// géneration de condensats G et recherche parmi les listes de condensats L
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    //faire une fonction pour ça ?
    if (argc < 2) {
        fprintf(stderr, "Erreur, mode G ou L\n");
        exit(1);
    }
    char *mode = argv[1];
    if (strcmp(mode, "G") == 0) {
        char *input = "";
        char *output = "";
        char *algo = "md5";

        for (int i = 2; i < argc; i++) {
            if ((strcmp(argv[i], "-i") == 0) || (strcmp(argv[i], "--input") == 0) && (i + 1 < argc)) {
                input = argv[++i];
            }else if ((strcmp(argv[i], "-o") == 0) || (strcmp(argv[i], "--output") == 0) && (i + 1 < argc)) {
                output = argv[++i];
            } else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--algo") && (i + 1 < argc)) {
                algo = argv[++i];
            }
        }
    }
    return 0;

}
