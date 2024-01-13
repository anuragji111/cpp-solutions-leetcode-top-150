**Implement Trie(Prefix Tree)**

Problem Statement 98) A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

-----------------------------------------------------------------------------------
SOLUTION = class TrieNode {
public:
    TrieNode* children[26] = {};  // Array to store children nodes (26 for lowercase letters)
    bool isEnd = false;          // Flag to indicate end of a word
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c - 'a']) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->isEnd = true;  // Mark the end of the word
    }

    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            current = current->children[c - 'a'];
            if (!current) {
                return false;  // Character not found
            }
        }
        return current->isEnd;  // Check if it's the end of a word
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            current = current->children[c - 'a'];
            if (!current) {
                return false;  // Character not found
            }
        }
        return true;  // Prefix found
    }

private:
    TrieNode* root;
};

-------------------Key Concepts:

Trie: A tree-like structure optimized for storing and searching strings with common prefixes.
Trie Nodes: Each node represents a character in a string and stores pointers to its children, forming a multiway tree.
Key Operations:
Insert: Adds a new word to the Trie.
Search: Checks if a word exists in the Trie.
StartsWith: Checks if a prefix exists in any of the stored words.
Code Breakdown:

TrieNode Class:

Represents a single node in the Trie.
children: Array of 26 pointers to child nodes (one for each lowercase letter).
isEnd: Boolean flag indicating whether this node marks the end of a word.
Trie Class:

Represents the entire Trie structure.
root: Pointer to the root node of the Trie.
insert: Inserts a word into the Trie:
Navigates through the Trie, creating nodes for each character if they don't exist.
Marks the end of the word with isEnd = true.
search: Searches for a word in the Trie:
Follows the characters of the word through the Trie.
Returns true if the word is found (node with isEnd = true), otherwise false.
startsWith: Checks if a prefix exists in the Trie:
Follows the characters of the prefix through the Trie.
Returns true if the prefix is found, otherwise false.
Time and Space Complexity:

Insertion, Search, StartsWith: O(L), where L is the length of the word or prefix.
Space: O(N * M), where N is the number of words and M is the average length of the words.
Advantages of Tries:

Efficient for storing and searching strings with common prefixes.
Fast autocomplete and spell-checking features.
Can be used for pattern matching and word suggestions.
