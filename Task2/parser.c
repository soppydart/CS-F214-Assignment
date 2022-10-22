#include "../Miscellaneous/node.h"
#include <stdio.h>
#include <stdlib.h>

int parser(node * temp, char * prefixstr, int len){
    if (len>0){
        len--;
        if(temp->atom!=0){
            if (temp->right==NULL)
                parser(temp->parent,prefixstr,len+1);
            else if (temp->right->atom==0)
                parser(temp->right,prefixstr,len+1);
            else
                parser(temp->parent,prefixstr,len+1);
        }
        else{
            temp->atom = *prefixstr;
            if ( *prefixstr=='*' || *prefixstr == '+' || *prefixstr == '>'){
                temp->left = (node *) calloc(1,sizeof(node));
                temp->right = (node *) calloc(1,sizeof(node));
                temp->left->parent = temp;
                temp->right->parent = temp;
                parser(temp->left,prefixstr+1,len);
            }
            else if (*prefixstr == '~'){
                temp->left = (node *) calloc(1,sizeof(node));
                temp->right = NULL;
                temp->left->parent = temp;
                parser(temp->left,prefixstr+1,len);
            }
            else{
                temp->left=NULL;
                temp->right=NULL;
                parser(temp->parent,prefixstr+1,len);
            }
        }
    }
    else
        return 1; 
}