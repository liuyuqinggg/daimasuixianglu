#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main(int argc, char const *argv[])
{
    ListNode node1 = ListNode(5);
    ListNode node6 = ListNode(6);
    node1.next = &node6;

    cout << node1.next->val << endl;

    return 0;
}
