#include <iostream>
#include <string>

using namespace std;

class VigenereCipher {
private:
    string key;

public:
    VigenereCipher(const string& keyword) : key(keyword) {}

    string encrypt(const string& plaintext) {
        string ciphertext = "";
        int keyLength = key.length();

        for (int i = 0; i < plaintext.length(); i++) {
            char currentChar = plaintext[i];
            if (isalpha(currentChar)) {
                char shift = isupper(currentChar) ? 'A' : 'a';
                char encryptedChar = ((currentChar - shift) + (key[i % keyLength] - 'A')) % 26 + shift;
                ciphertext += encryptedChar;
            }
            else {
                ciphertext += currentChar;
            }
        }

        return ciphertext;
    }

    string decrypt(const string& ciphertext) {
        string plaintext = "";
        int keyLength = key.length();

        for (int i = 0; i < ciphertext.length(); i++) {
            char currentChar = ciphertext[i];
            if (isalpha(currentChar)) {
                char shift = isupper(currentChar) ? 'A' : 'a';
                char decryptedChar = ((currentChar - shift) - (key[i % keyLength] - 'A') + 26) % 26 + shift;
                plaintext += decryptedChar;
            }
            else {
                plaintext += currentChar;
            }
        }

        return plaintext;
    }
};

int main() {
    string keyword, plaintext;

    cout << "Enter the keyword: ";
    cin >> keyword;

    VigenereCipher cipher(keyword);

    cout << "Enter the plaintext: ";
    cin.ignore(); // Ignore newline character in buffer
    getline(cin, plaintext);

    string ciphertext = cipher.encrypt(plaintext);
    string decryptedText = cipher.decrypt(ciphertext);

    cout << "\nEncrypted Text: " << ciphertext << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
