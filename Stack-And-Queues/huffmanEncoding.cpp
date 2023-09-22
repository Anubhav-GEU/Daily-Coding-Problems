class Solution
{
    public:
        struct node
        {
            int value;
            char ch;
            node *left, *right;
            node()
            {
                value = 0;
                ch = '\0';
                left = right = NULL;
            }
            node(int v, char c, node *l = NULL, node *r = NULL)
            {
                value = v;
                ch = c;
                left = l;
                right = r;
            }
        };
        class comp
        {
            public:
            bool operator()(node *a, node *b)
            {
                return a->value > b->value;
            }
        };
        void preorder(node *root, string s, vector<string> &ans)
        {
            if(root == NULL)
                return;
            if(root->ch != '0')
                ans.push_back(s);
            preorder(root->left, s + '0', ans);
            preorder(root->right, s + '1', ans);
        }
        vector<string> huffmanCodes(string S,vector<int> f,int N)
        {
            priority_queue<node*, vector<node*>, comp> pq;
            node *root = NULL;
            for(int i = 0;i < N;++i)
            {
                node *n = new node(f[i], S[i]);
                pq.push(n);
            }
            while(pq.size() > 1)
            {
                node *l = pq.top();
                pq.pop();
                node *r = pq.top();
                pq.pop();
                node *rt = new node(l->value + r->value, '0', l, r);
                pq.push(rt);
            }
            root = pq.top();
            vector<string> ans;
            preorder(root, "", ans);
            return ans;
        }
};
