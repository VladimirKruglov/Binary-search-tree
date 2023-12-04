#include <iostream>
#include <Windows.h>
#include "bst.hpp"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    BST<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Вывод дерева:\n";
    tree.printTree();

    std::cout << "Удаление узла с ключом 20\n";
    tree.deleteKey(20);
    std::cout << "Вывод измененного дерева:\n";
    tree.printTree();

    std::cout << "Поиск узла с ключом 60\n";
    Node<int>* searchResult = tree.search(60);
    if (searchResult != nullptr)
        std::cout << "Найден узел с ключом " << searchResult->key << "\n";
    else
        std::cout << "Узел с ключом 60 не найден в дереве\n";

    return 0;
}