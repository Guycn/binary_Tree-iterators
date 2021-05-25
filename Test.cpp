#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

TEST_CASE("preorder iterator"){
    int arr[10];
    int i = 0;
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 2)      // Now 2 is the left child of 1
    .add_right(1, 11)      // Now 11 is the right child of 1
    .add_right(11, 3)      // Now 3 is the right child of 11
    .add_left(11, 30)      // Now 3 is the left child of 11
    .add_left(2, 3)      // Now 3 is the left child of 2
    .add_right(3, 4)     // Now 4 is the right child of 3
    .add_left(3, 49)     // Now 4 is the right child of 3
    .add_right(4, 5)     // Now 5 is the right child of 4
    .add_left(4, 6);     // Now 6 is the left child of 4
    tree_of_ints.add_root(10); //10 replace 1
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it){
        arr[i] = (*it);
        i++;
    }
    CHECK_EQ(arr[0],10);
    CHECK_EQ(arr[1],2);
    CHECK_EQ(arr[2],3);
    CHECK_EQ(arr[3],49);
    CHECK_EQ(arr[4],4);
    CHECK_EQ(arr[5],6);
    CHECK_EQ(arr[6],5);
    CHECK_EQ(arr[7],11);
    CHECK_EQ(arr[8],30);
    CHECK_EQ(arr[9],3);

    //change the values
    tree_of_ints.add_root(100)
    .add_left(100, 20)      // Now 20 is the left child of 10
    .add_right(100, 110)      // Now 110 is the right child of 10
    .add_right(110, 30)      // Now 30 is the right child of 110
    .add_left(110, 300)      // Now 30 is the left child of 110
    .add_left(20, 30)      // Now 30 is the left child of 20
    .add_right(30, 40)     // Now 40 is the right child of 30
    .add_left(30, 490)     // Now 40 is the right child of 30
    .add_right(40, 50)     // Now 50 is the right child of 40
    .add_left(40, 60);     // Now 60 is the left child of 40

    i = 0;
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it){
        arr[i] = (*it);
        i++;
    }

    CHECK_EQ(arr[0],100);
    CHECK_EQ(arr[1],20);
    CHECK_EQ(arr[2],30);
    CHECK_EQ(arr[3],490);
    CHECK_EQ(arr[4],40);
    CHECK_EQ(arr[5],60);
    CHECK_EQ(arr[6],50);
    CHECK_EQ(arr[7],110);
    CHECK_EQ(arr[8],300);
    CHECK_EQ(arr[9],30);

    CHECK_THROWS(tree_of_ints.add_left(10000,10000)); //parent not exist

};

TEST_CASE("inorder iterator"){
    int i = 0;
    int arr[10];
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 2)      // Now 2 is the left child of 1
    .add_right(1, 11)      // Now 11 is the right child of 1
    .add_right(11, 3)      // Now 3 is the right child of 11
    .add_left(11, 30)      // Now 3 is the left child of 11
    .add_left(2, 3)      // Now 3 is the left child of 2
    .add_right(3, 4)     // Now 4 is the right child of 3
    .add_left(3, 49)     // Now 4 is the right child of 3
    .add_right(4, 5)     // Now 5 is the right child of 4
    .add_left(4, 6);     // Now 6 is the left child of 4
    tree_of_ints.add_root(10); //10 replace 1
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it){
        arr[i] = (*it);
        i++;
    }
    CHECK_EQ(arr[0],49);
    CHECK_EQ(arr[1],3);
    CHECK_EQ(arr[2],6);
    CHECK_EQ(arr[3],4);
    CHECK_EQ(arr[4],5);
    CHECK_EQ(arr[5],2);
    CHECK_EQ(arr[6],10);
    CHECK_EQ(arr[7],30);
    CHECK_EQ(arr[8],11);
    CHECK_EQ(arr[9],3);

    //change the values

    tree_of_ints.add_left(10, 20)      // Now 2 is the left child of 1
    .add_right(10, 110)      // Now 11 is the right child of 1
    .add_right(110, 30)      // Now 3 is the right child of 11
    .add_left(110, 300)      // Now 3 is the left child of 11
    .add_left(20, 30)      // Now 3 is the left child of 2
    .add_right(30, 40)     // Now 4 is the right child of 3
    .add_left(30, 490)     // Now 4 is the right child of 3
    .add_right(40, 50)     // Now 5 is the right child of 4
    .add_left(40, 60);     // Now 6 is the left child of 4

    i = 0;
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it){
        arr[i] = (*it);
        i++;
    }

    CHECK_EQ(arr[0],490);
    CHECK_EQ(arr[1],30);
    CHECK_EQ(arr[2],60);
    CHECK_EQ(arr[3],40);
    CHECK_EQ(arr[4],50);
    CHECK_EQ(arr[5],20);
    CHECK_EQ(arr[6],10);
    CHECK_EQ(arr[7],300);
    CHECK_EQ(arr[8],110);
    CHECK_EQ(arr[9],30);

    CHECK_THROWS(tree_of_ints.add_left(4900,10000)); //parent not exist

};

TEST_CASE("postorder iterator"){
    int i = 0;
    int arr[10];
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 2)      // Now 2 is the left child of 1
    .add_right(1, 11)      // Now 11 is the right child of 1
    .add_right(11, 3)      // Now 3 is the right child of 11
    .add_left(11, 30)      // Now 3 is the left child of 11
    .add_left(2, 3)      // Now 3 is the left child of 2
    .add_right(3, 4)     // Now 4 is the right child of 3
    .add_left(3, 49)     // Now 4 is the right child of 3
    .add_right(4, 5)     // Now 5 is the right child of 4
    .add_left(4, 6);     // Now 6 is the left child of 4
    tree_of_ints.add_root(10); //10 replace 1
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it){
        arr[i] = (*it);
        i++;
    }
    CHECK_EQ(arr[0],49);
    CHECK_EQ(arr[1],6);
    CHECK_EQ(arr[2],5);
    CHECK_EQ(arr[3],4);
    CHECK_EQ(arr[4],3);
    CHECK_EQ(arr[5],2);
    CHECK_EQ(arr[6],30);
    CHECK_EQ(arr[7],3);
    CHECK_EQ(arr[8],11);
    CHECK_EQ(arr[9],10);

    //change the values

    tree_of_ints.add_left(10, 20)      // Now 2 is the left child of 1
    .add_right(10, 110)      // Now 11 is the right child of 1
    .add_right(110, 30)      // Now 3 is the right child of 11
    .add_left(110, 300)      // Now 3 is the left child of 11
    .add_left(20, 30)      // Now 3 is the left child of 2
    .add_right(30, 40)     // Now 4 is the right child of 3
    .add_left(30, 490)     // Now 4 is the right child of 3
    .add_right(40, 50)     // Now 5 is the right child of 4
    .add_left(40, 60);     // Now 6 is the left child of 4

    i = 0;
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it){
        arr[i] = (*it);
        i++;
    }

    CHECK_EQ(arr[0],490);
    CHECK_EQ(arr[1],60);
    CHECK_EQ(arr[2],50);
    CHECK_EQ(arr[3],40);
    CHECK_EQ(arr[4],30);
    CHECK_EQ(arr[5],20);
    CHECK_EQ(arr[6],300);
    CHECK_EQ(arr[7],30);
    CHECK_EQ(arr[8],110);
    CHECK_EQ(arr[9],10);

    CHECK_THROWS(tree_of_ints.add_left(4900,10000)); //parent not exist

};