class Solution {
	public:
		bool addDigit(int& number, int digit) {
			if ((std::numeric_limits<int>::max() - digit) / 10 < number) {
				number = std::numeric_limits<int>::max();
				return false;
			} else {
				number = number * 10 + digit;
				return true;
			}
		}

		bool minusDigit(int& number, int digit) {
			if ((std::numeric_limits<int>::min() + digit) / 10 > number) {
				number = std::numeric_limits<int>::min();
				return false;
			} else {
				number = number * 10 - digit;
				return true;
			}
		}

		int myAtoi(string str) {
			using HandleDigit = bool (Solution::*)(int& number, int digit);

			int number = 0;
			size_t i = 0;
			HandleDigit handleDigit = nullptr;

			while (std::isspace(str[i])) i++;

			if ('+' == str[i]) {
				handleDigit = &Solution::addDigit;
			} else if ('-' == str[i]) {
				handleDigit = &Solution::minusDigit;
			} else if (isdigit(str[i])) {
				number = (str[i] - '0');
				handleDigit = &Solution::addDigit;
			} else {
				return 0;
			}

			while (std::isdigit(str[++i])) {
				if (!(this->*handleDigit)(number, str[i] - '0')) {
					break;
				}
			}

			return number;
		}
};
