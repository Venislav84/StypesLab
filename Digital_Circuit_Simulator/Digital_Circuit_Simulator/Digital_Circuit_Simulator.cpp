
// MADE FROM VENISLAV VENELINOV

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <stack>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <list>

struct IntegratedCircuit {
    std::string name;
    std::vector<std::string> inputs;
    std::string expression;
};

// check if symbol is operator
bool isOperator(char c) {
    return c == '&' || c == '|' || c == '!';
}

// check validation of schema name
bool isValidCircuitName(const std::string& name, const std::unordered_map<std::string, IntegratedCircuit>& circuits) {

    //check if the name is only one letter, if it is an alphabetic character, and if it is not already used
    if (name.size() != 1 || !std::isalpha(name[0]) || circuits.find(name) != circuits.end()) {
        return false;
    }
    return true;
}

bool validateLeftPart(const std::string& part, IntegratedCircuit& ic, const std::unordered_map<std::string, IntegratedCircuit>& circuits) {
    // check for opening parenthesis in input
    auto nameEnd = part.find('(');
    if (nameEnd == std::string::npos) {
        std::cerr << "Error: Unmatched opening parenthesis.\n";
        return false;
    }

    // check for name of circuit use isValidCircuit function
    std::string circuitName = part.substr(0, nameEnd);
    if (!isValidCircuitName(circuitName, circuits)) {
        std::cerr << "Invalid circuit name: Must be a single letter and unique.\n";
        return false;
    }
    // write the name of the scheme
    ic.name = circuitName;

    // check for closing closing parenthesis in input
    auto inputsEnd = part.find(')', nameEnd);
    if (inputsEnd == std::string::npos) {
        std::cerr << "Error: No closing closing parenthesis.\n";
        return false;
    }

    std::string inputsStr = part.substr(nameEnd + 1, inputsEnd - nameEnd - 1);
    std::istringstream iss(inputsStr);
    std::string input;

    // Check valiadtion of every one parameter
    while (std::getline(iss, input, ',')) {
        if (input.empty() || input.size() != 1 || !std::isalpha(input[0])) {
            std::cerr << "Invalid input parameter: " << input << "\n";
            return false;
        }
        // add input in vector
        ic.inputs.push_back(input);
    }

    return true;
}

bool validateRightPart(const std::string& part, IntegratedCircuit& ic) {
    // check for opening parenthesis
    auto nameSign = part.find('(');
    if (nameSign == std::string::npos) {
        std::cerr << "Error: Unmatched opening parenthesis.\n";
        return false;
    }

    // Check for operator sign: if operator is missing
    std::string operatorSign = part.substr(1, nameSign - 1);
    if (operatorSign.size() == 0 || operatorSign[0] == ' ') {
        std::cerr << "Operator name is missing!\n";
        return false;

        // Check if operator is only one sign
    }
    else if (operatorSign.size() > 1) {
        std::cerr << "Invalid operator name: It must be a single sign." << operatorSign << "\n";
        return false;

        // Check if operator is a sign(&, |, !), use isOperator function
    }
    else if (!isOperator(operatorSign[0])) {
        std::cerr << "Invalid operator name: Must be a single sign and unique.\n";
        return false;
    }

    auto exprEnd = part.find_last_of(')');
    if (exprEnd == std::string::npos) {
        std::cerr << "Error: No closing closing parenthesis.\n";
        return false;

    }
    std::string exprStr = part.substr(nameSign + 1, exprEnd - nameSign - 1);
    std::istringstream iss(exprStr);
    std::string inputExpr;

    // check if expression is empty
    if (exprStr.size() == 0) {
        std::cerr << "Error: Expression can not be empty.\n";
        return false;
    }
    // check for comma
    auto findcomma = exprStr.find(',');
    if (findcomma == std::string::npos) {
        std::cerr << "Error: No closing closing parenthesis.\n";
        return false;
    }

    // Check validation of every one parameter
    while (std::getline(iss, inputExpr, ',')) {
        if (inputExpr.empty()) {
            std::cerr << "Invalid input parameter: " << inputExpr << "\n";
            return false;
        }
    }

    // Expression cannot be empty
    std::string expression = part.substr(1, part.size());

    if (expression.empty()) {
        std::cerr << "Error: Expression is missing.\n";
        return false;
    }

    // check if left part input there is a maching with right part input
    for (size_t i = 0; i < expression.size(); i++) {
        if (isalpha(expression[i])) {
            bool found = false;
            for (size_t j = 0; j < ic.inputs.size(); j++) {
                if (expression[i] == ic.inputs[j].data()[0]) {
                    found = true;
                }
            }
            if (!found) {
                std::cerr << "Error: No input parameter with name: " << expression[i] << "\n";
                return false;
            }
        }
    }

    // Check for parameter matching
    for (size_t i = 0; i < ic.inputs.size(); i++) {
        bool found = false;
        for (size_t j = 0; j < expression.size(); j++) {
            if (ic.inputs[i].data()[0] == expression[j]) {
                found = true;
            }
        }
        if (!found) {
            std::cerr << "Error: No mach left circuit parameter with right part: " << ic.inputs[i].data()[0] << "\n";
            return false;
        }
    }

    // Check for parentheses matching and structure
    int openParentheses = 0;
    size_t lastComma = std::string::npos;

    for (size_t i = 0; i < expression.size(); i++) {
        if (expression[i] == '(') {
            openParentheses++;
        }
        else if (expression[i] == ')') {
            if (openParentheses == 0) {
                std::cerr << "Error: Unmatched closing parenthesis.\n";
                return false;
            }
            openParentheses--;
        }
        else if (expression[i] == ',') {
            if (lastComma != std::string::npos && lastComma == i - 1) {
                std::cerr << "Error: Consecutive commas are not allowed.\n";
                return false;
            }
            lastComma = i;
        }
    }
    // check for Invalid opening parenthesis
    if (openParentheses != 0) {
        std::cerr << "Error: Unmatched opening parenthesis.\n";
        return false;
    }

    ic.expression = expression;
    return true;
}

