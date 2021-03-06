/*
    struct node (data) -> defines and l datatype (l may be int/float/double or anything)
    struct node (next) -> also contains an node pointer to store an address of type struct node

    init() function creates an head for the linkedlist
    
*/
#include <stdlib.h>
#include <iostream>

template<class n>
struct Node{
    n data;
    struct Node<n> *next;
};

template<class l>
class LinkedList{
    private:
        struct Node<l> *head;
    public:
        void init(l headdata);
        LinkedList(l d){
            init(d);
        }
        void print(void);
        struct Node<l> *createNode(l data); 
        void append(struct Node<l> *node);  
        void replaceHead(struct Node<l> *node);
        struct Node<l> *getLastNode(void); 
        void insertAtIndex(int index,struct Node<l> *node); 
        void pop(void);
        void deleteAtIndex(int index);
        int length(void);           
};

template<class l>
void LinkedList<l>::init(l headdata){
    head = new Node<l>;
    head->data = headdata;
    head->next = NULL;
}

template<class l>
void LinkedList<l>::print(void){
    struct Node<l> *temp= head;
    std::cout << "[ ";
    while(temp->next != NULL){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << temp->data << " ]";
}

template<class l>
void LinkedList<l>::deleteAtIndex(int index){
    int count = 0;
    struct Node<l> *prev=NULL; struct Node<l> *temp= head;
    while(count != index){
        prev = temp; temp = temp->next;
        count++;
    }
    prev->next = temp->next;
}

template<class l>
void LinkedList<l>::pop(void){
    struct Node<l> *prev=NULL; struct Node<l> *temp= head;
    while(temp->next != NULL){
        prev = temp; temp = temp->next;
    }
    prev->next = NULL;
}

template<class l>
void LinkedList<l>::replaceHead(struct Node<l> *node){
    node->next = head;
    head = node;
}

template<class l>
void LinkedList<l>::insertAtIndex(int index,struct Node<l> *node){
    int count = 0;
    struct Node<l> *prev=NULL; struct Node<l> *temp= head;
    while(count != index){
        prev = temp; temp = temp->next;
        count++;
    }
    prev->next = node;
    node->next = temp;
}

template<class l>
void LinkedList<l>::deleteAtIndex(int index){
    int count = 0;
    struct Node *prev=NULL; struct Node *temp= head;
    while(count != index){
        prev = temp; temp = temp->next;
        count++;
    }
    prev->next = temp->next;
}

template<class l>
struct Node<l> *LinkedList<l>::getLastNode(void){
    struct Node<l> *temp = head;
    while(temp->next != NULL) temp = temp->next;
    return temp;
}

template<class l>
struct Node<l> *LinkedList<l>::createNode(l data){
    struct Node<l> *node = new Node<l>;
    node->data = data;
    node->next = NULL;
    return node;
}

template<class l>
int LinkedList<l>::length(void){
    struct Node<l> *temp = head;
    int len=1;
    while(temp->next != NULL) len++;
    return len;
}

template<class l>
void LinkedList<l>::append(struct Node<l> *node){
    struct Node<l> *lastone = getLastNode();
    lastone->next = node;
}

