class Solution {
	public:
		/**
		 *  Checking overflow
		 *
		 *  It's not overflowing if (INT_MAX >= x_reversed * 10 + val)
		 *  is true. which means ((INT_MAX - val) / 10 < x_reversed) is
		 *  true when it overflowing.
		 */
		bool is_overflow(const int x_reversed, const int val) {
			return ((std::numeric_limits<int>::max() - val) / 10 < x_reversed);
		}

		int reverse(int x) {
			auto negative = (x < 0);
			auto x_reversed = 0;

			if (0 == x) {
				return 0;
			}

			if (negative) {
				x = -x;
			}

			while (x != 0) {
				auto val = x % 10;

				if (is_overflow(x_reversed, val)) {
					return 0;
				} else {
					x /= 10;
					x_reversed = x_reversed * 10 + val;
				}
			}

			if (negative) {
				return -x_reversed;
			} else {
				return x_reversed;
			}
		}
};
