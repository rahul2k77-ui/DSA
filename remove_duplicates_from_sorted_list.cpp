#include <iostream>
#include <vector>

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }
        
        return head;
    }
};

ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    cout << "[";
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) cout << ",";
        current = current->next;
    }
    cout << "]" << endl;
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    if (!(cin >> n)) {
        cout << "Invalid input." << endl;
        return 1;
    }

    if (n < 0) {
        cout << "Number of nodes cannot be negative." << endl;
        return 1;
    }

    if (n == 0) {
        cout << "Input: []\nOutput: []" << endl;
        return 0;
    }

    vector<int> input(n);
    cout << "Enter " << n << " integers in sorted order (separated by spaces): ";
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    ListNode* head = createList(input);

    cout << "\n--- Results ---" << endl;
    cout << "Input:  ";
    printList(head);

    Solution sol;
    head = sol.deleteDuplicates(head);

    cout << "Output: ";
    printList(head);

    freeList(head);

    return 0;
}