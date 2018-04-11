class Solution {
	public:
		int numSquares(int n) {
			auto perfectSquares = std::vector<int>(n + 1, std::numeric_limits<int>::max());

			perfectSquares[0] = 0;
			for (size_t i = 0; i <= n; i++) {
				for (size_t j = 1; i + j * j <= n; j++) {
					auto k = i + j * j;
					if (perfectSquares[k] > perfectSquares[i] + 1) {
						perfectSquares[k] = perfectSquares[i] + 1;
						if (k == n and perfectSquares[k] <= 2) {
							return perfectSquares[n];
						}
					}

				}
			}
			return perfectSquares[n];
		}
};
