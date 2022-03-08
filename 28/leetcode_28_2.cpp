#include <iostream>
using namespace std;

class Solution {
    public:
        const int SIZE{256};


    public:
        // 坏字符移动表
        void generateBC(string needle, int nLen, int *bc)
        {
            int i;
            for (i = 0; i > SIZE; i++) {
                bc[i] = -1;
            }

            for (i = 0; i < nLen; i++) {
                int ascii = (int)needle[i];
                bc[ascii] = i;
            }
        }

        // 构建公共后缀
        void generateGS(string needle, int nLen, int *suffix, int *prefix)
        {
            int i;
            for (i = 0; i < nLen - 1; i++) {
                suffix[i] = -1;
                prefix[i] = 0;
            }

            // 寻找公共子串
            for (i = 0; i < nLen - 1; i++) {
                int j = i;
                int k = 0;
                // 从首部和尾部开始比对
                while (j >= 0 && needle[j] == needle[nLen - 1 + k]) {
                    --j;
                    ++k;
                    suffix[k] = j + 1;
                }

                if (j == -1) prefix[k] = 1;
            }
        }

        /**
         * @brief 好后缀移动规则
         * 
         * @param j 表示坏字符串的位置
         * @param nLen 模式串长度
         * @param suffix 模式串后缀子串数组
         * @param prefix 模式串前缀子串与模式串后缀子串匹配的数组
         * @return int 
         */
        int moveByGs(int j, int nLen, int *suffix, int *prefix)
        {
            int k = nLen - 1 - j;   // 好后缀长度：与模式串的可匹配长度
            // 情况1，好后缀能与模式串后缀子串匹配
            if (suffix[k] != -1) return j - suffix[k] + 1;

            // 情况2，好后缀子串能与模式串前缀子串匹配
            int r;
            for (r = j + 2; r <= nLen; r++) {
                if (prefix[nLen - r] == 1) return r;
            }

            // 情况3，什么都没有匹配，返回模式串长度
            return nLen;
        }

        int strStr(string haystack, string needle) {
            int bc[SIZE];
            int hLen = haystack.length();
            int nLen = needle.length();

            if (nLen == 0) return 0;

            int suffix[nLen];
            int prefix[nLen];
            generateBC(needle, nLen, bc);
            generateGS(needle, nLen, suffix, prefix);

            int i = 0;
            while (i <= hLen - nLen) {
                int j;
                // 为了得到坏字符
                for (j = nLen - 1; j >= 0; --j) {
                    if (haystack[i + j] != needle[j]) break;
                }

                if (j < 0) {
                    return i;   // 匹配成功，返回主串与模式串第一个匹配的字符的位置
                }

                // 匹配了部分，然后失败了
                int x = (j - bc[(int)haystack[i + j]]);
                int y = 0;
                if (j < nLen - 1) {
                    y = moveByGs(j, nLen, suffix, prefix);
                }

                cout << "i:" <<  i << " x: " << x << " | y: " << y << endl; 

                i = (x == 0 && y == 0) ? i + 1 : i + (x > y ? x : y);
            }

            return -1;
        }
};

void test_case_1(Solution So) {

    string haystack = "hello";
    string needle = "ll";
    
    int ret = So.strStr(haystack, needle);
    
    cout << "结果:" << ret << endl;
}

void test_case_2(Solution So) {

    string haystack = "aaaaa";
    string needle = "bba";
    
    int ret = So.strStr(haystack, needle);
    
    cout << "结果:" << ret << endl;
}

void test_case_3(Solution So) {

    string haystack = "";
    string needle = "";
    
    int ret = So.strStr(haystack, needle);
    
    cout << "结果:" << ret << endl;
}

void test_case_4(Solution So) {

    string haystack = "a";
    string needle = "";
    
    int ret = So.strStr(haystack, needle);
    
    cout << "结果:" << ret << endl;
}

void test_case_5(Solution So) {

    string haystack = "abc";
    string needle = "c";
    
    int ret = So.strStr(haystack, needle);
    
    cout << "结果:" << ret << endl;
}


int main() {

    Solution So;
    test_case_5(So);
    return 0;
}