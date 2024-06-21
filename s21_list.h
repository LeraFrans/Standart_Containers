#ifndef S21_LIST_H_
#define S21_LIST_H_

#include "s21_sequence_container.h"

namespace s21{
template <typename Type>
class s21_list : public SequenceContainer<Type> {
    public:


    // Member type
        using value_type = Type;
        using reference = Type &;
        using const_reference = const Type&;
        using size_type = std::size_t;

    using SequenceContainer<Type>::SequenceContainer; // Использование конструкторов базового класса


        using typename SequenceContainer<Type>::operator=;

        using typename SequenceContainer<Type>::count_of_elem;
        s21_list() : SequenceContainer<Type>() {}
                class ListNode {
            public:
                Type data;
                ListNode* next;
                ListNode* prev;

                ListNode(Type val = Type(), ListNode* pNext = nullptr, ListNode* pPrev = nullptr) {
                    this->data = val;
                    this->next = pNext;
                    this->prev = pPrev;
                }
        };
        ListNode *head;
        ListNode *tail;
        //int count_of_elem;

        using SequenceContainer<Type>::ListIterator; 

        //Element access
        typename SequenceContainer<Type>::const_reference front() { return this->SequenceContainer<Type>::front(); } //access the first element
        typename SequenceContainer<Type>::const_reference back() { return this->SequenceContainer<Type>::back(); } //access the last element

        //Iterators
        typename SequenceContainer<Type>::iterator begin() { return this->SequenceContainer<Type>::begin(); }  //returns an iterator to the beginning
        typename SequenceContainer<Type>::iterator end()  { return this->SequenceContainer<Type>::end(); }  //returns an iterator to the end

        //Capacity
        using typename SequenceContainer<Type>::empty;
        typename SequenceContainer<Type>::size_type max_size() { return this->SequenceContainer<Type>::max_size(); } //returns the maximum possible number of elements

        // Modifiers
        void clear() { this->SequenceContainer<Type>::clear(); };  //clears the contents
        typename SequenceContainer<Type>::iterator insert(typename SequenceContainer<Type>::iterator pos, typename SequenceContainer<Type>::const_reference value) { return this->SequenceContainer<Type>::insert(pos, value); }
        void erase(typename SequenceContainer<Type>::iterator pos) {this->SequenceContainer<Type>::erase(pos); } //erases element at pos
        
        using typename SequenceContainer<Type>::push_back;
        //void push_back(typename SequenceContainer<Type>::const_reference value) {this->SequenceContainer<Type>::push_back(value); }//adds an element to the end
        void pop_back() {this->SequenceContainer<Type>::pop_back(); } //removes the last element
        void push_front(typename SequenceContainer<Type>::const_reference value) {this->SequenceContainer<Type>::push_front(value); } //adds an element to the head
        void pop_front() {this->SequenceContainer<Type>::pop_front(); }  //removes the first element
        
        
        
        
        
        
        void swap(s21_list& other) {this->SequenceContainer<Type>::swap(other); }
        void merge(SequenceContainer<Type>& other) { this->SequenceContainer<Type>::merge(other); };         //merges two sorted lists
        void splice(typename SequenceContainer<Type>::ListIterator pos, SequenceContainer<Type>& other) { this->SequenceContainer<Type>::splice(pos, other); }; //transfers elements from list other starting from pos
        void reverse() {this->SequenceContainer<Type>::reverse();};                               //reverses the order of the elements
        void unique() {this->SequenceContainer<Type>::unique();};                                //removes consecutive duplicate elements
        void sort() {this->SequenceContainer<Type>::sort();};                                  //sorts the elements




        // // //Task 3
        using typename SequenceContainer<Type>::insert_many; //Inserts new elements into the container directly before pos.  FOR List, Vector.
        using SequenceContainer<Type>::insert_many_back;  //Appends new elements to the end of the container.  FOR List, Vector, Queue.
        using typename SequenceContainer<Type>::insert_many_front; // Appends new elements to the top of the container. FOR List, Stack.

};

// template <typename Type, typename... Args>
// inline void s21_list<Type>::insert_many_back( Args&&... args ) {
//     // Проверяем, что список не пустой
//     if (head == nullptr) {
//         // Если список пуст, добавляем первый элемент
//         head = new ListNode(std::forward<Args>(args)...);
//         tail = head;
//     } else {
//         // Если список не пуст, добавляем элементы в конец
//         ListNode* newNode = head;
//         while (newNode->next != nullptr) {
//             newNode = newNode->next;
//         }
//         // Создаем новый узел и добавляем его в конец списка
//         newNode->next = new ListNode(std::forward<Args>(args)...);
//         newNode->next->prev = newNode;
//     }
//     // Увеличиваем счетчик элементов
//     count_of_elem += sizeof...(args);
// }

}

#endif