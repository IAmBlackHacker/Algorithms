# include<iostream>
# include<stdlib.h>
# include<conio.h>
# include<cstdlib>
# include<stack>
using namespace std;
struct node
{
    char info;
    bool notvisit=true;
    struct node *left;
    struct node *right;
}*root;

void find(int item, node **par, node **loc)
{
    node *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->info)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->left;
	else
	    ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}

void insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"\n\n\n                     ROOT NODE IS ADDED"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"\n\n\n                     ELEMENT ALREADY IN THE TREE"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);
        }
        else
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"\n\n\n                     NODE ADDED TO LEFT"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"\n\n\n                     NODE ADDED TO RIGHT"<<endl;
            return;
        }
    }
}

void case_a(node *par, node *loc )
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}

void case_b(node *par, node *loc)
{
    node *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}

void case_c(node *par, node *loc)
{
    node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}

void del(char item)
{
    node *parent, *location;
    if (root == NULL)
    {
        cout<<"\n\n\n                     TREE IS EMPTY,NOTHING TO DELETE"<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"\n\n\n                     ITEM NOT PRESENT IN TREE"<<endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);
    free(location);
    cout<<"\n\n\n                     "<<item<<" IS DELETED SUCCESSFULLY."<<endl;
}



void preorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"\n\n\n                     TREE IS EMPTY,NOTHING TO TRAVERSAL."<<endl;
        return;
    }
    cout<<"  ";
    if (ptr != NULL)
    {
        cout<<ptr->info<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"\n\n\n                     TREE IS EMPTY,NOTHING TO TRAVERSAL."<<endl;
        return;
    }
    cout<<"  ";
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<"  ";
        inorder(ptr->right);
    }
}

void postorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"\n\n\n                     TREE IS EMPTY,NOTHING TO TRAVERSAL."<<endl;
        return;
    }
    cout<<"  ";
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<"  ";
    }
}

/*void display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->info<<endl;
        display(ptr->left, level+1);
    }
}*/

void display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}

void search_non_recursive(char num)
{
    node *ptr=root;
    /*stack<node*> temp;
    temp.push(ptr);
    while(!temp.empty())
    {
        if(ptr->right!=NULL && ptr->right->notvisit){
            ptr->right->notvisit=false;
            ptr=ptr->right;
            temp.push(ptr);
            continue;
        }
             if(num==ptr->info){
                cout<<"[";
             }
             cout<<ptr->info;
             if(num==ptr->info){
                cout<<"]";
             }
             cout<<endl;
        if(temp.top()->left!=NULL && ptr->left->notvisit){
            ptr->left->notvisit=false;
            ptr=temp.top()->left;
            temp.push(ptr);
            continue;
        }
        {
             temp.pop();
             ptr=temp.top();
        }
    }*/
    while(ptr!=NULL){
        if(ptr->info==num){
                cout<<"\n\n                     ELEMENT "<<num<<" IS SUSSESSFULY FOUND .....";
                return;
        }
        else if(ptr->info > num){

            ptr=ptr->left;
        }
        else{

            ptr=ptr->right;
        }
    }
    cout<<"\n\n                     ELEMENT "<<num<<" IS NOT FOUND .....";
}
int main()
{
    int choice;
    char num;
    root=NULL;
    node *temp;
    while (1)
    {
        system("cls");
        cout<<"\t----------------------------------------"<<endl;
        cout<<"\t|           OPERATIONS ON BST          |"<<endl;
        cout<<"\t----------------------------------------\n"<<endl;
        cout<<"\t\t1. INSERT ELEMENT "<<endl;
        cout<<"\t\t2. DELETE ELEMENT "<<endl;
        cout<<"\t\t3. INORDER TRAVERSAL"<<endl;
        cout<<"\t\t4. PREORDER TRAVERSAL"<<endl;
        cout<<"\t\t5. POSTORDER TRAVERSAL"<<endl;
        cout<<"\t\t6. DISPLAY"<<endl;
        cout<<"\t\t7. NON_RECURSIVE_SEARCH"<<endl;
        cout<<"\t\t8. QUIT"<<endl;
        cout<<"\t\nENTER YOUR CHOICE : ";
        choice=int(getche())-48;
        system("cls");
        switch(choice)
        {
        case 1:
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\t|            INSERT IN BST             |"<<endl;
            cout<<"\t----------------------------------------\n"<<endl;
            temp = new node;
            cout<<"\n\nEnter the number to be inserted : ";
            temp->info=getche();
            insert(root, temp);
            cout<<"\n\n                     Please [ENTER] TO Continue......";
            getch();
            break;
        case 2:
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\t|            DELETE FROM BST           |"<<endl;
            cout<<"\t----------------------------------------\n"<<endl;
            if (root == NULL)
            {
                cout<<"\n\n\n                 TREE IS EMPTY, NOTHING TO DELETE"<<endl;
                getch();
                continue;
            }
            cout<<"Enter the number to be deleted : ";
            num=getche();
            del(num);
            cout<<"\n\n                     Please [ENTER] TO Continue......";
            getch();
            break;
        case 3:
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\t|       INORDER TRAVERSAL OF BST       |"<<endl;
            cout<<"\t----------------------------------------\n"<<endl;
            inorder(root);
            cout<<endl;
            cout<<"\n\n\n\n                     Please [ENTER] TO Continue......";
            getch();
            break;
        case 4:
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\t|      PREORDER TRAVERSAL OF BST       |"<<endl;
            cout<<"\t----------------------------------------\n"<<endl;
            preorder(root);
            cout<<endl;
            cout<<"\n\n\n\n                     Please [ENTER] TO Continue......";
            getch();
            break;
        case 5:
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\t|     POSTORDER TRAVERSAL OF BST       |"<<endl;
            cout<<"\t----------------------------------------\n"<<endl;
            postorder(root);
            cout<<endl;
            cout<<"\n\n\n\n                     Please [ENTER] TO Continue......";
            getch();
            break;
        case 6:
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\t|             DISPLAY BST              |"<<endl;
            cout<<"\t----------------------------------------\n"<<endl;
            if (root == NULL)
            {
                cout<<"\n\n\n                 TREE IS EMPTY, NOTHING TO DISPLAY"<<endl;
                getch();
                continue;
            }
            display(root,1);
            cout<<endl;
            cout<<"\n\n\n\n---------------------------------------------------------------------------------------------------------------\n                     Please [ENTER] TO Continue......";
            getch();
            break;
        case 7:
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\t|      INSERT ELEMENT TO SEARCH        |"<<endl;
            cout<<"\t----------------------------------------\n"<<endl;
            if (root == NULL)
            {
                cout<<"\n\n\n                 TREE IS EMPTY, NOTHING TO SEARCH"<<endl;
                getch();
                continue;
            }
            cout<<"Enter the number to be search : ";
            search_non_recursive(getche());
            cout<<"\n\n                     Please [ENTER] TO Continue......";
            cout<<endl;
            cout<<"\n\n\n\n---------------------------------------------------------------------------------------------------------------\n                     Please [ENTER] TO Continue......";
            getch();
            break;
        case 8:
            exit(1);
        default:
            cout<<"\n\n\n\n                 WRONG CHOICE ...!"<<endl;
            getch();
        }
    }
}

