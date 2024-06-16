#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void deallocation(char**& words, char**& synonyms, int& rows);
void userinput(string& input);
void outputoftwostring(char**& words, char**& synonyms, int& rows);
void check(char**& words, char**& synonyms, int& rows, string& input);

int main() {
    int rows;
    cout << "ENTER NUMBER OF WORDS YOU WANT FOR SYNONYMS" << endl;
    cin >> rows;

    char** words = new char* [rows];
    char** synonyms = new char* [rows];

    string buffer;
    string buffer2;

    for (int i = 0; i < rows; i++) {
        cout << "ENTER WORD " << i + 1 << endl;
        cin >> buffer;
        cout << "ENTER SYNONYM FOR " << buffer << endl;
        cin >> buffer2;

        int size = buffer.length() + 1;
        int s = buffer2.length() + 1;

        words[i] = new char[size];
        synonyms[i] = new char[s];

        words[i][0] = size;
        synonyms[i][0] = s;

        for (int j = 1; j < size; j++) {
            words[i][j] = buffer[j - 1];
        }

        for (int j = 1; j < s; j++) {
            synonyms[i][j] = buffer2[j - 1];
        }
    }

    string input;
    outputoftwostring(words, synonyms, rows);
    userinput(input);
    check(words, synonyms, rows, input);
    deallocation(words, synonyms, rows);

    Sleep(-1); // Pause to view output before closing

    return 0;
}

void outputoftwostring(char**& words, char**& synonyms, int& rows) {
    cout << "ENTERED WORDS ARE : " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < words[i][0]; j++) {
            cout << words[i][j];
        }
        cout << endl;
    }

    cout << "ENTERED SYNONYMS ARE : " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < synonyms[i][0]; j++) {
            cout << synonyms[i][j];
        }
        cout << endl;
    }
}

void userinput(string& input) {
    cout << "ENTER THE TEXT YOU WANT TO CHANGE WITH SYNONYMS" << endl;
    cin.ignore();
    getline(cin, input);
}

void check(char**& words, char**& synonyms, int& rows, string& input) {
    int newsize = input.length() + 1;
    input[newsize - 1] = ' ';
    int i = 0;
    int temp = 0;
    int stop = 0;
    int counter = 0;
    string extra = "";

    for (; i < newsize; i++) {
        if (input[i] == ' ' || input[i] == '\0' || input[i] == '\n') {
            stop = i;
            for (; temp < stop; temp++) {
                extra += input[temp];
            }
            cout << extra << endl;
            counter++;
            temp = i + 1;
            extra = "";
        }
    }

    i = 0;
    temp = 0;
    temp = i;
    stop = 0;
    char** newarr = new char* [counter];
    int shount = 0;

    for (; i < newsize; i++) {
        if (input[i] == ' ' || input[i] == '\0' || input[i] == '\n') {
            stop = i;
            for (; temp < stop; temp++) {
                extra += input[temp];
            }
            int s = extra.length() + 1;
            newarr[shount] = new char[s];
            newarr[shount][0] = s;
            int w = 0;
            for (int v = 1; v < newarr[shount][0]; v++) {
                newarr[shount][v] = extra[w];
                w++;
            }
            shount++;
            temp = i + 1;
            extra = "";
        }
    }

    cout << "CHANGED ARRAY : " << endl;
    for (int c = 0; c < rows; c++) {
        for (int h = 0; h < counter; h++) {
            if (words[c][0] == newarr[h][0]) {
                bool flag = true;
                for (int g = 1; g < words[c][0]; g++) {
                    if (words[c][g] != newarr[h][g]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int f = 1; f < synonyms[c][0]; f++) {
                        cout << synonyms[c][f];
                    }
                    cout << " ";
                }
            }
        }
    }

    for (int i = 0; i < counter; i++) {
        delete[] newarr[i];
    }
    delete[] newarr;
}

void deallocation(char**& words, char**& synonyms, int& rows) {
    for (int i = 0; i < rows; i++) {
        delete[] words[i];
    }
    delete[] words;
    words = NULL;

    for (int i = 0; i < rows; i++) {
        delete[] synonyms[i];
    }
    delete[] synonyms;
    synonyms = NULL;
}
