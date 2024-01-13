**Minimum Genetic Mutuation**

Problem Statement 96) A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
 

Constraints:

0 <= bank.length <= 10
startGene.length == endGene.length == bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

----------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> validGenes(bank.begin(), bank.end());
        if (!validGenes.count(end)) return -1;  // End gene not in bank

        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);

        int mutations = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                if (curr == end) return mutations;

                for (int j = 0; j < 8; j++) {
                    char original = curr[j];
                    for (char base : {'A', 'C', 'G', 'T'}) {
                        curr[j] = base;
                        if (validGenes.count(curr) && !visited.count(curr)) {
                            q.push(curr);
                            visited.insert(curr);
                        }
                    }
                    curr[j] = original;  // Restore original gene
                }
            }
            mutations++;
        }

        return -1;  // No valid mutation path found
    }
};

--------------Problem:

Given a starting gene, an ending gene, and a bank of valid genes, find the minimum number of single-character mutations (A -> C, C -> G, G -> T, T -> A) needed to transform the starting gene into the ending gene, using only genes from the bank.
Key Points:

BFS Exploration: BFS systematically explores reachable genes, expanding one level at a time, tracking the number of mutations.
Valid Gene Set: An unordered_set efficiently stores valid genes from the bank for quick lookups.
Visited Tracking: A visited set prevents revisiting genes, avoiding cycles.
Explanation:

Initialization:

Creates a validGenes set for efficient lookups.
Checks if the ending gene is reachable (exists in the bank).
Initializes a queue for BFS and a visited set.
BFS Algorithm:

Enqueues the starting gene.
While the queue is not empty:
Processes the current level of genes:
Iterates through the genes in the current queue.
If the current gene matches the ending gene, return the number of mutations.
Explores potential mutations for each character in the current gene:
Temporarily modifies the character to all possible bases.
If the modified gene is valid and unvisited:
Enqueues it for further exploration.
Marks it as visited.
Increments the mutation count for the next level.
Result:

If the loop completes without finding a path, returns -1 (no valid path exists).
Time Complexity:

O(N * M), where N is the number of genes in the bank and M is the length of each gene, due to BFS exploring potential mutations for each character in each gene.
Space Complexity:

O(N) for the queue, visited set, and valid genes set, assuming a balanced gene bank.
