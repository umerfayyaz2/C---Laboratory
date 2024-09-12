struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {};
};

Node *swap_pairs_of_nodes(Node *head)
{
    Node *dummy = new Node(-1);

    dummy->next = head;

    Node *prev = dummy;

    while (prev->next && prev->next->next)
    {
        Node *first = prev->next;        // pointing to prev->dummy-> head-> our first node
        Node *second = prev->next->next; // second pointing back to prev -> next -> next [1,2]

        first->next = second->next; // pointing to first node =>>> second->next
        prev->next = second;        // point second [2]
        second->next = first;       // second node now holds first value which is [2,1]

        prev = first; // moves to the next pair
    }

    return dummy->next; // return head
}

int main()
{
}