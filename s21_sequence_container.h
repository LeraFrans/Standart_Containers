//       DONE
        // class ListNode;
        // class ListIterator;
        // void print_list();
        // SequenceContainer();                    //default constructor, creates empty list
        // SequenceContainer(size_type n);         //parameterized constructor, creates the list of size n
        // SequenceContainer(const SequenceContainer &l);  //copy constructor
        // SequenceContainer(SequenceContainer &&l);   //move constructor
        // ~SequenceContainer();                   //destructor
        // const_reference front();    //access the first element
        // const_reference back();     //access the last element
        // reference operator[](size_type pos);  //access specified element
        // iterator begin();  //returns an iterator to the beginning
        // iterator end();  //returns an iterator to the end
        // void clear();      //clears the contents
        // iterator insert(iterator pos, const_reference value) //inserts element into concrete pos and returns the iterator that points to the new element
        // void push_back(const_reference value);        //adds an element to the end
        // void pop_front();                             //removes the first element
        // void push_front(const_reference value);       //adds an element to the head
        // void erase(iterator pos);                     //erases element at pos
        // void pop_back();                              //removes the last element
        // reference at(size_type pos);   //access specified element with bounds checking
        // bool empty();         //checks whether the container is empty
        // size_type size();     //returns the number of elements
        // void fill(const_reference value);  //assigns the given value value to all elements in the container.
        // void splice(struct ListIterator pos, SequenceContainer& other); //transfers elements from list other starting from pos
        // void unique();                                //removes consecutive duplicate elements
        // void reverse();                               //reverses the order of the elements
        // void sort();                                  //sorts the elements
        // void merge(SequenceContainer& other);         //merges two sorted lists
        // void swap(SequenceContainer& other);          // меняем местами содержимое
        // SequenceContainer(std::initializer_list<value_type> const &items); //initializer list constructor, creates list initizialized using std::initializer_list
        // operator=(SequenceContainer &&l);       //assignment operator overload for moving object
        // size_type max_size(); //returns the maximum possible number of elements
        //iterator insert_many(const_iterator pos, Args&&... args); //Inserts new elements into the container directly before pos.  FOR List, Vector.
        //void insert_many_back(Args&&... args)  //Appends new elements to the end of the container.  FOR List, Vector, Queue.
        //void insert_many_front(Args&&... args); // Appends new elements to the top of the container. FOR List, Stack.


//   NOT DONE, BUT NOT FOR LIST

            // Type* data();  //direct access to the underlying array
            // iterator array_data();  //direct access to the underlying array
            // void reserve(size_type size); //allocate storage of size elements and copies current array elements to a newely allocated array
            // size_type capacity();  //returns the number of elements that can be held in currently allocated storage
            // void shrink_to_fit(); //reduces memory usage by freeing unused memory
            

#ifndef S21_SEQUENCE_CONTAINER_H_
#define S21_SEQUENCE_CONTAINER_H_



#include <iostream>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <stdarg.h>


namespace s21 {
template <typename Type>
class SequenceContainer {

        public:

        class ListIterator;

        // Member type
        using value_type = Type;
        using reference = Type &;
        using const_reference = const Type&;
        using iterator = ListIterator;
        using const_iterator = const ListIterator;
        using size_type = std::size_t;

        //template <typename Type>
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
        int count_of_elem;

        class ListIterator 
        {
            public:
            ListNode * elemPtr;
            ListIterator() = delete;
            ListIterator(ListNode *ptr) {elemPtr = ptr; }
            reference operator*() { return elemPtr->data; }
            ListIterator& operator++() 
            { 
                elemPtr = elemPtr->next;
                return *this;
            };
            ListIterator& operator--() 
            {   
                elemPtr = elemPtr->prev;
                return *this;
            };
            bool operator==(const ListIterator& other) { return this->elemPtr == other.elemPtr; }
            bool operator!=(const ListIterator& other) { return this->elemPtr != other.elemPtr; }
        };


        //
        void print_list() {
            ListNode *tmp = this->head;
            while (tmp != nullptr) {
                std::cout << "Data: " << tmp->data << "  next: " << tmp->next << "  prew:  " << tmp->prev << std::endl;
                tmp = tmp->next;
            }
            std::cout << " count_of_elem = " << this->count_of_elem << std::endl;
        }

        //Functions       
        SequenceContainer();                    //default constructor, creates empty list   DONE
        SequenceContainer(size_type n);         //parameterized constructor, creates the list of size n
        SequenceContainer(std::initializer_list<value_type> const &items); //initializer list constructor, creates list initizialized using std::initializer_list
        SequenceContainer(const SequenceContainer &l);  //copy constructor
        SequenceContainer(SequenceContainer &&l);       //move constructor
        ~SequenceContainer();                   //destructor
        operator=(SequenceContainer &&l);       //assignment operator overload for moving object

        //Capacity
        bool empty() { return this->head == nullptr; }         //checks whether the container is empty
        size_type size() { return this->count_of_elem; };     //returns the number of elements
        
        //Modifiers
        void swap(SequenceContainer& other);          //swaps the contents
//
        protected:

