/*
Delete duplicates from linked list
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

struct llnode{
  int data;
  llnode *next;
};

void deleteDups(llnode *node){
  if(!node) return;
  map<int,int>hashMap;
  while(node->next){
     hashMap[node->data]++;
     if(hashMap.find(node->data)->second > 1){
       //delete node code
       struct *temp = node;
       prev->next = node->next;
       temp->next = NULL;
       node = prev;
       delete(temp);
     }
     prev = node;
     node = node->next;
  }
}

int main(){
  return 0;
}
