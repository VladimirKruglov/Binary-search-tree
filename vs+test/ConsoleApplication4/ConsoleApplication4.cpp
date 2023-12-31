﻿#include <iostream>
#include <Windows.h>
#include "bst.h"

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
    tree.print();

    std::cout << "Удаление узла с ключом 20\n";
    tree.deleteKey(20);
    std::cout << "Вывод измененного дерева:\n";
    tree.print();

    std::cout << "Поиск узла с ключом 60\n";
    Node<int>* searchResult = tree.search(60);
    if (searchResult != nullptr)
        std::cout << "Найден узел с ключом " << searchResult->key << "\n";
    else
        std::cout << "Узел с ключом 60 не найден в дереве\n";
    
    std::cout << tree;

    Node<int>* minNode = tree.minValueNode(tree.getRoot());
    if (minNode != nullptr)
        std::cout << "Минимальный элемент: " << minNode->key << std::endl;
    else 
        std::cout << "Дерево пустое" << std::endl;

    tree.deleteKey(60);
    std::cout << tree;

    tree.insert(45);
    std::cout << tree;

    std::cout << tree.to_string();

    return 0;
}