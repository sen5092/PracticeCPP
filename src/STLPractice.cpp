//
//  STLPractice.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/24/22.
//

#include "STLPractice.hpp"
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Test {

  private:
    string name;

  public:
    Test(string n) {
        name = n;
    }

    ~Test() {}

    void print() {
        cout << name << endl;
    }
};

void practiceVector() {
    cout << "Practing vectors" << endl;

    vector<string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    cout << strings.size() << endl;

    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }

    vector<string>::iterator it = strings.begin();
    it++;
    cout << *it << endl;

    for (it = strings.begin(); it != strings.end(); it++) {
        cout << *it << endl;
    }

    vector<int> myVex;
    myVex.push_back(1);
    myVex.push_back(2);
    myVex.push_back(3);
    myVex.push_back(4);

    for (vector<int>::iterator iter = myVex.begin(); iter != myVex.end(); iter++) {
        cout << *iter << endl;
    }

    vector<double> moop(20);

    // size is the actual number of elements in the vector
    // capacity is the current size of elements reserved for that vector
    double capacity = moop.capacity();
    cout << "Capactiy " << moop.capacity() << endl;

    for (int i = 0; i < 10000; i++) {

        if (capacity != moop.capacity()) {
            capacity = moop.capacity();
            cout << "Capacity is now: " << capacity << " when i is: " << i << endl;
        }

        moop.push_back(i);
    }

    // 2d vector
    vector<vector<int>> matrix(3, vector<int>(4, 7));

    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[row].size(); col++) {
            cout << matrix[row][col];
        }

        cout << endl;
    }

    vector<vector<int>> multTable(13, vector<int>(13, 0));

    for (int row = 0; row <= 12; row++) {
        multTable[row][0] = row;
    }

    for (int col = 0; col <= 12; col++) {
        multTable[0][col] = col;
    }

    for (int row = 1; row <= 12; row++) {
        for (int col = 1; col <= 12; col++) {
            multTable[row][col] = row * col;
        }
    }

    for (int row = 0; row < multTable.size(); row++) {
        for (int col = 0; col < multTable[row].size(); col++) {
            cout << multTable[row][col] << " ";
        }

        cout << endl;
    }

    cout << "End of vector practice." << endl;
}

void practiceLists() {
    cout << "Practice Lists" << endl;

    // Items can be inserted anywhere in the list
    // Memory isn't contiguous in a list, it's a bunch of nodes
    // Doubly linked lists

    list<int> numbers;

    numbers.push_back(4);
    numbers.push_back(6);
    numbers.push_back(8);
    numbers.push_front(10);

    list<int>::iterator myIt = numbers.begin();
    myIt++;
    numbers.insert(myIt, 100);

    numbers.erase(myIt);

    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }

    cout << "Done with Lists" << endl;
}

void practiceMaps() {
    cout << "Practice Maps" << endl;

    pair<string, int> addToMap("Moop", 100);

    map<string, int> ages;

    ages["mike"] = 40;
    ages["scott"] = 30;
    ages["Shrek"] = 24;
    ages["Finn"] = 14;

    ages.insert(addToMap);
    ages.insert(pair<string, int>("Hello", 99));

    ages.insert(make_pair("sigh", 77));

    cout << ages["scott"] << endl;

    if (ages.find("Vicky") != ages.end()) {
        cout << "found vicky" << endl;
    } else {
        cout << "didn't find vicky" << endl;
    }

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    cout << "Done with Maps" << endl;
}

void practiceSets() {
    cout << "Practice Sets" << endl;

    // set only stores unique elements

    set<int> numbers;

    numbers.insert(10);
    numbers.insert(11);
    numbers.insert(134);
    numbers.insert(16);
    numbers.insert(1);
    numbers.insert(0);
    numbers.insert(134);

    cout << "Set includes: ";
    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    set<int>::iterator iter = numbers.find(1);
    if (iter != numbers.end()) {
        cout << "Found: " << *iter << endl;
    }

    if (numbers.count(1)) {
        cout << "Number found." << endl;
    }

    cout << "Done with Sets" << endl;
}

void practiceStackQueue() {
    cout << "\nPractice SQ" << endl;

    // stiack is LIFO last in first out
    // like a stack of plates
    stack<Test> testStack;

    testStack.push(Test("Jobe"));
    testStack.push(Test("Mah"));
    testStack.push(Test("Pop"));
    testStack.push(Test("Loopy"));

    // don't use references because the object is destroyed on PoP
    Test test1 = testStack.top();
    test1.print();

    testStack.pop();
    test1 = testStack.top();
    test1.print();

    while (testStack.size() > 0) {
        Test& test = testStack.top();
        test.print();
        testStack.pop();
    }

    // queue
    // queue is FIFO like a line at the movies
    queue<int> testQueue;

    testQueue.push(11);
    testQueue.push(134);
    testQueue.push(55);
    testQueue.push(1);
    testQueue.push(11000);

    cout << endl;

    while (testQueue.size() > 0) {
        int meep = testQueue.front();
        cout << "Q: " << meep << " ";
        testQueue.pop();
    }

    cout << "\nDone with SQ" << endl;
}

void practiceOtherSTL() {
    cout << "\nPractice STL stuff" << endl;

    // Making a change to commit to my branch.

    cout << "Done with STL stuff\n" << endl;
}
