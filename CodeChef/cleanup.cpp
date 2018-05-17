            #include <iostream>
	    using namespace std;
             
            class TasksLeft
            {
             public:
		int chef[1000];
		int assistant[1000];
		int h, k;
		TasksLeft()
		{
		  chef[0] = 0;
		  assistant[0] = 0;
		}
            };
             
            TasksLeft cleanUp(int n,int m)
            {
             TasksLeft obj;
             int a, count = 0;
             int list[n];
	     list[0] = 0;
             for(int i = 0; i < m; i++)
             {
             	cin >> a;
             	list[a-1] = 1;
             }
	     int h = 0, k = 0;
             for(int j = 0; j < n; j++)
             {
               if(list[j] != 1)
               {
               	if(count % 2 == 0)
		{
               	  obj.chef[h] = j+1;
		  h++;
		}
               	else
		{
               	  obj.assistant[k] = j+1;
		  k++;
		}
               	count++;
               }
             }
	     obj.h = h;
	     obj.k = k;    	  
             return obj;  	   
            }
             
            int main()
            {
             int T, n, m;
             cin >> T;
             TasksLeft obj[T];
             for(int i = 0; i < T; i++)
             {
             	cin >> n >> m;
             	obj[i] = cleanUp(n,m);
             }
             for(int i = 0; i < T; i++)
             {
                for(int a = 0; a < obj[i].h; a++)
                {
                  cout << obj[i].chef[a] << ' ';
                }
                cout << endl;
                for(int b = 0; b < obj[i].k; b++)
                {
                  cout << obj[i].assistant[b] << ' ';
                }
                cout << endl;
             }
             return 0;
            }   