#include <iostream>
#include <vector>
using namespace std;

class Point
{
    double _x;
    double _y;
public:
    // Constructor with parameters
    Point(double x = 0.0, double y = 0.0)
        : _x{x}, _y{y} {}

    // Move a point
    void move(double dx, double dy) {
        _x += dx;
        _y += dy;
    }

    // Print point to console
    void print(bool nl = true) {
        cout << "(" << _x << ", " << _y << ")";
        if (nl) {
            cout << endl;
        }
    }
};

class Polygonline {
    vector<Point> _points;
public:
    // Default constructor
    Polygonline() {}

    // Constructor with a point
    Polygonline(Point& p)
        : _points{p} {}

    // Print the polygonline points
    void print(bool nl = true);

    // Add a point at the end of the polygonline
    Polygonline& add_point(Point p) {
        _points.push_back(p);
        return *this; // damit man ".add_point(p1).add_point(p2)"
    }

    // Append another polygonline
    // kopiert keine reference  
    void append_polygonline(Polygonline& pl) {
        for (const auto& point : pl._points) {
            _points.push_back(point);
        }
    }

    // Move the entire polygonline
    void move(double dx, double dy) {
        for (auto& point : _points) {
            point.move(dx, dy);
        }
    }
};

void Polygonline::print(bool nl) {
    // If there are no points, print the "empty" format
    if (_points.empty()) {
        cout << "||";
        if (nl) {
            cout << endl;
        }
        return;
    }

    // Print starting delimiter
    cout << "|";

    // Print each point, separated by " - "
    for (vector<Point>::size_type i = 0; i < _points.size(); ++i) {
        _points[i].print(false);  // Print the point without newline
        if (i < _points.size() - 1) {
            cout << " - ";  // Add separator between points
        }
    }

    // Print closing delimiter
    cout << "|";

    // If nl is true, print an additional newline
    if (nl) {
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    Point p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
    Polygonline l1;
    Polygonline l2(p3);

    // Ausgabe 1:
    cout << "Ausgabe 1:" << endl;
    l1.print();
    l2.print();

    // Add points to both polygons
    l1.add_point(p1).add_point(p2);
    l2.add_point(p4).add_point(p5);

    // Ausgabe 2:
    cout << "Ausgabe 2:" << endl;
    l1.print();
    l2.print();

    // Move point p2
    p2.move(0.5, 0.5);
    cout << "Ausgabe 3:" << endl;
    p2.print();   // Print moved point
    l1.print();
    l2.print();

    // Append l2 to l1
    l1.append_polygonline(l2);
    cout << "Ausgabe 4:" << endl;
    l1.print();
    l2.print();

    // Move all points in l1
    l1.move(0, 0.5);
    cout << "Ausgabe 5:" << endl;
    l1.print();
    l2.print();

    return 0;
}

