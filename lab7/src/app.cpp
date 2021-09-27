#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <Array.h>
#include <LinkedList.h>
#include <TimeSupport.h>
#include <RandomSupport.h>
#include <BST.h>
#include <HashTable.h>


using namespace std;

string reverse(string word){
    reverse(word.begin(), word.end());
    return word;
}


int main(){

    fstream file;

    ResizableArray words;
    HashTable mT;

     file.open("words.txt",ios::in);
     if (file.is_open()){
         string tp;
        while(getline(file, tp)){
            mT.insert(tp);
            words.append(tp);
        }
        file.close();
    }
    else{
        cout << "Could not read file..." << endl;
    }

     timestamp begin = current_time();

    // int count = 0;
    // for(int i = 0; i < words.count; i++){
    //     if(mT.search(reverse(words[i]))){
    //         count++;
    //         //cout<< words[i] << endl;
    //     }
    // }

     timestamp end = current_time();
    long diff = time_diff(begin, end);
    mT.print();
    // cout << "There were " << count << " words that match..." << endl;
    cout << "in " << diff << endl;
    return 0;
}




















