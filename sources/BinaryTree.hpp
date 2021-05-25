#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Node.hpp"
#include "inorder.hpp"
#include "postorder.hpp"
#include "preorder.hpp"
using namespace std;

namespace ariel{
    template<typename T>
    class BinaryTree{
        
        public:
            BinaryTree(){
                root = nullptr;
            }

            //Node* getNode(T data){
            //}
            //Destructor
            ~BinaryTree(){
                if(!root){
                    for(auto iter = begin_preorder(); iter!= end_preorder();++iter){
                        Node<T>* temp = iter.getNode();
                        delete temp;
                    }
                }
            }

            //template<typename T>
            friend ostream& operator<<(ostream& out, const BinaryTree<T>& bin_tree);

            BinaryTree& add_root(T data){
                if(root!= nullptr){
                    root->data = data;
                    return *this;
                }
                root = new Node<T>{};
                root->data = data;
                return *this;
            }

            BinaryTree& add_left(T parent, T child){
                for(auto iter = begin_preorder(); iter!=end_preorder();++iter){
                    Node<T>* tmp = iter.getNode();
                    if(tmp->data == parent){
                        if(!tmp->left){
                            tmp->left = new Node<T>{};
                            tmp->left->data = child;
                            return *this;
                        }
                        else{
                            tmp->left->data = child;
                            return *this;
                        }
                    }
                }
                        throw invalid_argument("Parent not exist");
            }

            BinaryTree& add_right(T parent, T child){
                for(auto iter = begin_preorder(); iter!=end_preorder();++iter){
                    Node<T>* tmp = iter.getNode();
                    if(tmp->data == parent){
                        if(!tmp->right){
                            tmp->right = new Node<T>{};
                            tmp->right->data = child;
                            return *this;
                        }
                        else{
                            tmp->right->data = child;
                            return *this;
                        }
                    }
                }
                throw invalid_argument("Parent not exist");
            }

            preorder<T> begin_preorder(){
                return preorder<T>{root};
            }

            inorder<T> begin_inorder(){
                return inorder<T>{root};
            }

            postorder<T> begin_postorder(){
                return postorder<T>{root};
            }

            preorder<T> end_preorder(){
                return preorder<T>{};
            }

            inorder<T> end_inorder(){
                return inorder<T>{};
            }

            postorder<T> end_postorder(){
                return postorder<T>{};
            }

            inorder<T> begin(){
                return inorder<T>{root};
            }

            inorder<T> end(){
                return inorder<T>{};
            }

        private:
            Node<T>* root;


            //this print should work like inorder
            friend ostream& operator<<(ostream& out, BinaryTree<T>& bin_tree){
                for(auto var: bin_tree){
                    out << var << " ";
                }
                out << endl;
                return out;
            }

    };
}
