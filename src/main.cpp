#include <iostream>
#include <string>
#include <sstream>
#include <gtest/gtest.h>
#include "btree.h"
#include "stack.h"
#include "queue.h"

int main(int argc, char **argv) {
    Stack s;
    Queue q;
    Tree b;

    std::string line;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line) || line == "exit") {
            break;
        }

        std::stringstream ss(line);
        std::string cmd;
        
        if (!(ss >> cmd)) {
            continue;
        }

        int val;

        if (cmd == "spush" && ss >> val) {
            s.spush(val);
        } else if (cmd == "spop") {
            s.spop();
        } else if (cmd == "sprint") {
            s.sprint();
        } else if (cmd == "sTop") {
            std::cout << "Top: " << s.getTop() << std::endl;
        } 
        else if (cmd == "qpush" && ss >> val) {
            q.qpush(val);
        } else if (cmd == "qpop") {
            q.qpop();
        } else if (cmd == "qprint") {
            q.qprint();
        } else if (cmd == "qhead") {
            std::cout << "Head: " << q.getHead() << std::endl;
        } 
        else if (cmd == "bpush" && ss >> val) {
            b.bpush(val);
        } else if (cmd == "bpop" && ss >> val) {
            b.bpop(val);
        } else if (cmd == "bprint") {
            b.bprint();
        } else if (cmd == "bcontains" && ss >> val) {
            std::cout << "Contains: " << (b.contains(val) ? "Yes" : "No") << std::endl;
        } 
        else if (cmd == "tests") {
            ::testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        } 
        
    }

    return 0;
}