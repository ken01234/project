#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

bool hcheck(vector<vector<char> > v){
    int count=0;
    for(int i=0;i<3;i++){
        count=0;
        for(int j=0;j<2;j++){
            if((v[i][j]!=v[i][j+1])||(v[i][j]=='*')){
                break;
            }else{
                count+=1;
            }
        }if(count==2){
            return true;
        }
        count=0;
    }return false;
    
}
bool vcheck(vector<vector<char> > v){
    int count=0;
    for(int i=0;i<3;i++){
        int count=0;
        for(int j=0;j<2;j++){
            if((v[j][i]!=v[j+1][i])||(v[j][i]=='*')){
                break;
            }else{
                count+=1;
            }
        }if(count==2){
            return true;
        }
        count=0;
    }return false;
    
}
bool dcheck(vector<vector<char> > v){
    if((v[0][0]==v[1][1])&&(v[0][0]==v[2][2])&&(v[1][1]!='*')){
        return true;
    }
    if((v[0][2]==v[1][1])&&(v[0][2]==v[2][0])&&(v[1][1]!='*')){
        return true;
    }else{
        return false;
    }
}
vector<vector<char> > bot(vector<vector<char> >v){
    int count=0;
    int n1,n2;
    int c=0;
    srand(time(0));
    n1=(rand()%3);
    n2=(rand()%3);
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(v[i][j]=='k'){
            break;
        }
c++;
    }        
}
count=0;
    if(c==9){
        v[n1][n2]='k';
        return v;
    }
for(int t =0;t<2;t++){
    if((v[2][t]=='k')&&(v[2][t+1]=='*')){
        v[2][t+1]='k';
        count+=1;
        break;
    }
    if((v[1][t]=='k')&&(v[1][t+1]=='*')){
        v[1][t+1]='k';
        count+=1;
        break;
    }
    if((v[0][t]=='k')&&(v[0][t+1]=='*')){
        v[0][t+1]='k';
        count+=1;
        break;
    }
}
if(count==1){
    return v;
}
for(int r =2;r>0;r--){
    if((v[r][2]=='k')&&(v[r-1][2]=='*')){
        v[r-1][2]='k';
        count+=1;
        break;
    }
    if((v[r][1]=='k')&&(v[r-1][1]=='*')){
        v[r-1][1]='k';
        count+=1;
        break;
    }
    if((v[r-1][0]=='k')&&(v[r-1][0]=='*')){
        v[r-1][0]='k';
        count+=1;
        break;
    }
}
if(count==1){
    return v;
}
int a=0;
for(int r =2;r>0;r--){
    if((v[r][r]=='k')&&(v[r-1][r-1]=='*')){
        v[r-1][2]='k';
        break;
    }
    if((v[a][r]=='k')&&(v[a+1][r-1]=='*')){
        v[a+1][r-1]='k';
        break;
    }
    a+=1;
}
if(c==1){
for(int b=0;b<3;b++){
    for(int d=0;d<3;d++){
        if(v[b][d]=='*'){
            v[b][d='k'];
            return v;
        }
    }        
}
}
return v;
}


int main(){
    vector<char> row;
    vector<vector<char> > box;
    vector<string> say;
    say.push_back("BOT: I'm gonna win next time ");
    say.push_back("BOT: I should have seen that coming");
    say.push_back("BOT: NOOOOOOOOOOOOOO");

    srand(time(0));
    int count=0;
    int players;

    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            row.push_back('*');
        }
        box.push_back(row);
    }

    for(int k =0;k<3;k++){
        for(int p =0;p<3;p++){
            cout<<box[k][p]<<" ";
        }
        cout<<'\n';
    }
    cin>>players;
    if(players==2){
    cout<<"This is a game of tic tac toe. The first player will be x and the second player will be y."<<'\n';
int x,x1,y,y1;
// multiplayer
while(count<=9){
    cout<<"Player 1's turn"<<'\n';
    cin>>x>>x1;
    count+=1;
    if(box[x][x1]!='y'){
    box[x][x1]='x';
    }else{
        cout<<"You can't do that!"<<'\n';
    }
        for(int k =0;k<3;k++){
        for(int p =0;p<3;p++){
            cout<<box[k][p]<<" ";
        }
        cout<<'\n';
        }
if((hcheck(box)==true)||(vcheck(box)==true)||(dcheck(box)==true)){
    cout<<"Player 1 win"<<'\n';
    break;
}
cout<<"Player 2's turn"<<'\n';
    cin>>y>>y1;
    count+=1;
    if(box[y][y1]!='x'){
    box[y][y1]='y';
    }else{
        cout<<"You can't do that!"<<'\n';
    }
        for(int k =0;k<3;k++){
        for(int p =0;p<3;p++){
            cout<<box[k][p]<<" ";
        }
        cout<<'\n';
    }
if((hcheck(box)==true)||(vcheck(box)==true)||(dcheck(box)==true)){
    cout<<"Player 2 win"<<'\n';
    break;
}
    if(count==9){
            cout<<"It's a tie"<<endl;
            break;
        }
}return 0;
    
}else{
int x,x1,y,y1;
cout<<"BOT: You're never gonna beat me"<<'\n';
// bot vs player
while(count<=9){
    count+=1;
    box=bot(box);
        for(int k =0;k<3;k++){
        for(int p =0;p<3;p++){
            cout<<box[k][p]<<" ";
        }
        cout<<'\n';
        }
if((hcheck(box)==true)||(vcheck(box)==true)||(dcheck(box)==true)){
    cout<<"Player bot win"<<'\n';
    break;
}
cout<<"Player 1's turn"<<'\n';
    cin>>y>>y1;
    count+=1;
    if(box[y][y1]!='x'){
    box[y][y1]='y';
    }else{
        cout<<"You can't do that!"<<'\n';
    }
        for(int k =0;k<3;k++){
        for(int p =0;p<3;p++){
            cout<<box[k][p]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
if((hcheck(box)==true)||(vcheck(box)==true)||(dcheck(box)==true)){
    cout<<"Player 1 win"<<'\n'<<say[rand()%3]<<'\n';
    break;
}
    if(count==9){
            cout<<"It's a tie"<<endl;
            break;
        }
}return 0;
}
}