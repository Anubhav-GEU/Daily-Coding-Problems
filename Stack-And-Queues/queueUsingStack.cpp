/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        while (q1.empty() == false){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (q2.empty() == false){
            q1.push(q2.front());
            q2.pop();
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code 
        if (q1.empty() == false) {
            int ans = q1.front();
            q1.pop();
            return ans;
        }
        return -1;
}
