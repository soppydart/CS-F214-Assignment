/** @file height.c
 *  @brief Contains definition for height()
 *  @author Saksham Attri
 *  @bug No known bugs.
 */

/* -- Includes -- */

/* libc includes */
#include <stdio.h> /* for referencing to NULL */

/* node includes */
#include "../Miscellaneous/node.h" /* for using the node struct */

/** @brief Definition of height() function
 *
 *  Put profiled data here
 *
 * @return Height of binary parse tree with root at @a temp
 */
int height(node * temp)
{
    int max=0,current=0,back=0; // Initialize variables
    node * prev=NULL;
    while(temp!=NULL){ // loop terminates when temp points to NULL
        if(temp->left==NULL || back == 1){
            /*
            * temp has reached tree endpoint or it has travelled back up to the parent node
            */
            if(temp->right==NULL || temp->right==prev){
                /*
                * temp can't travel right so it visits parent
                */
                current--;
                prev=temp;
                temp = temp->parent;
                back=1;
            }
            else{
                /*
                * temp travels right
                */
                current++;
                prev = temp;
                temp = temp->right;
                back=0;
            }
        }
        else{
            /*
            * temp travels left
            */
            current++;
            prev = temp;
            temp = temp->left;
            back=0;
        }
        if(current>max)
            max=current; // update max
    }
    return max+1; // height
}