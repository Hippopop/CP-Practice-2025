#include<bits/stdc++.h>

using namespace std;


int queue1[100], front =-1, rear =-1,max_size =5;


void queue_push(int value)
{
        
        if(front==-1)
        {
                front=rear =0;
                queue1[rear]=value;
        }
        else
        {
                rear= (rear+1)%max_size;
                if(rear!=front)
                {
                        queue1[rear] = value;
                }
                else
                {
                        rear=(rear+max_size-1)%max_size;
                        cout<<"OverFlow"<<endl;
                }
        }
        
}


void queue_pop()
{
        if(front==-1)
        {
                cout<<"Empty"<<endl;
        }
        else
        {
                if (front== rear)
                {
                      front=rear=-1;  
                }
                else
                        front = (front+1)%max_size;
        }
}





void queue_print()
{
        if(front==-1)
        {
                cout<<"Empty"<<endl;
        }
        
        else
        {
                // for(int i=front;i<max_size;i++)
                // {
                //         cout<<queue1[i]<<endl;
                // }
                // for(int i=0;i<=rear;i++)
                // {
                //         cout<<queue1[i]<<endl;
                // }

                int i = front;
                while(i!=rear)
                {
                        cout<<queue1[i]<<endl;
                        i=(i+1)%max_size;
                }
                cout<<queue1[rear]<<endl;
        }

        
        
}




int main()
{

        // queue<int> q;

        // q.push(1);

        // q.push(2);

        // q.push(3);

        // q.push(4);


        // cout<<q.front()<<endl;

        // q.pop();

        // cout<<q.front()<<endl;

        // cout<< "Printing the whole queue"<<endl;

        // while(q.size()!=0)
        // {
        //         cout<<q.front()<<endl;
        //         q.pop();
        // }


        queue_push(14);
        queue_push(22);
        queue_push(13);
        queue_push(-6);


        queue_print();



        

        

        queue_pop();
        queue_pop();

        queue_print();


        queue_push(9);
        queue_push(20);
        queue_push(5);


        queue_print();

        queue_push(20);

        //queue_print();



        
        
}
