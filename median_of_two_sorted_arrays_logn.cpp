#include<bits/stdc++.h>
using namespace std;

double findMedian(int arr1[], int n, int arr2[], int m){
    if(n>m){
        return findMedian(arr2, m, arr1,  n);
    }

    int start=0;
    int end=n;
    int leftMaxX;
    int rightMinX;
    int leftMaxY;
    int rightMinY;
    while(start<end){
        int parX= (start+end)/2;
        int parY= (n+m+1)/2- parX;
         leftMaxX= (parX==0?INT_MIN: arr1[parX-1]);
         rightMinX= (parX==n?INT_MAX: arr1[parX]);
         leftMaxY= (parY==0? INT_MIN: arr2[parY-1]);
         rightMinY= (parY==m? INT_MAX: arr2[parY]);
         if(leftMaxX<=rightMinY&& leftMaxY<=rightMinX){
             if((n+m)%2==0){
                return (double)(max(leftMaxY,leftMaxX)+min(rightMinX, rightMinY))/2;
            }else{
                return max(leftMaxX, leftMaxY);
            }
         }
        else if(leftMaxY>rightMinX){
            start= parX+1;
        }else{
            end= parX-1;
        }
    }

}
int main() {
	int n, m;
	cin>>n>>m;
	int arr1[n];
	int arr2[m];
	for(int i=0;i<n;i++){
	    cin>>arr1[i];
	}
	for(int i=0;i<m;i++){
	    cin>>arr2[i];
	}
	cout<< findMedian(arr1, n, arr2, m);
	return 0;
}
