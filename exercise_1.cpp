#include <iostream>
#include "BinarySearchTree.h"
#include "Node.h"
int main() {
    BinarySearchTree bst(7);
    
    // bst.Insert(bst.getroot(), 5);
    // bst.Insert(bst.getroot(), 1);
    // bst.Insert(bst.getroot(), 6);
    // bst.Insert(bst.getroot(), 9);
    // bst.Insert(bst.getroot(), 8);
    // bst.Insert(bst.getroot(), 11);

    // Print the tree structure
    std::cout << "Binary Search Tree:" <<std::endl;
    bst.inorder(bst.getroot());  
    std::cout << " "<< std::endl;

    // Search for a value
    int searchValue = 7;
    if (bst.search(bst.getroot(), searchValue)) {
        std::cout << "Value " << searchValue << " found in the tree."<<std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the tree."<<std::endl;;
    }

    // Delete a node
    int Value = 11;
    std::cout << "Delete node with value " << Value << std::endl;
    // bst.deleteNode(bst.getroot(), Value);

    return 0;
}
