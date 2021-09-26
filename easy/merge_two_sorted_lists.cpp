#include <utility>
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    typedef ListNode* ptr;

    void insert( ptr L, ptr in ){
        in->next = L->next;
        L->next = in;
    }

    void walk(ptr &p)
        {p = p->next;}

    ptr merge_one_node( ptr loc, ptr source ){
        const int val = source->val;
        while( loc->next ){
            if(loc->next->val < val)
                walk(loc);
            else
                break;
        }
        insert(loc,source);
        return source;
    }

public:
    ptr mergeTwoLists(ptr l1, ptr l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        // first find the list with smallest begin val
        // assume l1 has always the smallest, swap otherwise
        if( l1->val > l2->val )
            swap(l1,l2);

        ptr loc = l1;
        while( l2 ){
            ptr l2new = l2->next;
            loc = merge_one_node(loc,l2);
            l2 = l2new;
        }

        return l1; 
    }


    ptr merge2( ptr l1, ptr l2 )
    {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ptr Head;
        if( l1->val < l2->val ){
            Head = l1;
            l1 = l1->next;
        }
        else {
            Head = l2;
            l2 = l2->next;
        }
        ptr base = Head;

        while( l1 && l2 ){
            if( l1->val < l2->val ){
                base->next = l1;
                base = l1;
                l1 = l1->next;
            }
            else {
                base->next = l2;
                base = l2;
                l2 = l2->next;
            }
        }
        if(l1)
            base->next = l1;
        if(l2)
            base->next = l2;
        return Head;
    }
};

ListNode* make_list( initializer_list<int> nums )
{
    if(nums.size()==0) return nullptr;

    ListNode* L = new ListNode, *cur=L;
    for_each( nums.begin(), nums.end()-1, [&cur](int x){
        cur->val = x;
        cur->next = new ListNode;
        cur = cur->next;
    });
    cur->val = *(nums.end()-1);

    return L;
}

int main( int argc, char* argv[] ) {
    ListNode *l1 = make_list({1,2,3}),
             *l2 = make_list({1,2,4});
    Solution S;
    ListNode* L = S.merge2(l1,l2);
    while (L)
    {
        auto next = L->next;
        cout << L->val << endl;
        delete L;
        L = next;
    }

    return EXIT_SUCCESS;
}

// ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//     if(l1 == nullptr)
//         return l2;
//     if(l2 == nullptr)
//         return l1;
//     if(l1->val <= l2->val){
//         ListNode* head = mergeTwoLists(l1->next, l2);
//         l1->next = head;
//         return l1;
//     } else {
//         ListNode* head = mergeTwoLists(l1, l2->next);
//         l2->next = head;
//         return l2;
//     }
//     return nullptr;
// }