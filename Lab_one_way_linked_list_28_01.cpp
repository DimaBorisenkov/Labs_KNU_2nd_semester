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
int* getList(Node* list){
    int n = size(list);
    int *result = new int [n];
    int i = 0;
    while(list != nullptr && i < n){
        result[i] = list->value;
        list = list->next;
        i++;
    }
    return result;
}
void printList(int* listArray, int n){
    for(int i = 0; i < n; i++){
        cout << listArray[i] << '\t';
    }
    cout << endl;
}
Node* generateList(int size, int* data){
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
int searchNode(int target,Node* list){
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
    // can use a trick to push == insert after -1
    // insert(-1, list, addNode) == insert(0, list, addNode) + swapValues(list, list->next)
    // if(position == -1){
    //     insertNode(0, list, add);
    //     int temp = list->value;
    //     list->value = list->next->value;
    //     list->next->value = temp;
    //     return;
    // }
    for(int i = 0; i < position; i++){
        if(list->next == nullptr){
            cout << "Error, can't add a node, your list is too short!" << endl;
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
        // for removing the first Node better use "delete pop();"
        // can use a trick to pop == remove(o, list)
        // remove(o, list) ==swapValues(list, list->next)+ remove(1, list)
        // if(position == 0){
        //     list->value = list->next->value;
        //     removeNode(1, list);
        //     return;
        // }
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
    Node* list = generateList(k,mass);
    printList(getList(list), size(list));
    //cout << searchNode(3, list) << endl;
    //cout<< "List size = " << size(list) << endl;
    //cout<< "Search result = " << search(89, list) << endl;
    //insertNode(-1, list, add);
    //removeNode(2,list);
    //cout << "pop value = " <<  popNode(list)->value << endl;
    //pushNode(15, list);


}
