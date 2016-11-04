public class ZigzagIterator {
    int idx1, idx2;
    List<Integer> v1, v2;
    boolean isFirst;
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        idx1 = 0; 
        idx2 = 0;
        this.v1 = v1;
        this.v2 = v2;
        isFirst = v1.size() == 0 ? false : true;
    }

    public int next() {  
        if (isFirst) {
            if (idx2 != v2.size()) isFirst = !isFirst;
            return v1.get(idx1++);
        } else {
            if (idx1 != v1.size()) isFirst = !isFirst;
            return v2.get(idx2++);
        }
    }

    public boolean hasNext() {
        return idx1 != v1.size() || idx2 != v2.size();
    }
} // Author: Cassie

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */
