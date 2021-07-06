


/*
    // 交叉面积除以最小面积
static float IntersectionRate(const mylanms::Polygon &a, const mylanms::Polygon &b) {
    MyClipperLib::Clipper clpr1;
    MyClipperLib::Path empty;
    clpr1.AddPath(a.poly, MyClipperLib::ptSubject, true);
    clpr1.AddPath(b.poly, MyClipperLib::ptClip, true);

    MyClipperLib::Paths inter;
    clpr1.Execute(MyClipperLib::ctIntersection, inter, MyClipperLib::pftEvenOdd);
    auto a_area = mylanms::paths_area(inter);


    MyClipperLib::Clipper clpr2;

    clpr2.AddPath(b.poly, MyClipperLib::ptSubject, true);
    clpr2.AddPath(empty, MyClipperLib::ptClip, true);
    MyClipperLib::Paths uni;
    clpr2.Execute(MyClipperLib::ctUnion, uni, MyClipperLib::pftEvenOdd);
    auto uni_area = mylanms::paths_area(uni);

    printf("a_area = %f b_area = %f\n", a_area, uni_area);

    return std::abs(a_area) / std::max(std::abs(uni_area), 1.0f);
}

float IntersectionRate(const vector<::Point>& target_a, const vector<::Point>& target_b) {

  mylanms::Polygon poly0;
  mylanms::Polygon poly1;

  for (const ::Point& point : target_a) {
   MyClipperLib::IntPoint point0((MyClipperLib::cInt)point.x, (MyClipperLib::cInt)point.y);
   poly0.poly.push_back(point0);
  }

  for (const ::Point& point : target_b) {
   MyClipperLib::IntPoint point1((MyClipperLib::cInt)point.x, (MyClipperLib::cInt)point.y);
   poly1.poly.push_back(point1);
  }

  return IntersectionRate(poly0, poly1);
}
*/


#include "./clipper.hpp"

typedef struct Polygon_T Polygon_T;
typedef struct IntPoint_T IntPoint_T;

IntPoint_T* NewIntPoint_T(signed long long x, signed long long y);
void DeleteIntPoint_T(IntPoint_T* point);

Polygon_T* NewPolygon_T(IntPoint_T* points[], int pointNum);

Polygon_T* NewEmptyPolygon_T();

void DeletePolygon_T(Polygon_T* polygon);

void AppendIntPoint(Polygon_T* polygon, IntPoint_T* point);

unsigned int EdgeNum(Polygon_T* polygon);

double PolygonArea(Polygon_T* polygon);

//
double IntersectionRate(Polygon_T* polygon1, Polygon_T* polygon2);





