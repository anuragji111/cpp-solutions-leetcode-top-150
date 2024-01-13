**Word Ladder**

Problem Statement 97) A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.

-------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); // Store valid words
        if (!wordSet.count(endWord)) return 0; // End word not in wordList

        queue<string> q;
        q.push(beginWord);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) return level;

                for (int j = 0; j < curr.size(); j++) {
                    char original = curr[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        curr[j] = c;
                        if (wordSet.count(curr)) {
                            q.push(curr);
                            wordSet.erase(curr); // Remove to avoid revisiting
                        }
                    }
                    curr[j] = original;
                }
            }
            level++;
        }

        return 0; // No transformation sequence found
    }
};

--------------Problem:

Given a starting word, an ending word, and a dictionary of valid words, find the shortest sequence of intermediate words that transforms the starting word into the ending word, where each intermediate word differs from the previous one by a single letter.
Key Points:

BFS Exploration: BFS systematically explores reachable words, expanding one level at a time, tracking the number of transformations.
Word Set: An unordered_set efficiently stores valid words from the dictionary for quick lookups and removal of visited words.
Character Substitution: The code generates potential transformations by substituting each character in the current word with all possible letters.
Explanation:

Initialization:

Creates a wordSet set for efficient lookups and removal.
Checks if the ending word is reachable (exists in the dictionary).
Initializes a queue for BFS and sets the starting level to 1.
BFS Algorithm:

Enqueues the starting word.
While the queue is not empty:
Processes the current level of words:
Iterates through the words in the current queue.
If the current word matches the ending word, returns the number of transformations (levels).
Explores potential transformations for each character in the current word:
Temporarily modifies the character to all possible letters.
If the modified word is valid and still in the word set:
Enqueues it for further exploration.
Removes it from the word set to avoid revisiting.
Increments the transformation count for the next level.
Result:

If the loop completes without finding a path, returns 0 (no valid transformation sequence exists).
Time Complexity:

O(N * M * 26), where N is the number of words in the dictionary, M is the length of each word, and 26 is the number of possible character substitutions.
Space Complexity:

O(N) for the queue, word set, and the recursion stack for character substitutions.
