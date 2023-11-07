#include<iostream>
using namespace std;

class sort

{
	public:
		
		int ct,w,wa;
		int n;
		int *c;
		
	sort()
	
	{
		cout<<"\nEnter number of elements :";
		cin>>n;
		c=new int (n);
		cout<<"Enter array elements :";
		for(int i=0;i<n;i++)
		cin>>c[i];
	}
	
	
	void selectionsort()
	
	{
		
	cout<<"The sorted elements are:";
	for(int h=0;h<n;h++)
	    {
		int small=h;
	    for(wa=h+1;wa<n;wa++)
	       {
		   if(c[wa]<c[small])
	       small=wa;
		   }
	       if(small!=h)
	       {
		   int t;
	       t=c[small];
	       c[small]=c[h];
	       c[h]=t;
	       }
	    }
	    for(int h=0;h<n;h++)
	    {
		cout<<c[h]<<"\t";
		}
	}
	
	void bubblesort()
	
	{
		
	cout<<"The sorted elements are:";
	bool sorted=false;
	    for(ct=0;ct<n;ct++)
        {
		if(sorted==false)
			{ 
			sorted=true;
	         for(w=n-1;w>ct;w--)
	          {
			  if(c[w]<c[w-1])
	            {
				int temp;
	            temp=c[w];
               	c[w]=c[w-1];
	            c[w-1]=temp;
	            sorted=false;
	            }
	          }
	        }
	    }
	    for(int j=0;j<n;j++)
	    {cout<<c[j]<<"\t";
		}
		
    }
    
    void insertionsort() 
    
	{
		cout<<"The sorted elements are:";
        for (ct=1;ct<n;ct++)
        {
            int hold=c[ct];
            wa=ct-1;
            while (wa>=0&&c[wa]>hold)
            {
                c[wa+1]=c[wa];
                wa--;
            }
            c[wa+1]=hold;
        }
        for (int i= 0;i<n;i++) {
            cout<<c[i]<<"\t";
        }
    }
};

int main()

{
	sort s1;
	s1.selectionsort();
	sort s2;
	s2.bubblesort();
	sort s3;
	s3.insertionsort();
	return 0;
 } 
