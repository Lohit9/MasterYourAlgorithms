/*
 Deleting a node from a linked list
*/

struct llnode{
  int data;
  llnode *next;
};

void delete_node(llnode *head, int n){
    if(!head) return;
    llnode *prev = head;
    if(head->data == n){
      return head->next;
    }
    while(head->next){
      if(head->data == n){
        head->next = head->next->next; //head didn't change
        return head;
      }
      head = head->next;
    }
    return head;
}
