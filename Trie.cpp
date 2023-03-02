#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,
            rb_tree_tag,tree_order_statistics_node_update>
            ordered_set;
struct node
{
    node *link[26];
    bool flag=false;
    int end_word=0,count_word_prefix=0;
};
class Trie
{
    private:
        node *root;
    public:
        Trie(){root=new node();}
        void insert(string word)
        {
            int len=word.size();
            node *Node=root;
            for (int i=0;i<len;i++)
            {
                if (Node->link[word[i]-'a']==nullptr)//neu ki tu do chua co
                {
                    Node->link[word[i]-'a']=new node();//tao 1 duong dan moi
                }
                Node=Node->link[word[i]-'a']; // tro toi duong dan do
                Node->count_word_prefix++;//So tu co tien to 
            }
            Node->flag=true;//da chen xong word
            Node->end_word++;//So tu ket thuc tai day.
        }
        bool search(string word)
        {
            int len=word.size();
            node *Node=root;
            for (int i=0;i<len;i++)
            {
                if (Node->link[word[i]-'a']!=nullptr)
                {
                    Node=Node->link[word[i]-'a'];
                }
                else return false;
            }
            return Node->flag;
        }
        bool startWith(string word)
        {
            node *Node=root;
            int len=word.size();
            for (int i=0;i<len;i++)
            {
                if (Node->link[word[i]-'a']!=nullptr)
                {
                    Node=Node->link[word[i]-'a'];
                }
                else return false;
            }
            return true;
        }
        void erase(string word)
        {
            node *Node=root;
            for (int i=0;i<word.size();i++)
            {
                if (Node->link[word[i]-'a']==nullptr) return;
                Node=Node->link[word[i]-'a'];
                Node->count_word_prefix--;
            }
            Node->end_word--;
        }
        node* &get_root(){return root;}
};
int main()
{
    Trie tree;
    tree.insert("aaaa");
    cout << tree.search("aaaa");
    node *x=tree.get_root();
    return 0;
}