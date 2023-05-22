#include <iostream>
#include <ostream>
#include <vector>
#include <iterator>
#include <unistd.h>
#include <cstdlib>
#include <algorithm> 


using namespace std;
class golem{
  public: 
  int hp,speed,attack,magic;
  vector<int> attri(){
    vector<int>s;
    hp=(rand()%10)+10;
    speed=(rand()%10);
    attack=(rand()%10)+10;
    magic=(rand()%5);
    s.push_back(hp);
    s.push_back(speed);
    s.push_back(attack);
    s.push_back(magic);
    return s;
  }

};
class knight{
  public: 
  int hp,speed,attack,magic;
  vector<int> attri(){
    vector<int>s;
    hp=(rand()%10);
    speed=(rand()%10)+10;
    attack=(rand()%10)+10;
    magic=(rand()%5);
    s.push_back(hp);
    s.push_back(speed);
    s.push_back(attack);
    s.push_back(magic);
    return s;
  }

};
class potato{
  public: 
  int hp,speed,attack,magic;
  vector<int> attri(){
    vector<int>s;
    hp=(rand()%10)+10;
    speed=(rand()%10)+10;
    attack=(rand()%10)+10;
    magic=(rand()%10)+10;
    s.push_back(hp);
    s.push_back(speed);
    s.push_back(attack);
    s.push_back(magic);
    return s;
  }

};

class boss{
  public: 
  int hp,speed,attack,magic;
  vector<int> attri(){
    vector<int>s;
    hp=(rand()%10)+20;
    speed=(rand()%10)+10;
    attack=(rand()%10)+10;
    magic=(rand()%10)+10;
    s.push_back(hp);
    s.push_back(speed);
    s.push_back(attack);
    s.push_back(magic);
    return s;
  }

};
vector<int> fight(vector<int> v,vector<int>e){
string answer;
int random;
int defence=v[4];
bool defend=false;
  cout<<"Oh no an enemy approaches"<<endl;
while(e[0]>0){
  cout<<"Will you attack, use magic, run away or defend"<<endl;
  cin>>answer;
  if(answer=="ATTACK"){
    e[0]= e[0]-(rand()%v[2]+1);
  }
  if(answer=="MAGIC"){
    e[0]= e[0]-(rand()%v[3]+1);    
  }
  if(answer=="RUN"){
    if(v[1]>e[1]){
      cout<<"You have managed to escape"<<endl;
      break;
    }
    else{
      cout<<"You are not fast enough to run away"<<endl;
    }
  }
  if(answer=="DEFEND"){
    defend=true;
  }
  cout<<"The enemy's hp is "<<e[0]<<endl;
if(e[0]<=0){
  cout<<"you won"<<endl;
  break;
}
  sleep(2);
  cout<<"Now the enemy attacks"<<endl;
random=(rand()%2)+1;
if(defend==true){
  if(random==1){
    cout<<"It attacks"<<endl;
    v[0]= v[0]-(rand()%e[2]+1)+defence;
    random=0;
    defend=false;
}else{
  cout<<"It uses magic"<<endl;
    v[0]= v[0]-(rand()%e[3]+1)+defence;  
    random=0;
    defend=false;
}
}else{
if(random==1){
    v[0]= v[0]-(rand()%e[2]+1);
    random=0;
}else{
    v[0]= v[0]-(rand()%e[3]+1);  
    random=0;
}
}
cout<<"Your health is now "<<v[0]<<endl;
if(v[0]<=0){
  cout<<"you lose"<<endl;
  break;
}
}
  return v;
}

vector<string> fill(string s,string s1, string s2,string s3, string s4,vector<string>v){
v.push_back(s);
v.push_back(s1);
v.push_back(s2);
v.push_back(s3);
v.push_back(s4);
return v;
}
//shop will give two items that will boost one attribute, the items will be random out of 5. The chosen weapon will increase the stat of the player. The standard weapon is a sword.

