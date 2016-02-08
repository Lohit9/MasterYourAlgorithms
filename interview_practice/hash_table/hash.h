#include <iostream>
#include <string>
using namespace std;

#ifndef HASH_H // these are called include guards they prevent redefinition and copying of heaser files
#define HASH_H

class hashclass{

private:
  static const int tablesize = 10;

  struct item{
    string name;
    string drink;
    item* next;
  };

 item* hashTable[tablesize];

public:
  hashclass();
  int hashFunc(string key); // takes in string and returns the integer
  void AddItem(string name, string drink);
  int numberOfItemsInIndex(int index);
  void printTable();
  void printItemsInIndex(int index);
};

#endif
