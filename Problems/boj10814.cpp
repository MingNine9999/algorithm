//Problem Number : 10814
//Problem Title : 나이순 정렬
//Problem Link : https://www.acmicpc.net/problem/10814

#include <stdio.h>
#include <algorithm>
#define N 100000
using namespace std;
struct mem{
	char name[101];
	int age;
	int order;
};
bool cmp(mem a, mem b){
	if (a.age == b.age)
		return a.order < b.order;
	return a.age < b.age;
}
mem arr[N];

int main(){
	int a, b, j, k,n;
	scanf("%d", &n);
	for (k = 0; k < n; k++){
		scanf("%d %s", &arr[k].age, &arr[k].name);
		arr[k].order = k;
	}
	sort(arr,arr + n,cmp);
	for (k = 0; k < n; k++)
		printf("%d %s\n", arr[k].age, arr[k].name);
	return 0;
}