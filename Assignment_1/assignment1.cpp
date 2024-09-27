// PROBLEM -1

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            // If the list is empty or has only one node, there's no middle to delete
            return nullptr;
        }

        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        ListNode* prevPtr = nullptr;

        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            prevPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        // Delete the middle node
        prevPtr->next = slowPtr->next;
        delete slowPtr;

        return head;
    }
};



// PROBLEM -2


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      // Create a dummy node to simplify the code
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Iterate while both lists have nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // If one of the lists is not empty, append the remaining nodes
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // Save the head of the merged list
        ListNode* mergedList = dummy->next;

        // Delete the dummy node to avoid memory leaks
        delete dummy;

        return mergedList;
    }  
    
};

// PROBLEM - 3
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        stack<pair<int, int>> indexStack; // Pair of (index, value) to track indices and values

        // Traverse the linked list
        int currentIndex = 0;
        while (head != nullptr) {
            result.push_back(0); // Default value if no greater node is found

            // Check for the next greater node for nodes in the stack
            while (!indexStack.empty() && indexStack.top().second < head->val) {
                result[indexStack.top().first] = head->val;
                indexStack.pop();
            }

            // Push the current node's index and value to the stack
            indexStack.push({currentIndex, head->val});
            head = head->next;
            ++currentIndex;
        }

        return result;
    }
};


//PROBLEM -4

class Solution {
public:
    int pairSum(ListNode* head) {
        // Reverse the original linked list
        ListNode* reversed = reverseList(head);

        int sum = 0;
        int t=0;

        // Traverse both the original and reversed linked lists
        while (head != nullptr && reversed != nullptr) {
            t= head->val + reversed->val;
            if(t>sum) sum = t;
            head = head->next;
            reversed = reversed->next;
        }

        return sum;
    }

    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};
