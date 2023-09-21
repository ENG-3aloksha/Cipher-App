// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: All ciphers.cpp
// Program Description: Program that encrypt or decrypt with 9 different ways
// Last Modification Date: 29/03/2022
// Author1 and ID and Group: Ali Mahmoud Mahmoud Awad - 20210249 - S9,S10
// Author2 and ID and Group: Abdelfattah Mohamed Abdelbaset Mousa - 20210215 - S9,S10
// Author3 and ID and Group: Maria Mohamed Bassam Badran - 20210786 - S9,S10
// Teaching Assistant: ENG.Afaf
// Purpose: ciphering and deciphering
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <regex>
using namespace std;
void affine_cipher(){
    string encrypt , decrypt ,validation_num,reply;
    bool check = true;
    int counter;
    char alphapet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    while(check){
        cout<<"for encryption press(1) for decryption press(2)"<<endl;
        getline(cin,validation_num,'\n');
        if((validation_num != "1") && (validation_num != "2") ){
            cout<<"invalid num please try again"<<endl;
            continue;
        }
        if(validation_num == "1"){
            cout<<"please enter the message you want to encrypt"<<endl;
            getline(cin,encrypt,'\n');
            for(int i=0; i < encrypt.length();i++){
                for(int j=0; j < 26;j++){
                    if(tolower(encrypt[i]) == alphapet[j]){
                        decrypt += alphapet[((5*j)+8)%26];
                        break;
                    }
                    else if(encrypt[i] == ' '){
                        decrypt += ' ';
                        break;
                    }
                }
            }

            cout<<"encrypted message is: "<<decrypt<<endl;
        }
        else if(validation_num =="2"){
            cout<<"please enter the message you want to decrypt"<<endl;
            getline(cin,decrypt,'\n');
            for(int i=0; i < decrypt.length();i++){
                for(int j=0; j < 26;j++){
                    if(tolower(decrypt[i]) == alphapet[j]){
                        counter = ((21*(j-8))+26);
                        while(counter<0){
                            counter += 26;
                        }
                        encrypt += alphapet[counter%26];
                        break;
                    }
                    else if(decrypt[i] == ' '){
                        encrypt += ' ';
                        break;
                    }
                }
            }

            cout<<"decrypted message is: "<<encrypt<<endl;

        }
        break;
    }

}
void ceaser_cipher(){
    char lst[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char lst1[26];
    int shifts,flag=0,flag1,flag2;
    string encrypt,decrypt,validation_num;
    char replay;
    bool check = true;
    while (check) {

        cout << "For encryption press (1) For decryption press(2)\n";
        getline(cin,validation_num,'\n');
        if (cin.fail()||((validation_num != "1")&&(validation_num != "2"))) {
            cout << "invalid input please try again\n";
            cin.clear();
            cin.sync();
            continue;
        }
        cout << "enter number of shifts: ";
        cin >> shifts;
        if (cin.fail()) {
            cout << "invalid input please try again\n";
            cin.clear();
            cin.sync();
            continue;
        }

        shifts = (shifts % 26 + 26) % 26;
        cout << shifts << endl;

        for (int i = 0; i < 26; i++) {
            flag1 = i + shifts ;
            if (flag1 <= 25){
                lst1[flag1] = lst[i];
                flag += 1;
            } else{

                flag1 = i - flag ;
                lst1[flag1] = lst[i];
            }

        }

        if (validation_num == "1"){
            cout << "Enter the message to encrypt";
            getline(cin,encrypt,'.');
            for (int i = 0; i < encrypt.length(); i++) {
                for (int j = 0; j < 26; j++) {
                    if (tolower(encrypt[i]) == lst[j]){

                        decrypt += lst1[j];
                    } else if (encrypt[i] == ' '){
                        decrypt += ' ';
                        break;
                    }

                }

            }
            cout << "the encrypted message is: " << decrypt << endl;
        }
        if (validation_num == "2"){
            cout << "Enter the message to decrypt";
            getline(cin,decrypt,'.');
            for (int i = 0; i < decrypt.length(); i++) {
                for (int j = 0; j < 26; j++) {
                    if (tolower(decrypt[i]) == lst1[j]){
                        encrypt += lst[j];
                    } else if ((decrypt[i] == ' ')||(decrypt[i] == '.')){
                        encrypt += ' ';
                        break;
                    }

                }

            }
            cout << "the decrypted message is: " << encrypt << endl;
        }
        break;
    }
}
void atbash_cipher(){
    string encrypt , decrypt;
    bool check= true;
    string validation_num;
    char replay, lst[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    while (check){
        cout<<"for encrypting press(1) and for decrypting press (2)"<<endl;
        getline(cin,validation_num,'\n');
        if(cin.fail() || ((validation_num != "1")&&(validation_num != "2"))){
            cout<<"invalid input"<<endl;
            cin.clear();
            cin.sync();
            continue;
        }
        if (validation_num == "1"){
            cout<<"please enter the message to encrypt"<<endl;
            getline(cin,encrypt,'\n');
            for(int i =0;i<encrypt.length();i++){
                for(int j =0;j<26;j++){
                    if(tolower(encrypt[i]) == lst[j]){
                        if(j<=12){
                            decrypt += lst[(13-j)+12];
                        }
                        else if(j>12){
                            decrypt  += lst[12-(j-13)];
                        }
                    }
                }
            }
            cout<<"the encrypted message is: "<<decrypt<<endl;
        }
        encrypt = "";
        decrypt ="";

        if (validation_num == "2"){
            cout<<"please enter the message to Decrypt"<<endl;
            getline(cin,decrypt,'\n');
            for(int i =0;i<decrypt.length();i++){
                for(int j =0;j<26;j++){
                    if(tolower(decrypt[i]) == lst[j]){
                        if(j<=12){
                            encrypt += lst[(13-j)+12];
                        }
                        else if(j>12){
                            encrypt  += lst[12-(j-13)];
                        }
                    }
                }
            }
            cout<<"the decrypted message is: "<<encrypt<<endl;
        }
        encrypt = "";
        decrypt ="";
        break;


    }
}
void vignere_cipher(){
    string encrypt,temp , decrypt,key,replay;
    int l;

    char arr_of_letters[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    bool check=true;
    string validation_num;
    while(check){
        cout<<"for encrypting press(1) for decrypting press (2)"<<endl;
        getline(cin,validation_num,'\n');
        if(cin.fail() || ((validation_num != "1")&&(validation_num != "2"))){
            cout<<"invalid input"<<endl;
            cin.clear();
            cin.sync();
            continue;
        }
        else{
            cout<<"please enter the key"<<endl;
            getline(cin,key,'\n');

        }
        if (validation_num == "1"){
            cout << "please enter the message to encrypt :" << endl;
            getline(cin,encrypt,'\n');
            for (int i = 0;i < encrypt.length();i++){
                if (i >= key.length()){
                    l = i % key.length();
                    temp += key[l];
                }
                else{
                    temp += key[i];
                }

            }
            for (int i = 0 ; i < encrypt.length(); i++){
                //  cout << int(encrypt[i]) << endl;
                if((int(encrypt[i])>90) ||(int(encrypt[i])<65)){
                    decrypt += encrypt[i];
                }
                else{
                    decrypt += char(((int(temp[i]+encrypt[i]))%26)+65);
                }

            }
            cout << decrypt << endl;


        }

        if(validation_num == "2"){
            cout << "please enter the message to decrypt :" << endl;
            getline(cin,decrypt,'\n');
            for (int i = 0;i < decrypt.length();i++){
                if (i >= key.length()){
                    l = i % key.length();
                    temp += key[l];
                }
                else{
                    temp += key[i];
                }

            }
            for (int i = 0 ; i < decrypt.length(); i++){


                if((int(decrypt[i])>90) ||(int(decrypt[i])<65)){
                    encrypt += decrypt[i];
                }
                else{
                    encrypt += char(((int(decrypt[i]-temp[i])+26)%26)+65);
                }


            }
            cout << encrypt << endl;


        }
        break;

    }
}
void baconian_cipher(){
    string encrypt, decrypt, temp, validation_num,replay;
    bool check = true;
    char key[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'};
    string values[26] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab",
                         "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb",
                         "babaa", "babab", "babba", "babbb", "bbaaa", "bbaab"};
    while (check) {
        cout << "For encrypting press (1) , For decrypting press (2)" << endl;
        getline(cin, validation_num, '\n');
        if ((validation_num != "1") && (validation_num != "2")) {
            cout << "invalid input" << endl;
            continue;
        } else if (validation_num == "1") {
            cout << "please enter the message to encrypt :" << endl;
            getline(cin, encrypt, '\n');
            for (int i = 0; i < encrypt.length(); ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (tolower(encrypt[i]) == key[j]) {
                        decrypt += values[j];
                        decrypt += ' ';
                        break;
                    } else if (encrypt[i] == ' ') {
                        decrypt += ' ';
                        break;
                    }
                }

            }
            cout << "The encrypted message is : " << decrypt << endl;
        } else if (validation_num == "2") {
            cout << "please enter the message to decrypt :" << endl;
            getline(cin, decrypt, '\n');
            for (int i = 0; i < decrypt.length(); i++) {
                if ((decrypt[i] != ' ') &&
                    (decrypt[i] != '.')) {
                    temp += decrypt[i];

                } else if ((decrypt[i] == ' ') || (decrypt[i] == '.')) {


                    for (int k = 0; k < 26; ++k) {

                        if (temp == values[k]) {

                            encrypt += key[k];
                            encrypt += ' ';
                            temp = "";
                            break;
                        }
                    }

                }

            }
            cout << "The decrypted message is : " << encrypt << endl;

        }
        break;

    }
}

void simple_sub_cipher(){
    string key,incrept_message,decript_message,validation_num ;
    int  flag = 0, flag1 = 5;
    bool check = true;
    string altralphapet;
    char replay, alphapet[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    while (check){
        cout<<"for encryption enter 1 or for decryption enter 2"<<endl;
        getline(cin,validation_num,'\n');
        if ((cin.fail()) | ((validation_num != "1") & (validation_num != "2"))){
            cout<<"please enter valid number"<<endl;
            cin.clear();
            cin.sync();
            continue;
        }
        cout<<"please enter the key with 5 uniqe characters with no numbers"<<endl;
        getline(cin,key,'\n');
        if((key.size()) != 5){
            cout<<"invalid key"<<endl;
            continue;
        }
        for(int i = 0; i < (key.size()); i++){
            for(int j = 0; j < (key.size()); j++ ){
                if (i == j){
                    continue;
                }
                else if( key[i] == key[j] ){
                    cout<<"invalid key"<<endl;
                    flag = 1;
                    break ;
                }

            }
            if (flag == 1){
                break;
            }

        } if (flag == 1){
            flag = 0;
            continue;
        }
        for(int i = 0; i < (key.size()); i++){
            altralphapet += key[i];
        }
        for (int i =0 ; i < 26; i++){
            for (int j = 0 ; j<5 ; j++){
                if (altralphapet[j] == alphapet[i]){
                    flag = 1;
                    break;

                }

            };
            if (flag == 0){
                altralphapet += alphapet[i];
                flag1 += 1 ;


            }
            flag = 0;

        }



        if(validation_num == "1"){
            cout<<"please enter the message you want to encrypt"<<endl;
            cin.clear();
            cin.sync();
            getline(cin,incrept_message,'\n');
            for(int i=0; i < (incrept_message.size()); i++ ){
                for(int j=0; j < 26; j++ ){
                    if(alphapet[j] == tolower(incrept_message[i])){
                        decript_message += altralphapet[j];

                    }
                    else if(incrept_message[i] == char(32)){
                        decript_message += char(32);
                        break;
                    }
                }
            }
            flag = 0;
            cout<<" encrypted message : "<<decript_message<<endl;
        }

        if(validation_num == "2"){
            cout<<"please enter the message you want to decrypt"<<endl;
            cin.clear();
            cin.sync();
            getline(cin,decript_message,'.');
            for(int i=0; i < (decript_message.size()); i++ ){
                for(int j=0; j < 26; j++ ){
                    if(altralphapet[j] == tolower(decript_message[i])){
                        incrept_message += alphapet[j];

                    }
                    else if(decript_message[i] == char(32)){
                        decript_message += char(32);
                        break;
                    }
                }
            }
            flag = 0;
            cout<<" decrypted message : "<<incrept_message<<endl;
        }
        break;

    }
}
void polybius_cipher(){
    bool check = true;
    string statement,result,code;
    string key,choice;
    char arr_of_letters[6][6] = {{' ','-','-','-','-','-'},
                                 {'-','A','B','C','D','E'},
                                 {'-','F','G','H','I','K'},
                                 {'-','L','M','N','O','P'},
                                 {'-','Q','R','S','T','U'},
                                 {'-','V','W','X','Y','Z'}};
    cout << "Please Enter the key : " << endl;
    getline(cin,key,'\n');
    arr_of_letters[1][0] = key[0];
    arr_of_letters[2][0] = key[1];
    arr_of_letters[3][0] = key[2];
    arr_of_letters[4][0] = key[3];
    arr_of_letters[5][0] = key[4];
    arr_of_letters[0][1] = key[0];
    arr_of_letters[0][2] = key[1];
    arr_of_letters[0][3] = key[2];
    arr_of_letters[0][4] = key[3];
    arr_of_letters[0][5] = key[4];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << arr_of_letters[i][j] << " ";

        }
        cout<<endl;
    }
    cout << "For Encrypting press(1)\nFor Decrypting press(2)";

    while (check){
        getline(cin,choice,'\n');

        if(choice == "1") {
            cout << "please enter the message to Encrypt "<<endl;
            getline(cin,statement);

            while (true){
                for (int k = 0; k < statement.length(); k++)
                    for (int i = 0; i < 6; i++) {
                        for (int j = 0; j < 6; j++) {
                            if (statement[k] == arr_of_letters[i][j]){
                                result += arr_of_letters[i][0];
                                if (statement[k] == arr_of_letters[i][j])
                                    result += arr_of_letters[0][j];
                            }
                        }
                    }
                cout << result;
                break;
            }


        }


        if (choice == "2"){
            cout << "please enter the code to Decrypt "<<endl;
            getline(cin,code,'\n');
            while(true){
                for (int k = 0; k < code.length(); k=k+2)
                    for (int i = 1; i < 6; i++) {
                        for (int j = 1; j < 6; j++) {
                            if (code[k] == arr_of_letters[i][0]){
                                if (code[k+1] == arr_of_letters[0][j]){
                                    result += arr_of_letters[i][j];
                                }
                            }
                        }

                    }
                break;
            }
            cout << result;
            }


        else{
            cout << "Invalid input please try again " << endl;
            continue;
        }
        break;
    }
}

void morse_cipher(){
    string inc , dec,dec1;
    char flag1 ;
    int flag = 0;
    string validation_num;
    bool check = true;
    map<char, string>::iterator  j;
    map<char , string> mp ={{' ' ,"  "},
                            {'a',".-"},
                            {'b',"-..."},
                            {'c',"-.-."},
                            {'d',"-.."},
                            {'e',"."},
                            {'f',"..-."},
                            {'g',"--."},
                            {'h',"...."},
                            {'i',".."},
                            {'j',".---"},
                            {'k',"-.-"},
                            {'l',".-.."},
                            {'m',"--"},
                            {'n',"-."},
                            {'o',"---"},
                            {'p',".--."},
                            {'q',"--.-"},
                            {'r',".-."},
                            {'s',"..."},
                            {'t',"-"},
                            {'u',"..-"},
                            {'v',"...-"},
                            {'w',".--"},
                            {'x',"-..-"},
                            {'y',"-.--"},
                            {'z',"--.."}
    };

    while(check){
        cout<<"for inceryption press 1 for decryption press 2"<<endl;
        getline(cin,validation_num,'\n');
        if((validation_num != "1") && (validation_num !="2")){
            cout<<"invalid number please try again"<<endl;
            cin.clear();
            cin.sync();
            continue;
        }
        if(validation_num == "1"){
            cout<<"please enter the message you want to incrypt"<<endl;
            getline(cin,inc,'\n');


            for (int i=0; i<inc.length();i++){

                j = mp.find(tolower(inc[i]));


                dec += j->second;
                dec += ' ';


            }
            cout<<dec<<endl;

        }
        if(validation_num == "2"){


            cout<<"please enter the message you want to decrypt with n character in the end"<<endl;
            getline(cin,dec,'\n');

            for (int i=0; i<dec.length();i++){
                if ( (dec[i] != ' ')&&
                     (dec[i] != 'n')){
                    dec1 += dec[i];

                }

                else if((dec[i] == ' ') || (dec[i] == 'n')){
                    dec1.erase(remove(dec1.begin(), dec1.end(), ' '), dec1.end());


                    for(int k = 0 ; k < 26; ++k){

                        if(dec1 == mp[char(97+k)]){

                            inc += char(97+k);
                            inc += ' ';
                            dec1 = "";
                            break;
                        }
                    }


                }

            }

            cout<<inc<<endl;

        }
        break;

    }
}
void encrypting_railFence(){
    string statement;
    cout << "Enter statement to encrypting: ";
    getline(cin, statement);
    statement = regex_replace(statement, regex("\\s"), "");

    cout << "Enter the key: ";
    int key;
    cin >> key;

    char array_of_chars[key][statement.length()];
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < statement.length(); j++) {
            array_of_chars[i][j] = '-';
        }
    }


    int row = 0;
    int checker = 0;
    for (int i = 0; i < statement.length(); i++) {
        if (checker == 0) {
            array_of_chars[row][i] = statement[i];
            row++;
            if (row == key) {
                checker = 1;
                row--;
            }
        } else if (checker == 1) {
            row--;
            array_of_chars[row][i] = statement[i];
            if (row == 0) {
                checker = 0;
                row = 1;
            }
        }
    }


    string encrypted_text = "";
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < statement.length(); j++) {

            encrypted_text += array_of_chars[i][j];
        }

    }


    encrypted_text = regex_replace(encrypted_text, regex("\\-"), "");
    cout << "Encrypted Text: " << encrypted_text << endl;
}
void decrypting_railFence(){
    string statement;
    cout << "Enter statement to decrypt: ";
    getline(cin , statement);



    statement = regex_replace(statement, regex("\\s"), "");

    cout << "Enter the key: ";
    int key;
    cin >> key;


    char array_of_chars[key][statement.length()];
    for (int i = 0; i < key; i++){
        for (int j = 0; j < statement.length(); j++){
            array_of_chars[i][j] = '-';
        }
    }
}

