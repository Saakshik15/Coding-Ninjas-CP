// code for search, insert and delete in trie

#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
	Node *next[26];
	int cnt;
	bool isEnding;

	Node(){
		cnt = 0;
		isEnding = false;
		for(int i=0; i<26; i++) next[i] = NULL;
	}
}Node;

void insert(Node *curr, string s, int index) {
	curr->cnt += 1;
	if(index == s.length()) {
		curr->isEnding = true;
		return;
	}
	int nextIndex = (int)(s[index] - 'a');
	if(curr->next[nextIndex] == NULL) {
		curr->next[nextIndex] = new Node();
	}

	insert(curr->next[nextIndex], s, index+1);
}


int search(Node *curr, string s, int index) {
	if(curr == NULL) {
		return 0;
	}
	if(index == s.length()) {
		return curr->cnt;
	}
	int nextIndex = (int)(s[index] - 'a');

	return search(curr->next[nextIndex], s, index+1);
}

Node* remove(Node *curr, string s, int index) {
	curr->cnt -= 1;
                if(curr->cnt==0)
               {
                  delete curr;
                  return NULL;
               }

	if(index == s.length()) {
		curr->isEnding = false;
		return curr;
	}
	int nextIndex = (int)(s[index] - 'a');
	

	curr->next[nextIndex] = remove(curr->next[nextIndex], s, index+1);
	return curr;
}


int main() {

	Node *root = new Node();
	insert(root, "abc", 0);
	insert(root, "aba", 0);
	insert(root, "ab", 0);
	insert(root, "aca", 0);

	cout<<search(root, "ab", 0)<<"\n";

	root = remove(root, "abc", 0);

	cout<<search(root, "ab", 0) <<"\n";
	cout<<search(root, "abc", 0)<<"\n";

	return 0;
}
