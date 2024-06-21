// ОСНОВНОЙ ФАЙЛ С ТЕСТАМИ

#include <gtest/gtest.h>

#include <set>
#include <vector>

#include "s21_sequence_container.h"
#include "s21_list.h"
#include "s21_queue.h"
#include "s21_stack.h"

// TEST(MapTest, DefaultConstructor) {
//     // Проверяем, что конструктор по умолчанию создает пустую карту
//     s21::map<int, std::string> map;
//     EXPECT_TRUE(map.empty());
//     EXPECT_EQ(static_cast<int>(map.size()), (0));
// }

// TEST(MapTest, InitializerListConstructor) {
//     // Проверяем конструктор с инициализацией из списка инициализации
//     s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};
//     EXPECT_FALSE(map.empty());
//     EXPECT_EQ(static_cast<int>(map.size()), 3);
// }

// TEST(MapTest, CopyConstructor) {
//     // Проверяем копирующий конструктор
//     s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};
//     s21::map<int, std::string> map_copy(map);
//     EXPECT_EQ(map.size(), map_copy.size());
//     // Проверяем, что значения в копии равны значениям в оригинале
//     for (const auto& pair : map) {
//         EXPECT_EQ(map_copy.at(pair.first), pair.second);
//     }
// }

// TEST(MapTest, erase) {
//     s21::map<int, int> map = {{10, 10}, {46, 46}, {19, 19}, {17, 17}, {23, 23}, {14, 14}, {49, 49}, {30, 30}, {38, 38}, {22, 22},
//                               {50, 50}, {43, 43}, {27, 27}, {13, 13}, {5, 5},   {33, 33}, {20, 20}, {15, 15}, {29, 29}, {36, 36},
//                               {37, 37}, {7, 7},   {25, 25}, {44, 44}, {2, 2},   {41, 41}, {48, 48}, {21, 21}, {39, 39}, {1, 1},
//                               {26, 26}, {11, 11}, {47, 47}, {34, 34}, {9, 9},   {8, 8},   {31, 31}, {16, 16}, {12, 12}, {45, 45},
//                               {6, 6},   {3, 3},   {42, 42}, {24, 24}, {28, 28}, {35, 35}, {4, 4},   {32, 32}, {40, 40}, {18, 18}};

//     EXPECT_FALSE(map.empty());

//     auto it = map.begin();
//     auto end = map.end();

//     // Ищу нужный итератор ноды для удаления
//     while (it != end) {
//         if ((*it).first == 16) {
//             map.erase(it);
//             it = map.begin();
//             end = map.end();
//             break;
//         }
//         ++it;
//     }

//     while (it != end) {
//         if ((*it).first == 24) {
//             map.erase(it);
//             it = map.begin();
//             end = map.end();
//             break;
//         }
//         ++it;
//     }

//     while (it != end) {
//         if ((*it).first == 40) {
//             map.erase(it);
//             it = map.begin();
//             end = map.end();
//             break;
//         }
//         ++it;
//     }

//     while (it != end) {
//         if ((*it).first == 25) {
//             map.erase(it);
//             it = map.begin();
//             end = map.end();
//             break;
//         }
//         ++it;
//     }

//     while (it != end) {
//         if ((*it).first == 25) {
//             map.erase(it);
//             break;
//         }
//         ++it;
//     }

//     it = map.begin();
//     end = map.end();

//     while (it != end) {
//         if ((*it).first == 32) {
//             map.erase(it);
//             it = map.begin();
//             end = map.end();
//             break;
//         }
//         ++it;
//     }

//     while (it != end) {
//         if ((*it).first == 1) {
//             map.erase(it);
//             it = map.begin();
//             end = map.end();
//             break;
//         }
//         ++it;
//     }

//     while (it != end) {
//         if ((*it).first == 5) {
//             map.erase(it);
//             it = map.begin();
//             end = map.end();
//             break;
//         }
//         ++it;
//     }

//     while (it != end) {
//         if ((*it).first == 30) {
//             map.erase(it);
//             it = map.begin();
//             end = map.end();
//             break;
//         }
//         ++it;
//     }

//     // Проверяю, что нод теперь 3
//     EXPECT_EQ(static_cast<int>(map.size()), 42);
// }

// TEST(MapTest, Merge) {
//     // Создаем две карты
//     s21::map<int, int> map1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}, {10, 10}};
//     s21::map<int, int> map2 = {{11, 11}, {12, 12}, {13, 13}, {14, 14}, {15, 15}, {16, 16}, {17, 17}, {18, 18}, {19, 19}, {20, 20}};

//     // Объединяем карты
//     map1.merge(map2);

//     // Проверяем, что карты были успешно объединены
//     EXPECT_EQ(static_cast<int>(map1.size()), 20);
//     EXPECT_EQ(static_cast<int>(map2.size()), 10);

//     // Проверяем, что все элементы из второй карты перенеслись в первую
//     for (int i = 1; i <= 20; ++i) {
//         EXPECT_EQ(map1.at(i), i);
//     }
// }

// TEST(MapTest, InsertOrAssign) {
//     s21::map<int, int> map = {{10, 10}, {46, 46}, {19, 19}, {17, 17}, {23, 23}, {14, 14}, {49, 49}, {30, 30}, {38, 38}, {22, 22},
//                               {50, 50}, {43, 43}, {27, 27}, {13, 13}, {5, 5},   {33, 33}, {20, 20}, {15, 15}, {29, 29}, {36, 36},
//                               {37, 37}, {7, 7},   {25, 25}, {44, 44}, {2, 2},   {41, 41}, {48, 48}, {21, 21}, {39, 39}, {1, 1},
//                               {26, 26}, {11, 11}, {47, 47}, {34, 34}, {9, 9},   {8, 8},   {31, 31}, {16, 16}, {12, 12}, {45, 45},
//                               {6, 6},   {3, 3},   {42, 42}, {24, 24}, {28, 28}, {35, 35}};
//     ;
//     map.insert_or_assign(1, 1);
//     map.insert_or_assign(2, 2);
//     map.insert_or_assign(3, 3);
//     map.insert_or_assign(51, 51);
//     map.insert_or_assign(4, 4);
//     map.insert_or_assign(32, 32);
//     map.insert_or_assign(40, 40);
//     map.insert_or_assign(18, 18);

//     // Проверка наличия вставленных элементов и их значений
//     EXPECT_TRUE(map.contains(1));
//     EXPECT_TRUE(map.contains(2));
//     EXPECT_TRUE(map.contains(3));
//     EXPECT_EQ(map.at(1), 1);
//     EXPECT_EQ(map.at(2), 2);
//     EXPECT_EQ(map.at(3), 3);
//     EXPECT_EQ(map.at(51), 51);

