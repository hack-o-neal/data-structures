#include <iostream>
using namespace std;
template<typename T>
class stack{
	public:
		T* arr;
		int top;
		int capacity;
		stack(int size){
			arr = new T[size];
			top = -1;
			capacity = size - 1;
		}
		
		bool isFull(){
			if(top == capacity){
				return true;
						
			}
			return false;
		}
		bool isEmpty(){
			return(top == -1);
		}
		void push(T value){
			if(isFull()){
				cout<<"stack Overflow!"<<endl;
			}else{
				top++;
				arr[top] = value;	
				cout<<"Element pushed!"<<endl;
				
			}
		}
		void pop(){
			if(isEmpty()){
				cout<<"stack underflow"<<endl;
			}else{
				top--;
				cout<<"Element poped!!"<<endl;
			}
		}
		void show(){
			if(isEmpty()){
				cout<<"there is nothing to see here bitch!"<<endl;
			}else{
				cout<<"top to bottom"<<endl;
				for(int i = top ; i>=0 ; i--){
					cout<<arr[i]<<endl;
				}
			}
		}
		~stack(){
			delete[] arr;
		}


};
int main(){
	stack<char> vowels(5);
	vowels.push('a');
	vowels.push('e');
	vowels.show();	
	return 0;
}
