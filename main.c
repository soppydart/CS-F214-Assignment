#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Miscellaneous/node.h"
#include "Miscellaneous/draw.h"
#include "Task1/infixToPrefix.h"
#include "Task2/parser.h"
#include "Task3/prefin.h"
#include "Task4/height.h"
#include "Task5/judge.h"

int main(){
    char ch, *infix; 
    int i = 0, lenInfix = 0, j = 10; 
    node * root = (node *) calloc(1,sizeof(node));
    root->parent=NULL;
    //Dynamic Memory allocation while taking input 
    infix=(char *) malloc(10*sizeof(char));
    printf("───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───\n───█▒▒░░░░░░░░░▒▒█───\n────█░░█░░░░░█░░█────\n─▄▄──█░░░▀█▀░░░█──▄▄─\n█░░█─▀▄░░░░░░░▄▀─█░░█\n█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█\n█░░║║║╠─║─║─║║║║║╠─░░█\n█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█\n"); 
    printf("\nPlease enter the infix propositional formula \n>"); 
    while((ch=getchar())!='\n'){ 
        if(i>j-2){ 
            infix=realloc(infix,(i+10)*sizeof(char)); 
            j=i+10; 
        }
        if(ch!='\b'){ 
            infix[i]=ch; 
            i++; 
        }
        else 
            i--; 
    }
    infix[i]='\0';
    lenInfix = i-1;
    char prefix[lenInfix];
    int lenPrefix = infixToPrefix(infix,prefix);
    //printf("The prefix form of above input is : %s",prefix);
    printf("\nMaking the parse tree ...\n");
    // if(parser(root,prefix,lenPrefix))
    //     printf("\n Tree was made \n");
    // int h = height(root);
    //printf("\nDo you want to print the tree (not recommended for height > 6 , current height: %d)? (experimental) (y/n): ",h);
    // char choice;
    // scanf("%c",choice);
    // if (choice == 'y' || choice == 'Y')
    //     draw(root,h);
    printf("\nConverting prefix back to infix by in-order traversal ... \n");
    //prefin(root);
    //printf("\nHeight of the parse tree is %d units !\n",h);
    printf("\nBeginning truth value evualuation for the proposition ...\n");
    // if(judge(root)){
    //     printf("\n        proposition true, done doggo a happy\n                \\ \n                 \\ \n                /^-----^\\ \n                V  o o  V\n                 |  Y  |\n                  \\ ◡ /\n                  / - \\ \n                  |    \\ \n                  |     \\     ) \n                  || (___\\====\n");
    // }
    // else{
    //     printf("\n        proposition false, done doggo a sad\n                \\ \n                 \\ \n                /^-----^\\ \n                V  o o  V\n                 |  Y  |\n                  \\ ⌓ /\n                  / - \\ \n                  |    \\ \n                  |     \\     ) \n                  || (___\\====\n");
    // }
    printf("\nDo you want to repeat for another input: (y/n) \n>");
    char choice2;
    scanf("%c",&choice2);
    if (choice2 == 'y' || choice2 == 'Y')
        main();
    return 0;
}