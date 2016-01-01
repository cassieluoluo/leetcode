# Course Schedule
### Difficulty: Medium

here are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

<code>2, [[1,0]]</code>

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

<code>2, [[1,0],[0,1]]</code>

There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

**Note:**

The input prerequisites is a graph represented by **a list of edges**, not adjacency matrices. Read more about [how a graph is represented](https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs).

**Hints:**

1. This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
2. [Topological Sort via DFS](https://class.coursera.org/algo-003/lecture/52) - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
3. Topological sort could also be done via [BFS](http://en.wikipedia.org/wiki/Topological_sorting#Algorithms).

**Tags:** Depth-first Search, Breadth-first Search, Graph, Topological Sort.

## Explanation

This problem is a simple application of topological sort. However, we are only required to return whether the course schedule is possible. Essentially, this is asking whether the graph is a Direct Acyclic Graph (DAG).

There are two ways to tackle this problem: BFS and DFS.

Here we discuss the BFS way first. To better organize the data, we would like to use adjacent list to store the graph. And we also need to maintain an array of indegrees of each node. 

In a DAG, there must be at least one node with zero indegree. Otherwise there is a loop in the graph. This is the core idea of BFS method. After constucting the graph and count the indegrees, we check the indegree of each node. If it is zero, remove that node by disconnecting it from all its neighbors. Meanwhile, we need to reduce the indegrees of its neighbors by one.

If there is no loop existing, we will have removed all the nodes by the end. Otherwise we will find that some nodes has non-zero indegrees. At this point we can conclude whether the course schedule is possible.

LeetCode Link: [https://leetcode.com/problems/course-schedule/](https://leetcode.com/problems/course-schedule/)

*Author: Xinyu Chen*