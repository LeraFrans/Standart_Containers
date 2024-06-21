#ifndef s21_stack_H_
#define s21_stack_H_

#include "s21_sequence_container.h"

namespace s21{
template <typename Type>
class s21_stack : public SequenceContainer<Type> {
    public:


    // Member type
        using value_type = Type;
        using reference = Type &;
        using const_reference = const Type&;
        using size_type = std::size_t;

    using SequenceContainer<Type>::SequenceContainer; // Использование конструкторов базового класса


        using typename SequenceContainer<Type>::operator=;

        using typename SequenceContainer<Type>::count_of_elem;
        s21_stack() : SequenceContainer<Type>() {}
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
        typename SequenceContainer<Type>::const_reference top() { return this->SequenceContainer<Type>::back(); } //access the last element

        //Capacity
        using SequenceContainer<Type>::empty;
        using SequenceContainer<Type>::size;

        // Modifiers
        void push(typename SequenceContainer<Type>::const_reference value) {this->SequenceContainer<Type>::push_back(value); } //adds an element to the end
        void pop() {this->SequenceContainer<Type>::pop_back(); }  //removes the first element
        void swap(s21_stack& other) {this->SequenceContainer<Type>::swap(other); }

        // // //Task 3
        void insert_many_front( std::vector<int> args ) {this->SequenceContainer<Type>::insert_many_back(args); }
        //using typename SequenceContainer<Type>::insert_many_front; // Appends new elements to the top of the container. FOR List, Stack.

};

}

#endif