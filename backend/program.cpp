#include<bits/stdc++.h>
using namespace std;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

void findRotateMatrix(){
    vector<vector<int>> matrix;
    int n,v;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v;
            matrix[i].push_back(v);   // input matrix building
        }
    }
    // matrix is ratate 90 degree or anti clockwise
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-1-i;j++){
            int val = matrix[i][j];
            matrix[i][j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[n-1-i][j];
            matrix[n-1-i][j] = val;
        }
    }
    // matrix is the final rotate matrix

    // rowwise swapping
    for(int i=0;i<n/2;i++){
        int temp =0;
        for(int j=0;j<n;j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[n-1-i][j];
            matrix[n-1-i][j] = temp;
        }
    }
    // column wise swaping
    for(int i=0;i<n/2;i++){
        int temp =0;
        for(int j=0;j<n;j++){
            temp = matrix[j][i];
            matrix[j][i] = matrix[j][n-1-i];
            matrix[j][n-1-i] = temp;
        }
    }

}
void lexicoSmallest(){
    string s;
    cin>>s; 
    int q;
    cin>>q; // operation
    int n= s.size();
    vector<set<int>>pos(26);
    for(int i=0;i<n;i++){
      pos[s[i]-'a'].insert(i); // character ar position gulo insert korlam
    }
    int swaps = 0;
    for(int i=0;i<n;i++){
        // checkig the smallest character
        for(int ch = 0; ch<s[i]-'a';ch++){
            if(!pos[ch].empty()){
               auto it = pos[ch].rbegin(); // sothik hobe jodi loop chalai
               int j = *it;
               if(j<i) continue;

               if(swaps < q){
              
                swap(s[i],s[j]);
                swaps++;

                 // update position
                 pos[ch].erase(j); // dite hobe it
                 pos[ch].insert(i);
                 pos[s[j]-'a'].erase(i); //dite hobe j
                 pos[s[j]-'a'].insert(j);
                 break;
               }
            }
        }
    }
    cout<<s<<endl;
}
void LCSubstring(){
    int maxLength = 0,lastInd=0;
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size() , m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m,0)); // first I assign all element is 0
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > maxLength){
                    maxLength = dp[i][j];
                    lastInd = i-1;
                }
            }
        }
    }
    string lcsubstring = s1.substr(lastInd-maxLength+1, maxLength);
    cout<<lcsubstring<<endl;
}
// transform the given string into a abcabcabc.... format
void transformString(){
    string s;
    cin>>s;
    int n= s.size();
    int extraChar;
    if(s[0] == 'a') extraChar = 0;  // we do not need to add any character
    else if(s[0]=='b') extraChar = 1; // we add 'a'
    else extraChar = 2; //(s[0] == 'c') // we add 'ab' .so extrachar = 2

    for(int i=1;i<n;i++){
        if(s[i] == 'a'){
            if(s[i-1] == 'a') extraChar += 2;   // if given string has 'aa' than we add 'bc' between them finally 'aa' became 'abca'
            else if(s[i-1] == 'b') extraChar += 1; // if given string has 'ba' than we add 'c' between them finally 'ba' became 'bca'
            else extraChar += 0;   // if given string has 'ca' than we do not need to add any character
        }
        else if(s[i] == 'b'){
            if(s[i-1] == 'a') extraChar += 0; // if given string has 'ab' than we do not need to add any character
            else if(s[i-1] == 'b') extraChar += 2; // if given string has 'bb' than we add 'ca' between them finally 'bb' became 'bcab'
            else extraChar += 1; // if given string has 'cb' than we add 'a' between them finally 'cb' became 'cab'
        }
        else{   // s[i] == 'c'
            if(s[i-1] == 'a') extraChar += 1; // if given string has 'ac' than we add 'b' between them finally 'ac' became 'abc'
            else if(s[i-1] == 'b') extraChar += 0; // if given string has 'bc' than we do not need to add any character
            else extraChar += 2;  // if given string has 'cc' than we add 'ab' between them finally 'cc' became 'cabc'
        }
    }
    if(s[n-1] == 'a') extraChar += 2;  // if last character is 'a' then we add 'bc' 
    else if(s[n-1] == 'b') extraChar += 1;// if last character is 'b' then we add 'c' 
    else extraChar += 0;  // if last character is 'c' then we do need to add any character 
    cout<<extraChar<<endl;
    return;
}
void topological_sort(){
    int n;  // enter node 0 to n-1 node 
    cin>>n;
    vector<vector<int>> adj(n); // for graph representation
    vector<int> indegree(n,0);
    // input the edge
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); 
        indegree[v]++;
    }
    // for listing the node which indegree is zero
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    // finding topological sort
    vector<int> topoSort;
    while(! q.empty()){
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto n : adj[node]){
            indegree[n]--;
            if(indegree[n]==0)  q.push(n);
        }
    }

    for(int i=0;i<topoSort.size();i++){
        cout<<topoSort[i]<<endl;
    }
    return;
}
void findBlankSpace(){
    string s = "Hello world";
    if(s.find(' ') != s.npos){
        cout<<"there is blank space"<<endl;
    }
    cout<<count(s.begin(),s.end(),' ')<<" blank space";
    // remove blank space
    string str = "Hello World, How are you?";
    string result = "";

    for (char c : str) {
        if (c != ' ') {
            result += c;
        }
    }

    cout << "String after removing spaces: " << result << endl;
}
bool isPalindrome(string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
void arrayReduction(){
    int n,v;
    cin>>n;
    vector<int> num(n);
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        cin>>v;
        num.push_back(v);
        pq.push(-v);
    }
    int x,y,ans=0,val;
    while(pq.size()>=2){
      x = -pq.top();
      pq.pop();
      y = -pq.top();
      pq.pop();
      val = x+y;
      ans+=val;

      pq.push(-val);
    }
    cout<<ans<<endl;
    return;
}
void priority(){
    int n,v;
    cin>>n;
    vector<int> num(n);
    vector<pair<int,int>> vp;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        cin>>v;
        num.push_back(v);
        vp.push_back({v,i});
    } 
    sort(vp.begin(),vp.end());  // for solving purpose I sort this array
    int g = 0;
    for(int i=0;i<n;i++){
        int ind = vp[i].second;

        if(i-1>=0 && vp[i-1].first==vp[i].first){
            ans[ind] = g;
        }
        else {
            g++;
            ans[ind] = g;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;

}
void negPosThree(){
    int n,v;
    cin>>n;
    vector<int> num;
    int sum = 0,ans = n;
    for(int i=0;i<n;i++){
        cin>>v;
        num.push_back(v);
        sum += v;
    }
    if(sum>=0){
        cout<<ans<<endl;
        return;
    }
    sort(num.begin(),num.end());
    for(int i=0;i<n;i++){
        sum -= num[i];
        ans--;
        if(sum>=0){
           cout<<ans<<endl;
           return;
        }
    }
    cout<<0<<endl;

}

int main(){
    FastIO;
    //transformString(); 
    //topological_sort();
    //findBlankSpace();
    //arrayReduction();
    //priority();
    //negPosThree();
    //lexicoSmallest();
    LCSubstring();
    return 0;
}
// // transform the given string into a abcabcabc.... format
// void transformString(){
//     string s;
//     cin>>s;
//     int n= s.size();
//     int extraChar;
//     if(s[0] == 'a') extraChar = 0;
//     else if(s[0]=='b') extraChar = 1;
//     else extraChar = 2; //(s[0] == 'c')

//     for(int i=1;i<n;i++){
//         if(s[i] == 'a'){
//             if(s[i-1] == 'a') extraChar += 2;
//             else if(s[i-1] == 'b') extraChar += 1;
//             else extraChar += 0;
//         }
//         else if(s[i] == 'b'){
//             if(s[i-1] == 'a') extraChar += 0;
//             else if(s[i-1] == 'b') extraChar += 2;
//             else extraChar += 1;
//         }
//         else{   // s[i] == 'c'
//             if(s[i-1] == 'a') extraChar += 1;
//             else if(s[i-1] == 'b') extraChar += 0;
//             else extraChar += 2;
//         }
//     }
//     if(s[n-1] == 'a') extraChar += 2;
//     else if(s[n-1] == 'b') extraChar += 1;
//     else extraChar += 0;
//     cout<<extraChar<<endl;
//     return;
// }
// rotate a matrix

// find the area of a triangle ,we have only three co-ordinate of this triangle
void findArea(){
    vector<vector<int>> point(3,vector<int>(2));
    for(int i=0;i<3;i++){
       cin>>point[i][0]>>point[i][1];
    }
   // vector<vector<int>> point = {{1,0},{5,0},{3,5}};
    int len1 = 0, len2 = 0;
    int x1,x2,x3,y1,y2,y3;
    x1 = point[0][0];
    y1 = point[0][1];
    
    x2 = point[1][0];
    y2 = point[1][1];

    x3 = point[2][0];
    y3 = point[2][1];

    if(x1 == x2 || y1 == y2){
        if(x1 == x2){
            len1 = abs(y1-y2);
            len2 = abs(x3-x1);
        }
        else {
            len1 = abs(x1-x2);
            len2 = abs(y3-y1);
        }
    }
    else if(x1 == x3 || y1 == y3){
        if(x1 == x3){
            len1 = abs(y1-y3);
            len2 = abs(x2-x1);
        }
        else {
            len1 = abs(x1-x3);
            len2 = abs(y2-y1);
        }
    }
    else{
        if(x2 == x3){
            len1 = abs(y2-y3);
            len2 = abs(x1-x2);
        }
        else {
            len1 = abs(x2-x3);
            len2 = abs(y1-y2);
        }
    }
    int area = (len1*len2)/2;
    cout<<area<<endl;
}