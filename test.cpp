#include <gtest/gtest.h>
#include "LinkedList.c"

class ListFixture : public :: testing::Test{

protected:

    MyList lst = create_list();
};


TEST_F(ListFixture, push)
{
    for(int i = 0; i < 10; ++i)
    {
        ListPush_back(&lst, i);
    }

    EXPECT_EQ(ListAt(&lst, 3), 3);
    EXPECT_EQ(ListAt(&lst, 0), 0);
    EXPECT_EQ(ListAt(&lst, 9), ListBack(&lst));
    ListClear(&lst);
    ListEmpty(&lst);

    for(int i = 0; i < 10; ++i)
    {
        ListPush_front(&lst, i);
    }

    EXPECT_EQ(ListAt(&lst, 3), 6);
    EXPECT_EQ(ListAt(&lst, 0), 9);
    EXPECT_EQ(ListAt(&lst, 0), ListFront(&lst));
}

TEST_F(ListFixture, insert_erase)
{
    ListClear(&lst);
    for(int i = 0; i < 10; ++i)
    {
        ListPush_back(&lst, i);
    }
    list_print(&lst);
    ListInsert(&lst, 3, 120);
    ListInsert(&lst, 7, 300);
    EXPECT_EQ(list_size(&lst), 12);
    EXPECT_EQ(ListAt(&lst, 3), 120);
    EXPECT_EQ(ListAt(&lst, 2), 2);
    EXPECT_EQ(ListAt(&lst, 4), 3);
    EXPECT_EQ(ListAt(&lst, 7), 300);
    EXPECT_EQ(ListAt(&lst, 8), 6);
    EXPECT_EQ(ListAt(&lst, 6), 5);

    list_print(&lst);
    ListErase(&lst, 2);
    ListErase(&lst, 7);
    EXPECT_EQ(ListAt(&lst, 7), 7);
    EXPECT_EQ(ListAt(&lst, 2), 120);
    EXPECT_EQ(list_size(&lst), 10);
    list_print(&lst);
}


TEST_F(ListFixture, swap)
{
    MyList list1 = create_list();
    MyList list2 = create_list();
    for(int i = 0; i < 10; ++i)
    {
        ListPush_back(&list1, i);
        ListPush_front(&list2, i);
    }

    list_swap(&list1, &list2);
    EXPECT_EQ(ListAt(&list1, 2), 7);
    EXPECT_EQ(ListAt(&list2, 2), 2);
}