//     // Проверка перезаписи элемента при повторной вставке с тем же ключом
//     map.insert_or_assign(2, 22);
//     EXPECT_EQ(map.at(2), 22);
// }

// TEST(MapTest, Swap) {
//     s21::map<int, std::string> map1 = {{1, "one"}, {2, "two"}, {3, "three"}};
//     s21::map<int, std::string> map2 = {{4, "four"}, {5, "five"}, {6, "six"}};

//     map1.swap(map2);

//     // Проверка, что содержимое поменялось местами
//     EXPECT_FALSE(map1.contains(1));
//     EXPECT_FALSE(map1.contains(2));
//     EXPECT_FALSE(map1.contains(3));
//     EXPECT_TRUE(map1.contains(4));
//     EXPECT_TRUE(map1.contains(5));
//     EXPECT_TRUE(map1.contains(6));

//     EXPECT_TRUE(map2.contains(1));
//     EXPECT_TRUE(map2.contains(2));
//     EXPECT_TRUE(map2.contains(3));
//     EXPECT_FALSE(map2.contains(4));
//     EXPECT_FALSE(map2.contains(5));
//     EXPECT_FALSE(map2.contains(6));
// }

// TEST(MapTest, InsertMany) {
//     s21::map<int, std::string> map;

//     // Вставляем несколько элементов сразу
//     auto results = map.insert_many(std::make_pair(1, "one"), std::make_pair(2, "two"), std::make_pair(3, "three"));

//     // Проверяем, что все элементы были успешно вставлены
//     EXPECT_EQ(static_cast<int>(results.size()), 3);
//     for (const auto& result : results) {
//         EXPECT_TRUE(result.second);  // Проверяем, что элемент был успешно вставлен
//     }

//     // Проверяем наличие всех вставленных элементов и их значения
//     EXPECT_TRUE(map.contains(1));
//     EXPECT_TRUE(map.contains(2));
//     EXPECT_TRUE(map.contains(3));
//     EXPECT_EQ(map.at(1), "one");
//     EXPECT_EQ(map.at(2), "two");
//     EXPECT_EQ(map.at(3), "three");
// }

// TEST(MapTest, InsertManyVariadic) {
//     s21::map<int, std::string> map;

//     // Вставляем несколько элементов сразу
//     auto results =
//         map.insert_many(std::make_pair(1, "one"), std::make_pair(2, "two"), std::make_pair(3, "three"), std::make_pair(4, "four"));

//     // Проверяем, что все элементы были успешно вставлены
//     EXPECT_EQ(static_cast<int>(results.size()), 4);
//     for (const auto& result : results) {
//         EXPECT_TRUE(result.second);  // Проверяем, что элемент был успешно вставлен
//     }

//     // Проверяем наличие всех вставленных элементов и их значения
//     EXPECT_TRUE(map.contains(1));
//     EXPECT_TRUE(map.contains(2));
//     EXPECT_TRUE(map.contains(3));
//     EXPECT_TRUE(map.contains(4));
//     EXPECT_EQ(map.at(1), "one");
//     EXPECT_EQ(map.at(2), "two");
//     EXPECT_EQ(map.at(3), "three");
//     EXPECT_EQ(map.at(4), "four");
// }

// TEST(MapIteratorTest, PostfixDecrement) {
//     s21::map<int, int> map = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
//     auto it = map.end();
//     it--;

//     EXPECT_EQ((*it).first, 4);

//     it--;
//     EXPECT_EQ((*it).first, 3);
// }

// // QUEUE
TEST(QueueTest, DefaultConstructor) {
    s21::s21_queue<int> q;
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(static_cast<int>(q.size()), 0);
}

TEST(QueueTest, InitializerListConstructor) {
    s21::s21_queue<int> q = {1, 2, 3, 4, 5};
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(static_cast<int>(q.size()), 5);
    EXPECT_EQ(q.front(), 1);
    EXPECT_EQ(q.back(), 5);
}

TEST(QueueTest, CopyConstructor) {
    s21::s21_queue<int> q1 = {1, 2, 3, 4, 5};
    s21::s21_queue<int> q2 = q1;
    EXPECT_EQ(static_cast<int>(q1.size()), 5);
    EXPECT_EQ(static_cast<int>(q2.size()), 5);

    EXPECT_EQ(q1.front(), 1);
    EXPECT_EQ(q1.back(), 5);

    EXPECT_EQ(q2.front(), 1);
    EXPECT_EQ(q2.back(), 5);
}

TEST(QueueTest, AssignmentOperatorMove) {
    s21::s21_queue<int> q1 = {1, 2, 3, 4, 5};
    s21::s21_queue<int> q2 = {6, 7, 8};

    EXPECT_EQ(static_cast<int>(q1.size()), 5);
    EXPECT_EQ(static_cast<int>(q2.size()), 3);

    q2 = std::move(q1);

    EXPECT_TRUE(q1.empty());
    EXPECT_EQ(static_cast<int>(q1.size()), 0);
    EXPECT_EQ(static_cast<int>(q2.size()), 5);

    EXPECT_EQ(q2.front(), 1);
    EXPECT_EQ(q2.back(), 5);
}

TEST(QueueTest, InsertMany) {
    s21::s21_queue<int> q{1, 2, 3};

    std::vector<int> args{4, 5, 6};
    q.insert_many_back(args);

    ASSERT_EQ(q.front(), 1);
    ASSERT_EQ(q.back(), 6);
    ASSERT_EQ(q.count_of_elem, 6);
}

TEST(QueueTest, Push) {
    s21::s21_queue<int> q;
    q.push(1);
    ASSERT_EQ(q.back(), 1);
    q.push(2);
    ASSERT_EQ(q.back(), 2);
}

TEST(QueueTest, Pop) {
    s21::s21_queue<int> q{1, 2, 3};
    q.pop();
    ASSERT_EQ(q.front(), 2);
}

TEST(QueueTest, Swap) {
    s21::s21_queue<int> q1 = {1, 2, 3, 4, 5};
    s21::s21_queue<int> q2 = {6, 7, 8};
    EXPECT_EQ(static_cast<int>(q1.size()), 5);
    EXPECT_EQ(static_cast<int>(q2.size()), 3);

    q1.swap(q2);
    EXPECT_EQ(static_cast<int>(q1.size()), 3);
    EXPECT_EQ(static_cast<int>(q2.size()), 5);
}

