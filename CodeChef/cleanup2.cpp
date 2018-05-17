#include <iostream>
#include <cstdio>

int main()
{
int T, n, a, m, h, k, count, status[1001], chef[501], assistant[501];

scanf("%d", &T);
	
for(int i = 0; i < T; i++)
{
	scanf("%d %d", &n, &m);
	std::fill(status, status + 1001, 0);
	for(int c = 0; c < m; c++)
	{
		scanf("%d", &a);
		status[a-1] = 1;
	}
	h = k = count = 0;
	std::fill(chef, chef + 501, 0);
	std::fill(assistant, assistant + 501, 0);
        for(int j = 0; j < n; j++)
        {
          if(status[j] != 1)
          {
          	if(count % 2 == 0)
		{
               	  chef[h] = j+1;
		  h++;
		}
               	else
		{
               	  assistant[k] = j+1;
		  k++;
		}
               	count++;
          }
        }
	
	for(int a = 0; a < h; a++)
        {
          printf("%d ", chef[a]);
        }
        printf("\n");
        for(int b = 0; b < k; b++)
        {
          printf("%d ", assistant[b]);
        }
        printf("\n");
}
return 0;
}





