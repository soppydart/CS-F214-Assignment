/*! \file node.h
    \brief A documented header file
    
    Contains declaration for node
*/
/*! \struct node
    \brief Structure definition for \a node
    \param parent Points to the parent node.
    \param left Points to the left child node.
    \param right Points to the right child node.
*/
/*! \var typedef struct node node
    \brief A type definition for node
*/
struct node{
    struct node * parent; 
    struct node * left;
    char atom;
    struct node * right;
};
typedef struct node node;