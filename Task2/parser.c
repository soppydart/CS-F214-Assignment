/** @file parser.c
 *  @brief Contains definition for parser()
 *  @author Saksham Attri
 *  @bug No known bugs.
 */

/* -- Includes -- */

/* libc includes */
#include <stdio.h> /* for referencing to NULL */
#include <stdlib.h> /* for using calloc() */

/* node includes */
#include "../Miscellaneous/node.h" /* for using node Struct */

/** @brief Definition of parser() function
 *
 *  Put profiled data here
 *
 * @return 1
 */
int parser(node * temp, char * prefixstr, int len)
{
    if (len>0){
        len--;
        if(temp->atom!=0){

            // the node has been occupied already

            if (temp->right==NULL)
                parser(temp->parent,prefixstr,len+1);
            else if (temp->right->atom==0)
                parser(temp->right,prefixstr,len+1);
            else
                parser(temp->parent,prefixstr,len+1);
        }
        else{

            // data allocation for the new node

            temp->atom = *prefixstr;
            if ( *prefixstr=='*' || *prefixstr == '+' || *prefixstr == '>'){

                // creating two child nodes

                temp->left = (node *) calloc(1,sizeof(node));
                temp->right = (node *) calloc(1,sizeof(node));

                //parent for child nodes points back to temp

                temp->left->parent = temp;
                temp->right->parent = temp;
                parser(temp->left,prefixstr+1,len); //recursing on left child
            }
            else if (*prefixstr == '~'){

                // ~ operator has only left child node, right one is set to NULL

                temp->left = (node *) calloc(1,sizeof(node));
                temp->right = NULL;

                //parent for child node points back to temp

                temp->left->parent = temp;
                parser(temp->left,prefixstr+1,len); //recursing on left child
            }
            else{

                // a non operator atom has no children

                temp->left=NULL;
                temp->right=NULL;

                // recurse on the parent atom 
                
                parser(temp->parent,prefixstr+1,len);
            }
        }
    }
    else
        return 1; 
}