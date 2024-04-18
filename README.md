# Standart_Containers

Реализация библиотеки s21_containers.h , включающей основные стандартные контейнерные классы языка С++: list (список), map (словарь), queue (очередь), set (множество),  multiset (мультимножество), stack (стек), vector (вектор) и array (массив). Предоставлен весь набор стандартных методов и атрибутов для работы с элементами, проверкой заполненности контейнера и итерирования. 

Проект в стадии разработки, на данный момент реализован двунаправленный связный список. От него будут наследоваться list и queue. 

  <summary>Реализованные методы</summary>

*List Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `iterator`               | internal class `ListIterator<T>` defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `ListConstIterator<T>` defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*List Functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `SequenceContainer()`  | default constructor, creates empty list                                  |
| `SequenceContainer(size_type n)`  | parameterized constructor, creates the list of size n                                 |
| `SequenceContainer(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates list initizialized using std::initializer_list<T>    |
| `SequenceContainer(const SequenceContainer &l)`  | copy constructor  |
| `SequenceContainer(SequenceContainer &&l)`  | move constructor  |
| `~SequenceContainer()`  | destructor  |
| `operator=(SequenceContainer &&l)`      | assignment operator overload for moving object                                |

*List Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access | Definition                                      |
|----------------|-------------------------------------------------|
| `reference at(size_type pos)`                     | access specified element with bounds checking                                          |
| `reference operator[](size_type pos);`             | access specified element                                                               |
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*List Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*List Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*List Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void clear()`          | clears the contents                             |
| `iterator insert(iterator pos, const_reference value)`         | inserts element into concrete pos and returns the iterator that points to the new element     |
| `void erase(iterator pos)`          | erases element at pos                                 |
| `void push_back(const_reference value)`      | adds an element to the end                      |
| `void pop_back()`   | removes the last element        |
| `void push_front(const_reference value)`      | adds an element to the head                      |
| `void pop_front()`   | removes the first element        |
| `void swap(list& other)`                   | swaps the contents                                                                     |
| `void merge(list& other)`                   | merges two sorted lists                                                                      |
| `void splice(const_iterator pos, list& other)`                   | transfers elements from list other starting from pos             |
| `void reverse()`                   | reverses the order of the elements              |
| `void unique()`                   | removes consecutive duplicate elements               |
| `void sort()`                   | sorts the elements                || Modifiers      | Definition                                      | Containers |
|----------------|-------------------------------------------------| -------------------------------------------|
| `iterator insert_many(const_iterator pos, Args&&... args)`          | Inserts new elements into the container directly before `pos`.  |
| `void insert_many_back(Args&&... args)`          | Appends new elements to the end of the container.  |
| `void insert_many_front(Args&&... args)`          | Appends new elements to the top of the container.  |

</details>




