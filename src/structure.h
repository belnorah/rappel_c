#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct node_t3c {
    char *chaine;
    char hash[33];
    struct node_t3c *next;
}node_t3c;
#endif