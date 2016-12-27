class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int l1 = C - A;
		int k1 = D - B;
		int l2 = G - E;
		int k2 = H - F;
		int S1 = l1*k1;
		int S2 = l2*k2;
		int l[4] = { abs(C - E),abs(G - A),C - A,G - E };
		int k[4] = { abs(H - B),abs(D - F),D - B,H - F };
		if (C<E || G <= A || B >= H || D <= F)
			return S1 + S2;
		else if ((A <= E && C >= G && B <= F && D >= H) || (E <= A && G >= C && F <= B && H >= D))
		{
			if (S1 >= S2)
				return S1;
			else
				return S2;
		}
		else
			return S1 + S2 - (*min_element(l, l + 4))*(*min_element(k, k + 4));
		return 0;
	}
};