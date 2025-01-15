#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to apply an operation to two numbers
double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        case '^': return pow(a, b);
        default:
            throw invalid_argument("Invalid operator");
    }
}

// Function to check the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Helper function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to evaluate the mathematical expression
double evaluateExpression(const string& expression) {
    stack<double> values;    // Stack for numbers
    stack<char> operators;   // Stack for operators

    for (size_t i = 0; i < expression.length(); ++i) {
        if (isspace(expression[i])) {
            continue; // Skip whitespace
        } else if (isdigit(expression[i]) || 
                   (expression[i] == '-' && (i == 0 || expression[i - 1] == '(' || isOperator(expression[i - 1])))) {
            // Handle numbers and unary minus
            double value = 0;
            bool isNegative = (expression[i] == '-');
            if (isNegative) ++i;

            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    double decimalPlace = 0.1;
                    ++i;
                    while (i < expression.length() && isdigit(expression[i])) {
                        value += (expression[i] - '0') * decimalPlace;
                        decimalPlace *= 0.1;
                        ++i;
                    }
                    --i;
                } else {
                    value = value * 10 + (expression[i] - '0');
                }
                ++i;
            }
            --i;

            if (isNegative) value = -value;
            values.push(value);
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            if (!operators.empty()) operators.pop(); // Remove '('
        } else if (isOperator(expression[i])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(expression[i]);
        } else {
            throw invalid_argument("Invalid character in expression");
        }
    }

    // Apply remaining operators
    while (!operators.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

// Function to convert an equation string to its integer result
int equationToResult(const string& equation) {
    try {
        double result = evaluateExpression(equation);
        return static_cast<int>(result);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 0; // Return 0 in case of an error
    }
}

string intToString(int number) {
    stringstream ss;
    ss << number; // Insert the integer into the stream
    return ss.str(); // Extract and return the string
}

int main() {
	int titik_tengah_x; 
	int titik_tengah_y;
    
    int panjang;
    int lebar;
    int switching = 0;
    int spaceCount = 3;
    int middleColumn;
    int middleRow;
	cout << "masukan size grafik cartesius : ";
    cin >> panjang >> lebar;
    
    int originalX = panjang;
    int originalY = lebar;
    
    
    lebar *= 2;
    panjang *= 2;
    lebar += 1;
    
    string grafik[100000];
    int middleSafe[2];

    middleRow = lebar / 2;
    
    // array filling
	for (int i = 0; i < lebar; i++) {
		if (i == middleRow) continue;
		for (int j = 0; j < panjang * 2; j++) {
			grafik[i] += ' ';
		}
	}
	
	grafik[middleRow] = "";
    // creation of x line
    for(int i = 0; i < originalX * 2 + 1; i++) {
    	if (i == originalX) {
    		grafik[middleRow] += '+';
    		switching = 1;
			continue;
    	}
		if (switching == 0) {
    		grafik[middleRow] += "X'";
		}
		
		else if (switching == 1) {
			grafik[middleRow] += "'X";
		}
	}
	
	// pencarian titik 0,0
	for (int i = 0; i < grafik[middleRow].length(); i++) {
		if (grafik[middleRow][i] == '+') {
			middleColumn = i;
		}
	}
	
    // creation of y line
    
    
    for (int i = 0; i < lebar; i++) {
    	if (i == middleRow) {
    		spaceCount = 0;
			continue;
		}
		
		grafik[i][middleColumn] = 'X';
				
	}
	
	// output
	cout << endl;
	for (int i = 0; i < lebar; i++) {
		cout << grafik[i] ;
		cout << endl;
	}
	
	string equation;
	string originalEquation;
	string negativeTemp = "";
	string positiveTemp = "";
	int testX;
	int tempResult;
	// solving
	cout << grafik[middleRow][middleColumn] << endl;
	cout << "put in an equation : ";
	cin >> equation;
	originalEquation = equation;
	// x^2;
	
	// 0,0

	titik_tengah_y = middleRow;
	titik_tengah_x = middleColumn;
	
	//x = 0
	testX = 0;
	
	// opposite
	int opposite = 0;
	
	for (int i = -1 * originalX; i < originalX; i++) {
		cout << "success now " << i << endl;
		// current X
		for (int j = 0;j < equation.length(); j++) {
			cout << "success2 " << endl;
			if (equation[j] == 'x' || equation[j] == 'X' || equation[j] == 'Y' || equation[j] == 'y') {
				if (equation[j] == 'y' || equation[j] == 'Y') {
					opposite = 1;
				}
				if (i >= 0) {
					for (int k = 0; k < equation.length(); k++) {
						if (k == j) {
							if (k - 1 > -1) {
								// 57
								if (equation[k - 1] >= 48 || equation[k - 1] < 58) {
									positiveTemp += '*';
								}
							}
						positiveTemp += intToString(i);
						continue;
						}
						positiveTemp += equation[k];
					}
				}
				else if (i < 0) {
					for (int k = 0; k < equation.length(); k++) {
						if (k == j) {
							if (k - 1 > -1) {
								// 57
								if (equation[k - 1] >= 48 || equation[k - 1] < 58) {
									negativeTemp += '*';
								}
							}
							negativeTemp += intToString(i);
							continue;
						}
						
						negativeTemp += equation[k];
					}
				}
			}
		}
	
		cout << "positive equation : " << positiveTemp << endl;
		cout << "negative equation : " << negativeTemp << ' ' << endl;
		cout << "normal equation : " << equation << endl;
		
		// untuk negatif
		if (i < 0) {
			cout << "point -1 reached" << endl;
			// kalau koordinat melebihi size tabel
		
			if (equationToResult(negativeTemp) <= -1 * originalX || equationToResult(negativeTemp) > originalX) {
				negativeTemp = "";
				continue;
			}
			cout << "point one reached" << endl;

			grafik[titik_tengah_y - equationToResult(negativeTemp)][titik_tengah_x + i * 2] = '$';
			
			if (opposite == 1) {
				grafik[titik_tengah_y - equationToResult(negativeTemp)][titik_tengah_x + i * 2] = ' ';
				grafik[titik_tengah_y - i][titik_tengah_x + equationToResult(negativeTemp) * 2] = '$';
			}
			
			cout << titik_tengah_y - equationToResult(negativeTemp) << ' ' << titik_tengah_x + i * 2 << endl;
			for (int i = 0; i < lebar; i++) {
				cout << grafik[i] ;
				cout << endl;
			}
			negativeTemp = "";
			cout << "dot placement success" << endl;
		}
		// untuk positif
		else if (i >= 0) {
			if (equationToResult(positiveTemp) >= originalX) {
				cout << "too much2" << endl;
				equation = originalEquation;
				positiveTemp = "";
				continue;
			}
			else if (equationToResult(positiveTemp) < originalX) {
				grafik[titik_tengah_y - equationToResult(positiveTemp)][titik_tengah_x + i * 2] = '$';
				
				if (opposite == 1) {
					grafik[titik_tengah_y - equationToResult(positiveTemp)][titik_tengah_x + i * 2] = ' ';
					
					grafik[titik_tengah_y - i][titik_tengah_x + equationToResult(positiveTemp) * 2] = '$';
				}
			}
			
				
			else {
				grafik[titik_tengah_y - equationToResult(equation)][titik_tengah_x + i * 2] = '$';
				
				
				if (opposite == 1) {
					grafik[titik_tengah_y - equationToResult(equation)][titik_tengah_x + i * 2] = ' ';
					
					grafik[titik_tengah_y - i][titik_tengah_x + equationToResult(equation) * 2] = '$';
				}
			}
		}
		cout << "almost finish" << endl;
		negativeTemp = "";
		positiveTemp = "";
		equation =  originalEquation;
		cout << "full loop finish" << endl;
	}
	// 0,0

	
	for (int i = 0; i < lebar ; i++) {
		cout << grafik[i] ;
		cout << endl;
	}
	
	
	return 0;
}