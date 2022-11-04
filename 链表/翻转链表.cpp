#include <iostream>

using namespace std;

void test1();

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head){
    cout <<  "[ ";
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout <<  "]";
    cout << endl;
    return;
}

class Solution
{

public:
    ListNode* reverseList(ListNode* head){
        ListNode* tmp = nullptr;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
        
    }
};


int main(int argc, char const *argv[])
{
    test1();
  
}


void test1(){
    ListNode* node1 = new ListNode(1); //new的对象在堆区  可以用delete删除  https://blog.csdn.net/qq826364410/article/details/115460376
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(6);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(4);
    ListNode* node6 = new ListNode(5);
    ListNode* node7 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    printList(node1);    
    // cout << &node1 << endl;
    // printListAddress(&node1);    

    Solution solution;
    node1 = solution.reverseList(node1);

    printList(node1);
    return ;
}
