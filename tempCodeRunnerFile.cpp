#include<iostream>
#include<cmath>
using namespace std;
class Stack{
private:
    int a[100];
    int top;
public:
    Stack()
    {
        top=-1;
    }
    void push(int val)
    {
        a[++top]=val;
    }
    int pop()
    {
        int p=a[top--];
        return p;
    }
};
int evaluate(char x, int op1, int op2)
{
    if (x == '+')
        return(op1 + op2);

    if (x == '-')
        return(op1 - op2);

    if (x == '*')
        return(op1 * op2);

    if (x == '/')
        return(op1 / op2);

    if (x == '%')
        return(op1 % op2);

    if (x == '$')
        return(pow(op1, op2));

    return 0;
}

int main(){
    Stack s;
    char x;
    int op1, op2, val;
    cout<<"\nEnter postfix Expresson :";
     while ((x = getchar()) != '\n')
    {
        if (isdigit(x))
        {
            s.push(x - 48);
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();

            val = evaluate(x, op1, op2);

            s.push(val);
        }
    }

    val = s.pop();

    cout << "\nAnswer = " << val;

    return 0;
} 
