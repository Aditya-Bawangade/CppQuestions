
#include <bits/stdc++.h> 
/***************************************
 
    Following is the Node class already written.

    class Node 
    {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) 
        {
            next = NULL; prev=NULL;
            this->data = data;
        }

        ~Node() 
        {
            if (next != NULL)
            {
                delete next;
            }
        }
    };
 
***************************************/

int countAllTripletSum(Node *head, int x)
{
    vector<int> ans ;
    while(head != nullptr){
        ans.push_back(head->data) ;
        head = head->next ;
    }

    int count = 0 ;
    for(int i = 0 ; i < ans.size() ; i++){
        int s = i + 1 ;
        int e = ans.size() - 1 ;
        while(s < e){
            if(ans[i] + ans[s] + ans[e] > x){
                e-- ;
            }else if(ans[i] + ans[s] + ans[e] < x){
                s++ ;
            }else{
                count++ ;
                s++ ;
                e-- ;
            }
        }
    }
    return count ;
}