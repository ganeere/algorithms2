//Alican AYDIN
//150110044



#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void print_arr(vector<int>& arr, int first, int last)
{
	for (int i = first; i <= last; i++)
	{
		string if_eol = (i == last) ? "\n" : ", ";

		cout << arr[i] << if_eol;
	}
}
void func(vector<int>& arr, int first, int last){
print_arr(arr, first, last);
	int m=0;
	int x;
	vector<int> A;//int A[20];
	int temp;
	int k=first;
	while(k<last){
		if(arr[k]>arr[k+1]){
			temp=arr[k];
			arr[k]=arr[k+1];
			arr[k+1]=temp;
			
			}
			k=k+2;
	}
	k=first+1;
	while(k<=last){
		A.push_back(arr[k]);//A[m]=arr[k];
		m=m+1;
		k=k+2;
		
		}

	
		x=first;
		k=first;
		while(k<=last){
			arr[x]=arr[k];
			x=x+1;
			k=k+2;
			}
			k=0;
			while(k<m){
				arr[x]=A[k];
				x=x+1;
				k=k+1;
				}
}
void Merge(vector<int>& arr, int first,int mid,int midx,int last){
	int i=first;
	vector<int> temp;
	int j=mid+1;
	int k=0;
	while(i<=mid && j<=last){
		if(arr[i]<arr[j]){
			temp.push_back(arr[i++]);//temp[k++]=arr[i++];
			}
			else{
				temp.push_back(arr[j++]);//temp[k++]=arr[j++];
				}
				
		
		}
		while(i<=mid){
			temp.push_back(arr[i++]);
			
			}
			while(j<=last){
			temp.push_back(arr[j++]);
			
			}
			
		i=first;
		j=0;
		while(i<=last){
			arr[i]=temp[j];
			i=i+1;
			j=j+1;
			
			}
	
	
	}
void min_max(vector<int>& arr, int first, int last){

int b;
int n= last-first+1;

int a;
cout << "Min_max unsorted:";
print_arr(arr, first, last);
for(a=first,b=n-1;a<b;a++,b--){
int max_i = a;
int min_i = a;
int min=arr[a];
int max=arr[a];

for(int k=a;k<=b;k++){
	if(arr[k] > max){ 
                max = arr[k]; 
                max_i = k; 
            } else if (arr[k] < min) { 
                min = arr[k]; 
                min_i = k; 
            } 


}


	
 swap(arr[a], arr[min_i]); 
cout << "Min: "<<  min  ;
cout << "Max: "<< max <<endl;	
if (arr[min_i] == max)  
            swap(arr[b], arr[min_i]); 
  else
            swap(arr[b], arr[max_i]); 





}
cout << "Min_max sorted:";

}

void sort(vector<int>& arr, int first, int last)
{
	int mid;
	int n=last-first+1;
	if (n<=1){
		return ;
	}else if(first<last){

		func(arr,first,last);
		mid=(first+last)/2;
		
		min_max(arr,first,mid);
		print_arr(arr, first, mid);
		
		sort(arr,mid+1,last);
		Merge(arr,first,mid,mid+1,last);

	}
	else return ;		
}


int main(int argc, char *argv[])
{

	vector<int> all_values;


	try {
		
		string filename = argv[1];

		ifstream myfile(filename);

		
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				int number = stoi(line);
				all_values.push_back(number);
			}
			
			sort(all_values, 0, all_values.size() - 1);
			print_arr(all_values, 0, all_values.size() - 1);
			
		}
		else
		{
			cout << "File is not available." << endl;
			throw;
		}

	}
	catch (const ifstream::failure& e)
	{
		cerr << "Exception opening the file!" << endl;
		return -1;
	}
	catch (...)
	{
		cerr << "Something's wrong!" << endl;
		return -1;
	}



	return 0;
}




