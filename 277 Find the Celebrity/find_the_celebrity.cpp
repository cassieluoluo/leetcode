// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution { // slower solution
public:
    int findCelebrity(int n) {
        vector<int> people(n, 1);
		for (int i = 0; i < n; i++) {
			if (!people[i]) continue;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (knows(i, j) || !knows(j, i)) {
					people[i] = 0;
				} else {
                    people[j] = 0;
                }
			}
            if (people[i] == 1) return i;
		}
		return -1;
    }
};

class Solution { // faster solution
public:
    int findCelebrity(int n) {
        int person = 0;
        for (int i = 0; i < n; i++) {
            if (person == i) continue;
            if (knows(person, i)) {
                person = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (person == i) continue;
            if (knows(person, i) || !knows(i, person)) return -1;
        }
        return person;
    }
};