#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include <queue>

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    int calculateHeight() {
        return calculateHeight(root);
    }
    Node* getroot() {
        return root;
    }
    std::string printTree() {
        std::string result = "";
        printTree(root, 0, result);
        return result;
    }

    //exercise 1

//insert function
    void Insert(Node*& root, int newValue) {
    if (root == nullptr) {
        root = new Node(newValue);
        return;
    }
    if (newValue < root->data) {
        Insert(root->left, newValue);
    } else if (newValue > root->data) {
        Insert(root->right, newValue);
    }
}
//binary tree inorder

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        std::cout << root-> data<< " ";
        inorder(root->right);
    }
}
//search value function
  bool search(Node* root, int key) {
        if (root == nullptr) return false;
        if (root->data == key) return true;
        if (root->data > key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

//deleteNode function
void deleteNode(Node*& root, int value) {
    if (root == nullptr) return; 

    if (value < root->data) {
        deleteNode(root->left, value);
    }

    else if (value > root->data) {
        deleteNode(root->right, value);
    }else {
    
        if (root->left == nullptr) {
            Node* temp = root->right;  
            delete root;               
            root = temp;              
        } else if (root->right == nullptr) {
            Node* temp = root->left;   
            delete root;               
            root = temp;               
        }
      
        else {
            Node* temp = minValueNode(root->right);  
            root->data = temp->data;                
            deleteNode(root->right, temp->data);     
        }
    }
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

   // exercise 2
    std::string levelOrderTraverse() {
        std::string result = "";
        //your code here
        //Important note: you are allowed to use the std::queue class to implement this function
        std::queue<Node*> Q;
        Q.push(root);

        while (!Q.empty ()){
            Node* current = Q.front();
            result +=std::to_string(current->data ) + " ";
            if (current->left != NULL) Q.push(current->left);
            if (current->right !=NULL) Q.push(current->right);
            Q.pop();
        }
        return result;
    }
    
private:
    void printTree(Node* node, int depth, std::string& result) {
        if (node == nullptr) return;
        for (int i = 0; i < depth; ++i) {
            result += "- ";
        }
        result += std::to_string(node->data) + "\n";
        printTree(node->left, depth + 1, result);
        printTree(node->right, depth + 1, result);
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

};

#endif // BINARYTREE_H


