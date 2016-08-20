public class LRUCache {
    class CacheNode {
        public int key;
        public int val;
        public CacheNode prev;
        public CacheNode next;
        public CacheNode(int key, int val) {
            this.key = key;
            this.val = val;
            prev = null;
            next = null;
        }
    }

    private int capacity;
    private CacheNode head, tail;
    private HashMap<Integer, CacheNode> map;
    // @param capacity, an integer
    public LRUCache(int capacity) {
        this.capacity = capacity;
        head = new CacheNode(0, 0);
        tail = new CacheNode(0, 0);
        head.next = tail;
        tail.prev = head;
        map = new HashMap<>();
    }

    // @return an integer
    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        CacheNode node = map.get(key);
        moveBack(node);
        return node.val;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    public void set(int key, int value) {
        if (map.containsKey(key)) {
            CacheNode node = map.get(key);
            node.val = value;
            moveBack(node);
        } else {
            CacheNode node = new CacheNode(key, value);
            if (map.size() == capacity) {
                CacheNode front = removeFront();
                map.remove(front.key);
            }
            addBack(node);
            map.put(key, node);
        }
    }

    private CacheNode removeFront() {
        CacheNode front = head.next;
        head.next = front.next;
        front.next.prev = head;
        return front;
    }

    private void addBack(CacheNode node) {
        CacheNode prev = tail.prev;
        prev.next = node;
        node.next = tail;
        tail.prev = node;
        node.prev = prev;
    }

    private void moveBack(CacheNode node) {
        if (node.next == null) return;
        node.prev.next = node.next;
        node.next.prev = node.prev;
        addBack(node);
    }
} // Author: XC