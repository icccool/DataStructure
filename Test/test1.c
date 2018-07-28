#include <stdio.h>
union C{
	int i;
	char c;
};

int main() {
	union C c;
	c.i = 1;
	printf("%d\n",c.c);
	return 0;
}
