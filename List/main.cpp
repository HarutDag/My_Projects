#include <iostream>

template<typename T>
class List
{
    template<typename T>
    class Node
    {
    public:
        Node* next;
        T data;

        Node(T data = T(), Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
    int size;
    Node<T>* head;

public:
    List();
    ~List();
    void pop_front();
    void push_back(T data);
    void clear();
    int getSize() { return size; }
    T& operator[](const int index);
    void push_front(T data);
    void insert(T data, int index);
    void remove(int index);
    void pop_back();
};

template<typename T>
List<T>::List()
{
    std::cout << "\nList func\n";
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    std::cout << "\n~List func\n";
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    --size;
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node<T>(data);
    }

    ++size;
}

template<typename T>
void List<T>::clear()
{
    std::cout << "\nclear func\n";
    while (size)
    {
        pop_front();
    }
}

template<typename T>
T& List<T>::operator[](const int index)
{
    try
    {
        if (index < 0 || size <= index)
            throw index;
    }
    catch (int i)
    {
        std::cout << i << "\nindex not found!\n";
    }

    int counter = 0;

    Node<T>* current = this->head;

    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->next;
        ++counter;
    }
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    ++size;
}

template<typename T>
void List<T>::insert(T data, int index)
{
    try
    {
        if (index < 0 || size <= index)
            throw index;
    }
    catch (int i)
    {
        std::cout << i << "\nindex not found!\n";
    }

    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->next;
        }

        Node<T>* newNode = new Node<T>(data, previous->next);
        previous->next = newNode;
        ++size;
    }
}

template<typename T>
void List<T>::remove(int index)
{
    try
    {
        if (index < 0 || size <= index)
            throw index;
    }
    catch (int i)
    {
        std::cout << i << "\nindex not found!\n";
    }

    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->next;
        }

        Node<T>* toDelete = previous->next;
        previous->next = toDelete->next;
        delete toDelete;
        --size;
    }
}

template<typename T>
void List<T>::pop_back()
{
    remove(size - 1);
}

int main()
{
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    std::cout << "\n3 time push_front result:\n\n";
    for (int i = 0; i < list.getSize(); ++i)
    {
        std::cout << list[i] << '\n';
    }

    std::cout << "\n1 time pop_back result:\n\n";
    list.pop_back();


    for (int i = 0; i < list.getSize(); i++)
    {
        std::cout << list[i] << '\n';
    }

    return 0;
}