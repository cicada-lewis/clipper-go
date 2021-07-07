#if __cplusplus
extern "C" {
#endif

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

#if __cplusplus
}
#endif

