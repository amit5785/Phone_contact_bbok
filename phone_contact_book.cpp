#include<bits/stdc++.h>
using namespace std;

class MyTrieNode
{
private :
    vector<MyTrieNode *> data;
    set<int> index;
public :
    
    MyTrieNode()
    {
        data=vector<MyTrieNode*> (27,NULL);
        // index=-1;
    }
    
    void insert(string word,int i)
    {
        MyTrieNode *root=this;
        for(auto ch : word)
        {
            if(root->data[ch-'a']==NULL)
            {
                root->data[ch-'a']=new MyTrieNode();
            }
            root=root->data[ch-'a'];
            // root->index=i;
            root->index.insert(i);
        }
        
        // root->index=i;
        root->index.insert(i);
    }
    
    set<int> searchWord(string word)
    {
        set<int> res;
        MyTrieNode *root=this;
        for(auto ch:word)
        {
            if(root->data[ch-'a']==NULL)
            {
                return res;
            }

            root=root->data[ch-'a'];
            // res.insert(root->index);
            res.insert(root->index.begin(),root->index.end());
        }
        res.insert(root->index.begin(),root->index.end());
        // res.insert(root->index);
        return res;
    }
};


class WordFilter {
private:
    MyTrieNode head;
public: 
    void dataStorage(vector<string>& words) 
    {
        int len=words.size();
        for(int i=0;i<len;i++)
        {
            int n=words[i].size();
            for(int j=0;j<=n;j++)
            {
                head.insert(words[i].substr(j)+'{'+words[i],i);
            }
        }
    }
    
    set<int> matchContact(string prefix, string suffix) 
    {
        return head.searchWord((suffix+'{'+prefix));
    }
};


int main()
{
    WordFilter obj;
    
    int n;

    vector<string> contName,phoneNum;

    cout<<"total number of contacts"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"name"<<"  "<<"phone number"<<endl;
        string name,phone;
        cin>>name>>phone;

        contName.push_back(name);
        phoneNum.push_back(phone);
    }
    cout<<endl;

    obj.dataStorage(contName);
    
    cout<<"number of queries to be done"<<endl;
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cout<<"type prefix of name that you want to search"<<endl;
        string name;
        cin>>name;
        auto res=obj.matchContact(name,name);
        for(auto ind:res)
        {
          cout<<contName[ind]<<" "<<phoneNum[ind]<<endl;
        }

        cout<<endl;
    }

    return 0;
}