
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

void clrscr()
{
	system("@cls||clear");
}


struct node{
	int data;
	struct node* left;
	struct node* right;
};


struct node* newNode(int data)
{
	node* node = (struct node*)malloc(sizeof(struct node));
	
	node->data = data;
	
	node->left = NULL;
	
	node->right = NULL;
	
	return node;
}



int isRootNull(node* root)
{
	if(root == NULL)
	{
		return 1;	
	}	
	
	else
	{
		return 0;
	}
}

int toplam = 0;

int i = 0;


int sumLeafNodes(node* root)
{
	if(isRootNull(root))
	{
		printf("\nisRootnull'a girdi");
		return toplam;
	}
	
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			toplam += root->data;
		}
		
		else
		{
			if(root->left != NULL)
			{
				sumLeafNodes(root->left);
			}
			
			if(root->right != NULL)
			{
				sumLeafNodes(root->right);
			}
		}
	}
}



int main()
{
	setlocale(LC_ALL, "Turkish");		// Türkçe Karakter Kullanmak Ýçin
	
	
	struct node* root = newNode(1);
	
	root->left = newNode(2);
	
	root->right = newNode(3);
	
	root->left->left = newNode(4);
	
	root->left->left->left = newNode(41);
	
	root->right->right = newNode(62);
	
	
	/*   /	\		1
				  /  \
				 2	  3
			   /	   \
			  4 		62
			 /
		    41
		    
		    Non-Leaf yani hem right hem left child'ý olmayan düðümlerin toplamý = 62 + 41 = 103
	
	*/
	printf("\n\n\nSum of Leaf Nodes in this binary tree = %d",sumLeafNodes(root));
	
	getch();
	return 0;
}
