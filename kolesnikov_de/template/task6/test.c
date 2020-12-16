#include <memory.h>
typedef
struct _S
{
	int size;
	char* name;
}S;


int main() {
	S ss[5];
	ss[0].size = 5;
}