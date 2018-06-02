//
// Created by thinking on 6/2/18.
//

#include "msg.pb.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace lm;

void listmsg(const lm::helloworld &msg) {
    cout << msg.id() << endl;
    cout << msg.str() << endl;
}


int writeHelloMsg(lm::helloworld &msg, int id, string str, string fileName)
{
    msg.set_id(id);
    msg.set_str(str);
    fstream output("./" + fileName, ios::out | ios::trunc | ios::binary);
    if(!msg.SerializeToOstream(&output)){
        cerr<< "Failed to write msg" << endl;
        return  -1;
    }
    return  0;
}

int main(){
    lm::helloworld msg1;
    string filename = "hello.pb";
    if(-1 == writeHelloMsg(msg1, 101, "hello", filename)) {
        return  -1;
    }
    fstream input(filename, ios::in | ios::binary);
    if(!msg1.ParseFromIstream(&input)){
        cerr << "Failed to parse address book." << endl;
        return  -1;
    }
    listmsg(msg1);
    return 0;
}



