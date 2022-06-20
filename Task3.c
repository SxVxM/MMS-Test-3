#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
       
struct node{  
    int data;  
    struct node *next;  
};  
struct node *head = NULL;  
struct node *tail = NULL;  
       
void add(struct node *newNode, int data){  
    newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    if(head == NULL){  
        head = newNode;  
        tail = newNode;  
        newNode->next = head;  
    }else {  
        tail->next = newNode;  
        tail = newNode;  
        tail->next = head;  
    }  
}  
void display(){  
    struct node *current = head;  
    if(head == NULL){  
        printf("List is empty");  
    }  
    else{  
        printf("Nodes of the circular linked list: \n");  
        do{  
            printf("%d ", current->data);  
            current = current->next;  
        }while(current != head);
            printf("\n");  
     }
    free(head);
}    
void insertAfter(struct node* prev_node, int new_data){
    if (prev_node == NULL){
        printf("the given previous node cannot be NULL");
        return;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void print(struct node* llist){
    while (llist){
        printf("%d ", llist->data);
        llist = llist->next;
    }
    putchar('\n');
}   
int main(){  
    struct node node1;
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        add(&node1, arr[i]);
    }
    display();
    return 0;  
}  