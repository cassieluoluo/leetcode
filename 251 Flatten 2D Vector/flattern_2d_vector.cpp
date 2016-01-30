class Vector2D {	// Author: Xinyu Chen
public:
    Vector2D(vector<vector<int>>& vec2d) {
        data = vec2d;
        i = 0;
        j = 0;
        rows = vec2d.size();
    }

    int next() {
        return data[i][j++];
    }

    bool hasNext() {
        if (i >= data.size()) return false;
        if (j >= data[i].size()) {
            ++i; j = 0;
            while (i < data.size() && data[i].empty()) ++i;
        }
        if (i == data.size()) return false;
        return true;
    }
private:
    int i, j, rows;
    vector<vector<int>> data;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */