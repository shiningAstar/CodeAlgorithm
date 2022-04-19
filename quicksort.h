#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

/* �������� */

//�ݹ�ʵ��һ·��������
/***********************************************/

//���궨�����ҷֽ磬����������������궨�����ֽ粻ƽ��
int __partition1(vector<int> &nums, int l, int r)
{
    //���ѡ�궨��
    //swap(nums[l], nums[l + rand() % (r - l)]);
    int v = nums[l];
    int i, j;

    for(i = l + 1, j = l + 1; i <= r; i++)
    {
        if(nums[i] < v)
        {
            swap(nums[j], nums[i]);
            j++;
        }
    }

    swap(nums[l], nums[j - 1]);

    return j - 1;

}

//�Է�Χ[l,r]�������������
void __quickSort1(vector<int> &nums, int l, int r)
{
    if(l >= r)
        return;

    int q = __partition1(nums, l, r);
    __quickSort1(nums, l, q - 1);
    __quickSort1(nums, q + 1, r);

}

void quickSort1(vector<int> &nums)
{
    //����궨��
    //srand(time(NULL));
    __quickSort1(nums, 0, nums.size() - 1);
}

/***********************************************/



//�ݹ�ʵ����·���������ظ�Ԫ�ط�ɢ�����ߣ�������ƽ��
/***********************************************/

int __partition2(vector<int> &nums, int l, int r)
{
    //���ѡ�궨��
    //swap(nums[l], nums[l + rand() % (r - l)]);
    int v = nums[l];
    int i = l + 1, j = r;



    while(true)
    {
        while(i <= r && nums[i] < v) i++;
        while(j > l && nums[j] > v) j--;
        if(i > j) break;
        swap(nums[i], nums[j]);
        i++;
        j--;
    }

    swap(nums[l], nums[j]);

    return j;

}

void __quickSort2(vector<int> &nums, int l, int r)
{
    if(l >= r)
        return;

    int q = __partition2(nums, l, r);
    __quickSort2(nums, l, q - 1);
    __quickSort2(nums, q + 1, r);
}


void quickSort2(vector<int> &nums)
{
    __quickSort2(nums, 0, nums.size() - 1);
}

/***********************************************/



//�ݹ�ʵ����·�������򣬱궨���С�����ߣ��궨���ظ�Ԫ���м䣬ֻ������������
/***********************************************/

void __quickSort3(vector<int> &nums, int l, int r)
{
    if(l >= r)
        return;

    //partition
    //���ѡ�궨��
    //swap(nums[l], nums[l + rand() % (r - l)]);
    int v = nums[l];
    int lt = l, gt = r + 1;

    for(int i = l + 1; i < gt;)
    {
        if(nums[i] < v)
        {
            lt++;
            swap(nums[lt], nums[i]);
            i++;
        }
        else if(nums[i] > v)
        {
            gt--;
            swap(nums[i], nums[gt]);
        }
        else
            i++;
    }

    swap(nums[l], nums[lt]);


    __quickSort3(nums, l, lt - 1);
    __quickSort3(nums, gt, r);
}


void quickSort3(vector<int> &nums)
{
    __quickSort3(nums, 0, nums.size() - 1);
}

/***********************************************/

#endif // QUICKSORT_H_INCLUDED
