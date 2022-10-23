/** @file freee.c
 *  @brief Contains definition for freee()
 *  @author Saksham Attri
 *  @bug No known bugs.
 */

/* -- Includes -- */

/* libc includes */
#include <stdio.h> /* for referencing to NULL */
#include "node.h" /* for using the node struct*/

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