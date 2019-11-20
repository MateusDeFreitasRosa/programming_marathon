#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,n;
    int xi,yi,ni;
    scanf("%d %d %d",&x,&y,&n);

    int arr[n],k=-1;

    for(int i=1; i<=n; i++) {
        scanf("%d %d %d", &xi, &yi, &ni);

        //if ((double) ( pow(x-xi, 2) + pow(y-yi, 2)) < pow(ni,2)) {
         //   arr[++k]=i;
        //}

        if ((double) hypot((x-xi), (y-yi)) < (ni)) {
            arr[++k]=i;
        }
    }

    if (k == -1) {
        printf("-1\n");
    }
    else {
        for(int i=0; i<k; i++) {
            printf("%d ",arr[i]);
        }
        printf("%d\n", arr[k]);
    }

    return 0;
}
