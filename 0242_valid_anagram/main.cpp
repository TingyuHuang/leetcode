class AlphabetToCountMapping {
	public:
		AlphabetToCountMapping(const std::string& s) {
			for (const auto &c : s) {
				auto it = _mapping.find(c);

				if (_mapping.cend() == it) {
					_mapping[c] = 0;
				} else {
					it->second += 1;
				}
			}
		}

		bool operator==(const AlphabetToCountMapping& m) {
			if (this->_mapping.size() != m._mapping.size()) {
				return false;
			}

			for (const auto &e : m._mapping) {
				auto it = this->_mapping.find(e.first);

				if (this->_mapping.cend() == it) {
					return false;
				}

				if (e.second != it->second) {
					return false;
				}
			}
			return true;
		}

	private:
		std::map<char, int> _mapping;
};

class Solution {
	public:
		bool isAnagram(string s, string t) {
			if (s.size() == 0 && t.size() == 0) {
				return true;
			}

			if (s.size() != t.size()) {
				return false;
			}

			return (AlphabetToCountMapping{s} == AlphabetToCountMapping{t});
		}
};
