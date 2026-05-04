#include "my_list.h"
#include<iostream>
int main(){
    cout << "start" << endl;
    list<int> l;
    cout << "list created" << endl;
    l.insert(1, 23);
    cout << "insert done" << endl;
    int elem;
    for(int i = 2;i<=5;i++){
	cin>>elem;
    	l.insert(i,elem);
    }
    l.display();
    cout << "display done" << endl;
    return 0;
}
