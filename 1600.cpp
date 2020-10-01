class ThroneInheritance {
public:
    class Node {
    public:
        string name;
        string parent;
        vector<string> children;
        bool valid;
        Node (string _name = "", string _parent = "") {
            name = _name;
            parent = _parent;
            children.clear();
            valid = true;
        }
    };

    ThroneInheritance(string kingName) {
        nodes.insert(pair<string, Node>(kingName, Node(kingName)));
        root = kingName;
    }
    
    void birth(string parentName, string childName) {
        nodes[childName] = Node(childName, parentName);
        unordered_map<string, Node>::iterator itr = nodes.find(parentName);
        itr->second.children.push_back(childName);
    }
    
    void death(string name) {
        unordered_map<string, Node>::iterator itr = nodes.find(name);
        itr->second.valid = false;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        unordered_set<string> curOrder;
        Successor(root, curOrder, res);
        return res;
    }

    void Successor(string curKing, unordered_set<string>& curOrder, vector<string>& res) {
        if (curKing == "") return;
        unordered_map<string, Node>::iterator itr = nodes.find(curKing);
        if (itr->second.valid && curOrder.find(curKing) == curOrder.end()) {
            res.push_back(curKing);       
            curOrder.insert(curKing);
        } else if (curOrder.find(curKing) == curOrder.end()) {
            curOrder.insert(curKing);
        }
        int i = 0;
        for (; i < itr->second.children.size(); i++) {
            unordered_map<string, Node>::iterator nitr = nodes.find(itr->second.children[i]);
            if ((curOrder.find(itr->second.children[i]) != curOrder.end())) continue;
            Successor(itr->second.children[i], curOrder, res);
            break;
        }
        if (i == itr->second.children.size()) {
            Successor(itr->second.parent, curOrder, res);
        }
    }
private:
    unordered_map<string, Node> nodes;
    string root;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
