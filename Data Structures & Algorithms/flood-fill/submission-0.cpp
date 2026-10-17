class Solution {
private:
    int n,m;
    void dfs(vector<vector<int>>& image, int i,int j,int org, int col){
        if( i<0 || j<0 || i>=n || j>=m || image[i][j] != org)
        return;
        image[i][j] = col;
        dfs(image,i+1,j,org,col);
        dfs(image,i,j+1,org,col);
        dfs(image,i-1,j,org,col);
        dfs(image,i,j-1,org,col);
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];
        if(org == color) return image;
        n = image.size();
        m = image[0].size();
        dfs(image,sr,sc,org,color);
        return image;
    }
};