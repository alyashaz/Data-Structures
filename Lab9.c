#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

treeNode* FindMin(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->left) /* Go to the left sub tree to find the min element */
                return FindMin(node->left);
        else
                return node;
}

treeNode * inOrderSuccessor(treeNode *root, treeNode *n)
{
    // step 1 of the above algorithm
    if( n->right != NULL )
        return FindMin(n->right);

    treeNode *succ = NULL;

    // Start from root and search for successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }

    return succ;
}

treeNode* FindMax(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->right) /* Go to the left sub tree to find the min element */
                FindMax(node->right);
        else
                return node;
}

treeNode * Insert(treeNode *node, int data)
{
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = NULL;
		temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right, data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left, data);
        }
        /* Else there is nothing to do as the data is already in the tree. */
        return node;

}

treeNode * Delete(treeNode *node, int data)
{
        treeNode *temp;
        if(node==NULL)
        {
                printf("Element Not Found");
        }
        else if(data < node->data)
        {
                node->left = Delete(node->left, data);
        }
        else if(data > node->data)
        {
                node->right = Delete(node->right, data);
        }
        else
        {
                /* Now We can delete this node and replace with either minimum element 
                   in the right sub tree or maximum element in the left subtree */
                if(node->right && node->left)
                {
                        /* Here we will replace with minimum element in the right sub tree */
                        temp = FindMin(node->right);
                        node -> data = temp->data; 
                        /* As we replaced it with some other node, we have to delete that node */
                        node -> right = Delete(node->right,temp->data);
                }
                else
                {
                        /* If there is only one or zero children then we can directly 
                           remove it from the tree and connect its parent to its child */
                        temp = node;
                        if(node->left == NULL)
                                node = node->right;
                        else if(node->right == NULL)
                                node = node->left;
                        free(temp); /* temp is longer required */ 
                }
        }
        return node;

}

treeNode * Find(treeNode *node, int data)
{
        if(node==NULL)
        {
                /* Element is not found */
                return NULL;
        }
        if(data > node->data)
        {
                /* Search in the right sub tree. */
                return Find(node->right,data);
        }
        else if(data < node->data)
        {
                /* Search in the left sub tree. */
                return Find(node->left,data);
        }
        else
        {
                /* Element Found */
                return node;
        }
}

void PrintInorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left);
        printf("%d ",node->data);
        PrintInorder(node->right);
}

void PrintPreorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        printf("%d ",node->data);
        PrintPreorder(node->left);
        PrintPreorder(node->right);
}

void PrintPostorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintPostorder(node->left);
        PrintPostorder(node->right);
        printf("%d ",node->data);
}

int main()
{
        treeNode *root = NULL, *succ, *success;
        root = Insert(root, 5);
        root = Insert(root, 3);
        root = Insert(root, 7);
        root = Insert(root, 1);
        root = Insert(root, 4);
        root = Insert(root, 6);
        root = Insert(root, 8);
        root = Insert(root, 0);
	root = Insert(root, 2);
	root = Insert(root, 9);
        PrintInorder(root);
        printf("\n");
        root = Delete(root,5);
        root = Delete(root,9);
        PrintInorder(root);
        printf("\n");
        treeNode * temp;
        temp = FindMin(root);
        printf("Minimum element is %d\n",temp->data);
        temp = FindMax(root);
        printf("Maximum element is %d\n",temp->data);
        temp = Find(root,8);
        if(temp==NULL)
        {
                printf("Element 8 not found\n");
        }
        else
        {
                printf("Element 8 Found\n");
        }
        temp = Find(root,5);
        if(temp==NULL)
        {
                printf("Element 2 not found\n");
        }
        else
        {
                printf("Element 6 Found\n");
        }
	treeNode *root1 = NULL;
	success = root->right;

	succ = inOrderSuccessor(root1, success);
	if(succ != NULL)
		printf("\nInorder Successor of %d is %d\n", success->data, succ->data);
	else
		printf("\nInorder Successor doesn't exist\n");
}
