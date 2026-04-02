#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        curr->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

ListNode* buildList(int n) {
    if (n == 0) return nullptr;
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            curr = head;
        } else {
            curr->next = newNode;
            curr = curr->next;
        }
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n1, n2;

    cout << "Enter number of elements in List 1: ";
    cin >> n1;
    ListNode* list1 = buildList(n1);

    cout << "Enter number of elements in List 2: ";
    cin >> n2;
    ListNode* list2 = buildList(n2);

    cout << "\nList 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

        Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged: ";
    printList(merged);

    return 0;
}