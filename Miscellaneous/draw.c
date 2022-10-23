/** @file draw.c
 *  @brief Contains definition for draw()
 *  @bug For larger inputs, one atom may overwrite another thus distorting the output.
 */

/* -- Includes -- */

/* libc includes */
#include <stdio.h> /* for referencing to NULL and printf() */
#include <math.h> /* for using pow() */

/* node includes */
#include "../Miscellaneous/node.h" /* for using node Struct */

/** @brief Definition of height() function
 *
 *  This function is experimental
 * 
 *  Put profiled data here 
 *
 * @return 1
 */
int draw(node * temp, int height)
{
    int rows,cols=150;          // setting up total printable area
    float div;                  // length of child branch = length of parent / div

    // attempt to get better outputss for different heights

    if(height <= 4)
        div = 2;
    else if (height <= 6)
        div = 1.5;
    else if (height < 9)
        div = 1.25;
    else if (height < 15)
        div = 1.125;
    else if (height < 30)
        div = 1.075;
    rows=5*(height);
    char canvas[rows][cols];    // create 2D array that serves as buffer for the output

    // fill all canvas with whitespaces

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            canvas[i][j]=' ';
        }
    }

    // drawing logic loop

    node * prev=NULL;
    int x=0,y=cols/2,px=0,py=cols/2,level=0,back=0,diff=0;
    while(temp!=NULL){
        if(back){

            // this node has already been added to canvas

            if(temp->right==prev || temp->right==NULL){

                // right child node has already been added to canvas or there isn't any 

                prev=temp;
                temp=temp->parent;
                level--;
                x=px;
                y=py;
                px-=4;
                if(canvas[x][y-1]==' '){                    // node is left oriented 
                    py+=(cols/2)/(2*(pow(div,level)))+1;
                }
                else                                        // node is right oriented
                    py-=(cols/2)/(2*(pow(div,level)))+1;    
                
                back=1;
            }
            else{

                // right node hasn't been added to canvas

                px=x;
                py=y;
                x+=4;
                diff=(cols/2)/(2*(pow(div,level+1)));
                canvas[x][y]='+';
                canvas[x][y+diff+1]='+';
                for(int i=1;i<diff+1;i++){
                    canvas[x][y+i]='-';
                }
                y+=diff+1;
                prev=temp;
                temp=temp->right;
                level++;
                back=0;
            }
        }
        else{

            //add the atom to the canvas

            canvas[x+1][y-2]='.';
            canvas[x+1][y-1]=':';
            canvas[x+1][y]=':';
            canvas[x+1][y+1]=':';
            canvas[x+1][y+2]='.';
            canvas[x+2][y-3]=':';
            canvas[x+2][y-2]=':';
            canvas[x+2][y-1]=' ';
            canvas[x+2][y]=temp->atom;
            canvas[x+2][y+1]=' ';
            canvas[x+2][y+2]=':';
            canvas[x+2][y+3]=':';
            canvas[x+3][y-2]='\'';
            canvas[x+3][y-1]=':';
            canvas[x+3][y]=':';
            canvas[x+3][y+1]=':';
            canvas[x+3][y+2]='\'';
            if(temp->left==NULL){

                // atom is endpoint of the tree

                if(temp->right==NULL){

                    // going back to parent

                    prev=temp;
                    temp=temp->parent;
                    level--;
                    x=px;
                    y=py;
                    px=x-4;
                    if(canvas[x][y-1]==' '){
                    py+=(cols/2)/(2*(pow(div,level)))+1;
                    }
                    else
                        py-=(cols/2)/(2*(pow(div,level)))+1;
                    back=1;
                }
            }
            else{

                // travels to the left branch

                px=x;
                py=y;
                x+=4;
                if (temp->atom!='~'){
                    diff=(cols/2)/(2*(pow(div,level+1)));
                    canvas[x][y]='+';
                    canvas[x][y-diff-1]='+';
                    for(int i=1;i<diff+1;i++){
                        canvas[x][y-i]='-';
                    }
                    y-=diff+1;
                }
                else{
                    canvas[x][y]='+';
                }
                prev=temp;
                temp=temp->left;
                level++;
                back=0;
            }
        }
    }

    // print the final canvas

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
    return 1;
}