bool parseDefineCommand(const std::string& command, IntegratedCircuit& ic, const std::unordered_map<std::string, IntegratedCircuit>& circuits) {
    std::string definePart = "define ";

    // check for "define" command
    if (command.substr(0, definePart.size()) != definePart) {
        std::cerr << "Write define, white space and and after that the name of circuit! \n";
        return false;
    }

    // check for colon
    std::string remaining = command.substr(definePart.size());
    size_t colonPos = remaining.find(':');
    if (colonPos == std::string::npos) {
        std::cerr << "No colon found! \n";
        return false;
    }

    // check for validate in left and right part
    if (!validateLeftPart(remaining.substr(0, colonPos), ic, circuits) ||
        !validateRightPart(remaining.substr(colonPos + 1), ic)) {
        return false;
    }

    return true;
}
// Operators
int precedence(char op) {
    // Determine precedence of operators
    if (op == '!') return 3;
    if (op == '&') return 2;
    if (op == '|') return 1;
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> ops;  // Stack for operators
    std::string postfix;

    for (char c : infix) {
        if (std::isalnum(c)) {
            postfix += c; // Add an alphabetic character or number
        }
        else if (c == '(') {
            ops.push(c);  // Put an opening bracket on the stack
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();  // // Move operators to an opening parenthesis
                ops.pop();
            }
            ops.pop();  // Remove the opening brace
        }
        else if (isOperator(c)) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                postfix += ops.top();  // Move operators with higher or equal priority
                ops.pop();
            }
            ops.push(c);  // Add the current operator to the stack
        }
    }
    while (!ops.empty()) {
        postfix += ops.top();  // Add the remaining operators to the stack
        ops.pop();
    }
    return postfix;
}

bool evaluatePostfix(const std::string& postfix, const std::unordered_map<std::string, bool>& inputs) {
    std::stack<bool> values;  // Stack for values
    for (char c : postfix) {
        if (std::isalnum(c)) {
            std::string var(1, c);
            if (inputs.find(var) == inputs.end()) {
                std::cerr << "Undefined variable: " << var;  // Handle undefined variable
                //throw std::runtime_error("Undefined variable: " + var);  // Handle undefined variable
            }
            values.push(inputs.at(var));  // Add value
        }
        else if (isOperator(c)) {
            if (c == '!') {
                bool val = values.top();
                values.pop();
                values.push(!val);  // Add the negative value
            }
            else {
                bool val2 = values.top();  // Second operand
                values.pop();
                bool val1 = values.top();  // First operand
                values.pop();
                if (c == '&') {
                    values.push(val1 && val2);  // Logical AND
                }
                else if (c == '|') {
                    values.push(val1 || val2);  // Logical OR
                }
            }
        }
    }
    return values.top();  // Return the final result
}

