#include "intbst.cpp"
#include <iostream>
using namespace std;

int main(){

    IntBST<int> list;

    list.insert(10);
    list.insert(5);
    list.insert(15);
    list.insert(3);
    list.insert(1);
    list.insert(8);
    list.insert(9);
    list.insert(6);
    list.insert(7);
    list.insert(15);
    list.insert(22);
    list.insert(18);
    list.insert(20);
    list.insert(19);
    list.insert(21);

    cout << "\tPredecessor of 10 is: " << list.getPredecessor(10) << endl;
    cout << "\tPredecessor of 5 is: " << list.getPredecessor(5) << endl;
    cout << "\tPredecessor of 3 is: " << list.getPredecessor(3) << endl;
    cout << "\tPredecessor of 1 is: " << list.getPredecessor(1) << endl;
    cout << "\tPredecessor of 8 is: " << list.getPredecessor(8) << endl;
    cout << "\tPredecessor of 9 is: " << list.getPredecessor(9) << endl;
    cout << "\tPredecessor of 6 is: " << list.getPredecessor(6) << endl;
    cout << "\tPredecessor of 7 is: " << list.getPredecessor(7) << endl;
    cout << "\tPredecessor of 15 is: " << list.getPredecessor(15) << endl;
    cout << "\tPredecessor of 18 is: " << list.getPredecessor(18) << endl;
    cout << "\tPredecessor of 20 is: " << list.getPredecessor(20) << endl;
    cout << "\tPredecessor of 19 is: " << list.getPredecessor(19) << endl;
    cout << "\tPredecessor of 21 is: " << list.getPredecessor(21) << endl;
    cout << "\tPredecessor of 22 is: " << list.getPredecessor(22) << endl;

    cout << endl << endl;

    cout << "\tSuccessor of 10 is: " << list.getSuccessor(10) << endl;
    cout << "\tSuccessor of 3 is: " << list.getSuccessor(3) << endl;
    cout << "\tSuccessor of 5 is: " << list.getSuccessor(5) << endl;
    cout << "\tSuccessor of 1 is: " << list.getSuccessor(1) << endl;
    cout << "\tSuccessor of 8 is: " << list.getSuccessor(8) << endl;
    cout << "\tSuccessor of 9 is: " << list.getSuccessor(9) << endl;
    cout << "\tSuccessor of 6 is: " << list.getSuccessor(6) << endl;
    cout << "\tSuccessor of 7 is: " << list.getSuccessor(7) << endl;
    cout << "\tSuccessor of 15 is: " << list.getSuccessor(15) << endl;
    cout << "\tSuccessor of 18 is: " << list.getSuccessor(18) << endl;
    cout << "\tSuccessor of 20 is: " << list.getSuccessor(20) << endl;
    cout << "\tSuccessor of 19 is: " << list.getSuccessor(19) << endl;
    cout << "\tSuccessor of 21 is: " << list.getSuccessor(21) << endl;
    cout << "\tSuccessor of 22 is: " << list.getSuccessor(22) << endl;

    cout << endl << endl;

    list.remove(15);
    list.remove(20);
    list.remove(8);
    list.remove(1);
    list.remove(10);

    cout << "\tPredecessor of 5 is: " << list.getPredecessor(5) << endl;
    cout << "\tPredecessor of 22 is: " << list.getPredecessor(22) << endl;
    cout << "\tPredecessor of 3 is: " << list.getPredecessor(3) << endl;
    cout << "\tPredecessor of 7 is: " << list.getPredecessor(7) << endl;
    cout << "\tPredecessor of 9 is: " << list.getPredecessor(9) << endl;

    cout << endl << endl;

    cout << "\tSuccessor of 5 is: " << list.getSuccessor(5) << endl;
    //cout << "\tSuccessor of 22 is: " << list.getSuccessor(22) << endl;
    cout << "\tSuccessor of 3 is: " << list.getSuccessor(3) << endl;
    cout << "\tSuccessor of 7 is: " << list.getSuccessor(7) << endl;
    cout << "\tSuccessor of 9 is: " << list.getSuccessor(9) << endl;
    cout << "\tSuccessor of 18 is: " << list.getSuccessor(18) << endl;

    cout << endl << endl;
    list.printInOrder();
    cout << endl << endl;


    return 0;
}