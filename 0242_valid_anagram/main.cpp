class Solution {
	public:
		typedef std::map<char, int> CountCharMap;

		CountCharMap toMap(const string &s) {
			CountCharMap m;

			for (const auto &c : s) {
				auto it = m.find(c);

				if (m.cend() == it) {
					m[c] = 0;
				} else {
					it->second += 1;
				}
			}

			return m;
		}

		bool isAnagram(string s, string t) {
			if (s.size() == 0 && t.size() == 0) {
				return true;
			}

			if (s.size() != t.size()) {
				return false;
			}

			CountCharMap ms = toMap(s);
			CountCharMap mt = toMap(t);

			if (ms.size() != mt.size()) {
				return false;
			}

			for (const auto &e : ms) {
				auto mt_it = mt.find(e.first);

				if (mt.cend() == mt_it) {
					return false;
				}

				if (e.second != mt_it->second) {
					return false;
				}
			}

			return true;
		}
};
