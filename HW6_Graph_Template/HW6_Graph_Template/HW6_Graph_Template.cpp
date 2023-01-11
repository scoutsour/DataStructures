#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Graph {
private: // collaborated with tanner benbrooke and mounir zahidi
    int graph[5][5];
    vector<vector<int>> graph_list;

public:
    void BuildGraph(vector<int> link);
    vector<int> DepthFirstTraverse(int i);
    vector<int> BreadthFirstTraverse(int i);
};

void Graph::BuildGraph(vector<int> link) {
    for (int i = 0; i < 5; i++) {
        vector<int> list;
        for (int j = 0; j < link.size(); j += 2) {
            if (link[j] == i || link[j + 1] == i) {
                list.push_back(link[j] + link[j + 1] - i);
            }
        }
        graph_list.push_back(list);
    }
};

vector<int> Graph::DepthFirstTraverse(int i) {
    // This function performs depth-first traverse 
  // on the graph, starting at node i, and returns 
  // the sequence of visited nodes stored in a vector.
  // For example, if DFS visits 3, 1, 0, 2, 4, then 
  // this function returns a vector {3,1,0,2,4}. 
  // 
  // Whether you are using matrix or list implementation, 
  // break ties based on the order of nodes. 
  // For example, if node i has multiple univisited 
  // neighbors 2, 1, 3, we should visit 1 first, then 2 
  // and finally 3. (If you are using list implementation, 
  // it may be easier to store neighbor nodes in order 
  // to facilitate the traverse implementation.)
    vector<int> output;
    stack<int> s;
    vector<bool> visited(5, false);
    s.push(i);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (!visited[cur]) {
            output.push_back(cur);
            visited[cur] = true;
            for (int i = graph_list[cur].size() - 1; i >= 0; i--) {
                int n = graph_list[cur][i];
                if (!visited[n]) {
                    s.push(n);
                }
            }
        }
    }
    return output;
};

vector<int> Graph::BreadthFirstTraverse(int i) {
    queue<int> q;
    vector<int> output;
    vector<bool> visited(5, false);
    q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (!visited[cur]) {
            output.push_back(cur);
            visited[cur] = true;
            for (int i = 0; i < graph_list[cur].size(); i++) {
                int n = graph_list[cur][i];
                if (!visited[n]) {
                    q.push(n);
                }
            }
        }
    }

    return output;
};
int main()
{
    int mode, temp;
    vector<int> input;
    vector<int> output;
    Graph x;
    cin >> mode;
    while (cin >> temp) {
        input.push_back(temp);
    }
    switch (mode) {
    case 0:
        x.BuildGraph(input);
        output = x.DepthFirstTraverse(input.at(0));
        for (int i = 0; i < output.size(); i++) {
            cout << output.at(i) << endl;
        }
        break;
    case 1:
        x.BuildGraph(input);
        output = x.BreadthFirstTraverse(input.at(0));
        for (int i = 0; i < output.size(); i++)
        {
            cout << output.at(i) << endl;
        }
        break;
    }
    return 0;
}