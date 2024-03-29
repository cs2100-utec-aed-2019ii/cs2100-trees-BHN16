#include <iostream>
#include "BinaryTree.h"
int main() {
    BinaryTree<int> F;
    BinaryTree<int> H;
    F.InsertNode(25);
    F.InsertNode(15);
    F.InsertNode(50);
    F.InsertNode(10);
    F.InsertNode(22);
    F.InsertNode(35);
    F.InsertNode(70);
    F.InsertNode(4);
    F.InsertNode(12);
    F.InsertNode(18);
    F.InsertNode(24);
    F.InsertNode(31);
    F.InsertNode(44);
    F.InsertNode(66);
    F.InsertNode(90);
    H.InsertNode(25);
    H.InsertNode(15);
    H.InsertNode(50);
    H.InsertNode(10);
    H.InsertNode(22);
    H.InsertNode(35);
    H.InsertNode(70);
    H.InsertNode(4);
    H.InsertNode(12);
    H.InsertNode(18);
    H.InsertNode(24);
    H.InsertNode(31);
    H.InsertNode(44);
    H.InsertNode(66);
    H.InsertNode(3);
    F.print_Inorder();
    F.print_Postorder();
    F.print_Preorder();
    std::cout << "Height of the tree : " << F.get_Height() << std::endl;
    std::cout << F.Search(90) << std::endl;
    F.DeleteNode(35);
    F.print_Postorder();
    F.ancestors(22);
    F.InsertNode(46);
    F.InsertNode(48);
    F.ancestors(48);
    std::cout << F.check_identical(H.root) << std::endl;
    F.Delete_Tree();
    return 0;
}
