//
// Created by tmKla on 28/10/2022.
//

#include "FilsLLC.h"


Node *addLetterToDic0(Node *node, char *mot, int i, int *nbAction) {
    if (i == strlen(mot)) {
        if (*nbAction > 0) {
            node->ListFils = addtoEndList(node->ListFils, '.');
            node->nbFils++;
        }
        return node->ListFils->data;
    }
    if (isLetterExist(node->ListFils, mot[i]) == 0) {
        node->ListFils = addtoEndList(node->ListFils, mot[i]);
        node->nbFils++;
        (*nbAction)++;
    }
    List *temp = node->ListFils;
    while (temp->data->lettre != mot[i]) {
        temp = temp->next;
    }
    return addLetterToDic0(temp->data, mot, i + 1, nbAction);

}

Node *addWordToDic0(Tree **Arbre, char *mot, int nature, int *nbAction) {
    Node *Root = (*Arbre)->root;
    List *root = Root->ListFils;
    for (int i = 0; i < nature; i++) {
        root = root->next;
    }
    int lenWord = strlen(mot);
    return addLetterToDic0(root->data, mot, 0, nbAction);


}

Node *goToTheRandomNode(List *ListFils, int numFils) {
    List *temp = ListFils;
    int cpt = 0;
    while (cpt < numFils) {
        temp = temp->next;
        cpt++;
    }
    return temp->data;
}

Node *displayRandomLetter(Node *node) {
    if (node->lettre == '.') {
        printf(" ");
        return node;
    }
    int numFils = rand() % (node->nbFils);
    node = goToTheRandomNode(node->ListFils, numFils);
    if (node->lettre != '.') {
        printf("%c", node->lettre);
    }
    return displayRandomLetter(node);
}

Node *displayRandomWord(Tree *Arbre, int nature) {
    Node *root = goToTheRandomNode(Arbre->root->ListFils, nature);
    return displayRandomLetter(root);
}


void FlechirNom(char *motF, Node *nodemot, int genre, int nombre) {
    nodemot->nature->nom.genre = genre;
    if (genre == 0) {
        nodemot->nature->nom.determinant[0] = "le";
    } else {
        nodemot->nature->nom.determinant[0] = "la";
    }
    nodemot->nature->nom.determinant[1] = "les";
    nodemot->nature->nom.ecriture[nombre] = motF;
}

void FlechirAdj(char *motF, Node *nodemot, int genre, int nombre) {
    if (genre==2){
        nodemot->nature->adj.ecriture[0][nombre] = motF;
        nodemot->nature->adj.ecriture[1][nombre] = motF;
    }
    else{
        nodemot->nature->adj.ecriture[genre][nombre] = motF;
    }
}

void FlechirVerbe(char *motF, Node *nodemot, int temps, int pers, int nombre) {
    nodemot->nature->verbe.conjugaison[temps][pers][nombre] = motF;
}
void displayFormFlechieNom(Nom nom){
    printf("\n%s %s\n",nom.ecriture[0],nom.ecriture[1]);
}
void displayFormFlechieAdj(Adj adj){
    printf("\n");
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            printf("%s ",adj.ecriture[i][j]);
        }
    }
    printf("\n");
}
void displaysentence(Tree *Arbre) {
    srand(time(NULL));
    Node *nom = displayRandomWord(Arbre, NOM);
    displayFormFlechieNom(nom->nature->nom);
    Node *adj = displayRandomWord(Arbre, ADJ);
    displayFormFlechieAdj(adj->nature->adj);
    Node *verbe= displayRandomWord(Arbre,VERBE);
    printf("\n");
    int genre = nom->nature->nom.genre, nombre = rand() % 2,temps=rand()%3;
    char *determinant = nom->nature->nom.determinant[nombre], *nomF = nom->nature->nom.ecriture[nombre];
    char *adjF = adj->nature->adj.ecriture[genre][nombre];
    char *verbeF=verbe->nature->verbe.conjugaison[temps][2][nombre];
    printf("%s %s %s %s", determinant, nomF,adjF,verbeF);

}