// STACK
TEST(StackTest, DefaultConstructor) {
    s21::s21_stack<int> s;
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(static_cast<int>(s.size()), 0);
}

TEST(StackTest, InitializerListConstructor) {
    s21::s21_stack<int> s = {1, 2, 3, 4, 5};
    EXPECT_FALSE(s.empty());
    EXPECT_EQ(static_cast<int>(s.size()), 5);
    EXPECT_EQ(s.top(), 5);
}

TEST(StackTest, CopyConstructor) {
    s21::s21_stack<int> s1 = {1, 2, 3, 4, 5};
    s21::s21_stack<int> s2 = s1;
    EXPECT_EQ(static_cast<int>(s1.size()), 5);
    EXPECT_EQ(static_cast<int>(s2.size()), 5);

    EXPECT_EQ(s1.top(), 5);
    EXPECT_EQ(s1.top(), 5);
}

TEST(StackTest, AssignmentOperatorMove) {
    s21::s21_stack<int> s1 = {1, 2, 3, 4, 5};
    s21::s21_stack<int> s2 = {6, 7, 8};

    EXPECT_EQ(static_cast<int>(s1.size()), 5);
    EXPECT_EQ(static_cast<int>(s2.size()), 3);

    s2 = std::move(s1);

    EXPECT_TRUE(s1.empty());
    EXPECT_EQ(static_cast<int>(s1.size()), 0);
    EXPECT_EQ(static_cast<int>(s2.size()), 5);

    EXPECT_EQ(s2.top(), 5);
}

TEST(StackTest, InsertManyFront) {
    s21::s21_stack<int> s{1, 2, 3};

    std::vector<int> args{4, 5, 6};
    s.insert_many_front(args);

    ASSERT_EQ(s.top(), 6);
    ASSERT_EQ(s.count_of_elem, 6);
}

TEST(StackTest, Push) {
    s21::s21_stack<int> s;
    s.push(1);
    ASSERT_EQ(s.top(), 1);
    s.push(2);
    ASSERT_EQ(s.top(), 2);
}

TEST(StackTest, Pop) {
    s21::s21_stack<int> s{1, 2, 3};
    s.pop();
    ASSERT_EQ(s.top(), 2);
}

TEST(StackTest, Swap) {
    s21::s21_stack<int> s1 = {1, 2, 3, 4, 5};
    s21::s21_stack<int> s2 = {6, 7, 8};
    EXPECT_EQ(static_cast<int>(s1.size()), 5);
    EXPECT_EQ(static_cast<int>(s2.size()), 3);

    s1.swap(s2);
    EXPECT_EQ(static_cast<int>(s1.size()), 3);
    EXPECT_EQ(static_cast<int>(s2.size()), 5);
}

// // VECTOR
// TEST(VectorTest, DefaultConstructor) {
//     s21::vector<int> t;
//     EXPECT_TRUE(t.empty());
//     EXPECT_EQ(static_cast<int>(t.size()), 0);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 0);
// }

// TEST(VectorTest, InitializerListConstructor) {
//     s21::vector<int> t = {1, 2, 3, 4, 5};
//     EXPECT_FALSE(t.empty());
//     EXPECT_EQ(static_cast<int>(t.size()), 5);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 5);

//     EXPECT_EQ(t[0], 1);
//     EXPECT_EQ(t[4], 5);
// }

// TEST(VectorTest, CopyConstructor) {
//     s21::vector<int> t1 = {1, 2, 3, 4, 5};
//     s21::vector<int> t2 = t1;
//     EXPECT_EQ(static_cast<int>(t1.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.size()), 5);

//     EXPECT_EQ(static_cast<int>(t1.capacity()), 5);
//     EXPECT_EQ(static_cast<int>(t2.capacity()), 5);

//     EXPECT_EQ(t1[0], 1);
//     EXPECT_EQ(t2[0], 1);
// }

// TEST(VectorTest, MoveConstructor) {
//     s21::vector<int> t1 = {1, 2, 3, 4, 5};
//     s21::vector<int> t2 = std::move(t1);

//     EXPECT_TRUE(t1.empty());
//     EXPECT_EQ(static_cast<int>(t1.size()), 0);
//     EXPECT_EQ(static_cast<int>(t1.capacity()), 0);
//     EXPECT_FALSE(t2.empty());
//     EXPECT_EQ(static_cast<int>(t2.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.capacity()), 5);

//     EXPECT_EQ(t2[2], 3);
// }

// TEST(VectorTest, AssignmentOperatorCopy) {
//     s21::vector<int> t1 = {1, 2, 3, 4, 5};
//     s21::vector<int> t2 = {6, 7, 8};

//     EXPECT_EQ(static_cast<int>(t1.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.size()), 3);
//     t2.pop_back();
//     EXPECT_EQ(t2[t2.size() - 1], 7);
//     t2.push_back(9);
//     EXPECT_EQ(t2[t2.size() - 1], 9);

//     t2 = t1;
//     EXPECT_EQ(static_cast<int>(t1.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.size()), 5);

//     EXPECT_EQ(t2[t2.size() - 1], 5);
//     EXPECT_EQ(t2[t2.size() - 1], 5);

//     s21::vector<int> t3 = {10, 11, 12, 14, 15, 16, 17};
//     EXPECT_EQ(static_cast<int>(t3.size()), 7);
//     EXPECT_EQ(static_cast<int>(t3.capacity()), 7);

//     t3 = t2;
//     EXPECT_EQ(static_cast<int>(t3.size()), 5);
//     EXPECT_EQ(static_cast<int>(t3.capacity()), 7);
// }

// TEST(VectorTest, AssignmentOperatorMove) {
//     s21::vector<int> t1 = {1, 2, 3, 4, 5};
//     s21::vector<int> t2 = {6, 7, 8};

//     EXPECT_EQ(static_cast<int>(t1.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.size()), 3);

//     EXPECT_EQ(static_cast<int>(t1.capacity()), 5);
//     EXPECT_EQ(static_cast<int>(t2.capacity()), 3);

//     t2 = std::move(t1);

//     EXPECT_TRUE(t1.empty());
//     EXPECT_EQ(static_cast<int>(t1.size()), 0);
//     EXPECT_EQ(static_cast<int>(t1.capacity()), 0);

//     EXPECT_EQ(static_cast<int>(t2.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.capacity()), 5);

//     EXPECT_EQ(t2[t2.size() - 1], 5);
// }

// TEST(VectorTest, Insert) {
//     s21::vector<int> t = {1, 2, 3, 4, 5};

