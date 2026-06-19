#include <stdio.h>

/**
 * @brief 快速排序分区函数：确定基准值位置，小放左、大放右
 * @param arr 待排序数组
 * @param left 左边界下标
 * @param right 右边界下标
 * @return 基准值最终所在下标
 */
int partition(int arr[], int left, int right)
{
    // 1. 选取最左边元素作为基准值
    int pivot = arr[left];  

    // 左右探测指针
    int i = left;
    int j = right;

    // 2. 左右互相探测交换
    while (i < j)
    {
        // 从右边往左找：找到 小于基准值 的数停下
        while (i < j && arr[j] >= pivot)
        {
            j--;
        }
        // 把右边找到的小数 放到左边i位置
        arr[i] = arr[j];

        // 从左边往右找：找到 大于基准值 的数停下
        while (i < j && arr[i] <= pivot)
        {
            i++;
        }
        // 把左边找到的大数 放到右边j位置
        arr[j] = arr[i];
    }

    // 3. 循环结束 i==j，把基准值放入最终正确位置
    arr[i] = pivot;

    // 返回基准值下标，用来分割左右区间
    return i;
}

/**
 * @brief 递归实现快速排序
 * @param arr 数组
 * @param left 左边界
 * @param right 右边界
 */
void quickSort(int arr[], int left, int right)
{
    // 递归终止条件：区间只剩0个或1个元素，不用排序
    if (left >= right)
    {
        return;
    }

    // 第一步：分区，拿到基准值位置
    int mid = partition(arr, left, right);

    // 第二步：递归排序 基准左边区间 [left, mid-1]
    quickSort(arr, left, mid - 1);

    // 第三步：递归排序 基准右边区间 [mid+1, right]
    quickSort(arr, mid + 1, right);
}

// 数组打印函数
void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    // 待排序乱序数组
    int nums[] = {9, 5, 1, 4, 3, 7, 2, 8, 6};
    // 计算数组长度
    int length = sizeof(nums) / sizeof(nums[0]);

    printf("排序前：");
    printArr(nums, length);

    // 调用快速排序：从下标0到最后一个下标
    quickSort(nums, 0, length - 1);

    printf("排序后：");
    printArr(nums, length);

    return 0;
}