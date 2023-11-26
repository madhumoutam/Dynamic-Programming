#include <iostream>
#include <vector>

std::string longestCommonSubstring(const std::string& str1, const std::string& str2, int& length) {
    int m = str1.length();
    int n = str2.length();

   
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    int maxLength = 0;
    int endIndex = 0;

    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1; 
                }
            }
        }
    }

    std::string result = str1.substr(endIndex - maxLength + 1, maxLength);
    length = maxLength;

    return result;
}

int main() {
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::cin >> str1;
    std::cout << "Enter the second string: ";
    std::cin >> str2;

    int length;
    std::string commonSubstring = longestCommonSubstring(str1, str2, length);

    std::cout << "Longest Common Substring: " << commonSubstring << std::endl;
    std::cout << "Length of the Longest Common Substring: " << length << std::endl;

    return 0;
}

