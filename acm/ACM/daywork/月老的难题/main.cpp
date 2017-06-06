/*#include<iostream>
#include<cstring>
using namespace std;
int map[505][505];
int visit[505],flag[505];
int n,m;
bool dfs(int a)
{
    for(int i=1; i<=n; i++)
    {
        if(map[a][i]&&!visit[i])
        {
            visit[i]=1;
            if(flag[i]==0||dfs(flag[i]))
            {
                flag[i]=a;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int T;
    cin>>T;
    while(T--)

    {
        cin>>n>>m;
        memset(map,0,sizeof(map));
        for(int i=1; i<=m; i++)
        {
            int x,y;
            cin>>x>>y;
            map[x][y]=1;
        }
        memset(flag,0,sizeof(flag));
        int result=0;
        for(int i=1; i<=n; i++)
        {
            memset(visit,0,sizeof(visit));
            if(dfs(i))result++;
        }
        cout<<result<<endl;
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis[505];    //vis[i]��¼ĳ�����ʱ�Ƿ��ѿ���Ů��i
int flag[505];    //flag[i]��¼Ů��i�ĵ�ǰ�к�
vector<int> e[505];
bool dfs(int x)
{
    for(int i=0; i<e[x].size(); i++)
    {
        int g=e[x][i];
        if(!vis[g])
        {
            vis[g]=1;
            if(flag[g]==0||dfs(flag[g]))    //��Ů����û��Ʊ�����Ů��ԭ������Ʊ��������ȥ�ұ��Ů��
            {
                flag[g]=x;        //�к�x��Ů��gȷ��������ϵ
                return true;    //�к�x�ɹ��ҵ�Ů��
            }
        }
    }
    return false;    //�к�xû���ҵ�ŮƱ T_T
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) e[i].clear();//�������к�û�п�ѡ�����
        memset(flag,0,sizeof(flag));    //0���ޣ�������Ů��Ϊ����
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            e[x].push_back(y);    //���к�x����һ����ѡ��Ů��y
        }
        int num=0;    //��ʼ���ɹ������
        for(int i=1; i<=n; i++)        //�ӵ�һ���к���ʼ�����������
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i)) num++;    //�к�i�ɹ��ҵ�Ů���ѣ��ɹ������++
        }
        printf("%d\n",num);
    }
}