        //Element access
        const_reference front() {return this->head;}  //access the first element
        const_reference back() {return this->tail;}   //access the last element

        //Iterators
        iterator begin() { return ListIterator(this->head); };  //returns an iterator to the beginning
        iterator end()  { return ListIterator(this->tail); }  //returns an iterator to the end

        //Capacity
        size_type max_size(); //returns the maximum possible number of elements

        //Modifiers
        void clear();                                 //clears the contents
        iterator insert(iterator pos, const_reference value) //inserts element into concrete pos and returns the iterator that points to the new element
        {
            if (pos.elemPtr == this->head) {
                this->push_front(value);
                return iterator(this->head);
            }
            else 
            {
                ListNode *previous = this->head;
                while (previous->next != pos.elemPtr) {
                    previous = previous->next;
                }
                ListNode *newNode = new ListNode(value, previous->next);
                previous->next = newNode;
                newNode->prev = previous;
                newNode->next->prev = newNode;
                this->count_of_elem++;
                return iterator(newNode);
            }
        }

        void erase(iterator pos);                     //erases element at pos
        void push_back(const_reference value);        //adds an element to the end
        void pop_back();                             //removes the last element
        void push_front(const_reference value);       //adds an element to the head
        void pop_front();                                     //removes the first element
   
        void merge(SequenceContainer& other);         //merges two sorted lists
        void splice(struct ListIterator pos, SequenceContainer& other); //transfers elements from list other starting from pos
        void reverse();                               //reverses the order of the elements
        void unique();                                //removes consecutive duplicate elements
        void sort();                                  //sorts the elements

        //Task 3
        iterator insert_many(const_iterator pos, ... ); //Inserts new elements into the container directly before pos.  FOR List, Vector.
        void insert_many_back( ... );  //Appends new elements to the end of the container.  FOR List, Vector, Queue.
        void insert_many_front( ... ); // Appends new elements to the top of the container. FOR List, Stack.




        // А эти для вектора только, оказывается. Хз, зачем их сделела) 
 
