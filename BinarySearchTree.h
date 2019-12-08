//Programmer Name: Thomas Molnar-Brock
//Programmer ID: 1744869
//Assignment Name: Assignment 13 - Binary Tree Template
#ifndef BST_H
#define BST_H
#include <queue>
using namespace std;

template<typename K, typename V>
class BinarySearchTree{
  struct Node{
    K key;
    V value;
    Node* right;
    Node* left;
  };
  
  Node* rootNode;
  int siz;
  void Keys(const Node*, std::queue<K>&) const;
  void clear(Node*);
  void copyTree(Node*, const Node*);
  
public:
  BinarySearchTree(){rootNode = 0; siz = 0;} //Default Constructor
  BinarySearchTree(const BinarySearchTree&); //Copy Constructor
  BinarySearchTree<K,V>& operator=(const BinarySearchTree<K,V>&); //Assignment Operator
  ~BinarySearchTree() {clear();}; //Destructor
  
  int size(){return siz;}
  V operator[](const K&) const; //Square Bracket Getter
  V& operator[](const K&); //Square Bracket Setter
  bool containsKey(const K&) const; //Getter
  void deleteKey(const K&); //Setter
  std::queue<K> Keys() const; //Return a queue of keys
  void clear(); //Empty the tree
};

template<typename K, typename V>
bool BinarySearchTree<K,V>::containsKey(const K& key) const {
  Node* p = rootNode;
  while(p){
    if(p->key == key){
      return true;
    }
    if(p->key < key){
      p=p->right;
    }else{ //(p->key > key)
      p=p->left;
    }
  }
  return false;
}

template<typename K, typename V>
V BinarySearchTree<K,V>::operator[](const K& key) const {
  Node* p = rootNode;
  while(p){
    if(p->key == key){
      return p->value;
    }
    if(p->key < key){
      p = p->right;
    }else{ //(p->key > key)
      p = p->left;
    }
  }
  return V();
}

template<typename K, typename V>
V& BinarySearchTree<K,V>::operator[](const K& key){
  Node* p = rootNode;
  Node* prev = rootNode;
  while(p){
    if(p->key == key){
      return p->value;
    }
    prev = p;
    if(p->key < key){
      p = p->right;
    }else{
      p = p->left;
    }
  }
  siz++;
  Node* temp = new Node{key, V()};
  if(prev){
    if(prev->key < key){
      prev->right = temp;
    }else{
      prev->left = temp;
    }
  }else{
    rootNode = temp;
  }
  return temp->value;
}

template<typename K, typename V>
void BinarySearchTree<K,V>::deleteKey(const K& key){
  Node *p = rootNode;
  Node *prev = 0;
  while(p){
    prev = p;
    if(p->key == key)
      break;//found the key to delete so break
    if(p->key < key){
      p = p->right;
    }else{
      p = p->left;
    }
  }
  if(!p){ //key was not found so return
    return;
  }
  if(p->left==0 && p->right==0){ // node has no children
    if(prev == 0) // p is the only node
      rootNode = 0;
    else{
      if(prev->left == p) //p was prevs left child so set it to zero
        prev->left = 0;
      else //p was prev's right child so set it to zero
        prev->right = 0;
    }
  }else if(p->left==0 && p->right !=0){ //node has only right child
    //Find the smallest node in the right subtree
    Node* nodeToDelete = p;
    p = p->right;
    while(p->left){
      prev = p;
      p = p->left;
    }
    nodeToDelete->key = p->key;
    nodeToDelete->value = p->value; //replace with the smallest node in right subtree
    if(prev->left == p) prev->left = p->right; //incase there is a right child of the smallest node
    else prev->right = p->right; //incase no left children after rigth step
  }else if(p->left!=0 && p->right ==0){ //node has only left child
    //fix this
  }
    //Finish Cases
  delete p; //delete the node in question
  siz--; //decrement the size
}
template<typename K, typename V>
void BinarySearchTree<K,V>::Keys(const Node* p, std::queue<K>& q) const{
  if(!p) return; //base case
  keys(p->left, q); //push all nodes from left subtree
  q.push(p->key); //push parent node
  keys(p->right, q); //push all nodes from the right subtree
}
template<typename K, typename V>
std::queue<K> BinarySearchTree<K,V>::Keys() const{
  std::queue<K> Q; //Create an empty queue
  Keys(rootNode, Q); //Call the private recursive implementation of Keys
  return Q;
}
template<typename K, typename V>
void BinarySearchTree<K,V>::clear(Node* p){ //Private recursive implementation of clear
  if(!p){ return;} //Base case
  clear(p->left); //Clear left subtree
  clear(p->right); //Clear right subtree
  delete p; // Delete parent node
}
template<typename K, typename V>
void BinarySearchTree<K,V>::clear(){ //Serves as wrapper for recursive implementation of clear
  clear(rootNode);
  siz = 0;
  rootNode = 0;
}
template<typename K, typename V>
void BinarySearchTree<K,V>::copyTree(Node* rootNode, const Node* originalRoot){
  if(!originalRoot) {return;} //return when base case is hit
  rootNode->key = originalRoot->key;
  rootNode->value = originalRoot->value;
  rootNode->right = rootNode->left = 0;
  if(originalRoot->left) copyTree(rootNode->left, originalRoot->left); //Copy left subtree
  if(originalRoot->right)copyTree(rootNode->right, originalRoot->right); //Copy right subtree
}
//template<typename K, typename V>
//BinarySearchTree<K,V>::BinarySearchTree(const BinarySearchTree& original){
//}

#endif