// check inputs values(0 or 1) in "run" command 
// checks if the values ​​are greater than or less than the passed parameters
bool validateInputValues(const std::string& valuesStr, const std::vector<std::string>& icInputs) {

    std::istringstream inputIss(valuesStr);
    std::string value;
    size_t index = 0;

    // Process the input values
    while (std::getline(inputIss, value, ',')) {
        if (index >= icInputs.size()) {
            std::cerr << "Error: Too many input values provided.\n";

            return false;
        }

        if (value == "1" || value == "0") {
            index++;  // Skip a valid value
        }
        else {
            std::cerr << "Error: Invalid value '" << value << "'. Must be 0 or 1.\n";
            return false;
        }
    }

    if (index < icInputs.size()) {
        std::cerr << "Error: Not enough input values provided.\n";
        return false;
    }

    return true;
}

void parseRunCommand(const std::string& command, const std::unordered_map<std::string, IntegratedCircuit>& circuits) {

    std::istringstream iss(command);
    std::string temp, circuitInput;
    iss >> temp >> circuitInput;  // Split the command

    std::string runPart = "run ";

    // check for white space after run
    if (command.substr(0, runPart.size()) != runPart) {
        std::cerr << "Error: Write run whitespace and after that name of command.\n";
        return;
    }

    std::string remaining = command.substr(runPart.size());

    auto nameCirc = remaining.find('(');
    if (nameCirc == std::string::npos) {
        std::cerr << "Error: Unmatched opening parenthesis .\n";
        return;
    }
    // check name of circuit
    std::string circuitLetter = remaining.substr(0, nameCirc);
    if (circuitLetter.size() > 1) {
        std::cerr << "Invalid operator name: It must be a single sign\n";
        return;
    }

    // check if is valid circuit name
    if (circuitInput.empty() || !std::isalpha(circuitInput[0])) {
        std::cerr << "Error: Invalid circuit input. Must be a single letter and unique.\n";
        return;
    }

    std::string circuitName = remaining.substr(0, 1);

    // Check if the schema exists
    if (circuits.find(circuitName) == circuits.end()) {
        std::cerr << "Error: Circuit " << circuitName << " not found.\n";
        return;
    }

    IntegratedCircuit ic = circuits.at(circuitName);

    size_t openParen = command.find('(');

    size_t closeParen = command.find(')');

    // check for parenthesis
    if (openParen == std::string::npos || closeParen == std::string::npos || closeParen < openParen) {
        std::cerr << "Error: Invalid format for input values, parenthesis missing.\n";
        return;
    }

    // input values
    std::string inputValuesStr = command.substr(openParen + 1, closeParen - openParen - 1);

    // check if input values are validated use validateInputValues function
    if (!validateInputValues(inputValuesStr, ic.inputs)) {
        std::cerr << "Not validated values!\n";
        return;
    }

    std::unordered_map<std::string, bool> inputValues;
    std::istringstream inputIss(inputValuesStr);
    std::string value;
    size_t index = 0;

    // Save the result of the input values
    while (std::getline(inputIss, value, ',')) {
        inputValues[ic.inputs[index]] = (value == "1");  // Set the input values
        index++;
    }

    try {
        // Convert the expression from infix to postfix notation
        std::string postfixExpr = infixToPostfix(ic.expression);
        // Evaluate the postfix expression
        bool result = evaluatePostfix(postfixExpr, inputValues);
        std::cerr << "Evaluation result: " << result << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";  // Error handling
    }
}

void parseAllCommand(const std::string& command, const std::unordered_map<std::string, IntegratedCircuit>& circuits) {
    std::istringstream iss(command);
    std::string temp, circuitName;
    iss >> temp >> circuitName;

    // check for "all" command
    if (temp != "all") {
        std::cerr << "Error: Invalid command. Expected 'all'.\n";
        return;
    }

    // check if name of circuit is correct
    if (circuits.find(circuitName) == circuits.end()) {
        std::cerr << "Error: Circuit " << circuitName << " not found.\n";
        return;
    }

    IntegratedCircuit ic = circuits.at(circuitName);

    // create a thurt table
    int numInputs = ic.inputs.size();
    int numCombinations = 1 << numInputs;

    // Print the table title
    for (const auto& input : ic.inputs) {
        std::cout << input << " | ";
    }
    std::cout << "out" << std::endl;

    // Calculate the inputs and the result
    for (int i = 0; i < numCombinations; ++i) {
        std::unordered_map<std::string, bool> inputValues;
        for (int j = 0; j < numInputs; ++j) {
            bool inputValue = (i & (1 << (numInputs - j - 1))) != 0;  // Determine the input value
            inputValues[ic.inputs[j]] = inputValue;
            std::cout << inputValue << " | ";  // Print input value
        }

        try {
            std::string postfixExpr = infixToPostfix(ic.expression);  // Convert the expression
            bool result = evaluatePostfix(postfixExpr, inputValues);  // Evaluate the expression
            std::cout << result << "\n";
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";  // Error handling
        }
    }
}

