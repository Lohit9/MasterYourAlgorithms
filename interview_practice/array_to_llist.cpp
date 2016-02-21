/*
 Make a linked list out of an array
*/

#include <iostream>
#include <string>
using namespace std;

struct node{
  int data;
  node *next;
};


node* to_linkedList(node* input, int data[], int len){
  node *temp = input;
  temp->next = input->next;
  temp->data = data[0];
 for(int i =1 ;i<=len;i++){
   if(input == NULL){
     input = new node;
     input->next = NULL;
     input->data = data[i];
     cout << input->data << endl;
   }
    else input = input->next;
 }

  return temp;
}

int main(){
  int arr[] = {1,2,3,4,5,6,7};
  node *llnode = new node;
  llnode->next = NULL;
  int len = sizeof(arr)/sizeof(arr[0]);
  node* result = to_linkedList(llnode,arr,len);
  while(result->next){
    cout << result->data << endl;
    result = result->next;
    }

  return 0;
}
