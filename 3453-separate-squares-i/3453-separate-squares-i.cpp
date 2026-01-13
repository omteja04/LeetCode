class Solution {
public:
    pair<long double, long double> predicate(long double y, const vector<vector<int>> &squares) {
        long double areaAbove = 0.0, areaBelow = 0.0;

        for (const auto &info : squares) {
            long double xi = info[0];
            long double yi = info[1];
            long double h = info[2];
            long double topOfSquare = yi + h;

            if (y <= yi) { 
                areaAbove += h * h;
            } 
            else if (y >= topOfSquare) {  
                areaBelow += h * h;
            } 
            else {  
                long double abovePart = h * (topOfSquare - y);
                long double belowPart = h * (y - yi);
                areaAbove += abovePart;
                areaBelow += belowPart;
            }
        }

        return {areaAbove, areaBelow};
    }

    double separateSquares(vector<vector<int>> &squares) {
        int n = squares.size();

        double low = 0, high = 0;

        for (const auto& square : squares) {
            high = max(high, (double)(square[1] + square[2]));
        }

        double PRECISION = 1e-6;
        while (high - low > PRECISION) {  
            long double mid = low + (high - low) / 2;
            auto [above, below] = predicate(mid, squares);

            if (below < above) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
