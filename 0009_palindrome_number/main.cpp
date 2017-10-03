class Solution {
	public:
		bool isPalindrome(int x) {
			stringstream ss;
			string s;

			ss << x;
			ss >> s;

			size_t i = 0, j = s.size() - 1;

			while (i < j) {
				if (s[i++] != s[j--]) {
					return false;
				}
			}

			return true;
		}
};