//     EXPECT_EQ(static_cast<int>(t.size()), 5);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 5);
//     t.insert(t.begin(), 10);

//     EXPECT_EQ(static_cast<int>(t.size()), 6);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 10);

//     EXPECT_EQ(t[0], 10);
//     t.insert(t.begin(), 11);
//     t.insert(t.begin(), 12);
//     t.insert(t.begin(), 13);
//     t.insert(t.begin(), 14);
//     EXPECT_EQ(static_cast<int>(t.size()), 10);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 10);
//     t.insert(t.begin(), 15);

//     EXPECT_EQ(static_cast<int>(t.size()), 11);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 20);
//     EXPECT_EQ(t[0], 15);
// }

// TEST(VectorTest, InsertMany) {
//     s21::vector<int> t = {1, 2, 3, 4, 5};
//     EXPECT_EQ(t[3], 4);
//     EXPECT_EQ(static_cast<int>(t.size()), 5);
//     t.insert_many(t.cbegin(), 6, 7, 8);
//     EXPECT_EQ(static_cast<int>(t.size()), 8);
//     EXPECT_EQ(*(t.cbegin()), 6);

//     t.insert_many_back(100, 90, 200);
//     EXPECT_EQ(static_cast<int>(t.size()), 11);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 20);
//     EXPECT_EQ(*(--t.cend()), 200);
// }

// TEST(VectorTest, Swap) {
//     s21::vector<int> t1 = {1, 2, 3, 4, 5};
//     s21::vector<int> t2 = {6, 7, 8};
//     EXPECT_EQ(static_cast<int>(t1.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.size()), 3);
//     EXPECT_EQ(static_cast<int>(t1.capacity()), 5);
//     EXPECT_EQ(static_cast<int>(t2.capacity()), 3);

//     t1.swap(t2);
//     EXPECT_EQ(static_cast<int>(t1.size()), 3);
//     EXPECT_EQ(static_cast<int>(t2.size()), 5);
//     EXPECT_EQ(static_cast<int>(t1.capacity()), 3);
//     EXPECT_EQ(static_cast<int>(t2.capacity()), 5);
// }

// TEST(VectorTest, AllocateMemory) {
//     s21::vector<int> t;
//     EXPECT_EQ(static_cast<int>(t.size()), 0);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 0);

//     t.push_back(99);
//     EXPECT_EQ(static_cast<int>(t.size()), 1);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 1);

//     t.push_back(100);
//     EXPECT_EQ(static_cast<int>(t.size()), 2);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 2);

//     t.push_back(101);
//     EXPECT_EQ(static_cast<int>(t.size()), 3);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 4);

//     t.push_back(102);
//     EXPECT_EQ(static_cast<int>(t.size()), 4);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 4);

//     t.push_back(103);
//     EXPECT_EQ(static_cast<int>(t.size()), 5);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 8);

//     t.insert_many(t.cend(), 104, 105, 106, 107);
//     EXPECT_EQ(static_cast<int>(t.size()), 9);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 16);

//     t.clear();
//     EXPECT_EQ(static_cast<int>(t.size()), 0);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 16);
// }

// TEST(VectorTest, MemoryManagment) {
//     s21::vector<int> t = {1, 2, 3, 4, 5};
//     EXPECT_EQ(static_cast<int>(t.size()), 5);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 5);
//     t.reserve(20);

//     EXPECT_EQ(static_cast<int>(t.size()), 5);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 20);

//     t.push_back(6);
//     EXPECT_EQ(static_cast<int>(t.size()), 6);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 20);

//     t.shrink_to_fit();
//     EXPECT_EQ(static_cast<int>(t.size()), 6);
//     EXPECT_EQ(static_cast<int>(t.capacity()), 6);

//     std::vector<int> v;
//     // на разных системах могут не сходить значения
//     EXPECT_EQ(v.max_size(), t.max_size());
// }

// TEST(VectorTest, UsingIterator) {
//     s21::vector<int> t = {1, 2, 3, 4, 5};
//     int i = 0;
//     for (auto it = t.begin(); it != t.end(); ++it, ++i) {
//         EXPECT_EQ(*it, t[i]);
//     }

//     EXPECT_EQ(*(t.cbegin() + 2), 3);
//     EXPECT_EQ(*(t.cend() - 2), 4);

//     EXPECT_TRUE(++t.cbegin() == t.begin() + 1);
// }

// TEST(VectorTest, View) {
//     s21::vector<int> t = {1, 2, 3, 4, 5};

//     EXPECT_EQ(t.at(t.size() - 1), t[t.size() - 1]);
//     EXPECT_THROW(t.at(t.size()), std::domain_error);
//     EXPECT_EQ(*t.data(), t[0]);

//     EXPECT_EQ(t.front(), 1);
//     EXPECT_EQ(t.back(), 5);
// }

// TEST(VectorTest, Erase) {
//     s21::vector<int> t = {1, 2, 3, 4, 5};
//     t.erase(t.begin());

//     EXPECT_EQ(t.front(), 2);
// }

// // SET
// TEST(SetTest, DefaultConstructor) {
//     s21::set<int> t;
//     EXPECT_TRUE(t.empty());
//     EXPECT_EQ(static_cast<int>(t.size()), 0);
// }

// TEST(SetTest, InitializerListConstructor) {
//     s21::set<int> t = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11};
//     EXPECT_FALSE(t.empty());
//     EXPECT_EQ(static_cast<int>(t.size()), 21);

//     EXPECT_EQ(*t.cbegin(), -11);
//     EXPECT_EQ(*(--t.cend()), 75);
// }

// TEST(SetTest, CopyConstructor) {
//     s21::set<int> t1 = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11};
//     s21::set<int> t2 = t1;
//     EXPECT_EQ(static_cast<int>(t1.size()), 21);
//     EXPECT_EQ(static_cast<int>(t2.size()), 21);

//     EXPECT_EQ(*t1.cbegin(), -11);
//     EXPECT_EQ(*t2.cbegin(), -11);

//     EXPECT_EQ(*(--t1.cend()), 75);
//     EXPECT_EQ(*(--t2.cend()), 75);
// }

// TEST(SetTest, MoveConstructor) {
//     s21::set<int> t1 = {1, 2, 3, 4, 5};
//     s21::set<int> t2 = std::move(t1);

//     EXPECT_TRUE(t1.empty());
//     EXPECT_EQ(static_cast<int>(t1.size()), 0);
//     EXPECT_FALSE(t2.empty());
//     EXPECT_EQ(static_cast<int>(t2.size()), 5);

