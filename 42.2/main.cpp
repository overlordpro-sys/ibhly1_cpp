#include <iostream>
#include <queue>
#include <set>
#include <stack>

using std::cout, std::endl, std::stack, std::queue, std::set, std::string,
    std::cin;

void promptCalc(stack<double> &, queue<string> &);
void printQueue(queue<string> &);
void printAnswer(stack<double> &);

int main() {
   char input;
   do {
      if (input == 'n')
         break;
      stack<double> stack;
      queue<string> expression;
      promptCalc(stack, expression);
      printQueue(expression);
      printAnswer(stack);
      cout << "\nContinue? (y/n): ";
      cin >> input;
   } while (input == 'y');
   return 0;
}

void promptCalc(stack<double> &stack, queue<string> &expression) {
   set<string> operations = {"+", "-", "*", "/"};
   string input;
   while (input.compare("q") != 0) {
      cout << "Input an operator (+, -, *, /) or a number: ";
      cin >> input;
      if (input.compare("q") == 0)
         continue;

      char *endchar;
      double num = strtod(input.c_str(), &endchar);
      if (*endchar == 0) {
         stack.push(num);
         expression.push(input);
         continue;
      }
      if (operations.count(input) == 1) {
         if (stack.size() < 2) {
            cout << "Invalid: Not enough numbers in the stack" << endl;
            continue;
         }
         expression.push(input);
         double temp1 = stack.top();
         stack.pop();
         double temp2 = stack.top();
         stack.pop();
         if (input.compare("+") == 0) {
            stack.push(temp1 + temp2);
         } else if (input.compare("-") == 0) {
            stack.push(temp2 - temp1);
         } else if (input.compare("*") == 0) {
            stack.push(temp1 * temp2);
         } else if (input.compare("/") == 0) {
            stack.push(temp1 / temp2);
         }
         continue;
      }
      cout << "Invalid: Incorrect input" << endl;
   }
}

void printQueue(queue<string> &expression) {
   while (!expression.empty()) {
      cout << expression.front() << " ";
      expression.pop();
   }
   cout << "= ";
}

void printAnswer(stack<double> &stack) {
   if (stack.size() == 1) {
      cout << stack.top();
   }
}
