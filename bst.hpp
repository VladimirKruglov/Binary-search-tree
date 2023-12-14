#ifndef BST_HPP
#define BST_HPP
#include "node.hpp"
#include <sstream>

template<typename T>
class BST {
private:
    Node<T>* root;

    /**
    * @brief Вставка ключа в узел дерева
    * @param node Узел для добавления
    * @param key Ключ для добавления
    * @return Узел дерева
    */
    Node<T>* insert(Node<T>* node, T key);

    /**
    * @brief Удаление ключа из узла дерева
    * @param root Корневой узел
    * @param key Ключ для удаления
    * @return Узел дерева.
    */
    Node<T>* deleteNode(Node<T>* root, T key);

    /**
    * @brief Вывод узлов дерева в центрированном порядке
    * @param root Корень дерева
    * @param os Выходной поток
    */
    void inorder(Node<T>* root) const;

    /**
    * @brief Поиск ключа в дереве
    * @param root Корень дерева
    * @param key Ключ для поиска
    * @return Узел с ключом, если он существует
    */
    Node<T>* search(Node<T>* root, T key) const;

public:
    /**
    * @brief Конструктор дерева
    */
    BST();

    /**
    * @brief Конструктор копирования
    * @param other Копируемое дерево
    */
    BST(const BST<T>& other) = delete;

    /**
    * @brief Конструктор перемещения
    * @param other Копируемое дерево
    */
	BST(BST<T>&& other) noexcept = default;

    /**
    * @brief Оператор присваивания копированием
    * @param other Копируемое дерево
    */
    BST& operator=(const BST<T>& other) = delete;

    /**
    * @brief Оператор присваивания перемещением
    * @param other Копируеое дерево
    */
    BST& operator=(BST&& other) noexcept = default;

    /**
    * @brief Деструктор дерева
    */
    ~BST();

    /**
    * @brief Вставка ключа в дерево
    * @param key Ключ для вставки
    */
    void insert(T key);

    /**
    * @brief Удаление ключа из дерева
    * @param key Ключ для удаления
    */
    void deleteKey(T key);

    /**
    * @brief Вывод дерева
    */
    void print() const;

    /**
    * @brief Поиск ключа в дереве
    * @param key Ключ для поиска
    * @return Узел с ключом, если он существует
    */
    Node<T>* search(T key) const;

    /**
    * @brief Наименьший узел в дереве
    * @param node Узел для поиска
    * @return Узел с наименьшим ключом
    */
    Node<T>* minValueNode(Node<T>* node);

     /**
    * @brief Получить корень дерева
    * @return Корень
    */
    Node<T>* getRoot();
};

template<typename T>
BST<T>::BST() : root(nullptr) {}

template<typename T>
Node<T>* BST<T>::getRoot() {
    return root;
}

template<typename T>
Node<T>* BST<T>::insert(Node<T>* node, T key) {
    if (node == nullptr)
        return new Node<T>(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

template<typename T>
Node<T>* BST<T>::deleteNode(Node<T>* root, T key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            Node<T>* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node<T>* temp = root->left;
            delete root;
            return temp;
        }

        Node<T>* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

template<typename T>
Node<T>* BST<T>::minValueNode(Node<T>* root) {
    if (root == nullptr)
        return nullptr;
    
    else if (root->left == nullptr)
        return root;
    
    else 
        return minValueNode(root->left);
}

template<typename T>
void BST<T>::inorder(Node<T>* root) const {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

template<typename T>
Node<T>* BST<T>::search(Node<T>* root, T key) const {
    if (root == nullptr || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

template<typename T>
BST<T>::~BST() {
    while(root != nullptr)
        deleteKey(root->key);
}

template<typename T>
void BST<T>::insert(T key) {
    root = insert(root, key);
}

template<typename T>
void BST<T>::deleteKey(T key) {
    root = deleteNode(root, key);
}

template<typename T>
void BST<T>::print() const {
    inorder(root);
    std::cout << "\n";
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const BST<T>& bst) {
    bst.print();
    return os;
}

template<typename T>
Node<T>* BST<T>::search(T key) const {
    return search(root, key);
}

template class BST<int>;

#endif