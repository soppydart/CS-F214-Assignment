/** @file freee.c
 *  @brief Contains definition for freee()
 *  @bug No known bugs.
 */

/* -- Includes -- */

/* libc includes */
#include <stdio.h> /* for referencing to NULL */
#include "node.h" /* for using the node struct*/
#include <stdlib.h> /* for using free() */

int freee(node * temp){
    if (temp->left==NULL && temp->right==NULL){
        free(temp); // frees the node if it has no children
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