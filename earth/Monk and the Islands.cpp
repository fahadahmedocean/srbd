#include <stdio.h>
#include<malloc.h>

struct queuenode
{
    int data;
    struct queuenode *next;
}*rear,*front;


void createqueue()faha
{
    rear =front =NULL;
}

void enqueue(int data)
{
    if(rear==NULL)
    {
        rear=malloc(sizeof(struct queuenode));
        rear->next=NULL;
        rear->data=data;
        front = rear;
        return;
    }
    struct queuenode *temp = malloc(sizeof(struct queuenode));
    temp->data = data;
    temp->next=NULL;
    rear->next=temp;
    rear = temp;
    return;
}

int dequeue()
{
    if(front == NULL)
        return;

    if(front == rear)
    {
        struct queuenode *temp = front;
        front = NULL;
        rear = NULL;
        return temp->data;
    }
    struct queuenode *temp = front;
    front = front->next;
    return temp->data;

}

struct adjlist
{
    int data;
    struct adjlist *next;
};

struct adjlisthead
{
    struct adjlist *head;
};

struct graph
{
    int v;
    struct adjlisthead *arr;
};

struct adjlist *createnode(int data)
{
    struct adjlist *newnode = malloc(sizeof(struct adjlist));
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
}

struct graph *creategraph(int vertex)
{
    struct graph *g = malloc(sizeof(struct graph));
    g->v = vertex;
    g->arr = (struct adjlisthead *)malloc(vertex*sizeof(struct adjlisthead));
    for(int i=0; i<vertex; i++)
    {
        g->arr[i].head = NULL;
    }
    return g;
}

void addedge(struct graph *g,int src,int des)
{
    struct adjlist *newnode = createnode(des);
    newnode->next = g->arr[src-1].head;
    g->arr[src-1].head=newnode;
    newnode = createnode(src);
    newnode->next = g->arr[des-1].head;
    g->arr[des-1].head=newnode;
    return;


}


int main()
{

    int T;
    scanf("%d",&T);
    while(T)
    {
        int N, M;
        scanf("%d %d",&N,&M);

        struct graph *g  =creategraph(N);

        int src,des;
        while(M)
        {
            scanf("%d %d",&src,&des);
            addedge(g,src,des);
            M--;
        }

        int *level = (int *)malloc(N*sizeof(int));

        for(int i=0; i<N; i++)
        {
            level[i]=0;
        }

        int start =1;
        int target = N;
        enqueue(start);
        level[start-1]=1;
        while(front!=NULL)
        {
            int temp = dequeue();
            struct adjlist *curr_head = g->arr[temp-1].head;
            while(curr_head)
            {
                if(level[(curr_head->data)-1]==0)
                {
                    level[(curr_head->data)-1] = level[temp-1]+1;
                    enqueue(curr_head->data);
                }
                curr_head = curr_head->next;
            }
        }
        printf("%d",level[target-1]-1);
        printf("\n");
        T--;
    }

    return 0;
}
