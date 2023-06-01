#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class myString
{
    private:
        string m_str;
    public:
        myString(string s){
            m_str=s;
        }
};

class ReadClass
{
    public:
    void showClass(){
        int n=0;
        ifstream in;
        string line;
        string str("class");
        in.open("main.cpp");
        if(in.fail()){
            cout<<"Erro to open file."<<endl;
        }
        while (getline(in, line)) {
            size_t found = line.find(str);
            if (found != string::npos){
                const char* characters = line.c_str();
                if(characters[0]=='c'){
                    cout << characters << endl;
                    n++;
                }
            }
        }
        cout<<n<<" class in main.cpp"<<endl;
    }
};

int main()
{
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
