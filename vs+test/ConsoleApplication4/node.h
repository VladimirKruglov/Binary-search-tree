#pragma once
#include <iostream>
template<typename T>
struct Node {
    T key;
    Node<T>* left;
    Node<T>* right;

    /**
    * @brief ����������� ����
    */
    Node();

    /**
    * @brief ����������� ����
    * @param key ���� ����
    */
    explicit Node(T key) : key(key), left(nullptr), right(nullptr) {}

    /**
    * @brief ���������� ����
    */
    ~Node();

    /**
    * @brief ����������� �����������
    * @param other ���������� ����
    */
    Node(const Node& other) = delete;

    /**
    * @brief �������� ������������ ������������
    * @param other ���������� ����
    */
    Node& operator=(const Node& other) = delete;

    /**
    * @brief ����������� �����������
    * @param other ���������� ����
    */
    Node(Node&& other) noexcept = default;

    /**
    * @brief �������� ������������ ������������
    * @param other ���������� ����
    */
    Node& operator=(Node&& other) noexcept = default;

    /**
    * @brief �������� ������ ����
    * @param stream ������� �����
    * @param node ��������� ����
    * @return �������� �����
    */
    friend std::ostream& operator<<(std::ostream& stream, const Node& node) {
        stream << node.key;
        return stream;
    }
};

template <typename T>
Node<T>::Node() : key{ 0 }, left{ nullptr }, right{ nullptr } {}

template<typename T>
Node<T>::~Node() {
    delete left;
    delete right;
}