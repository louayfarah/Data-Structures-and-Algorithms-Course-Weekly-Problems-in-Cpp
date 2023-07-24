//Louay Farah
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
 
bool is_greater_or_equal(string o2, string o1)
{
    vector<char> m(500, 0);
 
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
 
    if(m[o2[0]] >= m[o1[0]])
        return true;
 
    return false;
}
 
 
int apply(int a, int b, string operation)
{
    if(operation == "+")
    {
        return (a+b);
    }
    else if(operation == "-")
    {
        return (a-b);
    }
    else if(operation == "*")
    {
        return (a*b);
    }
    else if(operation == "/")
    {
        return (a/b);
    }
    else if(operation == "min")
    {
        return min(a, b);
    }
    else if(operation == "max")
    {
        return max(a, b);
    }
 
    return -1;
}
 
template <typename T> class MyStack
{
private:
    int size = 0;
public:
    vector<T> arr;
    void push(T elt);
    void pop();
    T top();
    int stackSize();
    bool empty();
};
 
template <typename T> void MyStack<T>::push(T elt)
{
    MyStack::arr.pb(elt);
    MyStack::size++;
}
 
template <typename T> void MyStack<T>::pop()
{
    MyStack::arr.pop_back();
    MyStack::size--;
}
 
template <typename T> T MyStack<T>::top()
{
    T elt = *(MyStack::arr.end()-1);
 
    return elt;
}
 
template <typename T> int MyStack<T>::stackSize()
{
    return MyStack::size;
}
 
template <typename T> bool MyStack<T>::empty()
{
    return (MyStack::size == 0);
}
 
 
template <typename T> class MyQueue
{
private:
    int size = 0;
public:
    list<T> arr;
    void push(T elt);
    void pop();
    T front();
    int queueSize();
    bool empty();
};
 
template <typename T> void MyQueue<T>::push(T elt)
{
    arr.push_back(elt);
    MyQueue::size++;
}
 
template <typename T> void MyQueue<T>::pop()
{
    arr.pop_front();
    MyQueue::size--;
}
 
template <typename T> T MyQueue<T>::front()
{
    T elt = *(MyQueue::arr.begin());
    return elt;
}
 
template <typename T> int MyQueue<T>::queueSize()
{
    return MyQueue::size;
}
 
template <typename T> bool MyQueue<T>::empty()
{
    return (MyQueue::size == 0);
}
 
 
int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
 
 
    MyStack<string> s;
    MyQueue<string> q;
 
    vector<string> buffer;
 
    string curr;
    while(cin >> curr)
    {
        buffer.pb(curr);
 
        if(curr == "(" || curr == ")")
        {
            buffer.pb(curr);
        }
        else if(curr == ",")
        {
            buffer.pop_back();
            buffer.pb(")");
            buffer.pb("(");
        }
    }
 
 
    for(auto elt: buffer)
    {
        curr = elt;
 
        if(curr[0] >= '0' && curr[0] <= '9')
        {
            q.push(curr);
        }
        else if(curr == "min" || curr == "max")
        {
            s.push(curr);
        }
        else if(curr == "(")
        {
            s.push(curr);
        }
        else if(curr == ")")
        {
            while(!s.empty() && (s.top() != "("))
            {
                q.push(s.top());
                s.pop();
            }
            s.pop();
 
            if(!s.empty() && (s.top() == "min" || s.top() == "max"))
            {
                q.push(s.top());
                s.pop();
            }
        }
        else
        {
            while(!s.empty() && (s.top() != "(") && is_greater_or_equal(s.top(), curr))
            {
                q.push(s.top());
                s.pop();
            }
            s.push(curr);
        }
    }
 
    while(!s.empty())
    {
        if(s.top() != "(")
        {
            q.push(s.top());
            s.pop();
        }
    }
 
    buffer.clear();
    while(!q.empty())
    {
        buffer.pb(q.front());
        q.pop();
    }
 
    MyStack<int> is;
 
    for(int i = 0; i<int(buffer.size()); i++)
    {
        if(buffer[i][0] >= '0' && buffer[i][0] <= '9')
        {
            is.push(int(buffer[i][0]-'0'));
        }
        else
        {
            int b = is.top();
            is.pop();
            int a = is.top();
            is.pop();
 
            int c = apply(a, b, buffer[i]);
            is.push(c);
        }
    }
 
    cout << is.top() << endl;
 
    return 0;
}