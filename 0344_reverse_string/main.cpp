class Solution {
	public:
		string reverseString(string s) {
			for (size_t i = 0; i < s.size() / 2; i++) {
				swap(s[i], s[s.size() - 1 - i]);
			}
			return s;
		}
	private:
		void swap(char& c1, char& c2) {
			auto tmp = c1;
			c1 = c2;
			c2 = tmp;
		}
};
