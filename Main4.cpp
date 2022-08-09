#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
//arrays of string plus (array of algebraic sums of products expressions)
int** getParanthesesStartEndPosLevel(string, int&);
int main(){
	string expression = "(()(()(()))())";
	//expression = "()(())";
	int num = 0;
	int** pos = getParanthesesStartEndPosLevel(expression, num);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < num; j++){
			cout << pos[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 4; i++){
		delete[] pos[i];
	}
	system("pause");
	return 0;
}
int** getParanthesesStartEndPosLevel(string expression, int& num){
	int count = 0;
	int lastPos = 0;
	int level = 0;
	for (int i = 0; i < expression.length(); i++){
		if (expression[i] == '('){
			count++;
		}
	}
	num = count;
	int** paranthesesStartEndPos = new int*[4];
	for (int i = 0; i < 4; i++){
		paranthesesStartEndPos[i] = new int[count];
	}
	bool found = true;
	count = 0;
	int foundCount = 0;
	int saved = 0;
	int numClosedParanthesesPassedBy = 0;
	int count2 = 0;
	int count3 = 0;
	int lastClosed = 0;
	int match = 0;
	int count4 = 0;
	bool done = false;
	int count5 = 0;
	for (int i = 0; i < expression.length(); i++){
		if (expression[i] == '('){
			if (found){
				count4 = 0;
				match = i;
				for (int j = 0; j<count; j++){
					if (paranthesesStartEndPos[1][j] + 1 == match){
						count2 = paranthesesStartEndPos[2][j];
						break;
					}
				}
				if (count > 0 && i < paranthesesStartEndPos[1][count - 1]){
					count2++;
				}
				saved = i;
				paranthesesStartEndPos[3][count3] = count2;
				count3++;
			}
			found = false;
			foundCount++;
		}
		else if (expression[i] == ')'){
			if (found){
				numClosedParanthesesPassedBy++;
			}
			else if (found == false){
				foundCount--;
				if (foundCount == 0){
					found = true;
					paranthesesStartEndPos[1][count] = i;
					paranthesesStartEndPos[0][count] = saved;
					paranthesesStartEndPos[2][count] = level - numClosedParanthesesPassedBy;
					lastClosed = count;
					count++;
					level -= numClosedParanthesesPassedBy;
					level++;
					i = saved;
					numClosedParanthesesPassedBy = 0;
				}
			}
		}
	}
	//consecutively same level //search for the end of parantheses pair and the corresponding level is the same or not
	return paranthesesStartEndPos;
}
