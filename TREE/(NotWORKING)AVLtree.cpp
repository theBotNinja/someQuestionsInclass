#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int bfactor;
}*ROOT;

void Inorder(Node* root){a
    if (root==NULL){
        return;
    }
    Inorder(root->left);
    cout <<"root<"<<root->data<<"> bf<"<<root->bfactor<<">"<< endl;
    Inorder(root->right);
}

Node * RR(Node *R1){
    Node *R2 = R1->left;
    R1->left = R2->right;
    R2->right = R1;
    Node * temp  = R1->parent;
    R1->parent = R2;
    if (temp != NULL){
        if (temp->left == R1){
            temp->left = R2;
        }else if (temp->right == R1){
            temp->right = R2;
        }
        return R2;
    }else{
        ROOT = R2;
        return R2;
    }
}

Node * LL(Node *L1){
    Node *L2 = L1->right;
    L1->right = L2->left;
    L2->left = L1;
    Node * temp  = L1->parent;
    L1->parent = L2;
    if (temp != NULL){
        if (temp->left == L1){
            temp->left = L2;
        }else if (temp->right == L1){
            temp->right = L2;
        }
        return L2;
    }else{
        ROOT = L2;
        return L2;
    }
}

Node* LR(Node *LR1){
    Node * temp1 = LL(LR1->right);
    Node * temp2 = RR(LR1);
    return temp2;
}
Node* RL(Node *RL1){
    Node * temp1 = LL(RL1->left);
    Node * temp2 = RR(RL1);
    return temp2;
}

void printubnode(Node* newNode){
    Node * temp = newNode;
    while (temp)
    {
        if (temp->bfactor >=2 || temp->bfactor <= 2){

            if (temp->data < newNode->data && temp->right != NULL &&temp->right->data <newNode->data)
                {
                    cout <<"LL"<< endl;
                    Inorder(LL(temp));
                    cout << endl;
                    cout<<ROOT->data<<endl;
                    break;
                }
            else if (temp->data > newNode->data && temp->left != NULL &&temp->left->data > newNode->data)
                {
                    cout <<"RR"<< endl;
                    Inorder(RR(temp));
                    cout << endl;
                    cout<<ROOT->data<<endl;
                    break;
                }
            else if (temp->data < newNode->data && temp->right != NULL &&temp->right->data >newNode->data)
                {
                    cout <<"RL"<< endl;
                    Inorder(LR(temp));
                    cout << endl;
                    cout<<ROOT->data<<endl;
                    break;
                }
            else if (temp->data > newNode->data && temp->left != NULL &&temp->left->data <newNode->data)
                {
                    cout <<"LR"<< endl;
                    Inorder(RL(temp));
                    cout << endl;
                    cout<<ROOT->data<<endl;
                    break;

                }
        }
        temp = temp->parent;
        printf("sdfsdfs");
    }
    
}

Node* pushIntoAVLtree(Node *root,Node * new_Node){
    struct Node* temp = root;
    while(temp!=NULL){
        // check if node is smaller or greater then val
        if (temp->data < new_Node->data){
            // check if right of the node is null or not
            if (temp->right == NULL){
                // create new node and insert the val
                temp->right = new_Node;
                new_Node->parent = temp;
                printubnode(new_Node);
                break;
            }else{
                temp->bfactor++;
                temp = temp->right;
            }
        }else if (temp->data > new_Node->data){
            // check if left of the node is null or not
            if (temp->left == NULL){
                // create new node and insert the val
                temp->left = new_Node;
                new_Node->parent = temp;
                printubnode(new_Node);
                break;
            }else{
                temp->bfactor--;
                temp = temp->left;
            }
        }
    }
    return root;
}

Node * createAVLtree(){
    Node * root = (Node *)malloc(sizeof(Node));
    cout << "Enter the value at root node : ";
    cin >> root->data;
    root->bfactor = 0;
    root->parent = root ->left = root->right = NULL;
    char user_res;
    while(1){
        cout << "want to push more nodes (n to exit) : ";
        cin >> user_res;
        if (user_res == 'n'){
            break;
        }
        Node * new_Node = (Node *)malloc(sizeof(Node));
        cout << "Enter the value at this node : ";
        cin >> new_Node->data;
        new_Node->bfactor = 0;
        new_Node->parent = new_Node ->left = new_Node->right = NULL;
        root = pushIntoAVLtree(root,new_Node);
        cout << "processing ..." <<endl; 
    }
    return root;
}
//10 g 1 g 8 g 4 g 6 g 3 g 15 g 14 g 20 n 
int main(){
    Node * root = createAVLtree();
    Inorder(root);
    cout << endl;
    Inorder(ROOT);
   return 0;
}