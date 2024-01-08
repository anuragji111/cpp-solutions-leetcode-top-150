Statement 53) Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

 

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

---------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        stringstream ss(path);
        string dir;

        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") continue; // Ignore empty or '.'
            if (dir == "..") {
                if (!dirs.empty()) dirs.pop_back(); // Go up a level if possible
            } else {
                dirs.push_back(dir); // Add valid directory
            }
        }

        string canonicalPath;
        for (const string& dir : dirs) {
            canonicalPath += "/" + dir;
        }

        return canonicalPath.empty() ? "/" : canonicalPath; // Handle root case
    }
};

------------------------------------------------------------------------------------------------------
Explanation:

Splitting Directories: The code splits the path into directories using a vector to store them.
Handling Slashes: It processes each character, adding a directory to the vector when a slash is encountered.
Ignoring ".": It ignores "." directories as they represent the current directory.
Going Up a Level: When a ".." directory is encountered, it removes the last directory from the vector, effectively going up a level.
Constructing Simplified Path: It builds the simplified path by joining the directories with slashes, ensuring no trailing slash.
Handling Root Path: It returns "/" for an empty path, representing the root directory.
This code effectively handles various path scenarios and produces the expected simplified canonical paths in Unix-style file systems.