vector<int> shop(vector<int> v){
  vector<int>chosen;
  vector<string> sitems;
  vector<string> item;
  vector<string> presented;
  int n1,n2,n3;
sitems = fill("kimono","iikutsu","tate","chikara","ki", sitems);//0 = hp, 1 = sp ,2 = df ,3 = at,4=mg
item = fill("armor","Better shoes","better shield","strength","tree",item);
cout<<"You have reached the store"<<endl;
sleep(2);
cout<<"Which of three item do you chose? Enter 1,2 or 3."<<endl;
int TF;
for(int i=0;i<3;i++){
  TF=(rand()%100)<10;
if(TF<=10){
  n1=rand()%5;
  cout<<sitems[n1]<<endl;
  presented.push_back(sitems[n1]);
  
}else{
  n2=rand()%5;
  cout<<item[n2]<<endl;
  presented.push_back(item[n2]);
}
}
cin>>n3;
  cout<<"Ah, you have chose the "<<presented[n3-1] <<endl;
  int place;
  for (int t=0;t<presented.size();t++){
    if(presented[t]==presented[n3-1]){
      place=t;
    }
  }
  for(int j=0;j<sitems.size();j++){
    if(presented[n3-1]==sitems[j]){
      v[place]+=10;
      break;
    }if(presented[n3-1]==item[j]){
      v[place]+=5;
      break;
    }
  }
  return v;
}
//
//main
// The defend ability giving health to the player, let it be. makes it a bit easier
int main(){
  string name,race;
  string r = " ";
  vector<int>skill;//first index is health,second is speed,third is defence,fourth is attack and fifth is magic
  vector<int>s;
  srand(time(0));
    cout<<"Hello, welcome to this adventure"<<endl;
      sleep(2);
    cout<<"Before we continue with this game, what is the name of the hero you want to be?"<<endl;
    getline(cin,name);
    cout<<"That's a good name. In this world, there will be 5 levels with either monster to fight, a store to upgrade or switch weapons and nothing to just relax."<<endl;
    sleep(3);
    cout<<"There are 4 races to choose from. Elves, humans, robots and undead"<<endl;
    sleep(3);
    cout<<"You will find out the attributes that each race have when you choose them. Also, although you may choose the same race for ever playthrough, the magnitude of the attributes will differ."<<endl;
    sleep(4);
    cout<<"Which race will you choose? Please type it out in capital letters. EVERYTHING WOULD BE IN CAPITAL LETTERS MUAHAHAHAHAH"<<endl<<endl;
    cin>>race;
  if(r=="ELF"){
  for(int e=0;e<5;e++){
    skill.push_back((rand()%10)+1);
  }
    skill[3]=((rand()%10)+1)+10;
    
  }
  if(race=="HUMAN"){
  for(int h=0;h<5;h++){
    skill.push_back((rand()%10)+1);
  }
    skill[1]=((rand()%10)+1)+10;

  }
  if(race=="ROBOT"){
  for(int r=0;r<5;r++){
    skill.push_back((rand()%10)+1);
  }
    skill[2]=((rand()%10)+1)+10;
  }
  if(race=="UNDEAD"){
  for(int u=0;u<5;u++){
    skill.push_back((rand()%10)+1);
  }
    skill[0]=((rand()%10)+1)+10;
  }

  for(int j=0;j<5;j++){
    cout<<skill[j]<<" ";
  }cout<<endl;
  cout<<"The first number is the health, then speed, then defence, then attack and magic. The specialty of the race will be always larger than 10"<<endl;
  sleep(3);
  cout<<"Now, let's start our adventure"<<endl<<endl;


int count=0;
bool lose=false;
while(count!=5){
  int possibility = (rand()%5)+1;
  for(int q =0; q<3;q++){
    cout<<'.'<<endl;
      sleep(1);
  }
  sleep(1);
if(possibility==1){
  golem enemy;
  cout<<"A golem approaches!"<<endl<<endl;
  s=enemy.attri();
    sleep(2);
      for(int g=0;g<5;g++){
    cout<<s[g]<<" ";
  }cout<<endl;
skill = fight(skill,s);
if(skill[0]==0){
  count=5;
}
count+=1;
sleep(1);
}
if(possibility==2){
  knight e2;
  cout<<"A knight approaches!"<<endl<<endl;
  s=e2.attri();
    sleep(2);
  for(int k=0;k<5;k++){
    cout<<s[k]<<" ";
  }cout<<endl;
  skill=fight(skill,s);
  if(skill[0]==0){
  count=5;
}
  count+=1;
sleep(1);
}
if(possibility==3){
  potato e3;
  cout<<"A potato approaches?! "<<endl<<endl;
  sleep(2);
  s=e3.attri();
  for(int p=0;p<5;p++){
    cout<<s[p]<<" ";
  }cout<<endl;
  skill = fight(skill,s);
  if(skill[0]==0){
  count=5;
}
  count+=1;
sleep(1);
}
if(possibility==4){
skill = shop(skill);
  for(int l=0;l<5;l++){
    cout<<skill[l]<<" ";
  }cout<<endl;
  count+=1;
}
if(skill[0]<=0){
count=3;
break;
}
}

if(skill[0]>0){
boss b1;
cout<<"You have reached the boss of the game!"<<endl<<endl;
s=b1.attri();
sleep(2);
  for(int b=0;b<5;b++){
    cout<<s[b]<<" ";
  }cout<<endl;
  skill=fight(skill,s);
sleep(1);
if(skill[0]>0){
cout<<"Congrats! You have killed the boss of the game, hope you had fun!"<<endl;
}else{
  cout<<"Game over"<<endl;
}
}
}
