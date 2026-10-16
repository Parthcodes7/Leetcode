class LRUCache {
private:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        
        Node(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> m;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void addNode(Node* newNode) {
        Node* nextNode = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        
        Node* node = m[key];
        deleteNode(node);
        addNode(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            node->val = value;
            deleteNode(node);
            addNode(node);
            return;
        }
        
        if (m.size() == cap) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }
        
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};