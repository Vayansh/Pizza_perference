#include<bits/stdc++.h>

using namespace std;

class customerin{
    private:
        int likes;
        int dislikes;
        string *like_ing;
        string *dislike_ing;
    public:
        void put_like(int i)
        {
            likes = i;
            like_ing= new string[likes];   
        }
        int get_like()
        {
            return likes;
        }
        string get_like_ing(int i)
        {
            return like_ing[i];
        }
        void input_like()
        {
            for(int i=0; i<likes; i++)
            {
                cin >> *(like_ing+i);
            }
        }  
        void put_dislike(int i)
        {    
            dislikes = i;
            dislike_ing = new string[dislikes];
        }
        int get_dislike()
        {
            return dislikes;
        }
        string get_dislike_ing(int i)
        {
            return dislike_ing[i];
        }
        void input_dislike()
        {
            for(int i=0; i<dislikes; i++)
            {
                cin >> *(dislike_ing+i);
            }
        }  
        
};
bool check(string str,string final_ing[],int j)
{
    for(int i=0;i<j;i++)
    {
        if(final_ing[i]==str)
           return true;   
    }
    return false;
}
bool check(string str,int j,string total_dislike[])
{
    for(int i=0;i<j;i++)
    {
        if(total_dislike[i]==str)
           return false;   
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int likes;
    int dislikes;
    int var=0;
    customerin customerpref[n];
    
    for(int i=0; i<n;i++)
    {
        cin>>likes;
        customerpref[i].put_like(likes);
        customerpref[i].input_like();
        cout << endl;
        cin >> dislikes;
        var+=dislikes;
        customerpref[i].put_dislike(dislikes);
        customerpref[i].input_dislike();
        cout << endl;
    }
    int pos = 0;
    string total_dislike[var];
    for(int i =0;i<n;i++)
    {   
        for(int j=0;j<customerpref[i].get_dislike();j++)
        {
            total_dislike[pos]=customerpref[i].get_dislike_ing(j);
            pos++;
        }
    }
    int tot = 0;
    string final_ing[5*n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<customerpref[i].get_like();j++)
        {
            if(check(customerpref[i].get_like_ing(j),final_ing,tot))
            {
                continue;
            }
            if(check(customerpref[i].get_like_ing(j),var,total_dislike))
            {
                final_ing[tot] = customerpref[i].get_like_ing(j);
                tot ++;    
            }
            else
                continue;
        }
    }
    cout << tot << endl;
    for(int i=0;i<tot;i++)
    {
        cout << final_ing[i] << " ";
    }

    return 0;
}