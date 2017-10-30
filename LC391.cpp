class Solution {
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		if (rectangles.size() == 0 || rectangles[0].size() == 0) return false;
		int x1 = INT_MAX;
		int y1 = INT_MAX;
		int x2 = INT_MIN;
		int y2 = INT_MIN;
		unordered_set<string> points;
		int area = 0;
		for (int i = 0; i < rectangles.size(); i++) {
			x1 = min(x1, rectangles[i][0]);
			y1 = min(y1, rectangles[i][1]);
			x2 = max(x2, rectangles[i][2]);
			y2 = max(y2, rectangles[i][3]);
			string leftbottom = to_string(rectangles[i][0]) + " " + to_string(rectangles[i][1]);
			string lefttop = to_string(rectangles[i][0]) + " " + to_string(rectangles[i][3]);
			string rightbottom = to_string(rectangles[i][2]) + " " + to_string(rectangles[i][1]);
			string righttop = to_string(rectangles[i][2]) + " " + to_string(rectangles[i][3]);
			if (points.find(leftbottom) != points.end())
				points.erase(leftbottom);
			else
				points.insert(leftbottom);
			if (points.find(lefttop) != points.end())
				points.erase(lefttop);
			else
				points.insert(lefttop);
			if (points.find(rightbottom) != points.end())
				points.erase(rightbottom);
			else
				points.insert(rightbottom);
			if (points.find(righttop) != points.end())
				points.erase(righttop);
			else
				points.insert(righttop);
			area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
		}
		string leftbottom = to_string(x1) + " " + to_string(y1);
		string lefttop = to_string(x1) + " " + to_string(y2);
		string rightbottom = to_string(x2) + " " + to_string(y1);
		string righttop = to_string(x2) + " " + to_string(y2);
		if (points.size() == 4 && points.find(leftbottom) != points.end() && points.find(lefttop) != points.end()
			&& points.find(rightbottom) != points.end() && points.find(righttop) != points.end())
			return area == (y2 - y1) * (x2 - x1);
		return false;
	}
};