#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
 
class Solution{

    public:
    //construct a map that stores parent of each node
    unordered_map<Node*, Node*> parent;
    void store_parent(Node* root)
    { 
        queue<Node*> q;
        q.push(root);
        //do level order traversal- first root then it's children ,in tree
        //and store parent of each node in map
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            //if node is root, then store nullptr as it's parent in map
            if(node == root)
            {
                parent[root] = nullptr;
            }
            //if left child exists, store node as parent with left child as key
            //and push left child to queue
            if(node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            //if right child exists, store node as parent with right child as key
            //and push right child to queue
            if(node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    void search(Node* root, int target, Node* &node)
    {
        if(root!= nullptr)
        {
            //cout<<root->data<<endl;
            if(root->data == target) node= root;
            else
            {
                //search in left subtree
                search(root->left, target, node);
                //search in right subtree
                search(root->right, target, node);
            }
        }
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        // Your code goes here
        int sum = 0, dist = 0;
        Node* tnode ;
        store_parent(root);
        search(root, target, tnode);
        //do bfs starting from target node untill kth node is reached, in 3 directions(left, right, parent)
        // Keep track of each node 
       // which are visited so that 
       // while doing BFS we will 
       // not traverse it again
        unordered_set<Node*> s;
        queue<Node*> q;
        q.push(tnode);
        s.insert(tnode);
        while(!q.empty() && dist <= k)
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                Node* curr = q.front();
                q.pop();
                sum+=curr->data;
                //bfs on left child of tnode
                if(curr->left && s.find(curr->left) == s.end())
                {
                    q.push(curr->left);
                    s.insert(curr->left);
                }
                //bfs on right child of tnode
                if(curr->right && s.find(curr->right) == s.end())
                {
                    q.push(curr->right);
                    s.insert(curr->right);
                }
                //bfs on parent of tnode, in upward direction
                if(parent[curr] && s.find(parent[curr]) == s.end())
                {
                    q.push(parent[curr]);
                    s.insert(parent[curr]);
                }
            }
            dist++;
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends

