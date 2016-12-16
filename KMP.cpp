//KMP algorithm
#include<iostream>
#include<vector>
using namespace std;

class KMP{
public:
    KMP(){};
    void computeNext(string pattern, vector<int>& next);

    int findPatternPos(string target, string pattern, vector<int>& next);
};

void KMP::computeNext(string pattern, vector<int> &next) {
    int j=0;
    for(int i=1; i<pattern.size(); ++i){
        j=next[i-1];//j: the maximum length of such string: proper prefix = suffix
        while(j>0 and pattern[i]!=pattern[j]){
            j=next[j-1];
        }
        next[i]=(j+=(pattern[i]==pattern[j]));

    }
}

int KMP::findPatternPos(string target, string pattern, vector<int>& next) {
    int i=0;
    int j=0;
    while(i<target.size()){
        if(j==pattern.size())
            return i-j;
        if(target[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            while(target[i]!=pattern[j]) {
                if(j==0 and target[i]!=pattern[j])
                {
                    i++;
                    break;
                }
                j = next[j-1];//jump

            }
        }
    }
    return -1;
}

int main(){

    KMP S;
    string target="babcbabcabcaabcabcabcacabc";
    string pattern="abcabcacab";
    vector<int> next(pattern.size(), 0);
    S.computeNext(pattern, next);
    int index=S.findPatternPos(target, pattern, next);
    cout<<index;
}
