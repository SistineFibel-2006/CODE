#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    int a[n] = {0};
    for(int i = 0; i < n; i ++)
		a[i] = inf.readInt();
	int c = -1, tim;
	for(int i = 0; i < n; i ++){
		int b = ouf.readInt();
		if(c != b * a[i]) {
			tim ++;
			if(tim == 2)
				quitf(_wa,"Wrong answer!");
		}
		c = b * a[i];
	}
	quitf(_ok,"correct!");
}