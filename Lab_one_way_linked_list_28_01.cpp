#include<iostream>
using namespace std;
struct Node{
int value;
Node* next;
};
int size(Node* list){
    int size = 0;
    while(list != nullptr){
        size++;
        list = list->next;
    }
    return size;
}
void list_view(Node* list){
    while(list != nullptr){
        cout << list->value << endl;
        list = list->next;
    }

}
Node* list_generate(int size, int* data){
    Node* last = new Node;
    Node* first;
    last->next = nullptr;
    for(int i = size-1; i > 0;  i--){
        first = new Node;
        first->next = last;
        last->value = data[i];
        last = first;
    }
    first->value = data[0];
    return first;
}
int search(int target,Node* list){
    int result_position = -1;
    while(list->value != target){
        if(list->next == nullptr){
            return -1;
        }
        list = list->next;
        result_position++;
    }
    if(result_position > -1){
        result_position++;
    }
    return result_position;
}
void insertNode(int position, Node* list, Node* add){
    //inserts after Node, which num == position
    for(int i = 0; i < position; i++){
        if(list->next == nullptr){
            cout << "Error, can't add a node, your list is too short!" << endl;
            return;
        }
        list = list->next;
    }
    Node* prev = list;
    Node* next = list->next;
    prev->next = add;
    add->next = next;
}
void removeNode(int position, Node* list){
        //position != 0
        // for removing the first Node use "delete pop();"
        for(int i = 0; i < position-1; i++){
            if(list->next->next == nullptr){
                cout << "Error, can't remove a node, your list is too short!" << endl;
                return;
            }
            list = list->next;
        }
        Node* prev = list;
        Node* next = list->next->next;
        delete list->next;
        prev->next = next;    
}
void pushNode(int value_to_push, Node*& list){
    Node* temp = new Node;
    temp->value = value_to_push;
    temp->next = list;
    list = temp;
}
void pushNode(Node* node_to_push, Node*& list){
    node_to_push->next = list;
    list = node_to_push;
}
Node* popNode(Node*& list){
    Node* pop = list;
    list = list->next;
    return pop;
}
int main(){
    int k = 5;
    int mass[8] = {23,21,3,34,56,6,7,89};
    Node* add = new Node;
    add->value = 777;
    Node* list = list_generate(k,mass);
    list_view(list);
    //cout<< "List size = " << size(list) << endl;
    //cout<< "Search result = " << search(89, list) << endl;
    insertNode(5, list, add);
    //list_view(list);
    removeNode(5,list);
    //cout << "pop value = " <<  popNode(list)->value << endl;
    list_view(list);


}
