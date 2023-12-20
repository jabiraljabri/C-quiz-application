#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Structure for each question
struct Question {
    string question;
    vector<string> options;
    int correctOption;
};

// Function to conduct the quiz
void conductQuiz() {
    string name, email;

    cout << "Welcome to the C++ Quiz!\n";
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your email: ";
    getline(cin, email);

    vector<Question> questions = {
        {"What is the result of 3 + 4?",
         {"5", "6", "7", "8"},
         2
        },
        {"Which header file is needed for input and output in C++?",
         {"<iostream>", "<string>", "<fstream>", "<vector>"},
         0
        },
        {"What is the result of 5 * 9?",
         {"35", "45", "54", "59"},
         1
        },
        {"Which data type is used to store a single character in C++?",
         {"char", "int", "float", "bool"},
         0
        },
        {"Which loop is known as an entry-controlled loop?",
         {"for loop", "while loop", "do-while loop", "if-else loop"},
         0
        },
        {"What does the 'cin' object do in C++?",
         {"Prints output to the console", "Reads input from the console", "Performs mathematical operations", "None of the above"},
         1
        },
        {"Which operator is used for accessing the value at a memory address in C++?",
         {"&", "*", "#", "@"},
         1
        },
        {"Which statement is used to terminate a loop in C++?",
         {"break", "end", "finish", "exit"},
         0
        },
        {"Which keyword is used to define a constant in C++?",
         {"const", "var", "let", "static"},
         0
        },
        {"What is the output of 'cout << (5 + 7) / 2;'?",
         {"6", "5", "7", "Error"},
         0
        }
        // Add more questions here
    };

    int totalQuestions = questions.size();
    int score = 0;

    cout << "\nLet's start the quiz!\n";

    // Iterate through each question
    for (int i = 0; i < totalQuestions; ++i) {
        cout << "\nQuestion " << i + 1 << ": " << questions[i].question << endl;

        // Display options
        for (size_t j = 0; j < questions[i].options.size(); ++j) {
            cout << j + 1 << ". " << questions[i].options[j] << endl;
        }

        // Get user's answer
        int userAnswer;
        cout << "Enter your answer (1-" << questions[i].options.size() << "): ";
        cin >> userAnswer;

        // Check if the answer is correct
        if (userAnswer - 1 == questions[i].correctOption) {
            cout << "Correct!\n";
            score++;
        }
        else {
            cout << "Wrong!\n";
        }

        // Clear input buffer
        cin.ignore();
    }

    // Display user's result
    cout << "\nDear " << name << ", your quiz result:\n";
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Score: " << score << " out of " << totalQuestions << endl;

    // Save the result to a file
    ofstream outFile("quiz_result.txt");
    if (outFile.is_open()) {
        outFile << "Name: " << name << endl;
        outFile << "Email: " << email << endl;
        outFile << "Score: " << score << " out of " << totalQuestions << endl;
        outFile.close();
        cout << "Quiz result saved in 'quiz_result.txt' file.\n";
    }
    else {
        cout << "Unable to open file to save quiz result.\n";
    }

    cout << "Thank you for attending the quiz!\n";
}

int main() {
    conductQuiz();
    return 0;
}
