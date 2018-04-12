class Solution {
	public:
		NestedInteger deserialize(string s) {
			if ('[' == s[0]) {
				NestedInteger ni;
				size_t depth = 0;
				std::string token;

				for (size_t i = 1; i < s.size() - 1; i++) {
					if ('[' == s[i]) {
						depth += 1;
					} else if (']' == s[i]) {
						depth -= 1;
					}

					if (0 == depth and ',' == s[i]) {
						ni.add(deserialize(token));
						token = "";
					} else {
						token += s[i];
					}
				}
				if (not token.empty()) {
					ni.add(deserialize(token));
				}
				return ni;
			} else {
				return stoi(s);
			}
		}
};
