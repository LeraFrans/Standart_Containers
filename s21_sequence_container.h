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
        //SequenceContainer& operator=(SequenceContainer<Type>&&l);       //assignment operator overload for moving object

    SequenceContainer& operator=(SequenceContainer<Type>&& l) {
    // Обмен указателями
    ListNode* tempHead = this->head;
    ListNode* tempTail = this->tail;
    //int tempCountOfElem = this->count_of_elem;

    this->head = l.head;
    this->tail = l.tail;
    this->count_of_elem = l.count_of_elem;

    // Освобождение памяти исходного объекта
    l.head = nullptr;
    l.tail = nullptr;
    l.count_of_elem = 0;

    // Перепривязка указателей, если они были связаны
    if (tempHead != nullptr) {
        tempHead->prev = nullptr;
        tempHead->next = this->head;
    }
    if (tempTail != nullptr) {
        tempTail->prev = this->tail;
        tempTail->next = nullptr;
    }

    // Если мы перемещаем в себя, нужно очистить предыдущее состояние
    if (&l == this) {
        clear();
    }

    return *this;
}

        //Capacity
        bool empty() { return this->head == nullptr; }         //checks whether the container is empty
        size_type size() { return this->count_of_elem; };     //returns the number of elements
        
        //Modifiers
        void swap(SequenceContainer& other);          //swaps the contents
        protected:

        //Element access
        const_reference front() const {return this->head->data;}  //access the first element
        const_reference back() const {return this->tail->data;}   //access the last element

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
        ListIterator insert_many(const ListIterator pos, std::vector<int> args ) {
            // Проверяем, не пустой ли вектор аргументов
            if (args.empty()) {
                return pos; // Возвращаем текущую позицию, если вставлять нечего
            }
            // Создаем новый узел списка для хранения первого элемента
            ListNode* newNode = new ListNode(args[0]);
            // Вставляем первый элемент перед позицией
            newNode->next = pos.elemPtr;
            newNode->prev = pos.elemPtr->prev;
            newNode->prev->next = newNode;
            newNode->next->prev = newNode;
            ++this->count_of_elem;
            // Вставляем остальные элементы
            for (size_t i = 1; i < args.size(); ++i) {
                insert(pos, args[i]);
            }
            // Возвращаем новую позицию после вставки всех элементов
            return ListIterator(newNode);
        } //Inserts new elements into the container directly before pos.  FOR List, Vector.
        
        void insert_many_back( std::vector<int> args );  //Appends new elements to the end of the container.  FOR List, Vector, Queue.
        void insert_many_front( std::vector<int> args ); // Appends new elements to the top of the container. FOR List, Stack.


        // А эти для вектора только, оказывается. Хз, зачем их сделела) 
 
        reference operator[](size_type pos);  //access specified element
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

template <typename Type>            //destructor
SequenceContainer<Type>::~SequenceContainer() {
    while (head) {
        ListNode* next = head->next; // Сохраняем следующий узел
        delete head;                // Освобождаем память текущего узла
        head = next;                // Переходим к следующему узлу
    }
}

template <typename Type>
SequenceContainer<Type>::SequenceContainer(size_type n)             //parametizated constructor
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
SequenceContainer<Type>::SequenceContainer(std::initializer_list<value_type> const &items)       //initialized_list constructor 
{


    this->count_of_elem = 0;
    this->head = nullptr;
    this->tail = this->head;
    ListNode *current = head;

    for (auto it = items.begin(); it != items.end(); ++it) {
            push_back(*it); // Добавляем каждый элемент из списка в контейнер
        }
}


template <typename Type>
void SequenceContainer<Type>::clear()
{
    while (head) {
        ListNode* next = head->next; // Сохраняем следующий узел
        delete head;                // Освобождаем память текущего узла
        head = next;                // Переходим к следующему узлу
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
    if (this->head == nullptr) {
        this->head = new ListNode(value);
        this->tail = this->head;
    }
    else {
        ListNode* newNode = new ListNode(value);
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }
    this->count_of_elem++;
}

template <typename Type>
void SequenceContainer<Type>::pop_front()
{
    if (head == nullptr) {
        // Список уже пуст, ничего делать не нужно
        return;
    }
    ListNode* first = head; // Сохраняем указатель на первый узел
    head = head->next; // Обновляем голову списка
    head->prev = nullptr; // Указываем, что новый первый узел не имеет предыдущего
    // Освобождаем память первого узла
    delete first;
    count_of_elem--; // Уменьшаем количество элементов
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
    for (int i = 0; i < other.count_of_elem; i++) {
        this->push_back(other[i]);
    }
    this->sort();
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

template <typename Type>
inline void SequenceContainer<Type>::insert_many_back( std::vector<int> args )
{
    if (!args.empty()) {
        // Используем метод push_back для вставки каждого элемента из вектора
        for (int value : args) {
            push_back(value);
        }
    }
}

template <typename Type>
inline void SequenceContainer<Type>::insert_many_front( std::vector<int> args )
{
    if (!args.empty()) {
        // Используем метод push_back для вставки каждого элемента из вектора
        for (int value : args) {
            push_front(value);
        }
    }
}


}
#endif