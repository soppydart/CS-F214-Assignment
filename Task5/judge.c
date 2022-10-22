#include <stdio.h>
#include "../Miscellaneous/node.h"
int judge(node * temp){
    static int val;
    int a,b;
    if (temp->left!=NULL)
        a = judge(temp->left);
    if (temp->right!=NULL)
        b = judge(temp->right);
    char ch = temp->atom;
    if (ch == '*')
        val = a&&b;
    else if (ch == '+')
        val = a||b;
    else if (ch == '>')
        val = (!a)+b;
    else if (ch == '~')
        val = !a;
    else {
        printf("Enter truth value for %c: ",ch);
        scanf("%d",&val);
    }
    return val;
}