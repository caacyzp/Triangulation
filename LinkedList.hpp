#include <iostream>

namespace CustomeLinkedList
{
    template<typename T>
    struct Node
    {
        T data;
        Node* next;
        Node* previous;
        unsigned int initial_index;
    };

    template<typename T>
    class CircleLinkedList
    {
        public:
            CircleLinkedList():
            m_head (nullptr),
            m_tail (nullptr),
            m_size (0)
            {
            };

            ~CircleLinkedList()
            {   
                while(m_size > 0)
                {
                    m_head->next;
                    m_size--;
                }
            };

            void AddNodeToTail(T data)
            {
                Node<T>* node = new Node<T>;
                if (m_head == nullptr)
                {
                    node->data = data;
                    node->next = node;
                    node->previous = node;
                    node->initial_index = 0;
                    m_head = node;
                    m_tail = m_head;
                    m_size ++;

                }
                else
                {
                    node->data = data; //Assign data to node
                    node->previous = m_tail; //Assign last to Tail
                    node->next = m_head; //Assign next to Head
                    node->previous->next = node; //Update the previous item's next pointer
                    m_tail = node; //Tail is now the node
                    m_head->previous = node;//Head's previous is now the node
                    m_size ++;
                    node->initial_index = m_size - 1;
                }
                std:: cout << "Head:" << m_head << "Tail:" << m_tail << std::endl;
                std:: cout << "Head Next:" << m_head->next << "Head Pre:" << m_head->previous << std::endl;
                std:: cout << "Tail Next:" << m_tail->next << "Tail Pre:" << m_tail->previous << std::endl;
                std:: cout << "-----------------------------------" << std::endl;
            }

            Node<T>* at(int i)
            {
                if (i > m_size)
                {
                    return nullptr;
                }
                else
                {
                    int count = i;
                    Node<T>* node = m_head;
                    while (count > 0)
                    {
                        node = node->next;
                        count--;
                    }
                    return node;
                }
            }

            void del(int i)
            {
                if (i<m_size)
                {
                    int count = i;
                    Node<T>* node = m_head;
                    while(count > 0)
                    {
                        node = node->next;
                        count --;
                    }
                    node->previous->next = node->next;
                    node->next->previous = node->previous;
                    m_head = (node == m_head) ? node->next : m_head;
                    delete node;
                    m_size --;
                }
            }

            void del(Node<T>* node)
            {
                node->previous->next = node->next;
                node->next->previous = node->previous;
                delete node;
                m_size --;
            }
            
            size_t size()
            {
                return m_size;
            }
            
        private:
            Node<T>* m_head;
            Node<T>* m_tail;
            unsigned int m_size;
    };
}
