
#include "Point.hpp"
#include <iomanip>
Point  Point::moveTowards(Point &src, Point &target, double r) {
    if (r < 0)
        throw std::invalid_argument("");
    double dist = src.distance(target);
    if (dist < r)
        return target;
    double ratio = r / dist;
    double a = (target.y - src.y) /(target.x - src.x);
    double b = src.y - src.x * a;
    /// y = a * x + b -
    double ans_y, ans_x;
    if (target.y >= src.y)
    { /// target is higher then src
        ans_y = src.y + (target.y - src.y) * ratio;
        ans_x = (ans_y - b ) / a;
    }
    else  /// src is higher then target
    {
       ans_y = src.y - (src.y-target.y)*ratio;
       ans_x = (ans_y - b ) / a;
    }
    return Point(ans_x, ans_y);
}
///https://stackoverflow.com/questions/3748749/rounding-off-floats-with-ostringstream
double Point::distance(const Point &other) const {
     double dx = this->x - other.x;
    double dy = this->y - other.y;
    double  p= sqrt(pow((dx),2) + pow((dy),2));
    ostringstream oss;
    oss  << setprecision(5) << p;
    string r = oss.str();
    double d = stod(r);
    return d;


}


