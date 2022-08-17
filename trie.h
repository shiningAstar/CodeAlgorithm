#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

typedef struct Node{
    int t = 0;  //为1表示有以此位置结束单词
    Node l[26] = {0};
}Node;

vector<Node> nodes;
int n;

void init_trie(){
    n = 0; nodes.emplace_back(Node()); ++n;
}

int add_word_letter(string &w, int wn, int i, int ni){
    if(i == wn - 1){
        if(nodes[ni].t == 0){
            nodes[ni].t = 1;
            return 0;
        } else return -1;
    }
    int ln;
    ++i;
    ln = w[i] - 'a';
    if(nodes[ni].l[ln] == 0){
        nodes.emplace_back(Node());
        nodes[ni].l[ln] = n; ++n;
    }
    return add_word_letter(w, wn, i, nodes[ni].l[ln]);
}

int add_word(string &w){
    return add_word_letter(w, w.size(), -1, 0);
}

int find_word_letter(string &w, int wn, int i, int ni){
    if(i == wn - 1){
        if(nodes[ni].t == 1) return 0;
        else return -1;
    }
    int ln;
    ++i;
    ln = w[i] - 'a';
    if(nodes[ni].l[ln] > 0) {
        return find_word_letter(w, wn, i, nodes[ni].l[ln]);
    } else return -1;
}

int find_word(string &w){
    return find_word_letter(w, w.size(), -1, 0);
}


#endif