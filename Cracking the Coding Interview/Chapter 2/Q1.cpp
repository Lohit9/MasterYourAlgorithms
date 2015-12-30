#include <iostream>
using namespace std;

struct llnode{
    int data;
    struct llnode *next;
};

//O(n) solution using an array buffer, the book's solution uses a hash table as a buffer
void removeDuplicates(struct llnode *llist){
    int integers[10] = {0};
    struct llnode *current = llist;
    struct llnode *prev;
    while(current != NULL){
        integers[current->data]++;
        if(integers[current->data] > 1){
            prev->next = current->next;
            current = prev;
        }
        prev = current;
        current = current->next;
    }
}

//O(n^2) solution without using a buffer
void removeDuplicatesWithoutBuffer(struct llnode *llist){
    struct llnode *current = llist;
    struct llnode *runner = llist;
    while(current != NULL){
        while(runner != NULL){
            if (runner->data == current->data){
                runner->next = runner->next->next;
            }
            else{
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main(){
    return 0;
}
