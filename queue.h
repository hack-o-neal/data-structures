#ifndef QUEUE_H
#define QUEUE_H
#include"my_list.h"
#include<iostream>
using namespace std;

template <typename T>
struct queue{
	
	node<T>* front;
	node<T>* rear;
	queue(){
		front = nullptr;
		rear = nullptr;	
	}
	void enqueue(T val){
		node<T>* n =  new node<T>(val);
		if(front==nullptr && rear==nullptr){
			front = n;
			rear = n;
			return;
		}
		rear->next = n;
		rear = n;

	};
	void dequeue(){
		if(front==nullptr){
			cout<<"queue is already empty"<<endl;
			return;
		}
		node<T>* temp = front;
		front = front->next;
		delete temp;


		
	};
	void peek(){
		if(front ==  nullptr){
			cout<<"queue is empty"<<endl;
			return ;
		}
		cout<<front->data<<endl;
	};
};
#endif
