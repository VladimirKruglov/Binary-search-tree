#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
struct Node {
    T key;
    Node<T>* left;
    Node<T>* right;

    /**
    * @brief Конструктор узла
    */
    Node();

    /**
    * @brief Конструктор узла
    * @param key Ключ узла
    */
    explicit Node(T key) : key(key), left(nullptr), right(nullptr) {}
    
    /**
    * @brief Конструктор копирования
    * @param other Копируемый узел
    */
    Node(const Node& other) = delete;

    /**
    * @brief Оператор присваивания копированием
    * @param other Копируемый узел
    */
    Node& operator=(const Node& other) = delete;

    /**
    * @brief Конструктор перемещения
    * @param other Копируемый узел
    */
    Node(Node&& other) noexcept = default;

    /**
    * @brief Оператор присваивания перемещением
    * @param other Копируемый узел
    */
    Node& operator=(Node&& other) noexcept = default;

    /**
	* @brief Оператор вывода узла
	* @param stream Входной поток
	* @param node Выводимый узел
	* @return Выходной поток
	*/
	friend std::ostream& operator<<(std::ostream& stream, const Node& node){
		stream << node.key;
		return stream;
	}
};

template <typename T>
Node<T>::Node() : key{ 0 }, left{ nullptr }, right{ nullptr } {}

#endif