//     EXPECT_EQ(*t2.cbegin(), 1);
//     EXPECT_EQ(*(--t2.cend()), 5);
// }

// TEST(SetTest, AssignmentOperatorCopy) {
//     s21::set<int> t1 = {1, 2, 3, 4, 5};
//     s21::set<int> t2 = {6, 7, 8};

//     EXPECT_EQ(static_cast<int>(t1.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.size()), 3);

//     t2 = t1;
//     EXPECT_EQ(static_cast<int>(t1.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.size()), 5);
// }

// TEST(SetTest, AssignmentOperatorMove) {
//     s21::set<int> t1 = {1, 2, 3, 4, 5};
//     s21::set<int> t2 = {6, 7, 8};

//     EXPECT_EQ(static_cast<int>(t1.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.size()), 3);

//     t2 = std::move(t1);

//     EXPECT_TRUE(t1.empty());
//     EXPECT_EQ(static_cast<int>(t1.size()), 0);
//     EXPECT_EQ(static_cast<int>(t2.size()), 5);
// }

// TEST(SetTest, Insert) {
//     s21::set<int> t = {1, 2, 3, 4, 5};

//     EXPECT_EQ(static_cast<int>(t.size()), 5);
//     t.insert(10);

//     EXPECT_EQ(static_cast<int>(t.size()), 6);

//     EXPECT_EQ(*(--t.cend()), 10);
//     t.insert(11);
//     t.insert(12);
//     t.insert(13);
//     t.insert(14);
//     EXPECT_EQ(static_cast<int>(t.size()), 10);
// }

// TEST(SetTest, InsertMany) {
//     s21::set<int> t = {1, 2, 3, 4, 5};
//     t.insert_many(100, 99, 98);
//     EXPECT_EQ(*(--t.cend()), 100);

//     EXPECT_EQ(static_cast<int>(t.size()), 8);
//     t.insert_many(-6, 7, 8);
//     EXPECT_EQ(static_cast<int>(t.size()), 11);
//     EXPECT_EQ(*(t.cbegin()), -6);
// }

// TEST(SetTest, Swap) {
//     s21::set<int> t1 = {1, 2, 3, 4, 5};
//     s21::set<int> t2 = {6, 7, 8};
//     EXPECT_EQ(static_cast<int>(t1.size()), 5);
//     EXPECT_EQ(static_cast<int>(t2.size()), 3);

//     t1.swap(t2);
//     EXPECT_EQ(static_cast<int>(t1.size()), 3);
//     EXPECT_EQ(static_cast<int>(t2.size()), 5);
// }

// TEST(SetTest, MemoryManagment) {
//     s21::set<int> t = {1, 2, 3, 4, 5};
//     EXPECT_EQ(static_cast<int>(t.size()), 5);

//     t.clear();
//     EXPECT_EQ(static_cast<int>(t.size()), 0);

//     std::set<int> s;
//     // на разных системах могут не сходить значения
//     EXPECT_EQ(s.max_size(), t.max_size());
// }

// TEST(SetTest, UsingIterator) {
//     s21::set<int> t = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11, 1, 1, 1, -100, -99, -88};

//     s21::array<int, 30> res = {-100, -99, -88, -11, -10, -9, -5, 1, 2, 3, 5, 10, 13, 18, 20, 22, 23, 27, 55, 56, 57, 59, 60, 75};

//     int i = 0;
//     for (auto it = t.begin(); it != t.end(); ++it, ++i) {
//         EXPECT_EQ(*it, res[i]);
//     }

//     s21::set<int> x;
//     EXPECT_THROW(*x.cbegin(), std::domain_error);
//     EXPECT_THROW(*x.cend(), std::domain_error);
//     EXPECT_THROW(*x.begin(), std::domain_error);
//     EXPECT_THROW(*x.end(), std::domain_error);
//     EXPECT_THROW(*(--x.end()), std::domain_error);

//     s21::set<int> z = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11, 1, 1, 1, -100, -99, -88};
//     s21::array<int, 30> res_reverse = {75, 60, 59, 57, 56, 55, 27, 23, 22, 20, 18, 13, 10, 5, 3, 2, 1, -5, -9, -10, -11, -88, -99};

//     int j = 0;
//     for (auto it = --z.cend(); it != z.cbegin(); --it, ++j) {
//         EXPECT_EQ(*it, res_reverse[j]);
//     }
// }

// TEST(SetTest, Erase) {
//     s21::set<int> t = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11, 1, 1, 1, 12};

//     t.erase(t.begin());
//     t.erase(t.find(1));
//     t.erase(t.find(10));
//     t.erase(t.find(13));
//     t.erase(t.find(56));

//     s21::array<int, 20> res = {-10, -9, -5, 2, 3, 5, 12, 18, 20, 22, 23, 27, 55, 57, 59, 60, 75};

//     EXPECT_EQ(static_cast<int>(t.size()), 22 - 5);

//     int i = 0;
//     for (auto it = t.begin(); it != t.end(); ++it, ++i) {
//         EXPECT_EQ(*it, res[i]);
//     }
// }

// TEST(SetTest, Merge) {
//     s21::set<int> t1 = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11, 1, 1, 1};
//     s21::set<int> t2 = {-100, -99, -88};

//     s21::array<int, 30> res = {-100, -99, -88, -11, -10, -9, -5, 1, 2, 3, 5, 10, 13, 18, 20, 22, 23, 27, 55, 56, 57, 59, 60, 75};

//     t1.merge(t2);

//     int i = 0;
//     for (auto it = t1.begin(); it != t1.end(); ++it, ++i) {
//         EXPECT_EQ(*it, res[i]);
//     }

//     EXPECT_TRUE(t2.empty());
// }

// // MULTISET
// TEST(MultisetTest, DefaultConstructor) {
//     s21::multiset<int> t;
//     EXPECT_TRUE(t.empty());
//     EXPECT_EQ(static_cast<int>(t.size()), 0);
// }

// TEST(MultisetTest, InitializerListConstructor) {
//     s21::multiset<int> t = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11};
//     EXPECT_FALSE(t.empty());
//     EXPECT_EQ(static_cast<int>(t.size()), 23);

//     EXPECT_EQ(*t.cbegin(), -11);
//     EXPECT_EQ(*(--t.cend()), 75);
// }

// TEST(MultisetTest, CopyConstructor) {
//     s21::multiset<int> t1 = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11};
//     s21::multiset<int> t2 = t1;
//     EXPECT_EQ(static_cast<int>(t1.size()), 23);
//     EXPECT_EQ(static_cast<int>(t2.size()), 23);

