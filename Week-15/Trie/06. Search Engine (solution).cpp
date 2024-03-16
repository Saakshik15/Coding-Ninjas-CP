/*
Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.

Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.

Note: All the strings in database will be unique.

INPUT

First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.
OUTPUT

Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
CONSTRAINTS

1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
potential 10
potent 8
pot
SAMPLE OUTPUT
10
*/

typedef struct Node {
    Node* next[26];
    int maxSubtree;
    Node()
    {
        maxSubtree = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
    ~Node() {
            for (int i = 0; i < 26; i++){
                if (next[i] != NULL) {
                    delete next[i];
                }
            }
        }
} Node;

void insert(Node* curr, pair<string, int>& databaseEntry, int index)
{
    // Setting the Priority of the current text. 
    if (index == databaseEntry.first.length()) {
        curr->maxSubtree = databaseEntry.second;
        return;
    }

    curr->maxSubtree = max(curr->maxSubtree, databaseEntry.second);
    
    // Getting the next character.
    int nextIndex = (int)(databaseEntry.first[index] - 'a');
    
    // Creating a new node in Trie.
    if (curr->next[nextIndex] == NULL) {
        curr->next[nextIndex] = new Node();
    }
    insert(curr->next[nextIndex], databaseEntry, index + 1);
}

int query(Node* curr, string& txt, int index)
{

    // String not found.
    if (curr == NULL)
        return -1;
    
    //  String found.
    if (index == txt.length()) {
        return curr->maxSubtree;
    }

    // The next character that we need. 
    int nextIndex = (int)(txt[index] - 'a');
    return query(curr->next[nextIndex], txt, index + 1);
}

vector<int> searchEngine(vector<pair<string, int> > database, vector<string> text)
{
    // Creating a Trie data-structure.
    Node* root = new Node();

    int n = database.size();

    // Inserting the database in the Trie.
    for (int i = 0; i < n; i++) {
        insert(root, database[i], 0);
    }

    vector<int> ans;

    // Iterating in each query.
    for (auto& i : text) {
        // Appending the answer in 'ans'.
        ans.push_back(query(root, i, 0));
    }

    delete root;

    return ans;
}
