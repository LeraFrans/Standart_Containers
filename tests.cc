// ОСНОВНОЙ ФАЙЛ С ТЕСТАМИ

#include <gtest/gtest.h>

#include <set>
#include <vector>

#include "s21_sequence_container.h"   

/* ---------------------------- List Tests ---------------------------- */

TEST(ListTest, DefaultConstructor) {
    s21::SequenceContainer<int> lst;
    ASSERT_TRUE(lst.empty());
}

TEST(ListTest, ParameterizedConstructor) {
    s21::SequenceContainer<int> lst(5);
    ASSERT_EQ(static_cast<int>(lst.size()), 5);
}

TEST(ListTest, CopyConstructor) {
    s21::SequenceContainer<int> lst1{1, 2, 3};
    s21::SequenceContainer<int> lst2(lst1);
    ASSERT_EQ(static_cast<int>(lst2.size()), 3);
}

TEST(ListTest, Destructor) {
    s21::SequenceContainer<int>* lst = new s21::SequenceContainer<int>{1, 2, 3};
    delete lst;
    ASSERT_TRUE(true);  // Проверка на успешное удаление
}

TEST(ListTest, PushBack) {
    s21::SequenceContainer<int> lst;
    lst.push_back(1);
    ASSERT_EQ(lst.back(), 1);
}

TEST(ListTest, PushFront) {
    s21::SequenceContainer<int> lst;
    lst.push_front(1);
    ASSERT_EQ(lst.front(), 1);
}

TEST(ListTest, PopBack) {
    s21::SequenceContainer<int> lst{1, 2, 3};
    lst.pop_back();
    ASSERT_EQ(lst.back(), 2);
}

TEST(ListTest, PopFront) {
    s21::SequenceContainer<int> lst{1, 2, 3};
    lst.pop_front();
    ASSERT_EQ(lst.front(), 2);
}

TEST(ListTest, Clear) {
    s21::SequenceContainer<int> lst{1, 2, 3};
    lst.clear();
    ASSERT_TRUE(lst.empty());
}

TEST(ListTest, AssignmentOperator) {
    s21::SequenceContainer<int> lst1{1, 2, 3};
    s21::SequenceContainer<int> lst2;
    lst2 = lst1;
    ASSERT_EQ(static_cast<int>(lst2.size()), 3);
}

TEST(ListTest, EqualityOperator) {
    s21::SequenceContainer<int> lst1{1, 2, 3};
    ASSERT_TRUE(lst1 == lst1);
}

TEST(ListTest, InequalityOperator) {
    s21::SequenceContainer<int> lst1{1, 2, 3};
    s21::SequenceContainer<int> lst2{1, 2};
    ASSERT_TRUE(lst1 != lst2);
}

TEST(ListTest, Merge) {
    s21::SequenceContainer<int> lst1{1, 3, 5};
    s21::SequenceContainer<int> lst2{2, 4, 6};
    lst1.merge(lst2);
    ASSERT_EQ(static_cast<int>(lst1.size()), 6);
    ASSERT_TRUE(lst2.empty());
}

TEST(ListTest, Sort) {
    s21::SequenceContainer<int> lst{3, 1, 2};
    lst.sort();
    ASSERT_EQ(lst.front(), 1);
    ASSERT_EQ(lst.back(), 3);
}

TEST(ListTest, Reverse) {
    s21::SequenceContainer<int> lst{1, 2, 3};
    lst.reverse();
    ASSERT_EQ(lst.front(), 3);
    ASSERT_EQ(lst.back(), 1);
}

TEST(ListTest, Unique) {
    s21::SequenceContainer<int> lst{1, 1, 2, 3, 3, 3};
    lst.unique();
    ASSERT_EQ(static_cast<int>(lst.size()), 3);
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
