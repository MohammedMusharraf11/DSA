class LRUCache {
public:
    struct Node {
        int key, value;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    int capacity;
    std::map<int, Node*> mpp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0); // Dummy head
        tail = new Node(0, 0); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* currentHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = currentHead;
        currentHead->prev = node;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (mpp.size() == capacity) {
                Node* nodeToDelete = tail->prev;
                mpp.erase(nodeToDelete->key);
                deleteNode(nodeToDelete);
                delete nodeToDelete;
            }
            Node* newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};