        reference operator[](size_type pos);  //access specified element
        Type* data();  //direct access to the underlying array
        iterator array_data();  //direct access to the underlying array
        void reserve(size_type size); //allocate storage of size elements and copies current array elements to a newely allocated array
        size_type capacity();  //returns the number of elements that can be held in currently allocated storage
        void shrink_to_fit(); //reduces memory usage by freeing unused memory
        void fill(const_reference value);  //assigns the given value value to all elements in the container.
        reference at(size_type pos)   //access specified element with bounds checking
        {
            if (pos < 0 || pos >= this->count_of_elem) {
                Type a = Type();       //а я хуй знает как ещё вернуть ссылку на дефолтное значение типа
                reference b = a;
                return b;
            }

            ListIterator result_ref = ListIterator(this->head);
            for (int i = 0; i < pos; i++) result_ref.operator++();
            return result_ref.elemPtr->data;
        }

    
};

template <typename Type>            //default constructor, creates empty list
SequenceContainer<Type>::SequenceContainer() {
    this->count_of_elem = 0;
    this->head = nullptr;
    this->tail = this->head;
}

template <typename Type>
SequenceContainer<Type>::SequenceContainer(size_type n)             //default constructor, creates empty list 
{
    this->count_of_elem = 0;
    this->head = nullptr;
    this->tail = this->head;
    Type data = Type();
    for (int i = 0; i < n; i++) this->push_back(data);
}

template <typename Type>
SequenceContainer<Type>::SequenceContainer(const SequenceContainer &l)       //copy constructor 
{
    this->count_of_elem = 0;
    this->head = nullptr;
    this->tail = this->head;
    ListIterator current_l(l.head);
    while (current_l.elemPtr) {
        this->push_back(current_l.elemPtr->data);
        current_l.operator++();
    }
}

template <typename Type>
SequenceContainer<Type>::SequenceContainer(SequenceContainer &&l)       //move constructor 
{
    ListNode *tmp_old_head(l.head);
    ListNode *tmp_old_tail(l.tail);

    l.head = this->head;
    l.tail = this->tail;

    delete(tmp_old_head);
    delete(tmp_old_tail);
}

template <typename Type>
void SequenceContainer<Type>::clear()
{
    while (this->count_of_elem)
    {
        this->pop_front();
    }
}

template <typename Type>
inline void SequenceContainer<Type>::erase(iterator pos)
{
    if (pos.elemPtr == this->head) this->pop_front();
    else if (pos.elemPtr == this->tail) this->pop_back();
    else 
    {
        ListNode *previous = this->head;
        while (previous->next != pos.elemPtr) {
            previous = previous->next;
        }
        ListNode *toDelete = previous->next;
        previous->next = toDelete->next;
        toDelete->next->prev = previous;
        delete toDelete;
        this->count_of_elem--;
    }
}

template <typename Type>
void SequenceContainer<Type>::push_back(const_reference value)
{
    if (this->head == nullptr) {
        this->head = new ListNode(value);
        this->tail = this->head;

    }
    else {
        ListNode* lastNode = this->tail;
        ListNode * newNode = new ListNode(value);
        lastNode->next = newNode;
        newNode->prev = lastNode;
        tail = newNode;
    }
    this->count_of_elem++;
}

template <typename Type>
inline void SequenceContainer<Type>::pop_back()
{
    ListNode* tmp = this->tail;
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
    delete tmp;
    this->count_of_elem--;
}

template <typename Type>
void SequenceContainer<Type>::push_front(const_reference value)
{
    this->head = new ListNode(value, this->head);
    this->head->next->prev = this->head;
    this->count_of_elem++;
}

template <typename Type>
void SequenceContainer<Type>::pop_front()
{
    ListNode* tmp = this->head;
    this->head = this->head->next;
    this->head->prev = nullptr;
    delete tmp;
    this->count_of_elem--;
}

template <typename Type>
inline void SequenceContainer<Type>::swap(SequenceContainer &other)
{

//есть стд свап он сам делает
    ListNode *tmp_this = this->head;
    ListNode *tmp_other = other.head;
    int this_size = this->count_of_elem;
    int other_size = other.count_of_elem;

    this->head = tmp_other;
    other.head = tmp_this;
    this->count_of_elem = other_size;
    other.count_of_elem = this_size;
    //тут возможно нужно ещё с хвостами что-то сделать, но я не знаю как

}

template <typename Type>
inline void SequenceContainer<Type>::merge(SequenceContainer &other)
{
    //лучше скопировать, иначе если второй удалить, то будет плохо
    SequenceContainer tmp(&other);

    this->tail->next = other.head;
    tmp.head->prev = this->tail;
    this->tail = tmp.tail;
    this->sort();
    this->count_of_elem = this->count_of_elem + tmp.count_of_elem;
}

template <typename Type>
inline void SequenceContainer<Type>::splice(ListIterator pos, SequenceContainer &other)
{
    ListIterator current(this->head);
    int index = 0;
    while (current.elemPtr != pos.elemPtr) 
    { 
        current.operator++();
        index++;
    }
    other.count_of_elem = this->count_of_elem - index;
    this->count_of_elem = index;

    current.elemPtr->prev->next = nullptr;
    other.head = current.elemPtr;
    other.head->prev = nullptr;
}

template <typename Type>
inline void SequenceContainer<Type>::reverse()
{
    //меняем местами head и tail, переворачиваем prev и next
    ListNode *tmp_head(this->head);
    ListNode *tmp_tail(this->tail);
    ListNode *tmp_prev;

    iterator current(this->head);
    for (int _ = 0; _ < this->count_of_elem; _++) {
        tmp_prev = current.elemPtr->prev;
        current.elemPtr->prev = current.elemPtr->next;
        current.elemPtr->next = tmp_prev;
        current.operator--();
    }

    this->head = tmp_tail;
    this->tail = tmp_head;
}

template <typename Type>
inline void SequenceContainer<Type>::unique()
{ 
    iterator current(this->head);      //current идёт на 1 впереди tmp. Как только они равны, удаляем current. Переназначаем current = tmp->next
    iterator tmp(this->head);
    if (this->head->next != nullptr) current.operator++();

    while(current.elemPtr != nullptr) {
        while (current.elemPtr->data == tmp.elemPtr->data) {
            this->erase(current);
            current.elemPtr = tmp.elemPtr->next;
            if (tmp.elemPtr->next == nullptr) break;
        }
        if (tmp.elemPtr->next == nullptr) break;
        current.operator++();
        tmp.operator++();
    }
}

// сортировка выбором
template <typename Type>
inline void SequenceContainer<Type>::sort()
{
    iterator border(this->head);
    iterator current(this->head);
    iterator min(this->head);

    while (border.elemPtr->next != nullptr)
    {   
        min.elemPtr = border.elemPtr;
        current.elemPtr = border.elemPtr->next;
        int flag_swap = 0;
        while (current.elemPtr != nullptr) {
            if (current.elemPtr->data < min.elemPtr->data) {
                min.elemPtr = current.elemPtr;
                flag_swap = 1;
            }
            current.operator++();
        }
        if (flag_swap) {
            Type data_tmp = border.elemPtr->data;
            border.elemPtr->data = min.elemPtr->data;
            min.elemPtr->data = data_tmp;
        }
        border.operator++();
    }
}

template <typename Type>
inline void SequenceContainer<Type>::fill(const_reference value)
{
    iterator current(this->head);
    while (current.elemPtr != nullptr) {
        current.elemPtr->data = value;
        current.operator++();
    }
}

template <typename Type>
SequenceContainer<Type>::~SequenceContainer()
{
    this->clear();
}

template <typename Type>
Type & SequenceContainer<Type>::operator[](size_type pos)
{
    int count = 0;
    ListNode *current = this->head;
    while (current != nullptr)
    {
        if (count == pos) return current->data;
        current = current->next;
        count++;
    }
    Type res1 = Type();    //вот я хз как без этого костыля сделать
    Type &res = res1;
    return res;
}

}
#endif