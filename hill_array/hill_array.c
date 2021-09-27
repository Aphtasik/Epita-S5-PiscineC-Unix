int top_of_the_hill(int tab[], size_t len)
{
    int left = 0;
    int right = len-1;

    while(left!=right)
    {
        if(tab[left]<tab[right])
        {
            if(tab[left]<=tab[left+1])
            {
                left++;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            if(tab[right-1]>=tab[right])
            {
                right--;
            }
            else
            {
                return -1;
            }
        }
    }

    return left;
}
