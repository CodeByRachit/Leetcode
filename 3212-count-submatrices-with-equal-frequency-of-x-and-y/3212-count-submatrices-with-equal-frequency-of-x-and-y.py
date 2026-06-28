class Solution(object):
    def numberOfSubmatrices(self, grid):
        m, n = len(grid), len(grid[0])
        dpX = [0] * n
        dpY = [0] * n
        count = 0
        for i in range(m):
            rowX = 0
            rowY = 0
            for j in range(n):
                if grid[i][j] == 'X':
                    rowX += 1
                elif grid[i][j] == 'Y':
                    rowY += 1
                dpX[j] += rowX
                dpY[j] += rowY
                if dpX[j] > 0 and dpX[j] == dpY[j]:
                    count += 1
        return count