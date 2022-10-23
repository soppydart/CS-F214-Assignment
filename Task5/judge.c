/** @file judge.c
 *  @brief Contains definition for judge()
 *  @bug For the same atom used in different places, user has to enter it's truth value every time
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
int judge(node * temp)
{
    static int val;     // contains truth value of expression created at root
    int a,b;
    if (temp->left!=NULL)
        a = judge(temp->left);      // contains truth value of left branch
    if (temp->right!=NULL)
        b = judge(temp->right);     // contains truth value of right branch
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

        // input truth values of the propositional atoms

        printf("Enter truth value for %c: ",ch);
        scanf("%d",&val);
    }
    return val;
}