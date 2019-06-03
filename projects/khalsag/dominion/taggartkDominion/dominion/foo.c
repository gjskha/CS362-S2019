#include <stdio.h>

void func(int array[]) {

	printf("%d\n",array[2]);
	//array++;
	array[2] = 111;
	printf("%d\n",array[2]);
	
}

int main() {

	int a[4] = {1,2,3,4};

	func(a);
	return 0;

}
