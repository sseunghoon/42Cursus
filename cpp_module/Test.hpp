#ifndef TEST_HPP
#define TEST_HPP

class Test {
public:
    Test();
    Test(const Test& copy);
    Test& operator=(const Test& copy);
    ~Test();
};

#endif
