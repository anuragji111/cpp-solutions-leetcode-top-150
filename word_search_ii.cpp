**Word Search II**

Problem Statement 100) Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.

-------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:

    string str;
    bool vis[13][13];

    unordered_set<string> res;
    unordered_set<string> toFound;
    unordered_map<string, int> m;

    void rec(int i, int j, vector<vector<char>> &a)
    {
        if (toFound.find(str) != toFound.end())
        {
            string curr;

            for (auto x : str)
            {
                curr += x;
                m[curr]--;
            }

            toFound.erase(curr);
            res.insert(str);
        }

        if (i < 0 || j < 0 || i >= a.size() || j >= a[0].size() || vis[i][j] || m[str] == 0)
        {
            return;
        }

        vis[i][j] = 1;

        str += a[i][j];

        rec(i + 1, j, a);
        rec(i, j + 1, a);
        rec(i, j - 1, a);
        rec(i - 1, j, a);

        vis[i][j] = 0;

        str.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& a, vector<string>& words) {


        for (auto x : words)
        {
            string curr;

            toFound.insert(x);

            for (auto y : x)
            {
                curr += y;
                m[curr]++;
            }
        }

        m[""]++;

        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[0].size(); j++)
            {
                memset(vis, 0, sizeof(vis));
                rec(i, j, a);
            }
        }

        vector<string> ans;

        for (auto x : res)
        {
            ans.push_back(x);
        }

        return ans;
    }
};

----------------------------------------Problem:

Given a 2D character grid and a list of words, find all words that can be formed by traversing adjacent cells (up, down, left, right) in the grid.
Key Points:

Backtracking: Explores possible word combinations by recursively visiting valid cells and backtracking when necessary.
Data Structures: Uses unordered sets and a map for efficient lookups and tracking.
Pruning: Optimizes search by early termination when a word is found or when a prefix is no longer viable.
Code Breakdown:

Preprocessing:

toFound: Stores words to be found.
m: Maps prefixes to word counts, used for pruning.
findWords Function:

Iterates through all cells in the grid:
Initializes vis array for visited cells.
Calls rec function to explore words from each cell.
Constructs the final result vector ans.
rec Function (Backtracking):

Base Cases:
If a word is found, add it to res and update m and toFound.
If out of bounds, already visited, or prefix not viable, return.
Mark cell as visited.
Append character to str.
Recursively explore adjacent cells.
Unmark cell and backtrack (remove character from str).
Time and Space Complexity:

Time: O(M * N * W^2), where M is grid rows, N is grid columns, and W is the average word length.
Space: O(M * N) for vis array, O(W * W) for m and toFound sets, and O(W) for recursion stack depth.
