class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
      int sumx1 = (square1[0] * 2) + square1[2];
      int sumx2 = (square2[0] * 2) + square2[2];
      int sumy1 = (square1[1] * 2) + square1[2];
      int sumy2 = (square2[1] * 2) + square2[2];
      vector<double> res(4, 0);
      // mid point = sumx1 / 2, sumy1 / 2; sumx2 / 2, sumy2 / 2
      double minx = std::min(square1[0], square2[0]);
      double miny = std::min(square1[1], square2[1]);
      double maxx = std::max(square1[0] + square1[2], square2[0] + square2[2]);
      double maxy = std::max(square1[1] + square1[2], square2[1] + square2[2]);

      if (sumx1 == sumx2) {
        res[0] = res[2] = sumx1 / 2.0;
        res[1] = miny;
        res[3] = maxy;
        return res;
      }
      if (sumy1 == sumy2) {
        res[1] = res[3] = sumy1 / 2.0;
        res[0] = minx;
        res[2] = maxx;
        return res;
      }
      // y = k x + b
      double k = (sumy2 - sumy1) * 1.0 / (sumx2 - sumx1);
      double b = sumy1  / 2.0 - k * sumx1 / 2.0;
      
      double resx1 = (miny - b) / k;
      double resx2 = (maxy - b) / k;
      double resy1 = k * minx + b;
      double resy2 = k * maxx + b;
      //cout << "k = " << k << ", sumy2 = " << sumy2 << ", sumy1 = " << sumy1 << endl;
      //for (int i = 0; i < res.size(); ++i) {
      //  cout << res[i] << " ";
      //}
      //cout << endl;

      res[0] = std::min(resx1, resx2);
      if (res[0] < minx) {
        res[0] = minx;
        res[1] = resy1;
      } else if (resx1 < resx2) {
        res[1] = miny;
      } else {
        res[1] = maxy;
      }
      res[2] = std::max(resx1, resx2);
      if (res[2] > maxx) {
        res[2] = maxx;
        res[3] = resy2;
      } else if (resx1 > resx2) {
        res[3] = miny;
      } else {
        res[3] = maxy;
      }
      return res;
    }
};
