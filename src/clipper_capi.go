package clipper

/*

#cgo CXXFLAGS: -std=c++11 -stdlib=libc++
#cgo LDFLAGS: -lstdc++
#include  "./clipper_capi.hpp"

 */ 
import "C"
import (
	"unsafe"
)

type cgo_Polygon_T C.Polygon_T
type cgo_IntPoint_T C.IntPoint_T


func cgo_NewIntPoint_T(x int64, y int64) *cgo_IntPoint_T {
	point := C.NewIntPoint_T(C.longlong(x), C.longlong(y))
	return (*cgo_IntPoint_T)(point)
}

func cgo_DeleteIntPoint_T(point *cgo_IntPoint_T){
	C.DeleteIntPoint_T((*C.IntPoint_T)(point))
}

func cgo_NewPolygon_T(pointPtrList []*cgo_IntPoint_T) *cgo_Polygon_T {
	cgo_PolygonList := C.NewPolygon_T((**C.IntPoint_T)(unsafe.Pointer(&pointPtrList[0])), C.int(len(pointPtrList)))
	return (*cgo_Polygon_T)(cgo_PolygonList)
}

func cgo_NewEmptyPolygon_T() *cgo_Polygon_T {
	return (*cgo_Polygon_T)(C.NewEmptyPolygon_T())
}

func cgo_DeletePolygon_T(polygon *cgo_Polygon_T){
	C.DeletePolygon_T((*C.Polygon_T)(polygon))
}

func cgo_AppendIntPoint(polygon *cgo_Polygon_T, point *cgo_IntPoint_T){
	C.AppendIntPoint((*C.Polygon_T)(polygon), (*C.IntPoint_T)(point))
}

func cgo_EdgeNum(polygon *cgo_Polygon_T)  uint32{
	return uint32(C.EdgeNum((*C.Polygon_T)(polygon)))
}


func cgo_PolygonArea(polygon *cgo_Polygon_T) float64{
	return float64(C.PolygonArea((*C.Polygon_T)(polygon)))
}

func cgo_IntersectionRate(polygon1 *cgo_Polygon_T, polygon2 *cgo_Polygon_T) float64{
	return float64(C.IntersectionRate((*C.Polygon_T)(polygon1), (*C.Polygon_T)(polygon2)))
}