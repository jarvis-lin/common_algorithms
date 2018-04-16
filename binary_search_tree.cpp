#include <iostream>
#include <vector>
#include <stack>
#include "tree.h"

using namespace std;

void bstInsert(TreeNode* root, int val) {
    TreeNode* cur = root;
    while(true) {
        if(val < cur->value) {
            if(cur->left) {
                cur = cur->left;
                continue;
            }
            else {
                cur->left = new TreeNode(val);
                return;
            }
        }
        else {
            if(cur->right) {
                cur = cur->right;
                continue;
            }
            else {
                cur->right = new TreeNode(val);
                return ;
            }
        }
    }
}

void bstsortOverwriteWithRecycle(vector<int>& input, TreeNode *root) {
    stack<TreeNode*> buf;
    TreeNode *cur = root;
    int index = 0;
    while(cur!=NULL || buf.size()!=0) {
        if(cur == NULL) {
            cur = buf.top();
            input[index++] = cur->value;
            cur = cur->right;
            free(buf.top());
            buf.pop();
        }
        else {
            if(cur->left) {
                buf.push(cur);
                cur = cur->left;
            }
            else {
                input[index++] = cur->value;
                TreeNode *tmp = cur;
                cur = cur->right;
                free(tmp);
            }
        }
    }
}

void bstsort(vector<int>& input, int start, int end) {
    if(input.size() == 0)
        return ;
    else {
        TreeNode *root = new TreeNode(input[0]);
        for(int i=1; i<input.size(); ++i) {
            bstInsert(root, input[i]);
        }

        bstsortOverwriteWithRecycle(input, root);
    }

}

int main() {
    const int count = 500;
    const int max = 500;
    vector<int> test(count);
    cout << "test input ";
    srand(time(NULL));
    for(int i=0; i<count; ++i) {
        test[i] = rand() % max;
        cout << test[i] << " ";
    }
    cout << endl;
    bstsort(test, 0, count -1);
    cout << "sorted result " << test[0] << " ";
    bool correct = true;
    for(int i=1; i<count; ++i) {
        cout << test[i] << " ";
        correct &= (test[i] >=test[i-1]);
    }
    cout << endl;
    cout << "result " << correct << endl;

    return 0;
}
