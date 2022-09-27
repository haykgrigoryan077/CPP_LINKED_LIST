#include "LinkedList.h"

int main() {
    LinkedList<int> list;
    list.insert(9);
    list.insert(8);
    list.insert(7);
    list.insert(6);
    list.insert(4);
    list.insert(3);
    list.insert(5);
    list.insert(7);
    list.insert(0);
    list.insert(-15);
    list.print();
    list.reverse();
//    list.empty();
    list.print();
    cout << list.find_min_element();
    return 0;
}
