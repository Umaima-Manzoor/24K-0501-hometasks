#include <iostream>
#include <string>
using namespace std;

struct Node{
	string data;
	Node *link;
};

Node *top= NULL;
bool isEmpty(){
	if(top==NULL){
		return true;
	}else{
		return false;
	}
}
void Push(string value){
	Node * ptr = new Node();
	ptr->data = value;
	ptr->link=top;
	top = ptr;
    cout<< value <<" pushed to stack"<<endl;
}
void Pop(){
	if(isEmpty()){
		cout<< "Stack is UnderFlow"<<endl;
	}else{
		Node *ptr = top;
        cout<< "Popped element: "<< top->data << endl;
		top = top->link;
		delete(ptr);
	}
}
void ShowStack(){
	if(isEmpty()){
			cout<< "Stack is Empty\n"<<" ";
	}else 
	{
			 Node *temp = top;
        cout << "Stack elements (Top to Bottom): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->link;
        }
         cout << endl;
	}
	
}
void Top(){
	if(isEmpty()){
			cout<< "Stack is Empty"<<endl;
	}else{
		cout<< "Stack Top element: "<< top->data<< endl;
	}
}
int main(){
Push("Google");
Push("Facebook");
Push("Twitter");
Push("LinkedIn");
Push("Instagram");
ShowStack();
cout << "After clicking the back button twice:"<< endl;
Pop();
Pop();
ShowStack();
//If the user clicks the back button twice shouldn't the user return to the Twitter page instead of the Facebook page?
Top();
return 0;
}
