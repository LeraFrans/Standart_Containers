#ifndef s21_queue_H_
#define s21_queue_H_

#include "s21_sequence_container.h"

namespace s21{
template <typename Type>
class s21_queue : public SequenceContainer<Type> {
    public:


    // Member type
        using value_type = Type;
        using reference = Type &;
        using const_reference = const Type&;
        using size_type = std::size_t;

    using SequenceContainer<Type>::SequenceContainer; // Использование конструкторов базового класса


        using typename SequenceContainer<Type>::operator=;

        using typename SequenceContainer<Type>::count_of_elem;
        s21_queue() : SequenceContainer<Type>() {}
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

        //Capacity
        using typename SequenceContainer<Type>::empty;
        typename SequenceContainer<Type>::size_type max_size() { return this->SequenceContainer<Type>::max_size(); } //returns the maximum possible number of elements

  
        void push(typename SequenceContainer<Type>::const_reference value) {this->SequenceContainer<Type>::push_back(value); } //adds an element to the head
        void pop() {this->SequenceContainer<Type>::pop_front(); }  //removes the first element
        void swap(s21_queue& other) {this->SequenceContainer<Type>::swap(other); }

        // // //Task 3
        using SequenceContainer<Type>::insert_many_back;  //Appends new elements to the end of the container.  FOR List, Vector, Queue.
};

}

#endif