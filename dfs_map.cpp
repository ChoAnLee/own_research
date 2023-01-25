#include <bits/std++.h>
#define N 100
using namespace std;

int map[N][N], visited[N][N]={0};
typedef pair<int, int> p;
int n,m,found=0;
deque<p> path; // or list

void dfs(int x, int y){
	if (found==1) return; //last step of terminate the recursion of this function
	visited[x][y]=1;
	path.push_back(make_pair(x,y));
	if (x==n-1 && y==m-1){
		found=1;
		cout<<"Path: ";
		while(!path.empty()){
			cout<<"("<<path.front().first<<","<<path.front().second<<")";
			path.pop_front();
		}
		cout<<endl;
		return;
	}
	if (x+1<n && visited[x+1][y]==0 && map[x+1][y]==0){
		dfs(x+1,y);
		path.pop_back(); // in case of wrong way of dfs be recorded
	}
	if (y+1<m && visited[x][y+1]==0 && map[x][y+1]==0){
		dfs(x,y+1);
		path.pop_back(); // in case of wrong way of dfs be recorded
	}
	if (x-1>=0 && visited[x-1][y]==0 && map[x-1][y]==0){
		dfs(x-1,y);
		path.pop_back(); // in case of wrong way of dfs be recorded
	}
	if (y-1>=0 && visited[x][y-1]==0 && map[x][y-1]==0){
		dfs(x,y-1);
		path.pop_back(); // in case of wrong way of dfs be recorded
	}
}

int main(){
	cin>>n>>m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin>>map[i][j];
	dfs(0,0);
	if (found==0){
		cout<<"No routes accessible.\n";
	}	
	return 0;
} 
