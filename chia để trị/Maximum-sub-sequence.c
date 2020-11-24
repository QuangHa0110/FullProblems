/*
Bài toán dãy con cực đại
    Đầu vào: Dãy số nguyên a1,a2, ... , an;
    Đầu ra: tìm dãy con bao gồm các phần tử liên tiếp của dãy đã cho có tổng cực đại
*/
#include <stdio.h>
int a[100];
void initArray()
{
    FILE *fptr;
    fptr = fopen("inputMaximumSubSequence.txt", "r");
    for (int i = 0; i < 100; i++)
    {
        fscanf(fptr, "%d", &a[i]);
    }
}
int maxLeft(int *a, int l, int r)
{
    int max = -9999999;
    int s = 0;
    for (int i = r; i >= l; i--)
    {
        s += a[i];
        if (s > max)
            max = s;
    }
    return max;
}
int maxRight(int *a, int l, int r)
{
    int max = -99999999;
    int s = 0;
    for (int i = l; i <= r; i++)
    {
        s += a[i];
        if (s > max)
            max = s;
    }
    return max;
}
int maxSeq(int *a, int l, int r)
{
    if (l == r)
        return a[l];
    int max;
    int mid = (l + r) / 2;
    int mL = maxSeq(a, l, mid);
    int mR = maxSeq(a, mid + 1, r);
    int mLR = maxLeft(a, l, mid) + maxRight(a, mid + 1, r);
    max = mL;
    if (max < mR)
        max = mR;
    if (max < mLR)
        max = mLR;
    return max;
}

int main()
{
    initArray();
  int rs=  maxSeq(a, 0, 99);
  printf("%d",rs);
    return 0;
}