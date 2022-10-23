#include <stdio.h>
#include "node.h"

int freee(node * temp){
    if (temp->left==NULL && temp->right==NULL){
        free(temp);
    }
    else{
        if(temp->left!=NULL && temp->right==NULL){
            freee(temp->left);
        }
        else{
            freee(temp->left);
            freee(temp->right);
        }
    }
}