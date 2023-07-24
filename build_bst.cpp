//Louay Farah
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
 
const int nx[4] = {0, 0, 1, -1};
const int ny[4] = {1, -1, 0, 0};
 
template <typename T>
struct out
{
    T x;
    int leftChild;
    int rightChild;
};
 
template <typename T>
struct node
{
    T key;
    node* leftChild;
    node* rightChild;
    int index;
};
 
template <typename T>
class Bst
{
private:
    int size = 0;
    vector<out<T>> batch;
    int counter = 1;
public:
    node<T>* root;
    void init(int n);
    node<T>* insert(node<T>* curr, T k);
    void preOrder(node<T>* curr);
    void buildOutput(node<T>* curr);
    void output();
    int mySize();
    bool isEmpty();
};
 
template <typename T> void Bst<T>::init(int n)
{
    root = NULL;
    size = n;
    batch.assign(n+1, {0, -1, -1});
}
 
 
template <typename T> node<T>* Bst<T>::insert(node<T>* curr, T k)
{
    if(curr == NULL)
    {
        node<T>* res = new node<T>;
        res->index = 0;
        res->key = k;
        res->leftChild = NULL;
        res->rightChild = NULL;
        return res;
    }
 
    if(k <= curr->key)
    {
        curr->leftChild = insert(curr->leftChild, k);
    }
    else
    {
        curr->rightChild = insert(curr->rightChild, k);
    }
 
    return curr;
}
 
template <typename T> void Bst<T>::preOrder(node<T>* curr)
{
    curr->index = counter;
    counter++;
 
    if(curr->leftChild != NULL)
    {
        preOrder(curr->leftChild);
    }
    if(curr->rightChild != NULL)
    {
        preOrder(curr->rightChild);
    }
}
 
template <typename T> void Bst<T>::buildOutput(node<T>* curr)
{
    batch[curr->index].x = curr->key;
 
 
 
    if(curr->leftChild != NULL)
    {
        batch[curr->index].leftChild = curr->leftChild->index;
        buildOutput(curr->leftChild);
    }
    if(curr->rightChild != NULL)
    {
        batch[curr->index].rightChild = curr->rightChild->index;
        buildOutput(curr->rightChild);
    }
}
 
template <typename T> void Bst<T>::output()
{
    for(int i = 1; i <=size; i++)
    {
        cout << batch[i].x << ' ' << batch[i].leftChild << ' ' << batch[i].rightChild << endl;
    }
}
 
template <typename T> int Bst<T>::mySize()
{
    return Bst<T>::size;
}
 
template <typename T> bool Bst<T>::isEmpty()
{
    return Bst<T>::size == 0;
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
 
    ll n;
    cin >> n;
 
    Bst<int> tree;
    tree.init(n);
 
    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
 
        if(i == 0)
        {
            tree.root = tree.insert(tree.root, x);
        }
        else
        {
            tree.insert(tree.root, x);
        }
    }
 
 
    cout << n << endl;
    tree.preOrder(tree.root);
    tree.buildOutput(tree.root);
    tree.output();
    cout << 1 << endl;
 
    return 0;
}
