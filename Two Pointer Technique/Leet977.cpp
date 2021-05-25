class Solution
{
public:
    vector<int> sortedSquares(vector<int> &a)
    {
        // idea is start from the middle (ex: 0) to two directions: <- and ->

        int sz = a.size();

        if (a[0] < 0)
        {
            for (int i = 0; i < sz; ++i)
            {
                if (a[i] < 0)
                    a[i] = (-1) * a[i];
            }

            int pos = -1;

            for (int i = 1; i < sz; ++i)
            {
                if (a[i] < a[i - 1])
                {
                    pos = i;
                }
            }

            if (pos != -1)
            {
                vector<int> res;
                int left = pos - 1;
                int right = pos;
                while (left >= 0 && right < sz)
                {
                    if (a[left] > a[right])
                    {
                        res.push_back(a[right] * a[right]);
                        ++right;
                    }
                    else
                    {
                        res.push_back(a[left] * a[left]);
                        --left;
                    }
                }

                while (left >= 0)
                {
                    res.push_back(a[left] * a[left]);
                    --left;
                }

                while (right < sz)
                {
                    res.push_back(a[right] * a[right]);
                    ++right;
                }

                return res;
            }

            else
            {
                for (int i = 0; i < sz; ++i)
                {
                    a[i] = a[i] * a[i];
                }
                return a;
            }
        }

        else
        {
            for (int i = 0; i < sz; ++i)
            {
                a[i] = a[i] * a[i];
            }
            return a;
        }
    }
};