//     EXPECT_EQ(*t1.cbegin(), -11);
//     EXPECT_EQ(*t2.cbegin(), -11);

//     EXPECT_EQ(*(--t1.cend()), 75);
//     EXPECT_EQ(*(--t2.cend()), 75);
// }

// TEST(MultisetTest, MoveConstructor) {
//     s21::multiset<int> t1 = {1, 2, 3, 4, 5, 5};
//     s21::multiset<int> t2 = std::move(t1);

//     EXPECT_TRUE(t1.empty());
//     EXPECT_EQ(static_cast<int>(t1.size()), 0);
//     EXPECT_FALSE(t2.empty());
//     EXPECT_EQ(static_cast<int>(t2.size()), 6);

//     EXPECT_EQ(*t2.cbegin(), 1);
//     EXPECT_EQ(*(--t2.cend()), 5);
// }

// TEST(MultisetTest, AssignmentOperatorCopy) {
//     s21::multiset<int> t1 = {1, 2, 3, 4, 5, 5};
//     s21::multiset<int> t2 = {6, 7, 8, 6};

//     EXPECT_EQ(static_cast<int>(t1.size()), 6);
//     EXPECT_EQ(static_cast<int>(t2.size()), 4);

//     t2 = t1;
//     EXPECT_EQ(static_cast<int>(t1.size()), 6);
//     EXPECT_EQ(static_cast<int>(t2.size()), 6);
// }

// TEST(MultisetTest, AssignmentOperatorMove) {
//     s21::multiset<int> t1 = {1, 2, 3, 4, 5, 5};
//     s21::multiset<int> t2 = {6, 7, 8, 6};

//     EXPECT_EQ(static_cast<int>(t1.size()), 6);
//     EXPECT_EQ(static_cast<int>(t2.size()), 4);

//     t2 = std::move(t1);

//     EXPECT_TRUE(t1.empty());
//     EXPECT_EQ(static_cast<int>(t1.size()), 0);
//     EXPECT_EQ(static_cast<int>(t2.size()), 6);
// }

// TEST(MultisetTest, Insert) {
//     s21::multiset<int> t = {1, 2, 3, 4, 5, 5};

//     EXPECT_EQ(static_cast<int>(t.size()), 6);
//     t.insert(1);

//     EXPECT_EQ(static_cast<int>(t.size()), 7);

//     EXPECT_EQ(*(--t.cend()), 5);
//     t.insert(11);
//     t.insert(12);
//     t.insert(11);
//     t.insert(12);
//     EXPECT_EQ(static_cast<int>(t.size()), 11);
// }

// TEST(MultisetTest, InsertMany) {
//     s21::multiset<int> t = {1, 2, 3, 4, 5, 5};
//     t.insert_many(100, 99, 99);
//     EXPECT_EQ(*(--t.cend()), 100);

//     EXPECT_EQ(static_cast<int>(t.size()), 9);
//     t.insert_many(-6, -6, 8);
//     EXPECT_EQ(static_cast<int>(t.size()), 12);
//     EXPECT_EQ(*(t.cbegin()), -6);
// }

// TEST(MultisetTest, Swap) {
//     s21::multiset<int> t1 = {1, 2, 3, 4, 5, 5};
//     s21::multiset<int> t2 = {6, 7, 8, 6};
//     EXPECT_EQ(static_cast<int>(t1.size()), 6);
//     EXPECT_EQ(static_cast<int>(t2.size()), 4);

//     t1.swap(t2);
//     EXPECT_EQ(static_cast<int>(t1.size()), 4);
//     EXPECT_EQ(static_cast<int>(t2.size()), 6);
// }

// TEST(MultisetTest, MemoryManagment) {
//     s21::multiset<int> t = {1, 2, 3, 4, 5, 5};
//     EXPECT_EQ(static_cast<int>(t.size()), 6);

//     t.clear();
//     EXPECT_EQ(static_cast<int>(t.size()), 0);

//     std::set<int> s;
//     // на разных системах могут не сходить значения
//     EXPECT_EQ(s.max_size(), t.max_size());
// }

// TEST(MultisetTest, UsingIterator) {
//     s21::multiset<int> t = {1,  5,  2,  55, -9,  -5,  18, 56,  10, 3, 13, 23,   27,  20, 22,
//                             57, 60, 59, 75, -10, -11, 55, -11, 1,  1, 1,  -100, -99, -88};

//     s21::array<int, 40> res = {-100, -99, -88, -11, -11, -10, -9, -5, 1,  1,  1,  1,  2,  3, 5,
//                                10,   13,  18,  20,  22,  23,  27, 55, 55, 56, 57, 59, 60, 75};

//     int i = 0;
//     for (auto it = t.begin(); it != t.end(); ++it, ++i) {
//         EXPECT_EQ(*it, res[i]);
//     }

//     s21::multiset<int> x;
//     EXPECT_THROW(*x.cbegin(), std::domain_error);
//     EXPECT_THROW(*x.cend(), std::domain_error);
//     EXPECT_THROW(*x.begin(), std::domain_error);
//     EXPECT_THROW(*x.end(), std::domain_error);
//     EXPECT_THROW(*(--x.end()), std::domain_error);

//     s21::multiset<int> z = {1,  5,  2,  55, -9,  -5,  18, 56,  10, 3, 13, 23,   27,  20, 22,
//                             57, 60, 59, 75, -10, -11, 55, -11, 1,  1, 1,  -100, -99, -88};
//     s21::array<int, 30> res_reverse = {75, 60, 59, 57, 56, 55, 55, 27, 23, 22,  20,  18,  13,  10,
//                                        5,  3,  2,  1,  1,  1,  1,  -5, -9, -10, -11, -11, -88, -99};

//     int j = 0;
//     for (auto it = --z.cend(); it != z.cbegin(); --it, ++j) {
//         EXPECT_EQ(*it, res_reverse[j]);
//     }
// }

// TEST(MultisetTest, Erase) {
//     s21::multiset<int> t = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11, 1, 1, 1, 12};

//     t.erase(t.begin());
//     t.erase(t.find(1));
//     t.erase(t.find(10));
//     t.erase(t.find(13));
//     t.erase(t.find(56));

//     s21::array<int, 20> res = {-11, -10, -9, -5, 1, 1, 1, 2, 3, 5, 12, 18, 20, 22, 23, 27, 55, 55, 57, 59, 60, 75};

//     EXPECT_EQ(static_cast<int>(t.size()), 22);

