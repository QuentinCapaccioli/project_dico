#ifndef UNTITLED9_PARTIE1LLC_H
#define UNTITLED9_PARTIE1LLC_H
#define NOM 0
#define ADJ 1
#define VERBE 2
#define ADV 3
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
typedef struct Nom{
    int genre;
    char* ecriture[2];
    char* determinant[2];
}Nom;
typedef struct Adj{
    char* ecriture[2][2];
}Adj;
typedef struct Verbe{
    char* infinitf;
    char* conjugaison[3][3][2];

}Verbe;
typedef struct Nature{
    Nom nom;
    Adj adj;
    Verbe verbe;
}Nature;
#endif //UNTITLED9_PARTIE1LLC_H
typedef struct Node{
    char lettre;
    struct List* ListFils;
    int nbFils;
    Nature* nature;
}Node;
typedef struct List{
    Node* data;
    struct List* next;
}List;

typedef struct Tree{
    Node* root;
}Tree;
Nom creerNom();
Adj creerAdj();
Verbe creerVerbe();
Nature* creerNature();
Tree* creerArbrDico();
Node* creerNode();
List* creerList();
int isLetterExist(List* ListFils, char c);
List* addtoEndList(List* ListFils,char c);
void displaysentence(Tree);

//fonction debug
void displayAllSons(List *listFils);
