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
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < num; j++){
			cout << pos[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++){
		delete[] pos[i];
	}
	delete[] pos;
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
	int** paranthesesStartEndPos = new int*[3];
	for (int i = 0; i < 3; i++){
		paranthesesStartEndPos[i] = new int[count];
	}
	int foundCount = 0;
	count = 0;
	int saved = -1;
	int count2 = 0;
	int count3 = 0;
	bool found = true;
	bool first = true;
	for (int i = 0; i < expression.length(); i++){
		if (expression[i] == '('){
			if (found == true){
				saved = i;
			}
			foundCount++;
			found = false;
			if (first == true){
				paranthesesStartEndPos[2][count3] = count2;
				count2++;
				count3++;
			}
		}
		else if (expression[i] == ')'){
			if (found == false){
				foundCount--;
				if (foundCount == 0){
					paranthesesStartEndPos[0][count] = saved;
					paranthesesStartEndPos[1][count] = i;
					count++;
					if (first != true){
						i = saved;
						found = true;
					}
					
				}
			}
			count2--;
		}
		if (first == true && i + 1 == expression.length()){
			i = saved;
			first = false;
			found = true;
		}
	}
	//consecutively same level //search for the end of parantheses pair and the corresponding level is the same or not
	cout << endl;
	return paranthesesStartEndPos;
}
