#include <iostream>
#include <string>
using namespace std;

struct Node{
  int data;
  Node *next;
};

void deleteDuplicates(Node *node){

  Node *current = node;
  Node *runner = current;

  while (current->next != NULL){
    while(runner->next != NULL){
      if(runner->next->data== current->data){
        //code to delete the duplicate node
        runner->next = runner->next->next;
      }
      else{
        runner=runner->next;
      }
    }
    current = current->next;
  }

}

int main()
{
  return 0;
}
