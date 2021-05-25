#pragma once
#include <iostream>

namespace ariel{
    template<typename T>
    class Node{
        //private:
        public:
        T data;
        Node* right;
        Node* left;

        
        Node(Node* right, Node* left){
            this->right = right;
            this->left = left;
        }
        Node(){
            this->right = nullptr;
            this->left = nullptr;
        }
    };
}
