#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

hashclass::hashclass(){
  for(int i=0; i<tablesize ;i++){
    hashTable[i] = new item;
    hashTable[i]->name = "empty";
    hashTable[i]->drink = "empty";
    hashTable[i]->next = NULL;
  }
}

int hashclass::hashFunc(string key){
  int hash = 0;
  int index;

    for(int i =0; i<key.length() ;i++){
      hash += (int)key[i]; // adding up all the ascii values of each character in string
      //cout << "hash= " << hash<< endl;
    }

  index = hash%tablesize;
   return index;
}


void hashclass::AddItem(string name, string drink){
  int index = hashFunc(name);
  if(hashTable[index]->name == "empty"){
    hashTable[index]->name = name;
    hashTable[index]->drink = drink;
    hashTable[index]->next = NULL;
  }
  else{
    item* ptr = hashTable[index];
    item* n = new item;
    n->name = name;
    n->drink = drink;
    n->next = NULL;
    while(ptr->next != NULL){
      ptr = ptr->next;
    }
    ptr->next=n;
  }
}

int hashclass::numberOfItemsInIndex(int index){
  int count = 0;
  item* ptr=hashTable[index];
  if(ptr->name == "empty"){
    return count;
  }
  else{
    count++;
    while(ptr->next != NULL){
    count++;
    ptr = ptr->next;

  }
}
  return count;
}

void hashclass::printTable(){ // we are only printing the first item of each bucket in the hash table
  int number;
  for(int i =0; i<tablesize ; i++){
    number = numberOfItemsInIndex(i);
    cout<<"----------------------"<< endl;
    cout<< "number of items in bucket: " << number << endl;
    cout<< "index: "<< i<< endl;
    cout<<"name: "<< hashTable[i]->name << endl;
    cout << "drink: " << hashTable[i]->drink << endl;
    cout<<"----------------------"<< endl;

  }
}

void hashclass::printItemsInIndex(int index){
  item *ptr = hashTable[index];
  int number = numberOfItemsInIndex(index);
  if(ptr->name == "empty"){
    cout<< "index is empty"<< endl;
    return;
  }
  while(ptr != NULL){
    cout<<"----------------------"<< endl;
    cout<< "number of items in bucket: " << number << endl;
    cout<<"name: "<< ptr->name << endl;
    cout << "drink: " << ptr->drink << endl;
    cout<<"----------------------"<< endl;
    ptr= ptr->next;
  }
}
