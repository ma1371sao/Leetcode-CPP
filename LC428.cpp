struct Node {
    int val;
    vector<Node*> children;
    Node() {}
    Node(int v): val(v) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        string s = "";
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* nd = q.front();
            q.pop();
            s += to_string(nd->val) + "," + to_string(nd->children.size()) + " ";
            for (auto child : nd->children)
                q.push(child);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data == "") return NULL;
        queue<Node*> q;
        Node* root = new Node();
        q.push(root);
        int i = 0;
        while (!q.empty()) {
            Node* nd = q.front();
            q.pop();
            int val, numChild;
            int idx = data.find(" ", i);
            parseData(val, numChild, data.substr(i, idx - i));
            i = idx + 1;
            nd->val = val;
            for (int i = 0; i < numChild; i++) {
                Node* child = new Node();
                nd->children.push_back(child);
                q.push(child);
            }
        }
        return root;
    }
    
    void parseData(int& val, int& numChild, string s) {
        int idx = s.find(",");
        val = stoul(s.substr(0, idx), nullptr, 10);
        numChild = stoul(s.substr(idx + 1), nullptr, 10);
    }
};

int main() {
    Codec c;
    Node* root1 = new Node(1);
    Node* root2 = new Node(2);
    Node* root3 = new Node(3);
    Node* root4 = new Node(4);
    Node* root5 = new Node(5);
    root1->children.push_back(root2);
    root1->children.push_back(root3);
    root2->children.push_back(root4);
    root3->children.push_back(root5);
    string s = c.serialize(root1);
    cout << s << endl;
    Node* root = c.deserialize(s);
    cout << c.serialize(root) << endl;
}
