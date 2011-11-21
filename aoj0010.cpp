#include <stdio.h>
#include <math.h>

void solve(double x1, double x2, double x3, double y1, double y2, double y3) {
	double cx1 = (x1+x2)/2.0, cx2 = (x2+x3)/2.0;
	double cy1 = (y1+y2)/2.0, cy2 = (y2+y3)/2.0;
	double tx1 = y1-y2, tx2 = y2-y3;
	double ty1 = x2-x1, ty2 = x3-x2;
	double a=ty1, b=-tx1, c=cx1*ty1-cy1*tx1;
	double d=ty2, e=-tx2, f=cx2*ty2-cy2*tx2;
	double det = a*e-b*d;
	double x = (e*c-b*f)/det;
	double y = (-d*c+a*f)/det;
	double r = sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
	printf("%.3f %.3f %.3f\n", x, y, r);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double x1,x2,x3,y1,y2,y3;
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
		solve(x1, x2, x3, y1, y2, y3);
	}
	return 0;
}
