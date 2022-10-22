#include <stdio.h>
#include "../Miscellaneous/node.h"
void prefin(node * temp){
    if (!( temp->left!=NULL && temp->right==NULL)){
        if (temp->left!=NULL){
            printf("(");
            prefin(temp->left);
        }
        printf("%c",temp->atom);
        if (temp->right!=NULL){
            prefin(temp->right);
            printf(")");
        }
    }
    else{
        printf("(");
        printf("%c",temp->atom);
        if (temp->left!=NULL){
            printf("(");
            prefin(temp->left);
            printf(")");
        }
        printf(")");
    }
}