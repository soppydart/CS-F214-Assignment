/*! \file judge.h
    \brief A documented header file
    
    Contains declaration for judge()
*/
/*! \fn  int judge(node * temp)
    \brief Returns truth value of proposition by bottom up traversal of binary parse tree with root at \a temp
    \param temp The root node for binary tree
    \param a Pointer to an array of characters which will be used to store unique atoms and their truth values
*/
int judge(node * temp, char a[]);