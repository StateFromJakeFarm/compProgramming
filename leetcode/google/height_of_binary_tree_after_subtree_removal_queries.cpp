#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void print(vector<int>& vec) {
    for (auto &v : vec) {
        cout << v << ' ';
    }
    cout << endl;
}


void print(TreeNode *root) {
    queue<TreeNode*> Q;
    Q.push(root);
    TreeNode *cur;
    int i = 0;
    int power = 0;
    while (!Q.empty()) {
        cur = Q.front();
        Q.pop();
        cout << cur->val << ' ';

        if (cur->left != nullptr) {
            Q.push(cur->left);
        }
        if (cur->right != nullptr) {
            Q.push(cur->right);
        }

        if (i == 0 || i == pow(2, power)) {
            cout << endl;
            power++;
        }
        i++;
    }
    cout << endl;
}


void insert_bst(TreeNode* &root, int val) {
    TreeNode *n = new TreeNode(val);

    if (root == nullptr) {
        root = n;
        return;
    }

    TreeNode *cur = root;
    while (true) {
        if (val < cur->val) {
            if (cur->left == nullptr) {
                cur->left = n;
                break;
            } else {
                cur = cur->left;
            }
        } else {
            if (cur->right == nullptr) {
                cur->right = n;
                break;
            } else {
                cur = cur->right;
            }
        }
    }
}


TreeNode* build_bt(vector<int> &vals) {
    TreeNode *root = new TreeNode(vals[0]);

    queue<TreeNode*> Q;
    Q.push(root);

    int i = 1;
    TreeNode *cur = root;
    TreeNode *next;
    while (i < vals.size()) {
        if (cur->left == nullptr) {
            next = new TreeNode(vals[i]);
            Q.push(next);
            cur->left = next;
            i++;
        }
        if (i < vals.size() && cur->right == nullptr) {
            next = new TreeNode(vals[i]);
            Q.push(next);
            cur->right = next;
            i++;
        }
        Q.pop();
        cur = Q.front();
    }

    queue<TreeNode*> Q_search;
    Q_search.push(root);
    while (!Q_search.empty()) {
        cur = Q_search.front();
        Q_search.pop();
        if (cur == nullptr) {
            continue;
        }

        if (cur->left && cur->left->val == INT_MAX) {
            delete cur->left;
            cur->left = nullptr;
        }
        if (cur->right && cur->right->val == INT_MAX) {
            delete cur->right;
            cur->right = nullptr;
        }
        Q.push(cur->left);
        Q.push(cur->right);
    }

    return root;
}


class Solution {
public:
    vector<int> max_depths;
    vector<int> num_maxes;
    vector<int> height_counts;

    pair<int, int> biggest_here(TreeNode *node, int depth) {
        if (node->left == nullptr && node->right == nullptr) {
            max_depths[node->val] = depth;
            num_maxes[node->val] = 1;
            if (height_counts.size() < depth) {
                height_counts.resize(depth+1);
            }
            height_counts[depth] += 1;
            cout << node->val << ' ' << depth << ' ' << 1 << endl;

            return make_pair(depth, 1);
        }

        int max_depth, n_maxes;
        if (node->left == nullptr) {
            auto r = biggest_here(node->right, depth+1);
            max_depth = r.first;
            n_maxes = r.second;
        } else if (node->right == nullptr) {
            auto l = biggest_here(node->left, depth+1);
            max_depth = l.first;
            n_maxes = l.second;
        } else {
            auto l = biggest_here(node->left, depth+1);
            int l_d = l.first;
            int l_n = l.second;

            auto r = biggest_here(node->right, depth+1);
            int r_d = r.first;
            int r_n = r.second;

            if (l_d > r_d) {
                max_depth = l_d;
                n_maxes = l_n;
            } else if (l_d < r_d) {
                max_depth = r_d;
                n_maxes = r_n;
            } else {
                max_depth = l_d;
                n_maxes = l_n + r_n;
            }
        }

        n_maxes = (n_maxes > 0 ? n_maxes : 1);

        max_depths[node->val] = max_depth;
        num_maxes[node->val] = n_maxes;

        cout << node->val << ' ' << max_depth << ' ' << n_maxes << endl;

        return make_pair(max_depth, n_maxes);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        max_depths.resize(10);
        num_maxes.resize(10);

        biggest_here(root, 0);
        print(max_depths);
        print(num_maxes);
        print(height_counts);

        vector<int> output;
        for (int &q : queries) {
            int q_max_depth = max_depths[q];
            int q_n = num_maxes[q];
            for (int i=height_counts.size()-1; i>=0; i--) {
                if (height_counts[i] > 0) {
                    if (i == q_max_depth) {
                        if (height_counts[i] - q_n > 0) {
                            output.push_back(i);
                            break;
                        }
                    } else {
                        output.push_back(i);
                        break;
                    }
                }
            }
        }

        return output;
    }
};


int main() {
    Solution S;

    vector<int> in = {1,NULL,5,3,NULL,2,4};
    TreeNode *root = build_bt(in);
    print(root);

    vector<int> q = {3,5,4,2,4};
    vector<int> output = S.treeQueries(root, q);
    print(output);

    return 0;
}
