//#include <stdio.h>
//#include <assert.h>
//#include <limits.h>

int saturating_add(int x, int y){
    int w = sizeof(int) * 8;
    int soln = x + y;
    // make a mask to get the value of the farthest left bit
    int mask = 1 << (w - 1);
    // if 1 it is positive
    int x_sin = !(x & mask);
    int y_sin = !(y & mask);
    int x_y_sin = !(soln & mask);
    
    // positive overflow when both x and y are positive but soln is negative
    int overflow_pos = x_sin && y_sin && !x_y_sin;
    // negative overflow when both x and y are negative but soln is positive
    int overflow_neg = !x_sin && !y_sin && x_y_sin;
    
    (overflow_pos && (soln = INT_MAX))||(overflow_neg && (soln = INT_MIN));
    return soln;
}

//int main()
//{
//    int a = 5;
//    int b = 9;
//    assert(saturating_add(a, a) == a + a);
//    assert(saturating_add(a, b) == a + b);
//    assert(saturating_add(b, a) == a + b);
//    assert(saturating_add(0, 0) == 0);
//    assert(saturating_add(0, 1) == 1);
//    assert(saturating_add(1, 0) == 1);
//    assert(saturating_add(-1, 0) == -1);
//    assert(saturating_add(0, -1) == -1);
//    assert(saturating_add(-1, -1) == -2);
//    assert(saturating_add(INT_MAX, 1) == INT_MAX);
//    assert(saturating_add(INT_MAX, -1) == INT_MAX - 1);
//    assert(saturating_add(INT_MAX, INT_MAX) == INT_MAX);
//    assert(saturating_add(INT_MIN, 1) == INT_MIN + 1);
//    assert(saturating_add(INT_MIN, INT_MIN) == INT_MIN);
//    printf("done\n");
//    return 0;
//}

