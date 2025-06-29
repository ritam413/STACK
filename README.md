🧠 SL1: Insertion in Singly Linked List
📌 Function: insertAtBeginning(head, value)
plaintext
Copy
Edit
Function insertAtBeginning(head, value):
    newNode = createNode(value)
    newNode.next = head
    head = newNode
    RETURN head
✅ This function inserts a new node with the given value at the beginning of the singly linked list.

📌 Function: insertAtPosition(head, value, k)
plaintext
Copy
Edit
Function insertAtPosition(head, value, k):
    newNode = createNode(value)

    IF k == 1:
        newNode.next = head
        head = newNode
        RETURN head

    current = head
    count = 1

    WHILE current ≠ NULL AND count < k - 1:
        current = current.next
        count += 1

    IF current == NULL:
        PRINT "Position out of bounds"
        RETURN head

    newNode.next = current.next
    current.next = newNode

    RETURN head
