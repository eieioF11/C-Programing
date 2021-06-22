//Reverse polish notation for singke digit

#include <iostream> 
#include <stack> 
#include <string>
#include<vector>
#include<sstream>

bool op(char b) {
	return b == '+' || b == '-' || b == '*' || b == '/';
}

bool prio(char a, char b) {
	if (a == '+' || a == '-') {
		return true;
	}
	if (b == '+' || b == '-') {
		return false;
	}
	return true;
}

double posfix(const std::string& expression) {

	double fst, scd, ans;
	std::stringstream postfString(expression);
	std::vector<double> temp;
	std::string schar;

	while (postfString >> schar) {
		if (op(schar[0])) {
			fst = temp.back();
			temp.pop_back();
			scd = temp.back();
			temp.pop_back();

            switch (schar[0])
            {
            case '+':
                ans = scd + fst;
                break;
            case '-':
                ans = scd - fst;
                break;
            case '*':
                ans = scd * fst;
                break;
            case '/':
                ans = scd / fst;
                break; // check if fat !=0
            }

			temp.push_back(ans);
		}
		else {
			temp.push_back(std::stod(schar));
		}
	}
	return temp[0]; //last element is the answer
}

int main() {

	std::string siki;
	std::string rpoli;
	std::stack<char> que;
	double ans;
	int cnt = 0;

	std::cout << "Please input one-digit formula" << "\n";
	std::cin >> siki;

	for (int i = 0; i<siki.size(); i++) {
		if (op(siki[i]) == false) {
			cnt++;
			if (cnt == 1) {
				rpoli = siki[i];
			}
			else {
				rpoli = rpoli + " " + siki[i];
			}
		}

		if (op(siki[i]) == true) {	
			if (que.empty() || (que.empty() == false && prio(que.top(), siki[i]))) {	
				que.push(siki[i]);
			}
			else {
				while (que.empty() == false && prio(que.top(), siki[i]) == false) {
					rpoli = rpoli + " " + que.top();
					que.pop();	
				}
				que.push(siki[i]);
			}
		}
	}

	while (que.empty() == false) {
		rpoli = rpoli + " " + que.top();
		que.pop();	
	}

	std::cout << rpoli << std::endl;	
	ans = posfix(rpoli);
	std::cout << std::endl << ans << std::endl;

	return 0;
}

