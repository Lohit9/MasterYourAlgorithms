/*
Asked in google interview
 Make a linked list out of an array
*/

#include <iostream>
#include <string>
using namespace std;

struct llnode{
  int data;
  llnode *next;
};

int main(){
  int arr[] = {1,2,3,4,5,6,7};
  int len = sizeof(arr)/sizeof(arr[0]);
  llnode *head = new llnode;
  head->data = arr[0];
  head->next = NULL;
  llnode *temp = NULL;
  head->next = temp;
  for(int i=1;i<len;i++){
    temp = new llnode;
    temp->data = arr[i];
    temp->next = NULL;
    temp = temp->next;
  }
  while(head != NULL){
    cout << head->data << endl;
    head = head->next;
  }
  delete head;
  return 0;
}
