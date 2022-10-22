/*! \file height.c
    \brief A documented source file
    
    Contains definition for height()
*/
/*! \var max
    \brief Used to store the maximum value of \a level through the loops
*/
#include <stdio.h>
#include "../Miscellaneous/node.h"
int height(node * temp){
    int max=0,current=0,back=0;
    node * prev=NULL;
    while(temp!=NULL){
        if(temp->left==NULL || back == 1){
            if(temp->right==NULL || temp->right==prev){
                current--;
                prev=temp;
                temp = temp->parent;
                back=1;
            }
            else{
                current++;
                prev = temp;
                temp = temp->right;
                back=0;
            }
        }
        else{
            current++;
            prev = temp;
            temp = temp->left;
            back=0;
        }
        if(current>max)
            max=current;
    }
    return max+1;
}