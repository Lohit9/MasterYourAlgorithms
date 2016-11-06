#include <ctime>
#include <vector>
#include <cstdio>

struct PMatrix {
	int nsize;					// Size of Matrix = nsize * nsize.
	int psize;					// PSize = path length.
	std::vector<int> data;		// Values of cells.
	std::vector<bool> mark;		// Mark means cell already visited.

	std::vector<int> seq;		// Workspace for Path
	std::vector<int> bestseq;	// Best-known path so far.

	int BestVal;				// Value of best-known path so far.

	int si, sj;					// Starting coordinates.

	// Coordinates are linearized for easier movement. Element (i, j) = Element(ij), with ij = i * n + j.
	int l(int i, int j) const { return i*nsize + j; }
	// Movement: Up/Down changes i, Left/Right changes j. Provides wrap-around.
	int up(int i, int j) const { return l((i+1)%nsize, j); }
	int dw(int i, int j) const { return l((i-1 + nsize)%nsize, j); }
	int ri(int i, int j) const { return l(i, (j+1)%nsize); }
	int le(int i, int j) const { return l(i, (j-1+nsize)%nsize); }

	// Easy accessors.
	int e(int ij) const { return data[ij]; }
	int m(int ij) const { return mark[ij]; }
	// On visit: set node, branch, unset.
	void set(int ij) { mark[ij] = true; }
	void unset(int ij) { mark[ij] = false; }
	// Checks if node ij is visitable: value is not zero & unmarked (unvisited in current branch).
	bool c(int ij) const { return ((bool)e(ij) && !mark[ij]); }

	// Initialize, set starting point.
	PMatrix(int n, int k, int i, int j) : nsize(n), psize(k+1), data(nsize*nsize), mark(nsize*nsize, false), seq(psize), bestseq(psize), BestVal(0), si(i), sj(j) {
		seq[0] = l(i, j);
		set(l(i, j));
	}

	// Calculates total value of current finished path.
	int cvalue() {
		int v = 0;
		for (unsigned i = 0; i < seq.size(); ++i) {
			int ij = seq[i];
			v += e(ij);
		}
		return v;
	}

	// Print path and value.
	void PrintBest() {
		int v = 0;
		for (unsigned i = 0; i < bestseq.size(); ++i) {
			int ij = bestseq[i];
			v += e(ij);
			printf("Visit (%d, %d) for value %d.\n", ij/nsize, ij%nsize, e(ij));
		}
		printf("Total value: %d\n", v);
	}

	// Solve recursively: choose step k starting from (ci, cj).
	void Solve(int k, int ci, int cj) {
		// Full path constructed: check and end.
		if (k == psize) {
			// Calculate Value
			int val = cvalue();
			// If Val > BestVal, Save();
			if (val > BestVal) {
				BestVal = val;
				std::copy(seq.begin(), seq.end(), bestseq.begin());
			}
		}
		// Otherwise, set and branch. Bounds can be added.
		else /*if ((psize-k) * MaxElementValue > BestVal)*/ {

			// Try 4 moves and branch.
			if (c(up(ci, cj))) {
				seq[k] = up(ci, cj);
				set(up(ci, cj));
				Solve(k+1, (ci + 1)%nsize, cj);
				unset(up(ci, cj));
			}
			if (c(dw(ci, cj))) {
				seq[k] = dw(ci, cj);
				set(dw(ci, cj));
				Solve(k+1, (ci + -1 + nsize)%nsize, cj);
				unset(dw(ci, cj));
			}
			if (c(ri(ci, cj))) {
				seq[k] = ri(ci, cj);
				set(ri(ci, cj));
				Solve(k+1, ci, (cj + 1)%nsize);
				unset(ri(ci, cj));
			}
			if (c(le(ci, cj))) {
				seq[k] = le(ci, cj);
				set(le(ci, cj));
				Solve(k+1, ci, (cj - 1 + nsize)%nsize);
				unset(le(ci, cj));
			}
		}
		return;
	}


};

int main() {

	PMatrix p(5, 20, 2, 2);
	int vals[5*5] = {  9,  1,  3,  1,  9,  6,  3,  2,  4,  1,  0,  7,  0, 7,  7,  5,  4,  9,  4,  9,  7,  9,  1,  5,  5};
	for (int ij = 0; ij < 5*5; ++ij) {
		p.data[ij] = vals[ij];
	}
	clock_t a(clock());
	p.Solve(1, 2, 2);
	clock_t e(clock());
	p.PrintBest();
	printf("Number of ticks: %u.\n", (e-a));
	return 0;
}