//     int i = 0;
//     for (auto it = t.begin(); it != t.end(); ++it, ++i) {
//         EXPECT_EQ(*it, res[i]);
//     }
// }

// TEST(MultisetTest, Merge) {
//     s21::multiset<int> t1 = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11, 1, 1, 1};
//     s21::multiset<int> t2 = {-100, -99, -88, -88};

//     s21::array<int, 40> res = {-100, -99, -88, -88, -11, -11, -10, -9, -5, 1,  1,  1,  1,  2,  3,
//                                5,    10,  13,  18,  20,  22,  23,  27, 55, 55, 56, 57, 59, 60, 75};

//     t1.merge(t2);

//     int i = 0;
//     for (auto it = t1.begin(); it != t1.end(); ++it, ++i) {
//         EXPECT_EQ(*it, res[i]);
//     }

//     EXPECT_TRUE(t2.empty());
// }

// TEST(MultisetTest, Contains) {
//     s21::multiset<int> t = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11, 1, 1, 1};

//     EXPECT_EQ(static_cast<int>(t.count(1)), 4);
//     EXPECT_EQ(static_cast<int>(t.count(-1000)), 0);

//     EXPECT_THROW(*t.find(-1000), std::domain_error);
//     EXPECT_TRUE(t.contains(55));
// }

// TEST(MultisetTest, Range) {
//     s21::multiset<int> t = {1, 5, 2, 55, -9, -5, 18, 56, 10, 3, 13, 23, 27, 20, 22, 57, 60, 59, 75, -10, -11, 55, -11, 1, 1, 1};

//     EXPECT_EQ(*(t.lower_bound(19)), 20);
//     EXPECT_EQ(*(t.upper_bound(1)), 2);

//     auto pair1 = t.equal_range(1);
//     auto pair2 = t.equal_range(-500);
//     auto pair3 = t.equal_range(56);
//     int i1 = 0;
//     int i2 = 0;
//     int i3 = 0;
//     for (auto it = pair1.first; it != pair1.second; ++it) {
//         ++i1;
//     }
//     for (auto it = pair2.first; it != pair2.second; ++it) {
//         ++i2;
//     }
//     for (auto it = pair3.first; it != pair3.second; ++it) {
//         ++i3;
//     }

//     EXPECT_EQ(i1, 4);
//     EXPECT_EQ(i2, 0);
//     EXPECT_EQ(i3, 1);
// }

/* ---------------------------- List Tests ---------------------------- */

TEST(ListTest, DefaultConstructor) {
    s21::s21_list<int> lst;
    ASSERT_TRUE(lst.empty());
}

TEST(ListTest, ParameterizedConstructor) {
    s21::s21_list<int> lst(5);
    ASSERT_EQ(lst.count_of_elem, 5);
}

TEST(ListTest, CopyConstructor) {
    s21::s21_list<int> lst1{1, 2, 3};
    s21::s21_list<int> lst2(lst1);
    ASSERT_EQ(static_cast<int>(lst2.size()), 3);
}

TEST(ListTest, Destructor) {
    s21::s21_list<int>* lst = new s21::s21_list<int>{1, 2, 3};
    delete lst;
    ASSERT_TRUE(true);  // Проверка на успешное удаление
}

TEST(ListTest, PushBack) {
    s21::s21_list<int> lst;
    lst.push_back(1);
    ASSERT_EQ(lst.back(), 1);
    lst.push_back(2);
    ASSERT_EQ(lst.back(), 2);

}

TEST(ListTest, PushFront) {
    s21::s21_list<int> lst;
    lst.push_front(1);
    ASSERT_EQ(lst.front(), 1);
}

TEST(ListTest, PopBack) {
    s21::s21_list<int> lst{1, 2, 3};
    lst.pop_back();
    ASSERT_EQ(lst.back(), 2);
}

TEST(ListTest, PopFront) {
    s21::s21_list<int> lst{1, 2, 3};
    lst.pop_front();
    ASSERT_EQ(lst.front(), 2);
}

TEST(ListTest, Clear) {
    s21::s21_list<int> lst{1, 2, 3};
    lst.clear();
    ASSERT_TRUE(lst.empty());
}

TEST(ListTest, AssignmentOperator) {
    s21::s21_list<int> lst1{1, 2, 3};
    s21::s21_list<int> lst2;
    lst2 = std::move(lst1);
    
    ASSERT_EQ(static_cast<int>(lst2.size()), 3);
}

TEST(ListTest, EqualityOperator) {                              // FALSE
    // s21::s21_list<int> lst1{1, 2, 3};
    // ASSERT_TRUE(lst1 == lst1);

    s21::s21_list<int> lst1(1);
    s21::s21_list<int> lst2(1);

    // Проверка, что итераторы для разных списков не равны
    auto it1 = lst1.begin();
    auto it2 = lst2.begin();
    ASSERT_FALSE(it1 == it2);

    // Проверка, что итераторы для одного и того же списка равны
    auto it3 = lst1.begin();
    auto it4 = lst1.begin();
    ASSERT_TRUE(it3 == it4);
}

TEST(ListTest, InequalityOperator) {                           
    s21::s21_list<int> lst1(1);
    s21::s21_list<int> lst2(1);

    // Проверка, что итераторы для разных списков не равны
    auto it1 = lst1.begin();
    auto it2 = lst2.begin();
    ASSERT_TRUE(it1 != it2);
}

TEST(ListTest, Merge) {                             
    s21::s21_list<int> lst1{1, 3, 5};
    s21::s21_list<int> lst2{2, 4, 6};
    lst1.merge(lst2);
    
    ASSERT_EQ(lst1.count_of_elem, 6);
    ASSERT_EQ(lst1.front(), 1);
    ASSERT_EQ(lst1.back(), 6);
}

TEST(ListTest, Sort) {
    s21::s21_list<int> lst{3, 1, 2};
    lst.sort();
    ASSERT_EQ(lst.front(), 1);
    ASSERT_EQ(lst.back(), 3);
}

TEST(ListTest, Reverse) {
    s21::s21_list<int> lst{1, 2, 3};
    lst.reverse();
    ASSERT_EQ(lst.front(), 3);
    ASSERT_EQ(lst.back(), 1);
}

TEST(ListTest, Unique) {
    s21::s21_list<int> lst{1, 1, 2, 3, 3, 3};
    lst.unique();
    ASSERT_EQ(static_cast<int>(lst.size()), 3);
}

