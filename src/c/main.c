//
// Created by cicada on 2021/7/6.
//

#include <stdio.h>

#include "clipper.h"

int main(){
    IntPoint_T* points[4];
    points[0] = NewIntPoint_T(3, 0);
    points[1] = NewIntPoint_T(0, 0);
    points[2] = NewIntPoint_T(0, 3);
    struct Polygon_T *polygon = NewPolygon_T(points, 3);
    printf("%f\n", PolygonArea(polygon));

    // 计算相交度
    points[0] = NewIntPoint_T(0, 0);
    points[1] = NewIntPoint_T(0, 2);
    points[2] = NewIntPoint_T(2, 2);
    points[3] = NewIntPoint_T(2,0);
    struct Polygon_T *rect1 = NewPolygon_T(points, 4);
    struct Polygon_T *rect2 = NewEmptyPolygon_T();
    AppendIntPoint(rect2, NewIntPoint_T(1, -1));
    AppendIntPoint(rect2, NewIntPoint_T(1, 1));
    AppendIntPoint(rect2, NewIntPoint_T(3, 1));
    AppendIntPoint(rect2, NewIntPoint_T(3, -1));
    auto res = IntersectionRate(rect1, rect2);
    printf("%f\n edgeNum: %d", res, EdgeNum(rect2));
    DeletePolygon_T(rect2);
    DeletePolygon_T(rect1);
    return 0;
}