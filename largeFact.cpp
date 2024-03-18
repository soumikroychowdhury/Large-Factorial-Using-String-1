#include<iostream>
#include<string>
using namespace std;
string largeMult(string n1,string n2){
    string ans;
    int n=n1.size(),m=n2.size();
    ans.resize(n+m,'0');
    for(int i=n-1;i>=0;i--){
        int carry=0;
        for(int j=m-1;j>=0;j--){
            int product=(n1[i]-'0')*(n2[j]-'0')+(ans[i+j+1]-'0')+carry;
            carry=product/10;
            product%=10;
            ans[i+j+1]=product+'0';
        }
        ans[i]+=carry;
    }
    while(ans.size()>1&&ans[0]=='0') ans.erase(0,1);
    return ans;
}
string largeFact(int n){
    string ans="1";
    for(int i=1;i<=n;i++) ans=largeMult(ans,to_string(i)); //Run a loop from 1 to n and multiply the numbers
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number to calculate the factorial: ";
    cin>>n;
    cout<<"The factorial of "<<n<<" is "<<largeFact(n)<<endl;
    return 0;
}