TEST(ListTest, Insert_many_back) {
    s21::s21_list<int> lst{1, 2, 3};

    std::vector<int> args{4, 5, 6};
    lst.insert_many_back(args);

    ASSERT_EQ(lst.front(), 1);
    ASSERT_EQ(lst.back(), 6);
    ASSERT_EQ(lst.count_of_elem, 6);
}

TEST(ListTest, Insert_many_front) {
    s21::s21_list<int> lst{1, 2, 3};

    std::vector<int> args{4, 5, 6};
    lst.insert_many_front(args);

    ASSERT_EQ(lst.front(), 6);
    ASSERT_EQ(lst.back(), 3);
    ASSERT_EQ(lst.count_of_elem, 6);
}

TEST(ListTest, Insert_many) {
    s21::s21_list<int> lst{1, 2, 3};


    std::vector<int> args{4, 5, 6};
    auto it1 = lst.begin();
    it1.operator++();
    lst.insert_many(it1, args);

    ASSERT_EQ(lst.front(), 1);
    ASSERT_EQ(lst.back(), 3);
    ASSERT_EQ(lst.count_of_elem, 6);
}


/* ---------------------------- Array Tests ---------------------------- */

// TEST(ArrayTest, DefaultConstructor) {
//     s21::array<int, 5> arr;
//     ASSERT_EQ(static_cast<int>(arr.size()), 5);
// }

// TEST(ArrayTest, CopyConstructor) {
//     s21::array<int, 3> arr1{1, 2, 3};
//     s21::array<int, 3> arr2(arr1);
//     ASSERT_EQ(arr2[1], 2);
// }

// TEST(ArrayTest, MoveConstructor) {
//     s21::array<int, 3> arr1{1, 2, 3};
//     s21::array<int, 3> arr2(std::move(arr1));
//     ASSERT_EQ(arr2[2], 3);
// }

// TEST(ArrayTest, InitializerListConstructor) {
//     s21::array<int, 3> arr{1, 2, 3};
//     ASSERT_EQ(arr[0], 1);
//     ASSERT_EQ(arr[1], 2);
//     ASSERT_EQ(arr[2], 3);
// }

// TEST(ArrayTest, AtMethod) {
//     s21::array<int, 3> arr{1, 2, 3};
//     ASSERT_EQ(arr.at(1), 2);
//     ASSERT_THROW(arr.at(4), std::domain_error);
// }

// TEST(ArrayTest, OperatorSquareBrackets) {
//     s21::array<int, 3> arr{1, 2, 3};
//     ASSERT_EQ(arr[0], 1);
// }

// TEST(ArrayTest, FrontMethod) {
//     s21::array<int, 3> arr{1, 2, 3};
//     ASSERT_EQ(arr.front(), 1);
// }

// TEST(ArrayTest, BackMethod) {
//     s21::array<int, 3> arr{1, 2, 3};
//     ASSERT_EQ(arr.back(), 3);
// }

// TEST(ArrayTest, DataMethod) {
//     s21::array<int, 3> arr{1, 2, 3};
//     int* ptr = arr.data();
//     ASSERT_EQ(ptr[0], 1);
// }

// TEST(ArrayTest, FillMethod) {
//     s21::array<int, 3> arr;
//     arr.fill(5);
//     ASSERT_EQ(arr[0], 5);
//     ASSERT_EQ(arr[1], 5);
//     ASSERT_EQ(arr[2], 5);
// }

// TEST(ArrayTest, SwapMethod) {
//     s21::array<int, 3> arr1{1, 2, 3};
//     s21::array<int, 3> arr2{4, 5, 6};
//     arr1.swap(arr2);
//     ASSERT_EQ(arr1[0], 4);
//     ASSERT_EQ(arr2[0], 1);
// }

// TEST(ArrayTest, CopyAssignmentOperator) {
//     s21::array<int, 3> arr1{1, 2, 3};
//     s21::array<int, 3> arr2;
//     arr2 = arr1;
//     ASSERT_EQ(arr2[2], 3);
// }

// TEST(ArrayTest, MoveAssignmentOperator) {
//     s21::array<int, 3> arr1{1, 2, 3};
//     s21::array<int, 3> arr2;
//     arr2 = std::move(arr1);
//     ASSERT_EQ(arr2[2], 3);
// }

// TEST(ArrayMethodsTest, Empty) {
//     s21::array<int, 0> empty_arr;
//     ASSERT_TRUE(empty_arr.empty());

//     s21::array<int, 5> non_empty_arr;
//     ASSERT_FALSE(non_empty_arr.empty());
// }

// TEST(ArrayMethodsTest, Size) {
//     s21::array<int, 5> arr;
//     ASSERT_EQ(static_cast<int>(arr.size()), 5);
// }

// TEST(ArrayMethodsTest, MaxSize) {
//     s21::array<int, 5> arr;
//     ASSERT_EQ(static_cast<int>(arr.max_size()), 5);
// }

// TEST(ArrayMethodsTest, BeginEndIterators) {
//     s21::array<int, 3> arr{1, 2, 3};
//     s21::array<int, 3>::iterator it = arr.begin();
//     ASSERT_EQ(static_cast<int>(*it), 1);
//     ++it;
//     ASSERT_EQ(static_cast<int>(*it), 2);
//     ++it;
//     ASSERT_EQ(static_cast<int>(*it), 3);
//     ++it;
//     ASSERT_EQ(it, arr.end());
// }

// TEST(ArrayMethodsTest, ConstBeginEndIterators) {
//     const s21::array<int, 3> arr{1, 2, 3};
//     s21::array<int, 3>::const_iterator it = arr.cbegin(); // Обратите внимание на русскую 'с' в 'cbegin'
//     ASSERT_EQ(*it, 1);
//     ++it;
//     ASSERT_EQ(*it, 2);
//     ++it;
//     ASSERT_EQ(*it, 3);
//     ++it;
//     ASSERT_EQ(it, arr.cend()); // Обратите внимание на русскую 'с' в 'cend'
// }


// // TEST(ArrayTest, AssignmentOperator_ThrowsWhenSizesDiffer) {
// //     s21::array<int, 4> arr1{1, 2, 3};     // Создание массива размером 3
// //     s21::array<int, 4> arr2{4, 5, 6, 7};  // Создание массива размером 4

// //     // Проверка генерации исключения при попытке присвоить arr1 к arr2, что не должно быть возможным из-за разных размеров
// //     EXPECT_THROW(
// //         {
// //             arr1 = arr2;  // Попытка присвоить массивы разного размера
// //         },
// //         std::domain_error);  // Ожидаемое исключение
// // }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
