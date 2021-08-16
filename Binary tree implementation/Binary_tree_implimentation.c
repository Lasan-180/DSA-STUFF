#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node *right; 
    struct node *left; 
};

//create a newnode
struct node* newnode(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

//insert data into the binary tree
struct node* insert(struct node *root, int x)
{
    if(root==NULL)
        return newnode(x);
    else if(x>root->data) 
        root->right = insert(root->right, x);
    else 
        root->left = insert(root->left,x);
    return root;
}

//search
struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) 
        return root;
    else if(x>root->data) 
        return search(root->right, x);
    else 
        return search(root->left,x);
}

//find the minimum
struct node* minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) 
        return minimum(root->left); 
    
    return root;
}

//delete a node
struct node* delete(struct node *root, int x)
{
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right = delete(root->right, x);
    else if(x<root->data)
        root->left = delete(root->left, x);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        else
        {
            struct node *temp = minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}


void inorder_traverse(struct node *root)
{
    if(root!=NULL) 
    {
        inorder_traverse(root->left);
        printf(" %d ", root->data); 
        inorder_traverse(root->right);
    }
}

int main()
{
    struct node *root,*mini,*find;
    root = newnode(34);
    insert(root,6);
    insert(root,11);
    insert(root,15);
    insert(root,8);
    insert(root,14);
    insert(root,2);
   
   	printf("The binary tree in inorder proceeding : "); 
    inorder_traverse(root);
    printf("\n");
    
    mini=minimum(root);
	printf("\nThe minimum value is : %d\n",mini->data);

    delete(root, 2);
    delete(root, 11);
    
    printf("\nAfter the deletion : ");
    inorder_traverse(root);
	printf("\n");
	
	mini=minimum(root);
	printf("\nThe minimum value is : %d\n",mini->data);
	
	find=search(root,8);
	printf("\nThe serch value is %d and its address is %x",find->data,find);

    return 0;
}
