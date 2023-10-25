#include <iostream>
using namespace std;

struct node {
    node* next;
    int val;
    node(int a = 0) {
        this->next = nullptr;
        this->val = a;
    };
};
node* listlast(node* head) {
    while (head->next) {
        head = head->next;
    }
    return head;
}
void add(node*& head, int data) {
    node* newnode = new node();
    newnode->val = data;
    newnode->next = head;
    head = newnode;
}
void addlast(node*& head, int data) {
    node* lastnode = listlast(head);
    node* newnode = new node();
    newnode->val = data;
    lastnode->next = newnode;
}

void removenode(node*& head) {
   if (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

void remeveryother(node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    node* nextNext = head->next->next;
    delete head->next;
    head->next = nextNext;
    remeveryother(head->next);
}
void removeparity(node*& head) {
    while (head != nullptr && head->val % 2 == 0) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->next->val % 2 == 0) {
            node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

void switchel(node* sw) {
    if (sw->next) {
        node* tmp = new node();
        *tmp = *sw;  // 1->2->3
        *sw = *sw->next; // 1-1->3
        if (sw->next) {
            tmp->next = sw->next;
        }
        else { tmp->next = NULL; }; //
        sw->next = tmp;
    }
}

void coutall(node* head) {
    if (head) {
        cout << head->val;
        coutall(head->next);
    }
}

void kopialisty(node* head) {
    node* head2 = new node(head->val);
    while (head->next) {
        head = head->next;
        addlast(head2, head->val);
    }
    listlast(head)->next = head2;
}

void listdouble(node* head) {
    node* tmp = new node();
    while (head) {
        node* newnode = new node(head->val);
        tmp = head->next;
        head->next = newnode;
        newnode->next = tmp;
        head = head->next->next;
    }
}

void listrepeat(node* head) {
    node* tmp = new node();
    while (head) {
        int i = 1;
        while (i < head->val) {
            node* newnode = new node(head->val);
            tmp = head->next;
            head->next = newnode;
            newnode->next = tmp;
            head = head->next;
            i++;
        }
        head = head->next;
    }
}
    
void merge( node*& list1, node*& list2, node*& exithead ) {
 //   node* tmp1 = new node();
//    node* tmp2 = new node();
    node* tail = new node();

    exithead->next = tail;
    tail->val = 12;
//    *tmp1 = *list1; 
//    *tmp2 = *list2;
    while (list1 != nullptr && list2 != nullptr) {

        if (list1->val > list2->val) {
            cout << "doczepiono z listy 1 ";
            cout << list1->val << endl;
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            cout << "doczepiono z listy 2 " << list2->val << endl;
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    removenode(exithead);
    removenode(exithead);
    if (list1 != NULL) {
        tail->next = list1;
    }
    else {
        tail->next = list2;
    }
}

void split(node*& head, node*& exithead) {
    node* fast = new node();
    node* slow = new node();
    *fast = *head;
    *slow = *head;
    while ((fast->next != nullptr) && (fast->next->next!=nullptr)) {
            fast = fast->next->next;
            slow = slow->next;
    }
    exithead = slow->next;
    slow->next = nullptr;
}
int main() {
    node* head = new node(5);
    for (int i = 0; i <7; i++) {
        add(head, i);
    };
    node* head2 = new node(5);
    for (int i = 3; i < 8; i++) {
        add(head2, i);
    };
    node* exithead = new node();
    //    merge(exithead, head, head2);
    coutall(head);
    cout << endl;
    split(head, exithead);
    coutall(head);
    cout << endl;
    coutall(exithead);

}