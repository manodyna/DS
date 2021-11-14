#include <stdio.h>
#include <stddef.h>

// creating a bottom down heap
void bottomHeap(int *root, int n)
{
    // key refers to the value of var
    int key;
    int j, i;
    // iterating from half the array to the end
    for (int k = ((n - 1) / 2); k >= 0; k--)
    {
        // setting a temp int equal to the counter
        j = k;
        // settting the key = to the element at the root
        key = root[j];
        // finding the lchild of the root elem
        i = 2 * j + 1;
        // iterating to the end of the heap
        while (i <= n)
        {
            // if not last ele
            if ((i + 1) <= n)
            {
                // if child greater than parent
                if (root[i + 1] > root[i])
                {
                    // increment i
                    i++;
                }
            }
            // if key less than element
            if (key < root[i])
            {
                // swap
                root[j] = root[i];
                j = i;
                i = 2 * j + 1;
            }
            else
            {
                break;
            }
        }
        //  set the element at root equal to key
        root[j] = key;
    }
}

void topheap(int *root, int n)
{
    int key;
    int i, j;
    for (int k = ((n - 1) / 2); k >= 0; k--)
    {
        j = k;
        key = root[j];          
        i = 2 * j + 1;
        while (i <= n)
        {
            if (root[i + 1] < root[i])
            {
                i++;
            }
            if (key < root[i])
            {
                root[j] = root[i];
                j = i;
                i = 2 * j + 1;
            }
            else
            {
                break;
            }
        }
        root[j] = key;
    }
}

void heapify(int *root, int n)
{
    int i, j, key, k;
    j = 0;
    key = root[j];
    i = 2 * j + 1;
    while (i <= n)
    {
        if ((i + 1) <= n)
        {
            if (root[i + 1] > root[i])
            {
                i++;
            }
        }
        else if (key < root[i])
        {
            root[j] = root[i];
            j = i;
            i = 2 * j + 1;
        }
        else
        {
            break;
        }
    }
    root[j] = key;
}

int maxdel(int *root, int *n)
{
    int max = root[0];
    max = root[0];
    root[0] = root[*n - 1];
    --*n;
    heapify(root, *n - 1);
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
    topheap(h, n - 1);
    printf("\n After heapify\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", h[i]);
    max_ele = maxdel(h, &n);
    printf("max =%d is deleted", max_ele);
    printf("\n After deletion\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", h[i]);
}