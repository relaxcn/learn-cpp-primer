#include<string>
class TreeNode {
public:
    TreeNode():value(std::string()), count(new int(1)), left(nullptr), right(nullptr) { };
    // copy constructor
    TreeNode(const TreeNode &rhs): value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
    TreeNode &operator=(const TreeNode &rhs){
        ++*rhs.count;
        if (--*count = 0) {
            delete count;
            delete left;
            delete right;
        }
        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;
        return *this;
    }
    ~TreeNode() {
        if (--*count == 0) {
            delete count;
            delete left;
            delete right;
        }
    }
private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
    BinStrTree():root(new TreeNode()) { }
    // copy constructor
    BinStrTree(const BinStrTree &rhs):root(new TreeNode(*rhs.root)) { }
    BinStrTree &operator=(const BinStrTree &rhs) {
        // 首先复制右边操作符，避免自赋值的发生
        TreeNode *new_root = new TreeNode(*rhs.root);
        delete root;
        root = new_root;
        return *this;
    }
    ~BinStrTree() {
        delete root;
    }
private:
    TreeNode *root;
};