/** @file judge.c
 *  @brief Contains definition for judge()
 */

/* -- Includes -- */

/* libc includes */
#include <stdio.h> /* for referencing to NULL, printf() and scanf() */

/* node includes */
#include "../Miscellaneous/node.h" /* for using the node struct */

/** @brief Definition of judge() function
 *  When asked for input, enter 1 for true, 0 for false
 * @return 1 if true, 0 if false
 */
int judge(node * temp, char arr[])
{
    static int val;     // contains truth value of expression created at root
    static int unique;
    int a,b;
    if (temp->left!=NULL)
        a = judge(temp->left, arr);      // contains truth value of left branch
    if (temp->right!=NULL)
        b = judge(temp->right, arr);     // contains truth value of right branch
    char ch = temp->atom;
    if (ch == '*')
        val = a&&b;                 // Implementing a AND b
    else if (ch == '+')
        val = a||b;                 // Implementing a OR b
    else if (ch == '>')
        val = (!a)+b;               // Implementing a IMPLIES b
    else if (ch == '~')
        val = !a;                   // Implementing NOT a
    else {
        int found = 0;
        for (int i=0 ; i<unique ; i+=2){
            if (ch == arr[i]){
                val = (int) arr[i+1];
                found = 1;
                break;
            }
        }
        // input truth values of the propositional atoms
        if(!found){
            arr[unique]=ch;
            printf("Enter truth value for %c: ",ch);
            scanf(" %c",&arr[unique+1]);
            val = (int) arr[unique+1] - 48;
            unique+=2;
        }
    }
    return val;
}