int main() {
    string replay, cipher_validation;
    bool check = true;
    while (check){

    cout
            << "For Affine cipher press (0)\nFor ceaser cipher press (1)\nFor atbash cipher press (2)\nFor vignere cipher press (3)\nFor baconian cipher press (4)\nFor simple substitution cipher press (5)\n";
    cout << "For polybius cipher press (6)\nFor Morse cipher press (7)\nFor Rail Fence cipher press (8)\n";
    getline(cin, cipher_validation, '\n');
    if (cipher_validation == "0") {
        affine_cipher();
    } else if (cipher_validation == "1") {
        ceaser_cipher();
    } else if (cipher_validation == "2") {
        atbash_cipher();
    } else if (cipher_validation == "3") {
        vignere_cipher();
    } else if (cipher_validation == "4") {
        baconian_cipher();
    } else if (cipher_validation == "5") {
        simple_sub_cipher();
    } else if (cipher_validation == "6") {
        polybius_cipher();
    } else if (cipher_validation == "7") {
        morse_cipher();
    } else if (cipher_validation == "8") {
        encrypting_railFence();
        decrypting_railFence();
    }
    cout << "if you want to recipher press any button , if you want to end press n " << endl;
    getline(cin, replay, '\n');
    if ((replay == "n") || (replay == "N")) {
        check = false;
    }
}

}
