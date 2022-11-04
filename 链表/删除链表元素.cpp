#include <iostream>

using namespace std;
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

void printListAddress(ListNode* head){
    while (head)
    {
        cout << head << " "; //head为指针  直接输出就是地址值 不能写成 &head
        head = head->next;
    }
    cout << endl;
    return;
}


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // printList(head);
        // printListAddress(head);    
        ListNode* dummyhead = new ListNode(); //堆区创建的对象才能在函数中返回
        dummyhead->next = head;
        ListNode* cur;
        cur = dummyhead;

        while(cur->next != nullptr ){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;//只能删除堆区创建的对象  double free or corruption (out)
            }else{
                cur = cur->next;
            }
            
        }
        head = dummyhead->next;
        delete dummyhead;
        return head;

    }
};

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
    node1 = solution.removeElements(node1,6);

    printList(node1);
    return ;
}

void test2(){
    ListNode* node1 = nullptr;
   
    printList(node1);    
    // cout << &node1 << endl;
    // printListAddress(&node1);    

    Solution solution;
    node1 = solution.removeElements(node1,1);

    printList(node1);
    return ;
}

void test3(){
    ListNode* node1 = new ListNode(7);
    ListNode* node2 = new ListNode(7);
    ListNode* node3 = new ListNode(7);
    ListNode* node4 = new ListNode(7);
    ListNode* node5 = new ListNode(7);
    ListNode* node6 = new ListNode(7);
    ListNode* node7 = new ListNode(7);
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
    node1 = solution.removeElements(node1,7);

    printList(node1);
    return ;
}

int main(int argc, char const *argv[])
{
    test1();
    cout << "---------------------"<< endl;
    test2();
    cout << "---------------------"<< endl;
    test3();
    return 0;
}

