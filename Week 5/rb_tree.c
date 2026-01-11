#include<stdio.h>
#include<stdlib.h>
typedef enum{RED,BLACK}Color;
typedef struct RBNode{
    int data;
    Color color;
    struct RBNode*left,*right,*parent;
}RBNode;
RBNode*root=NULL;
RBNode*createNode(int data){
    RBNode*n=(RBNode*)malloc(sizeof(RBNode));
    n->data=data;
    n->color=RED;
    n->left=n->right=n->parent=NULL;
    return n;
}
void leftRotate(RBNode**root,RBNode*x){
    RBNode*y=x->right;
    x->right=y->left;
    if(y->left){
        y->left->parent=x;
    }
    y->parent=x->parent;
    if(!x->parent){
        *root=y;
    }
    else if(x==x->parent->left){
        x->parent->left=y;
    }
    else{
        x->parent->right=y;
    }
    y->left=x;
    x->parent=y;
}
void rightRotate(RBNode**root,RBNode*y){
    RBNode*x=y->left;
    y->left=x->right;
    if(x->right){
        x->right->parent=y;
    }
    x->parent=y->parent;
    if(!y->parent){
        *root=x;
    }
    else if(y==y->parent->left){
        y->parent->left=x;
    }
    else{
        y->parent->right=x;
    }
    x->right=y;
    y->parent=x;
}
void fixInsert(RBNode**root,RBNode*z)
{
    while(z!=*root&&z->parent->color==RED){
        RBNode*p=z->parent;
        RBNode*g=p->parent;
        if(p==g->left){
            RBNode*u=g->right;
            if(u&&u->color==RED){
                g->color=RED;
                p->color=BLACK;
                u->color=BLACK;
                z=g;
            }
            else{
                if(z==p->right){
                    z=p;
                    leftRotate(root,z);
                }
                p->color=BLACK;
                g->color=RED;
                rightRotate(root,g);
            }
        }
        else{
            RBNode*u=g->left;
            if(u&&u->color==RED){
                g->color=RED;
                p->color=BLACK;
                u->color=BLACK;
                z=g;
            }
            else{
                if(z==p->left){
                    z=p;
                    rightRotate(root,z);
                }
                p->color=BLACK;
                g->color=RED;
                leftRotate(root,g);
            }
        }
    }
    (*root)->color=BLACK;
}
void insertRB(int data){
    RBNode*z=createNode(data);
    RBNode*y=NULL;
    RBNode*x=root;
    while(x){
        y=x;
        if(z->data<x->data){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    z->parent=y;
    if(!y){
        root=z;
    }
    else if(z->data<y->data){
        y->left=z;
    }
    else{
        y->right=z;
    }
    fixInsert(&root,z);
}
void inorder(RBNode*r){
    if(r){
        inorder(r->left);
        printf("%d ",r->data);
        inorder(r->right);
    }
}
int main(){
    int a[]={20,15,25,10,5,1,30};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        insertRB(a[i]);
    }
    inorder(root);
    return 0;
}