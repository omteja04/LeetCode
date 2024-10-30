class Solution {
    private boolean isSameSlope(int x1, int x2, int y1, int y2) {
        return ((x1 * y2) == (x2 * y1));
    }
    private boolean isSameDirection(int x1, int x2, int y1, int y2) {
        if((x1 * x2) < 0) return false;
        if((y1 * y2) < 0) return false;
        return true;
    }


    public int minMovesToCaptureTheQueen(int xRook, int yRook, int xBishop, int yBishop, int xQueen, int yQueen) {
        // a, b -> rook
        // c, d -> bishop
        // e, f -> queen
        if(xQueen == xRook) {
            if((xRook == xBishop) && (((yRook > yBishop) && (yQueen < yBishop)) || ((yRook < yBishop) && (yQueen > yBishop)))) {
                return 2;
            } return 1;
        }

        if(yQueen == yRook) {
            if((yRook == yBishop) && (((xRook > xBishop) && (xQueen < xBishop)) || ((xRook < xBishop) && (xQueen > xBishop)))) {
                return 2;
            } return 1;
        }

        int dxQ2B = xQueen - xBishop;
        int dyQ2B = yQueen - yBishop;
        if(Math.abs(dxQ2B) == Math.abs(dyQ2B)) {
            int dxR2B = xRook - xBishop;
            int dyR2B = yRook - yBishop;

            if(isSameSlope(dxQ2B, dxR2B,dyQ2B, dyR2B) && isSameDirection(dxQ2B, dxR2B,dyQ2B, dyR2B) && (Math.abs(dxQ2B) > Math.abs(dxR2B)) && (Math.abs(dyQ2B) > Math.abs(dyR2B))) return 2;
            return 1;
        }
        return 2;

    }
}