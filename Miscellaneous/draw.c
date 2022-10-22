#include <stdio.h>
#include <math.h>
#include "node.h"
int draw(node * temp, int height){
    int rows,cols=150;
    float div;
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
    char canvas[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            canvas[i][j]=' ';
        }
    }
    node * prev=NULL;
    int x=0,y=cols/2,px=0,py=cols/2,level=0,back=0,diff=0;
    while(temp!=NULL){
        if(back){
            if(temp->right==prev || temp->right==NULL){
                prev=temp;
                temp=temp->parent;
                level--;
                x=px;
                y=py;
                px-=4;
                if(canvas[x][y-1]==' '){
                    py+=(cols/2)/(2*(pow(div,level)))+1;
                }
                else
                    py-=(cols/2)/(2*(pow(div,level)))+1;
                
                back=1;
            }
            else{
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
                if(temp->right==NULL){
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
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
    return 1;
}