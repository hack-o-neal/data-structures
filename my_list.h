#ifndef MY_LIST_H
#define MY_LIST_H

#include<iostream>
using namespace std;

template <typename T>
struct node{
	T data;
	node* next;
	node(T data){
		next = nullptr;
		this->data  = data;

	}

};
template<typename T>
class list{
public:
	node<T>* head;
	node<T>* tail;
	list(){
		head = nullptr;
		tail = nullptr;
	}	
	void insert(int pos , T val){
		node<T>* n = new node<T>(val);
		if(head == nullptr){
			head = n;
			tail = n;
			return;
		}
		if(pos == 1){
			n->next = head;
			head = n;
			return ;
		}
		node<T>* curr = head;
		int count = 1;
		while(count<pos-1 && curr!=nullptr ){
			count++;
			curr = curr->next;

		}
		   if (curr == nullptr) {
        	   	 cout << "Invalid position!" << endl;
            		delete n;
           		 return;
       		 }

		node<T>*  temp = curr->next;

		 n->next = temp;

		curr->next = n;
		if(temp==nullptr){
			tail = n;
		}

		

	};
	void display(){
		node<T>* temp = head;
		while(temp!=nullptr){
			cout<<temp->data<<endl;
			temp = temp->next;
		}
	};
	void insert_begining(T val){
		node<T>* n = new node<T>(val);
		if(head  == nullptr){
			head = n;
			tail = n;
			return ;
		}
		n->next =  head;
		head = n;

		
		
	};
	void insert_end(T val){
		node<T>* n = new node<T>(val);
		if(head == nullptr){
			head = n;
			tail = n;
			return ;

		}
		tail->next  = n;
		tail = n;
	};
	void delete_at(int pos){
		if(head == nullptr){
			cout<<"the list is empty"<<endl;
			return;
		}
 	if(pos == 1){
       		 node<T>* temp = head;
       	 	head = head->next;
       		 delete temp;
       		 return;
    }

	 node<T>* prev =  head;
		int count = 1;
		while(count < pos -1 && prev->next!=nullptr){
			prev = prev->next;
			count++;
		}
		node<T>* curr = prev->next;
		node<T>* next  = curr->next;

		prev->next = next;
		curr->next = nullptr;
		delete curr;

	 	if(next == nullptr)
       			 tail = prev;
	};


};

#endif
