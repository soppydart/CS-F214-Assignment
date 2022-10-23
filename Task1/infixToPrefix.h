/*! \file infixToPrefix.h
    \brief A documented header file
    
    Contains declaration for infixToPrefix()
*/
/*! \fn  int infixToPrefix(char * infix, char * prefix)
    \brief Reads \a infix and generates it's prefix which is written to \a prefix . 
    \param infix The input string of infix expression
    \param prefix The output string
    \param stack The stack for in-function operations
    \param lenInfix Length of the infix expression
    \return Returns length of \a prefix.
*/
int infixToPrefix(char * infix, char * stack, char * prefix, int lenInfix);