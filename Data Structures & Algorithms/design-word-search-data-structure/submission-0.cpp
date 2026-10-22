class WordDictionary {
private:
    struct Node{
        vector<Node*> arr;
        bool isEnd;

        Node(): isEnd(false), arr(vector<Node*>(26)) {}
    };

    Node* head;
public:
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node* cur = head;

        for(const char& x: word) {
            if(!cur->arr.at(x-'a')) cur->arr.at(x-'a') = new Node();
            cur = cur->arr.at(x-'a');
        }

        cur->isEnd = true;
    }

    bool mySearch(string word, Node* cur) {
        if(!cur) return false;
        if(word.empty()) return cur->isEnd;

        char c = word.back();
        bool isFound = false;
        word.pop_back();
        
        if(c == '.') {
            for(int i=0;i<26;i++) isFound |= mySearch(word, cur->arr.at(i));
        } else isFound = mySearch(word, cur->arr.at(c-'a'));

        return isFound;
    }
    
    bool search(string word) {
        reverse(word.begin(), word.end());
        return mySearch(word, head);
    }
};