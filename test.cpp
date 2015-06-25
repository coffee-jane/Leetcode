

#include <iostream>

using namespace std;

class BinarySearchTree {
    private:
        struct tree_node
        {
          tree_node* left;
          tree_node* right;
          int data;
        };

        tree_node* root;
    public:
        BinarySearchTree()
        {
          root = NULL;
        }

        bool isEmpty() const
        {
        return root == NULL;
        }
      void print_inorder();
      void inorder(tree_node*);
      void print_preorder();
      void preorder(tree_node*);
      void print_postorder();
      void postorder(tree_node*);
      void insert(int);
      void remove(int);
};


void BinarySearchTree::insert(int d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t -> data = d;
    t -> left = NULL;
    t -> right = NULL;
    parent = NULL;

    if (isEmpty())
        root = t;
    else
    {
        tree_node* curr;
        curr = root;
        while(curr)
        {
            parent = curr;
            if(t -> data > curr -> data)
                curr = curr -> right;
            else
                 curr = curr -> left;
        }

        if (t -> data > parent -> data)
            parent -> right = t;
        else
            parent -> left = t;
    }
}

void BinarySearchTree::remove(int d)
{
    bool found = false;
    if(isEmpty())
    {
        cout<<"This Tree is empty!"<<endl;
        return;
    }

    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr !=NULL)
    {
        if(curr -> data == d)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if(d > curr -> data)
                curr = curr -> right;
            else
                curr = curr -> left;
        }
    }

    if (!found)
    {
    cout<<"Data not found! "<<endl;
    return;
    }

    if(found)
    {
    if ((curr -> left == NULL && curr -> right != NULL)||
            (curr -> left != NULL && curr -> right == NULL))
    {
        if(curr -> left == NULL && curr -> right != NULL)
        {
            if(parent -> left == curr)
        {
            parent -> left = curr -> left;
            delete curr;
        }
        else
        {
            parent -> right = curr -> right;
            delete curr;
        }
    }
    else
    {
        if(parent -> left == curr)
        {
            parent -> left = curr -> left;
            delete curr;
        }
        else
        {
            parent -> right = curr -> left;
            delete curr;
        }
    }
    return;
    }

    if(curr -> left == NULL && curr -> right == NULL)
    {
        if(parent -> left == curr)
            parent -> left =NULL;
        else
            parent -> right = NULL;
        delete curr;
        return;
    }

 if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        tree_node* chkr1;
        tree_node* chkr2;
        chkr = curr->left;
        int i;
        if(chkr->right == NULL)
        {
            parent -> left = chkr;
            chkr -> left = curr -> left;
            chkr -> right = curr -> right;
            delete curr;
        }
        else // right child has children
        {
                while(chkr -> right != NULL)
                {
                    chkr1 = chkr;
                    chkr = chkr -> right;
                }

                if(chkr -> left != NULL)
                {
                    chkr2 = chkr -> left;
                    chkr1 -> right = chkr2;
                }
                parent -> left = chkr;
                chkr -> left = curr -> left;
                chkr -> right = curr -> right;
                delete curr;
        }
		 return;
    }
    }
}
    void BinarySearchTree::print_inorder()
    {
        inorder(root);
    }
    void BinarySearchTree::inorder(tree_node* p)
    {
    if (p != NULL)
    {
        if(p -> left)
            inorder(p->left);
        cout<<""<<p->data<<"";
        if(p->right)
            inorder(p->right);
    }
    else return;
    }

    void BinarySearchTree::print_preorder()
    {
    preorder(root);
    }

    void BinarySearchTree::preorder(tree_node *p)
    {
    if (p != NULL)
    {
        cout<<""<< p->data <<"";
        if (p -> left)
            preorder (p -> left);
        if (p -> right)
            preorder (p -> right);
    }
    else
        return;
    }

    void BinarySearchTree::print_postorder()
    {
    postorder(root);
    }
    void BinarySearchTree:: postorder(tree_node* p)
    {
    if (p != NULL)
    {
        if(p -> left)
            postorder(p -> left);
        if(p -> right)
            postorder(p -> right);
        cout << ""<<p -> data<<"";

    }
    else return;
    }

    int main()
{
    BinarySearchTree b;
    int ch,tmp,tmp1;
    while(1)
    {

    cout<<"Binary Search Tree Operation"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1. Insertion/Creation"<<endl;
    cout<<"2. Inorder Traversal"<<endl;
    cout<<"3. Pre-Order Traversal"<<endl;
    cout<<"4. Post-Order Traversal"<<endl;
    cout<<"5. Removal"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1: cout<<"Enter Number to be inserted:";
                cin>>tmp;
                b.insert(tmp);
                break;
        case 2: cout<<endl;
                cout<<"In-Order Traversal"<<endl;
                cout<<"------------------"<<endl;
                b.print_inorder();
                break;
        case 3: cout<<endl;
                cout<<"pre-Order Traversal"<<endl;
                cout<<"-------------------"<<endl;
                b.print_preorder();
                break;
        case 4: cout<<endl;
                cout<< "Post-Order Traversal"<<endl;
                cout<<"--------------------"<<endl;
                b.print_postorder();
                break;
        case 5:cout<<"Enter data to be deleted"<<endl;
               cin>>tmp1;
               b.remove(tmp1);
               break;
        case 6:
                return 0;
    }
    }
}

