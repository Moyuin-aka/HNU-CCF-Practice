#include <iostream>
#include <string>
using namespace std;
// 二叉树遍历模板题，输入前序遍历和中序遍历，输出后序遍历
// 可见[luogu原题](https://www.luogu.com.cn/problem/P1827)
void order(string pre, string in)
{

    if (pre.size() == 0 || in.size() == 0)
        return; // 如果前序遍历和中序遍历都为空，说明没有树了

    char root = pre[0];      // 前序遍历的第一个元素就是根节点
    int pos = in.find(root); // 在中序遍历中找到根节点的位置

    string left_in = in.substr(0, pos);   // 左子树的中序遍历
    string right_in = in.substr(pos + 1); // 右子树的中序遍历

    string left_pre = pre.substr(1, left_in.length());   // 左子树的前序遍历
    string right_pre = pre.substr(left_in.length() + 1); // 右子树的前序遍历

    order(left_pre, left_in);   // 递归左子树
    order(right_pre, right_in); // 递归右子树
    cout << root;               // 输出根节点
}
int main()
{
    int n;
    while (true)
    { // 输入n，直到n为0结束
        cin>>n;
        if (n == 0)
            break; // 如果n为0，结束输入
        string pre, in;
        cin >> pre >> in;
        order(pre, in); // 调用函数,还原一下二叉树
        cout<<endl;
    }
    return 0;
}