#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    double x, y, z;

    Point(double x, double y, double z) : x(x), y(y), z(z) {}
};

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

bool compareZ(const Point& a, const Point& b) {
    return a.z < b.z;
}

double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

pair<Point, Point> bruteForce(vector<Point>& points, int start, int end) {
    double minDist = numeric_limits<double>::infinity();
    pair<Point, Point> minPair = { Point(0, 0, 0), Point(0, 0, 0) };

    for (int i = start; i < end; ++i) {
        for (int j = i + 1; j < end; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
                minPair = { points[i], points[j] };
            }
        }
    }

    return minPair;
}

pair<Point, Point> closestPair(vector<Point>& points, int start, int end) {
    int n = end - start;

    if (n <= 3) {
        return bruteForce(points, start, end);
    }

    int mid = (start + end) / 2;
    pair<Point, Point> leftPair = closestPair(points, start, mid);
    pair<Point, Point> rightPair = closestPair(points, mid, end);

    double delta = min(distance(leftPair.first, leftPair.second), distance(rightPair.first, rightPair.second));

    vector<Point> strip;
    for (int i = start; i < end; ++i) {
        if (abs(points[i].z - points[mid].z) < delta) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < delta; ++j) {
            double dist = distance(strip[i], strip[j]);
            if (dist < delta) {
                delta = dist;
                leftPair = { strip[i], strip[j] };
            }
        }
    }

    return leftPair;
}

int main() {
    vector<Point> points = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
    sort(points.begin(), points.end(), compareZ);  // Sort points with respect to the z-axis

    pair<Point, Point> result = closestPair(points, 0, points.size());

    cout << "Closest pair: (" << result.first.x << ", " << result.first.y << ", " << result.first.z << ") and ("
        << result.second.x << ", " << result.second.y << ", " << result.second.z << ") with distance: "
        << distance(result.first, result.second) << endl;

    return 0;
}