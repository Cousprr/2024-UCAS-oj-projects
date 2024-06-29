#include <stdio.h>
#include <stdlib.h>
int num;
int graph[100][100];
int v,w;
int graph_temp[100][100];

void insertVex(int v){
    if(v>=num){
        for(int i=num;i<=v;i++){
            for(int j=0;j<=v;j++){
                graph[i][j]=0;
                graph[j][i]=0;
            }
        }
        num=v+1;
    }
    else{
        for(int i=0;i<=num;i++){
            for(int j=i;j<=num;j++){
                if(i<v && j<v){
                    graph_temp[i][j]=graph[i][j];
                    graph_temp[j][i]=graph[j][i];
                }
                else if(i==v || j==v){
                    graph_temp[i][j]=0;
                    graph_temp[j][i]=0;
                }
                else if(i<v&&j>v){
                    graph_temp[i][j]=graph[i][j-1];
                    graph_temp[j][i]=graph[j-1][i];
                }
                else{
                    graph_temp[i][j]=graph[i-1][j-1];
                    graph_temp[j][i]=graph[j-1][i-1];
                }
            }
        }
        num=num+1;
        for(int i=0;i<=num;i++){
            for(int j=0;j<=num;j++){
                graph[i][j]=graph_temp[i][j];
            }
        }
    }
}
void deleteVex(int v){
    if(v>=num){
        printf("Invalid Input");
    }
    else{
        for(int i=0;i<=num;i++){
            for(int j=i;j<=num;j++){
                if(i<v && j<v){
                    graph_temp[i][j]=graph[i][j];
                    graph_temp[j][i]=graph[j][i];
                }
                else if(i==v || j==v){
                    continue;
                }
                else if(i<v&&j>v){
                    graph_temp[i][j-1]=graph[i][j];
                    graph_temp[j-1][i]=graph[j][i];
                }
                else{
                    graph_temp[i-1][j-1]=graph[i][j];
                    graph_temp[j-1][i-1]=graph[j][i];
                }
            }
        }
        num=num-1;
        for(int i=0;i<=num;i++){
            for(int j=0;j<=num;j++){
                graph[i][j]=graph_temp[i][j];
            }
        }
    }
}
void insertArc(int v,int w){
    graph[v][w]=1;
    graph[w][v]=1;
}
void deleteArc(int v,int w){
    graph[v][w]=0;
    graph[w][v]=0;
}

void judge(char input[]){
    v=0,w=0;
    switch(input[0]){
        case 'I':
            switch(input[1]){
                case'A':
                    scanf("%d %d",&v,&w);
                    insertArc(v,w);
                    break;
                case 'V':
                    scanf("%d",&v);
                    insertVex(v);
                    break;
                default:
                    printf("Invalid Input");
                    break;
            }
            break;
        case 'D':
            switch(input[1]){
                case'A':
                    scanf("%d %d",&v,&w);
                    deleteArc(v,w);
                    break;
                case 'V':
                    scanf("%d",&v);
                    deleteVex(v);
                    break;
                default:
                    printf("Invalid Input");
                    break;
            }
            break;
        default:
            printf("Invalid Input");
            break;
    }
}

void print(){
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(j==0)printf("%d",graph[i][j]);
            else printf(" %d",graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    char input[100];
    while(1){
        if(~scanf("%s",input)){
            judge(input);
            input[0]='\0';
            input[1]='\0';
        }
        else{
            print();
            break;
        }
        
    }
    return 0;
}