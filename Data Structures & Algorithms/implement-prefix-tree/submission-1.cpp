class PrefixTree {
private:
    struct Tri {
        bool end;
        array<Tri*, 26> arr;

        Tri(): end(false) {
            arr.fill(nullptr);
        }
    };

    Tri* head;
public:
    PrefixTree() {
        head = new Tri();
    }
    
    void insert(string word) {
        Tri* cur = head;

        for(const char& x: word) {
            if(!cur->arr.at(x-'a')) cur->arr.at(x-'a') = new Tri();
            cur = cur->arr.at(x-'a');
        }

        cur->end = true;
    }
    
    bool search(string word) {
        Tri* cur = head;

        for(const char& x: word) {
            if(!cur->arr.at(x-'a')) return false;
            cur = cur->arr.at(x-'a');
        }

        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Tri* cur = head;

        for(const char& x: prefix) {
            if(!cur->arr.at(x-'a')) return false;
            cur = cur->arr.at(x-'a');
        }

        return true;
    }
};
