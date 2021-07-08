package clipper_test

import (
	clipper "git.querycap.com/tools/clipper-go/src"
	"github.com/stretchr/testify/require"
	"testing"
)

func TestPolygon(t *testing.T) {
	var intPointList []*clipper.IntPoint
	intPointList = append(intPointList, clipper.NewIntPoint(0, 0))
	intPointList = append(intPointList, clipper.NewIntPoint(0, 2))
	intPointList = append(intPointList, clipper.NewIntPoint(2, 2))
	intPointList = append(intPointList, clipper.NewIntPoint(2, 0))
	rect1 := clipper.NewPolygon(intPointList)
	rect2 := clipper.NewEmptyPolygon()
	rect2.AppendIntPoint(clipper.NewIntPoint(1, -1))
	rect2.AppendIntPoint(clipper.NewIntPoint(1, 1))
	rect2.AppendIntPoint(clipper.NewIntPoint(3, 1))
	rect2.AppendIntPoint(clipper.NewIntPoint(3, -1))
	require.Equal(t,  uint32(4), rect1.EdgeNum())
	require.Equal(t, float64(4), rect1.Area())
	require.Equal(t, 0.25, rect1.IntersectionRate(rect2))
	rect1.Delete()
	rect2.Delete()
}


