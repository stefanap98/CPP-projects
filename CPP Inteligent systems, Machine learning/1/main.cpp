#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <chrono>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

vector<vvi> TARGET_STATES;
//const int BOARD_SIDE = 3; // Global value for board side. Not used for now.
//const int ZERO_POSITION = -1; // In which corner is the zero. Not used for now.

void printMatrix(int **mat, const int BOARD_SIDE) {
	for (int i = 0; i < BOARD_SIDE; i++) {
		for (int j = 0; j < BOARD_SIDE; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void printMatrix(const vvi& mat, const int BOARD_SIDE) {
	for (int i = 0; i < BOARD_SIDE; i++) {
		for (int j = 0; j < BOARD_SIDE; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template <class T>
void printVector(vector<T>& v) {
	for (T el : v) {
		cout << el << " ";
	}
	cout << endl;
}

int globalID = 0; // Id of state in priority queue

struct State {
	State(int **other, const int BOARD_SIDE) {
		mat.resize(BOARD_SIDE);
		for (int i = 0; i < BOARD_SIDE; i++) {
			mat[i].resize(BOARD_SIDE);
			for (int j = 0; j < BOARD_SIDE; j++) {
				mat[i][j] = other[i][j];
				if (other[i][j] == 0) {
					zeroAt = { i, j };
				}
			}
		}
		this->heuristicDistance = getManhattanDistance(BOARD_SIDE);
		ID = globalID++;
	}

	State(vvi other, const int BOARD_SIDE) {
		mat.resize(BOARD_SIDE);
		for (int i = 0; i < BOARD_SIDE; i++) {
			mat[i].resize(BOARD_SIDE);
			for (int j = 0; j < BOARD_SIDE; j++) {
				mat[i][j] = other[i][j];
				if (other[i][j] == 0) {
					zeroAt = { i, j };
				}
			}
		}
		this->heuristicDistance = getManhattanDistance(BOARD_SIDE);
		ID = globalID++;
	}

	int getManhattanDistance(const int BOARD_SIDE)const {
		int result = 0;
		for (int i = 0; i < BOARD_SIDE * BOARD_SIDE; i++) {
			pii targetIndexes;
			pii stateIndexes;
			for (int j = 0; j < BOARD_SIDE; j++) {
				for (int k = 0; k < BOARD_SIDE; k++) {
					if (mat[j][k] == i) {
						stateIndexes = { j, k };
					}
				}
			}
			for (int j = 0; j < BOARD_SIDE; j++) {
				for (int k = 0; k < BOARD_SIDE; k++) {
					if (TARGET_STATES[BOARD_SIDE][j][k] == i) {
						targetIndexes = { j, k };
					}
				}
			}
			int current = abs(targetIndexes.first - stateIndexes.first) + abs(targetIndexes.second - stateIndexes.second);
			result += current;
		}
		return result;
	}

	bool operator<(const State& other)const {
		return this->heuristicDistance > other.heuristicDistance;
	}

	bool solveAStar(int& threshold, const int BOARD_SIDE);
	void solveIterativeDeepening(const int BOARD_SIDE);

	vvi mat;
	pii zeroAt = { 0, 0 };
	vector<string> sequence;
	int heuristicDistance = 0;
	int ID = -1;
};

bool isValidPos(int x, int y, const int BOARD_SIDE) {
	if (x < 0 || y < 0 || x >= BOARD_SIDE || y >= BOARD_SIDE) {
		return false;
	}
	return true;
}

State generateNewState(State oldState, pii swapPos, const string direction, const int BOARD_SIDE) {
	State newState(oldState.mat, BOARD_SIDE);
	newState.sequence = oldState.sequence;
	newState.sequence.push_back(direction);
	pii zeroAt = oldState.zeroAt;
	swap(newState.mat[zeroAt.first][zeroAt.second], newState.mat[swapPos.first][swapPos.second]);
	newState.zeroAt = swapPos;
	newState.heuristicDistance = newState.getManhattanDistance(BOARD_SIDE) + newState.sequence.size();

	return newState;
}

void pushNewState(priority_queue<State>& pq, set<vvi>& used, int& threshold, State newState) {

	if (!used.count(newState.mat) and newState.heuristicDistance <= threshold) {
		pq.push(newState);
		used.insert(newState.mat);
	}

}

bool State::solveAStar(int& threshold, const int BOARD_SIDE) {
	priority_queue<State> pq;
	pq.push(*this);
	set<vvi> used;
	used.insert((*this).mat);

	bool solutionFound = false;

	while (not pq.empty()) {
		State t = pq.top();

		if (t.getManhattanDistance(BOARD_SIDE) == 0) {
			solutionFound = true;
			printMatrix(t.mat, BOARD_SIDE);
			cout << "Number of actions: " << t.sequence.size() << endl << "Sequence: ";
			printVector(t.sequence);
			cout << "ID of generated state: " << t.ID << endl;
			cout << "Current pq size: " << pq.size() << endl;
			break;
		}

		int i = t.zeroAt.first,
			j = t.zeroAt.second;

		pq.pop();

		if (isValidPos(i - 1, j, BOARD_SIDE)) {
			pushNewState(pq, used, threshold, generateNewState(t, { i - 1, j }, "down", BOARD_SIDE));
		}

		if (isValidPos(i + 1, j, BOARD_SIDE)) {
			pushNewState(pq, used, threshold, generateNewState(t, { i + 1, j }, "up", BOARD_SIDE));
		}

		if (isValidPos(i, j - 1, BOARD_SIDE)) {
			pushNewState(pq, used, threshold, generateNewState(t, { i, j - 1 }, "right", BOARD_SIDE));
		}

		if (isValidPos(i, j + 1, BOARD_SIDE)) {
			pushNewState(pq, used, threshold, generateNewState(t, { i, j + 1 }, "left", BOARD_SIDE));
		}

	}

	return solutionFound;
}

void State::solveIterativeDeepening(const int BOARD_SIDE) {
	const int STEP = 1;
	bool solutionFound = false;
	int threshold = 30;
	while (not solutionFound) {
		solutionFound = solveAStar(threshold, BOARD_SIDE);
		threshold += STEP;
	}
}

void initTargetStates(const int BOARD_SIDE, const int ZERO_POSITION) {
	TARGET_STATES.resize(BOARD_SIDE * BOARD_SIDE);
	int cnt = 1;
	int zero = 0; // Flag for when zero position used

	cout << "Initialization" << endl;
	for (int i = 0; i < BOARD_SIDE; i++) {
		vector<int> temp;
		for (int j = 0; j < BOARD_SIDE; j++) {
			if (cnt == ZERO_POSITION) {
				cout << "0 ";
				temp.push_back(0);
				zero = 1;
				cnt++;
			} else {
			cout << (cnt-zero) % (BOARD_SIDE * BOARD_SIDE) << " ";
			temp.push_back(((cnt++)-zero) % (BOARD_SIDE * BOARD_SIDE));
			}
		}
		cout << endl;
		TARGET_STATES[BOARD_SIDE].push_back(temp);
	}
	cout << endl ;

}

int main() {
	int boardSize;
	do {
		cout << "Enter board side size: ";
		cin >> boardSize;
	} while (boardSize < 3);
	
	cout << endl; 

	int zero;
	do {
	cout << "Enter index of 0: "; //from 1 ot n-1
	cin >> zero;
	} while (zero < -1 || zero > (boardSize * boardSize) - 1);
	cout << endl << "Zero at position: " << zero << endl << endl;

	initTargetStates(boardSize, zero);

	int **test;
	test = new int*[boardSize];
	for (int i = 0; i < boardSize; ++i) {
		test[i] = new int[boardSize];
	}

	cout << "Enter n-puzzle state: " << endl;
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			cin >> test[i][j];
		}
	}
	/*
	cout << "The board example is:" << endl;
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			cout << test[i][j] << " ";
		}
		cout << endl;
	}*/

	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	/* List of examples
	int test3[3][3] = { {0, 1, 3}, {4, 2, 5}, {7, 8, 6} };
	int test3_simple[3][3] = { {1, 2, 3}, {4, 5, 6}, {0, 7, 8} };
	int test3_hard[3][3] = { {1, 8, 2}, {0, 4, 3}, {7, 6, 5} };
	int test3_unsolvable[3][3] = { {0, 3, 4}, {7, 5, 8}, {6, 1, 2} }; // unsolvable
	int test3_21[3][3] = { {6, 5, 3}, {2, 4, 8}, {7, 0, 1} };
	int test3_31[3][3] = { {8, 6, 7}, {2, 5, 4}, {3, 0, 1} };
	int test4_11[4][4] = { {2, 3, 4, 8}, {1, 6, 7, 12}, {5, 10, 11, 0}, {9, 13, 14, 15} };
	int test4_40[4][4] = { {5, 6, 3, 4}, {8, 0, 1, 15}, {10, 7, 2, 11}, {12, 9, 14, 13} }; // unsolvable?
	int test4_66[4][4] = { {14, 15, 8, 12}, {10, 11, 9, 13}, {2, 6, 5, 1}, {3, 7, 4, 0} }; // unsolvable?
	*/
	State a(test, boardSize);
	/*
	printMatrix(a.mat, boardSize);
	*/
	cout << endl << "Finished board: " << endl;
	
	a.solveIterativeDeepening(boardSize);

	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	cout << "Puzzle solved for: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << endl;
	
	for (int i = 0; i < boardSize; i++) {
		delete[] test[i];
	}
	delete[] test;

	return 0;
}