std::list<std::pair<std::vector<bool>, bool>> readTruthTable(const std::string& filename) {
    std::list<std::pair<std::vector<bool>, bool>> truthTable;
    std::ifstream inputFile(filename);  // Open the file with table
    std::string line;

    while (std::getline(inputFile, line)) {
        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos) {
            std::cerr << "Error parsing truth table line: " << line << std::endl;
            continue;
        }

        // Read input values
        std::string inputsStr = line.substr(0, colonPos);
        std::istringstream inputsStream(inputsStr);
        std::string input;
        std::vector<bool> inputs;

        while (std::getline(inputsStream, input, ',')) {
            inputs.push_back(input == "1");   // Save the input values
        }

        // Read output value
        bool output = line.substr(colonPos + 1) == "1";
        truthTable.push_back({ inputs, output });  // Append to the table
    }

    return truthTable;
}

std::string synthesizeFunction(const std::list<std::pair<std::vector<bool>, bool>>& truthTable) {
    std::string expression;

    // Creation of PDNF perfect disjunctive normal form
    for (const auto& entry : truthTable) {
        const auto& inputs = entry.first;
        bool output = entry.second;

        if (output) {
            // Add to the PDNF expression
            std::string term;
            for (size_t i = 0; i < inputs.size(); ++i) {
                if (inputs[i]) {
                    term += std::string(1, 'a' + i);  // Add the variable
                }
                else {
                    term += "!(" + std::string(1, 'a' + i) + ")";  // Add negative variable
                }
                if (i < inputs.size() - 1) {
                    term += ",";
                }
            }
            expression += "&(" + term + ")";  // Create term
            expression += " | "; // Disjunction between terms
        }
    }

    // Remove the last " | "
    if (!expression.empty()) {
        expression.erase(expression.size() - 3);  // Remove the last logical operation
    }

    return expression;
}

void parseFindCommand(const std::string& command, const std::unordered_map<std::string, IntegratedCircuit>& circuits) {

    //read thurt table
    auto truthTable = readTruthTable("findValues.txt");
    if (truthTable.empty()) {
        std::cerr << "Error: No valid truth table found.\n";
        return;
    }

    // Create a synthesized function
    std::string synthesizedExpression = synthesizeFunction(truthTable);
    std::cout << "Synthesized function: " << synthesizedExpression << "\n";
}

int main() {
    std::cout << std::endl;
    std::cout << "********************   A console simulator for digital integrated circuits   ********************" << std::endl;
    std::cout << std::endl;
    std::cout << "Please enter command that start with define, name of integrated circuit (only with one character i, j, k...) \nand parameters a, b, c... For Example: define j(a,b,c,d): &(a,|(b,c),!(d))" << std::endl;
    std::cout << std::endl;
    std::cout << "When integrated circuit is correctly defined, it is possible to run it: " << std::endl;
    std::cout << "Please enter command run, name, and values in parenthesis (0 or 1), For Example: run j(1,1,0,0)" << std::endl;
    std::cout << std::endl;
    std::cout << "To see the truth table enter command all and the name of integrated circuit For Example: all j" << std::endl;
    std::cout << std::endl;
    std::cout << "To see the PDNF perfect disjunctive normal form enter command find, For Example: find " << std::endl;
    std::cout << "It take data from external file inputValues.txt in folder, with given example in project \nif you want to change the data, go to file and make it" << std::endl;
    std::cout << std::endl;
    std::cout << "To exit the program, please enter command exit " << std::endl;
    std::cout << std::endl;

    std::unordered_map<std::string, IntegratedCircuit> circuits;  // Container for logic circuits

    while (true) {
        std::string command;
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        // Check for "define" command
        if (command.find("define") == 0) {
            IntegratedCircuit ic;
            if (parseDefineCommand(command, ic, circuits)) {
                circuits[ic.name] = ic;   // Add the schema
                std::cout << "Circuit " << ic.name << " defined successfully.\n";
            }
        }
        else if (command.find("run") == 0) {
            parseRunCommand(command, circuits);  // execute "run" command
        }
        else if (command.find("all") == 0) {
            parseAllCommand(command, circuits);  // execute "all" command
        }
        else if (command.find("find") == 0) {
            parseFindCommand(command, circuits); // execute "find" command
        }
        else if (command == "exit") {
            break;  //  Exit the loop
        }
        else {
            std::cerr << "Error: Unknown command.\n";
        }
    }

    return 0;
}
