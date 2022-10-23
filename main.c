/** @file main.c
 *  @brief Contains main()
 *  @author Saksham Attri
 *  @bug For larger inputs, during drawing the parse tree one atom may overwrite another thus distorting the output. Also, while evaluating truth value, for the same atom used in different places, user has to enter it's truth value every time.
 */

/* -- Includes -- */

/* libc includes */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/* custom headers */
#include "Miscellaneous/node.h"
#include "Miscellaneous/draw.h"
#include "Task1/infixToPrefix.h"
#include "Task2/parser.h"
#include "Task3/prefin.h"
#include "Task4/height.h"
#include "Task5/judge.h"

/** @brief Declaration and Definition of main() function
 *
 *  Enter profiling data here
 *
 * @return 0
 */
int main(){
    char ch, *infix; 
    int i = 0, lenInfix = 0, j = 10; 

    //Initial memory allocation for input infix expression

    infix=(char *) malloc(10*sizeof(char));

    // A cute welcome message

    printf("───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───\n───█▒▒░░░░░░░░░▒▒█───\n────█░░█░░░░░█░░█────\n─▄▄──█░░░▀█▀░░░█──▄▄─\n█░░█─▀▄░░░░░░░▄▀─█░░█\n█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█\n█░░║║║╠─║─║─║║║║║╠─░░█\n█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█\n"); 
    printf("\nPlease enter the infix propositional formula \n>"); 
    while((ch=getchar())!='\n'){ 
        if(i>j-2){ 

            // Memory realloc if we're falling short

            infix=realloc(infix,(i+10)*sizeof(char)); 
            j=i+10; 
        }
        if(ch!='\b'){ 
            infix[i]=ch;    // Storing the input
            i++; 
        }
        else 
            i--;    // A backspace character was used
    }
    infix[i]='\0';  // infix is a string
    lenInfix = i-1;
    char prefix[lenInfix];  // creating buffer to store prefix
    char stack[lenInfix];
    int lenPrefix = infixToPrefix(infix,stack,prefix,lenInfix);
    printf("The prefix form of above input is : %s",prefix);

    // creating root for binary tree

    node * root = (node *) calloc(1,sizeof(node));
    root->parent = NULL;

    // generating the parse tree

    printf("\nMaking the parse tree ...\n");
    if(parser(root,prefix,lenPrefix))
        printf("\n Tree was made \n");

    int h = height(root);

    // drawing the tree

    printf("\nDo you want to print the tree (not recommended for height > 4 , current height: %d)? (experimental) (y/n): ",h);
    char choice;
    scanf("%c",&choice);
    if (choice == 'y' || choice == 'Y')
        draw(root,h);

    // converting prefix back to infix by in-order traversal

    printf("\nConverting prefix back to infix by in-order traversal ... \n");
    prefin(root);

    // printing height of tree

    printf("\nHeight of the parse tree is %d units !\n",h);

    // evaluating truth value of the proposition 

    printf("\nBeginning truth value evualuation for the proposition ...\n");
    if(judge(root)){
        printf("\n        proposition true, done doggo a happy\n                \\ \n                 \\ \n                /^-----^\\ \n                V  o o  V\n                 |  Y  |\n                  \\ ◡ /\n                  / - \\ \n                  |    \\ \n                  |     \\     ) \n                  || (___\\====\n");
    }
    else{
        printf("\n        proposition false, done doggo a sad\n                \\ \n                 \\ \n                /^-----^\\ \n                V  o o  V\n                 |  Y  |\n                  \\ ⌓ /\n                  / - \\ \n                  |    \\ \n                  |     \\     ) \n                  || (___\\====\n");
    }

    // option to run the code again for a new input

    printf("\nDo you want to repeat for another input: (y/n) \n>");
    char choice2;
    getchar();
    scanf("%c",&choice2);
    if (choice2 == 'y' || choice2 == 'Y'){
        getchar();
        main();
    }
    else
        printf("\nExiting ...\n");
    return 0;
}