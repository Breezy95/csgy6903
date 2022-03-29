#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
#include <chrono>
#include <fstream>

using namespace std;



const int KEYSPACE = 27;

//coin flip algo, returns real numbers between 0 and 1 (decimals, pi,etc)
    double coin_flip(int i, int L){
            return (sin(i + L)/2 + .5);

    }

    void encrypt(){}

int main() {
    
    auto start = chrono::steady_clock::now();

    string plaintext1 = "underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con";
    string message = plaintext1;
    int *key;
    int kspace[KEYSPACE];  //set of all possible permutations of the set {0,...,26}
    key = kspace;
    unsigned int seed =rand()%100;
    char cipherspace[KEYSPACE] = {32};

    //fill cipherspace   
    for(int i=97;i<123;i++)
        cipherspace[i-96] = i;
    //ascii values <space>,a-z cipher space is same as keyspace

    //gen keyspace and creating a permutation
    for(int i=0; i<KEYSPACE; i++){
      
       kspace[i] = i;
     
    }
    shuffle(kspace,kspace +KEYSPACE, default_random_engine(seed)); // using generator algorithm for better randomness

    char char_message[message.length()+1];
    message.copy(char_message, message.length() +1);


    int L = message.length();

    
    // coin flip or encrypt loop
    int mCounter = 0;
    int cCounter =0;
    int randChar =0;
    double probRandomCipher = 0.00;
    vector<char> cipherText(0);
    srand(time(0));
    while(cCounter <= L + randChar){  

        double coin = coin_flip(cCounter,L);

    

        //encrypt by char
        if(probRandomCipher < coin && coin <= 1){
            int j = char_message[mCounter];
            cout <<"var: j " << j <<  " kspace: " << kspace[j%97]<<" message_counter: "<<mCounter <<" message char: "<< char_message[mCounter]<< endl; 
            // if char = whitespace push [j%26] + 97    
           if(j == 32){
               cipherText.push_back(kspace[0] + 97);
           }
           else if(kspace[j%97] == 0){
                cipherText.push_back('\ ');
           }
           else{
               cipherText.push_back(kspace[j%97] + 96);
           }
            //issue if another char moves to what space is
           // cipherText.push_back( j == 32 ? kspace[0]:kspace[j%97] == 0 ? ' ':kspace[j%97] + 97);
            mCounter++;
        }
    
        if(0<= coin && probRandomCipher >= coin){
        //random cipher
            
            int randomChar = (rand()%27);
            char ciph =cipherspace[randomChar];
            cout <<"random val: "<< randomChar<<" ciph value: " << ciph<< endl;
            cipherText.push_back(ciph);
            randChar++;
            
        }
    //cout <<"cCounter: " << cCounter <<"\t L: "<< L << "\t rand_chars" << randChar <<endl;
    cCounter++;
    }


    cout << "size of cipher vector " << cipherText.size() << endl;
    cout << "actual size of ciphertext "<< L + 1 + randChar<< endl;

    cout<<"vector contents: \n"<< endl;
    for (auto i : cipherText)
        cout << char(i) << " "; 

    auto end = chrono::steady_clock::now();
     cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;


    //write encryption to file
  ofstream output("output2.txt");
  if(!output)
  {  
    cout<<"Cannot open output file\n";
       return 1;
  }
    for(const auto &symbol : cipherText)
        output << symbol; 
return 0;
}

