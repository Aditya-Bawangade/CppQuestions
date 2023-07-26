/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 * };
 */

#include<bits/stdc++.h>
Node *cloneLL(Node *head){
	unordered_map<Node*, Node*> mp ;
    Node* curr = head ;
    while(curr != nullptr){
        mp[curr] = new Node(curr->data) ;
        curr = curr->next ;
    }
    curr = head ;
    while(curr != nullptr){
        mp[curr]->next = mp[curr->next] ;
        mp[curr]->random = mp[curr->random] ;
        curr = curr->next ;
    }

    return mp[head] ;
}