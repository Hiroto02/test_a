#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//四方向ベクトル
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int main()
{
	int R,C;
	cin>>R>>C;
	//マップの情報を格納する配列
	vector<string> field(R);
	//訪問済みかどうかを格納する配列
	//訪問済みなら最短距離を格納
	vector<vector<int>> dist(R,vector<int>(C,-1)); 
	int sx,sy,gx,gy;
	cin>>sy>>sx;
	cin>>gy>>gx;
	dist[sy][sx]=0;
	for(int i=0;i<R;i++)
	{
		cin>>field[i];
	}
	queue<pair<int,int>> que;
	//スタートの位置にプッシュ
	//make_pair:引数の値を持つpairを生成する
	que.push(make_pair(sy,sx));
	//キューの中身が空になるまでループ
	while(!que.empty())
	{
		//キューの中身を取り出す
		//取り出したキューの値から四方向を見る
		//探索したところが通れてかつ未探索なら現在位置の最短経路の値を更新
		//未探索の座標をキューにプッシュ
		//ここでキューの値をとりだす(キューの中身は残ったまま)
		//pair<int,int> ==auto
		pair<int,int> pos=que.front();
		int now_x=pos.first;
		int now_y=pos.second;
		//ここでキューの一番下の値がなくなる
		que.pop();
		for(int dir=0;dir<4;dir++)
		{
			int next_x=now_x+dx[dir];
			int next_y=now_y+dy[dir];
			//壁,場外ならスルー
			if(field[next_y][next_x]=='#') continue;
			if(next_x>50||next_x<0||next_y>50||next_y<0) continue;
			if(dist[next_y][next_x]==-1)
			{
				//キューに次の探索する値を格納
				que.push(make_pair(next_y,next_x));
				//探索したので最短経路を確定
				dist[next_y][next_x]+=dist[now_y][now_x]+1;
			}
		}
	}
	cout<<dist[gy][gx]<<endl;
	return 0;
}
//標準エラー出力
In file included from /usr/include/c++/5/ext/alloc_traits.h:36:0,
                 from /usr/include/c++/5/bits/basic_string.h:40,
                 from /usr/include/c++/5/string:52,
                 from /usr/include/c++/5/bits/locale_classes.h:40,
                 from /usr/include/c++/5/bits/ios_base.h:41,
                 from /usr/include/c++/5/ios:42,
                 from /usr/include/c++/5/istream:38,
                 from /usr/include/c++/5/sstream:38,
                 from /usr/include/c++/5/complex:45,
                 from /usr/include/c++/5/ccomplex:38,
                 from /usr/include/x86_64-linux-gnu/c++/5/bits/stdc++.h:52,
                 from ./Main.cpp:1:
/usr/include/c++/5/bits/alloc_traits.h: In instantiation of ‘struct std::allocator_traits<int>’:
/usr/include/c++/5/ext/alloc_traits.h:95:10:   required from ‘struct __gnu_cxx::__alloc_traits<int>’
/usr/include/c++/5/bits/stl_vector.h:75:28:   required from ‘struct std::_Vector_base<std::vector<int>, int>’
/usr/include/c++/5/bits/stl_vec...