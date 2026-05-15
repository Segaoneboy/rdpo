#include <iostream>
#include <gtest/gtest.h>
#include "btree.h"
#include "stack.h"
#include "queue.h"

TEST(StackTest, AllTests) {
    Stack s;

    EXPECT_TRUE(s.isEmpty());

    s.spush(10);
    s.spush(20);
    EXPECT_EQ(s.getTop(), 20);
    
    s.spop();
    EXPECT_EQ(s.getTop(), 10);
    
    s.spop();
    EXPECT_TRUE(s.isEmpty());
    s.sprint();
}

TEST(QueueTest, AllTests) {
    Queue q;

    EXPECT_TRUE(q.isEmpty());
    q.qpush(1);
    q.qpush(2);
    
    EXPECT_EQ(q.getHead(), 1);
    
    q.qpop();
    EXPECT_EQ(q.getHead(), 2);
    EXPECT_FALSE(q.isEmpty());
    q.qprint();
}
TEST(BTreeTest, AllTests){
    Tree t;
    t.bpush(5);
    t.bpush(3);
    t.bpush(7);

    EXPECT_TRUE(t.contains(5));
    EXPECT_TRUE(t.contains(3));
    EXPECT_FALSE(t.contains(9));

    t.bpop(5);
    EXPECT_FALSE(t.contains(5));
    EXPECT_TRUE(t.contains(3));
    EXPECT_TRUE(t.contains(7));
    t.bprint();
}
