#include<iostream>
using namespace std;

class search

	{
		public:
			int* a;
			int la,tar;
			search()
			{
				cout << "\nEnter number of elements in the list ";
				cin >> la;
				a = new int[la];
				cout << "Enter the elements of the list ";
				for(int i = 0 ;i < la; i++)
					cin >> a[i];
				cout << "Enter the target element ";
				cin >> tar;
			}

			int locn;
			void sequential()
				{  
				    int l;
					for(l = 0; l < la;l++)
					{
						if(tar == a[l])
							break ;
					}
					
					locn = l;
					if(locn < la)
						cout << "The element is found at index " << locn;
					else
						cout << "The element is not found";	
				}
				
			void binary()
			{
				int beg = 0;
				int end = la-1;
				int mid;
				while (beg<=end)
				{
					mid = (beg+end)/2;
					if(a[mid] < tar)
					beg = mid+1;
					else if (a[mid] > tar)
					end = mid-1;
					else if (a[mid]==tar)
					{
					cout<<"The element found at index " << mid;
					return;
					}
					else
					{
						cout<<"Element not found";
						return;
					}
				}
			}
		~search()
		{
			delete[] a;
		}
	};
	
	int main()
	{
		search s1;
		s1.sequential();
		search s2;
		s2.binary();
	}
