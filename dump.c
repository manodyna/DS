#include <stdio.h>


void heap_bottom(int *h, int n)
{
    int k, i, j, key;
    for (k = (n - 1) / 2; k >= 0; k--)
    {
        j = k;
        key = h[j];
        i = 2 * j + 1;
        while (i <= n)
        {
            if ((i + 1) <= n)
            {
                if (h[i + 1] > h[i])
                {
                    i++;
                }
            }
            if (key < h[i])
            {
                h[j] = h[i];
                j = i;
                i = 2 * j + 1;
            }
            else
                break;
        }
        h[j] = key;
    }
}
void heapify(int *h, int n)
{
    int i, j, key, k;
    j = 0;
    key = h[j];
    i = 2 * j + 1;
    while (i <= n)
    {
        if ((i + 1) <= n)
        {
            if (h[i + 1] > h[i])
                i++;
        }
        if (key < h[i])
        {
            h[j] = h[i];
            j = i;
            i = (2 * j) + 1;
        }
        else
            break;
    }
    h[j] = key;
}

int max_delete(int *h, int *n)
{
    int max;
    max = h[0];
    h[0] = h[*n - 1];
    --*n;
    heapify(h, *n - 1);
    return (max);
}

int main()
{
    int n, h[100], max_ele;
    printf("enter the value ofn\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);
    printf("\n before heapify\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", h[i]);
    heap_bottom(h, n - 1);
    printf("\n After heapify\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", h[i]);
    max_ele = max_delete(h, &n);
    printf("max =%d is deleted", max_ele);
    printf("\n After deletion\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", h[i]);
}
