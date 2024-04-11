#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

string opcode;
int rD, rA, rB;

void binaryCode() {
    int bit_4 = 0;
    if (opcode == "ADD" || opcode == "ADDC") {
        if (opcode == "ADD") cout << "000000";
        else {
            cout << "000010";
            bit_4 = 1;
        }
    }
    else if (opcode == "SUB" || opcode == "SUBC") {
        if (opcode == "SUB") cout << "000100";
        else {
            cout << "000110";
            bit_4 = 1;
        }
    }
    else if (opcode == "MOV" || opcode == "MOVC") {
        if (opcode == "MOV") cout << "001000";
        else {
            cout << "001010";
            bit_4 = 1;
        }
    }
    else if (opcode == "AND" || opcode == "ANDC") {
        if (opcode == "AND") cout << "001100";
        else {
            cout << "001110";
            bit_4 = 1;
        }
    }
    else if (opcode == "OR" || opcode == "ORC") {
        if (opcode == "OR") cout << "010000";
        else {
            cout << "010010";
            bit_4 = 1;
        }
    }
    else if (opcode == "NOT") {
        cout << "010100";
    }
    else if (opcode == "MULT" || opcode == "MULTC") {
        if (opcode == "MULT") cout << "011000";
        else {
            cout << "011010";
            bit_4 = 1;
        }
    }
    else if (opcode == "LSFTL" || opcode == "LSFTLC") {
        if (opcode == "LSFTL") cout << "011100";
        else {
            cout << "011110";
            bit_4 = 1;
        }
    }
    else if (opcode == "LSFTR" || opcode == "LSFTRC") {
        if (opcode == "LSFTR") cout << "100000";
        else {
            cout << "100010";
            bit_4 = 1;
        }
    }
    else if (opcode == "ASFTR" || opcode == "ASFTRC") {
        if (opcode == "ASFTR") cout << "100100";
        else {
            cout << "100110";
            bit_4 = 1;
        }
    }
    else if (opcode == "RL" || opcode == "RLC") {
        if (opcode == "RL") cout << "101000";
        else {
            cout << "101010";
            bit_4 = 1;
        }
    }
    else if (opcode == "RR" || opcode == "RRC") {
        if (opcode == "RR") cout << "101100";
        else {
            cout << "101110";
            bit_4 = 1;
        }
    }
    cout << bitset<3>(rD);  // rD를 3자리 2진수로 변환
    cout << bitset<3>(rA);
    if (bit_4 == 0) {
        cout << bitset<3>(rB) << 0;
    }
    else cout << bitset<4>(rB);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while (N--) {
        cin >> opcode >> rD >> rA >> rB;
        binaryCode();
    }

    return 0;
}
