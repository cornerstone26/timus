#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;

const int maxx = 1e5 + 100;
struct node {
	int l, r;
	bool operator<(const node& a)const {
		return r > a.r;
	}
}p[maxx];
int n, m;

inline bool cmp(node a, node b)
{
	return a.l < b.l;
}
int main()
{
	scanf("%d", &m);
	n = 0;
	int x, y;
	while (scanf("%d%d", &x, &y))
	{
		if (x == 0 && y == 0) break;
		p[++n].l = x;p[n].r = y;
	}
	sort(p + 1, p + 1 + n);
	int s = 0, e = m;
	vector<node> q;
	int flag = 1;
	while (s < e && flag)
	{
		flag = 0;
		for (int i = 1;i <= n;i++)
		{
			if (p[i].l <= s && s < p[i].r)
			{
				s = p[i].r;
				q.push_back(p[i]);
				flag = 1;
				break;
			}
		}
	}
	if (s < e) printf("No solution\n");
	else
	{
		printf("%d\n", q.size());
		sort(q.begin(), q.end(), cmp);
		for (int i = 0;i < q.size();i++) printf("%d %d\n", q[i].l, q[i].r);
	}
	return 0;
}


#include<iostream>
#include<math.h>
using namespace std;
struct node
{
    int l, r;
} a[100001];

bool cmp(node a, node b)
{
    return a.l < b.l;
}
int main()
{
    int m, c[100001];
    while (scanf("%d", &m) != EOF)
    {
        int x, y, k = 0, cont = 0, num = 0, p = 0, flag = 0, ans = 0, i;
        while (scanf("%d%d", &x, &y) && !(x == 0 && y == 0))
        {
            a[k].l = x;
            a[k].r = y;
            k++;
        }
        sort(a, a + k, cmp);
        for (i = 0; ;i++)
        {
            if (cont >= m)
            {
                break;
            }
            int ending = 0, temp = 0;
            while (num < k && a[num].l <= cont)
            {
                if (a[num].r > ending)
                {
                    ending = a[num].r;
                    temp = num;
                }
                num++;
            }
            if (ending == 0)
            {
                flag = 1;
                break;
            }
            cont = ending;
            c[temp] = 1;
            ans++;
        }
        if (flag)
        {
            cout << "No solution" << endl;

        }
        else
        {
            cout << ans << endl;
            for (i = 0;i < k;i++)
            {
                if (c[i])
                {
                    cout << a[i].l << ' ' << a[i].r << endl;
                }
            }
            cout << endl;
        }
    }
    return 0;
}