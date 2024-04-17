 #include <stdio.h>
#include <stdlib.h>
struct record{
    int p;
    int w;
}*pair;
int largest(struct record *pair, int w[], int t, int h, int i, int m) {
    while (t <= h) {
        int mid = (t + h) / 2;
        if (pair[mid].w + w[i] <= m)
            t = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}
int search(struct record *pair, int fixl, int fixh, int low, int high, int item){
    if (low > high || low < fixl || high > fixh){
        return 0;
    }

    else{
        int mid = (low + high) / 2;
        if (item < pair[mid].p)
            return search(pair, fixl, fixh, low, mid - 1, item);
        else if (item > pair[mid].p)
            return search(pair, fixl, fixh, mid + 1, high, item);
        else
        {
            return 1;
        }
    }
}
void show_pair(int next, int a, int t){
    printf("S^%d = {", a);
    for (int i = t; i < next; i++){
        printf("(%d,%d)", pair[i].p, pair[i].w);
        if (i < next - 1)
            printf(",");
    }
    printf("}\n");
}
void traceback(int *p, int *w, struct record *pair, int *x, int n, int m, int *b, int px){
    int low, high;
    low = b[n - 1];
    high = b[n];

    if (search(pair, low, high, low, high, px)){
        x[n] = 0;
    }

    else if (search(pair, low, high, low, high, px - p[n])){
        x[n] = 1;
        px = px - p[n];
    }
    if (n != 0)
        traceback(p, w, pair, x, n - 1, m, b, px);
    else
        return;
}
void Dknap(int *p, int *w, int *x, int n, int m){
    int t, h, k, i, j, next, b[n + 1], u, pp, ww;
    b[0] = 0;
    t = 1;
    h = 1;
    b[1] = 2;
    next = 2;
    pair[1].p = 0;
    pair[1].w = 0;
    show_pair(next, 0, t);
    for (i = 1; i < n + 1; i++){
        u = largest(pair, w, t, h, i, m);
        k = t;
        for (j = t; j <= u; j++){
            pp = pair[j].p + p[i];
            ww = pair[j].w + w[i];
                 printf("%d %d %d %d\n", pp, ww, i, k);
            while (k <= h && pair[k].w < ww){
                pair[next].p = pair[k].p;
                pair[next++].w = pair[k++].w;
            }
            printf("1-%d ", k);show_pair(next, i, b[i]);

            if (k <= h && pair[k].w == ww){
                if (pp < pair[k].p)
                    pp = pair[k++].p;
            }
            printf("2-%d ", k);show_pair(next, i, b[i]);
            if (pp > pair[next - 1].p){
                pair[next].p = pp;
                pair[next].w = ww;
                next++;
            }
            printf("3-%d ", k);show_pair(next, i, b[i]);
            while (k <= h && pair[k].p < pair[next - 1].p)
                k++;
            printf("4-%d ", k);show_pair(next, i, b[i]);
        }
        while (k <= h){
            pair[next].p = pair[k].p;
            pair[next++].w = pair[k++].w;
        }
        printf("5-%d ",k);show_pair(next, i, b[i]);
        t = h + 1;
        h = next - 1;
        b[i + 1] = next;
    }
    t = pair[b[n + 1] - 1].p;
    traceback(p, w, pair, x, n, m, b, t);
    printf("b[n]=%d,b[n+1]= %d ",b[n],b[n+1]);
}
int main(){
    int i, p[7] = {33, 45, 12, 26, 23, 34, 19}, w[7] = {5, 6, 3, 6, 5, 4, 7}, x[7] = {0}, m = 28, n = 7;
    pair = (struct record *)malloc(100 * (sizeof(struct record)));
    pair[0].p = -1;
    pair[0].w = -1;
    Dknap(p, w, x, n, m);
    printf("\n\nx: {");
    for (i = 1; i < n + 1; i++){
        printf("%d%c", x[i], i != n ? ',' : '\0');
    }
    printf("}\n");
}