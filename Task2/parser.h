/*! \file parser.h
    \brief A documented header file
    
    Contains declaration for parser()
*/
/*! \fn  int parser(node * temp, char * a, int size)
    \brief Generates a binary rooted parse tree, with root at \a temp , from string \a prefixstr of length \a len where \a prefixstr is a proposition in prefix form.  
    \param temp The root node for binary tree.
    \param prefixstr The input propositional formula in prefix form.
    \param len The length of \a prefixstr .
*/
int parser(node * temp, char * prefixstr, int len);