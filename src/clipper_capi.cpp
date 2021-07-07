
#include "./clipper.hpp"
#include "./clipper_capi.hpp"


struct Polygon_T : ClipperLib::Path{
    Polygon_T() : ClipperLib::Path(){}
    ~Polygon_T() {}
};
struct IntPoint_T : ClipperLib::IntPoint{
     IntPoint_T(signed long long x, signed long long y) : ClipperLib::IntPoint(x, y){}
     ~IntPoint_T() {}
};

IntPoint_T* NewIntPoint_T(signed long long x, signed long long y){
    auto intPoint = new ClipperLib::IntPoint(x, y);
    return  (IntPoint_T*)intPoint;
}

void DeleteIntPoint_T(IntPoint_T* point){
     delete point;
}

Polygon_T* NewPolygon_T(IntPoint_T* points[], int pointNum){
    auto polygon = new Polygon_T();
    for (int i=0; i < pointNum; i++){
        polygon->push_back(*points[i]);
    }
    return polygon;
}

Polygon_T* NewEmptyPolygon_T(){
    auto polygon = new Polygon_T();
    return polygon;
}

void DeletePolygon_T(Polygon_T* polygon){
    delete polygon;
}

void AppendIntPoint(Polygon_T* polygon, IntPoint_T* point){
    polygon->push_back(*point);
}

unsigned int EdgeNum(Polygon_T* polygon){
    return polygon->size();
}

double PolygonArea(Polygon_T* polygon){
    return std::abs(ClipperLib::Area(*polygon));
}

double IntersectionRate(Polygon_T* polygon1, Polygon_T* polygon2){

    ClipperLib::Clipper clipper1;
    ClipperLib::Path empty;
    clipper1.AddPath(*polygon1, ClipperLib::ptSubject, true);
    clipper1.AddPath(*polygon2, ClipperLib::ptClip, true);

    ClipperLib::Paths inter;
    clipper1.Execute(ClipperLib::ctIntersection, inter, ClipperLib::pftEvenOdd);
    double areaSum = 0;
    for(auto &single : inter){
        areaSum += ClipperLib::Area(single);
    }
    if (areaSum == 0)
        // 当两个图形不相交的时候，相交面积为0
        return areaSum;
    auto polygonArea = ClipperLib::Area(*polygon2);
    return std::abs(areaSum) / std::abs(polygonArea);
}






