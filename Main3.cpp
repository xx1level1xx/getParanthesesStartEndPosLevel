#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
//arrays of string plus (array of algebraic sums of products expressions)
int** getParanthesesStartEndPosLevel(string, int&);
int main(){
	string expression = "(()(()(()))())";
	expression = "()(())";
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
	for (int i = 0; i < expression.length(); i++){
		cout << i << " ";
		if (expression[i] == '('){
			if (found){
				saved = i;
				paranthesesStartEndPos[3][count] = count2;
				count2++;
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
					count2--;
					found = true;
					paranthesesStartEndPos[1][count] = i;
					paranthesesStartEndPos[0][count] = saved;
					paranthesesStartEndPos[2][count] = level - numClosedParanthesesPassedBy;
					count++;
					level -= numClosedParanthesesPassedBy;
					level++;
					i = saved;
					if (numClosedParanthesesPassedBy != 0){
						count2++;
					}
					numClosedParanthesesPassedBy = 0;
				}
			}
		}
	}
	//consecutively same level //search for the end of parantheses pair and the corresponding level is the same or not
	cout << endl;
	return paranthesesStartEndPos;
}
