#include "childrenLLC.h"

Nom creerNom(){
    Nom nom;
    nom.ecriture[0]=nom.ecriture[1]=NULL;
    return nom;
}
Adj creerAdj(){
    Adj adj;
    for (int i=0; i<2;i++){
        for (int j=0;j<2;j++){
            adj.ecriture[i][j]=NULL;
        }
    }
    return adj;
}
Verbe creerVerbe(){
    Verbe verbe;
    verbe.infinitf=NULL;
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for (int k=0;k<2;k++){
                verbe.conjugaison[i][j][k]=NULL;
            }
        }
    }
    return verbe;
}
Nature* creerNature(){
    Nature* nature= malloc(sizeof (Nature));
    nature->nom=creerNom();
    nature->adj=creerAdj();
    nature->verbe=creerVerbe();
    return nature;
}
Node *creerNode() {
    Node *newNode = malloc(sizeof(Node));
    newNode->lettre = '.';
    newNode->ListFils = creerList();
    newNode->nbFils = 0;
    newNode->nature=creerNature();
    return newNode;
}

List *creerList() {
    List *newList = malloc(sizeof(List));
    newList->data = NULL;
    newList->next = NULL;
    return newList;
}

Tree *creerArbrDico() {
    Tree *arbreDico = malloc(sizeof(Tree));
    arbreDico->root = malloc(sizeof(Node));
    List *temp = arbreDico->root->ListFils = creerList();
    temp->data = creerNode();
    temp->data->lettre = '0';
    for (int i = 0; i < 3; i++) {
        temp = temp->next = creerList();
        temp->data = creerNode();
        temp->data->lettre = (char) (i + 49);
    }
    return arbreDico;
}

void displayAllSons(List *listFils) {
    List *temp = listFils;
    while (temp != NULL) {
        printf("%c", temp->data->lettre);
        temp = temp->next;
    }
}

int isLetterExist(List *ListFils, char c) {
    List *temp = ListFils;
    if (temp->data == NULL) {
        return 0;
    }
    while (temp->next != NULL && temp->data->lettre != c) {
        temp = temp->next;
    }
    return temp->data->lettre == c;
}

List *addtoEndList(List *ListFils, char c) {
    List *newList = creerList();
    newList->data = creerNode();
    newList->data->lettre = c;
    if (ListFils->data == NULL) {
        ListFils = newList;
        return ListFils;
    }
    List *temp = ListFils;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newList;
    return ListFils;

}
