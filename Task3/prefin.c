/** @file prefin.c
 *  @brief Contains definition for prefin()
 *  @author Saksham Attri
 *  @bug No known bugs.
 */

/* -- Includes -- */

/* libc includes */
#include <stdio.h> /* for referencing to printf() and NULL */

/* node includes */
#include "../Miscellaneous/node.h" /* to use node Struct */

/** @brief Definition of prefin() function
 *
 *  Put profiled data here
 *
 * @return Void
 */
void prefin(node * temp)
{
    if (!( temp->left!=NULL && temp->right==NULL)){

        // temp has two child leaves so it's atom is not ~ operator

        if (temp->left!=NULL){
            printf("(");
            prefin(temp->left);     //print infix of left branch
        }
        printf("%c",temp->atom);    // print current root's atom value
        if (temp->right!=NULL){
            prefin(temp->right);    //print infix of right branch
            printf(")");
        }
    }
    else{

        // temp is a ~ operator

        printf("(");
        printf("%c",temp->atom);
        if (temp->left!=NULL){
            printf("(");
            prefin(temp->left);     // print infix of left branch
            printf(")");
        }
        printf(")");
    }
}