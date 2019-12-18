/*
类型：二维数组上的BFS，记录下标+剩余步骤数
题目：1293. 网格中的最短路径 
给你一个 m * n 的网格，其中每个单元格不是 0（空）就是 1（障碍物）。每一步，您都可以在空白单元格中上、下、左、右移动。
如果您 最多 可以消除 k 个障碍物，请找出从左上角 (0, 0) 到右下角 (m-1, n-1) 的最短路径，并返回通过该路径所需的步数。如果找不到这样的路径，则返回 -1。
示例 1：
输入： 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
输出：6
解释：
不消除任何障碍的最短路径是 10。
消除位置 (3,2) 处的障碍后，最短路径是 6 。该路径是 (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
示例 2：
输入：
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
输出：-1
解释：
我们至少需要消除两个障碍才能找到这样的路径。
提示：
grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] == 0 or 1
grid[0][0] == grid[m-1][n-1] == 0
*/
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        m=grid.size(); n=grid[0].size();
        if(m==1&&n==1) return 0;
        if(k>=m+n-3) return m+n-2;  //直接通过下下下右右右可以到达右下角，最多m+n-3个格子间隔开，当k大于等于这个值的时候可以取此最短路径
        queue<Node> q;
        q.emplace(0,0,k);   //emplace()   c++11g相当于insert，直接将三个参数放进去就可以了
        int cnt,nx,ny,tmpk,dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        int used[43][43],STEP=0,ans=INT_MAX;
        memset(used,-1,sizeof(used));
        while(!q.empty())
        {
            cnt=q.size();
            STEP++;
            while(cnt--){  //广度优先搜索
                Node tmpNode = q.front();
                q.pop();
                tmpk = tmpNode.steps - grid[tmpNode.x][tmpNode.y];
                if(tmpk>=0)
                {
                    for(int i=0;i<4;i++){
                        nx=tmpNode.x+dir[i][0];
                        ny=tmpNode.y+dir[i][1];
                        if(nx>=0&&nx<m && ny>=0&&ny<n && (used[nx][ny]==-1 || tmpk>used[nx][ny]))
                        {   //used为-1表示是第一次访问，是其他数字表示上次访问到此位置的时候还剩余的步数
                            if(nx==m-1&&ny==n-1){
                                ans=min(ans,STEP);
                            }else{
                                used[nx][ny]=tmpk;
                                q.emplace(nx,ny,tmpk);
                            }
                        }
                    }
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
private:
    int m,n;
    struct Node{
        int x,y,steps;
        Node(int _x,int _y,int _steps): x(_x),y(_y),steps(_steps) {} 
    };
};
