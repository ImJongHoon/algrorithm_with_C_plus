#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    int key;
    struct vertex* link;
} Vertex;

typedef struct head {
    struct vertex* a_vertex;
} headVertex;

#define MAX_VERTEX_SIZE 10

#define MAX_STACK_SIZE 10

//DFS를 구현하기 위한 stack. 배열하나당 자료형은 vertex의 주소.
Vertex* stack[MAX_STACK_SIZE];
int top = -1;

Vertex* pop();
void push(Vertex* a_vertex);//인자로 주소


#define MAX_QUEUE_SIZE 10
Vertex *queue[MAX_QUEUE_SIZE];
int front = 0;
int rear = 0;//원형큐

int visited[MAX_VERTEX_SIZE] = {0};//모든 배열 0으로 초기화. 0이면 그래프의 vertex에 방문 안 했고, 1이면 방문 했음.

Vertex* deQueue();
void enQueue(Vertex* a_vertex);


int initializeGraph(headVertex** h);//헤드 vertex의 list를 동적할당
int freeGraph(headVertex* h);//동적할당 해제. 배열인 헤드와 배열 안에 들어있는 리스트를 모두 해제해줘야 함
int insertVertex(headVertex* h);
void insertEdge(headVertex* h, int edge_first, int edge_second);//엣지도 삽입해야 했나?

Vertex* find_header(headVertex* h, int num);
int insert_tail(Vertex* vertex, int _key);
void printGraph(headVertex* h);

void depthFirstSearch(headVertex* h, int start_vertex);
Vertex* stack_top();
int adjacent(Vertex* a_vertex);
void breathFirstSearch(headVertex *h, int start_vertex);

int main(){

    char command;
    int key;
    int edge_first;
    int edge_second;
    int start_vertex;

    headVertex* headvertex = NULL;

    do{
        printf("\n\n");
		printf("-------[2018038074]----------------------[ImJongHoon]-----------\n");
		printf("                   Graph Searches                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph      = z                                       \n");
		printf(" Insert Vertex         = v      Insert Edge                  = e \n");
		printf(" Depth First Search    = d      Breath First Search          = b \n");
		printf(" Print Graph           = p      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

        switch(command){
        case 'z': case 'Z':
            initializeGraph(&headvertex);
            break;
        case 'q': case 'Q':
            freeGraph(headvertex);
        case 'v': case 'V':
			insertVertex(headvertex);
			break;
        case 'e': case 'E':
            printf("Please input first vertex in edge: ");//edge로 연결된 두개의 vertex 입력받음
            scanf("%d", &edge_first);
            printf("Please input second vertex in edge. : ");
			scanf("%d", &edge_second);
			if(edge_first==edge_second){
				printf("You can't make self edge. \n");
				break;
			}
            if(edge_first >= MAX_VERTEX_SIZE || edge_second >= MAX_VERTEX_SIZE){
                printf("\nInput value exceed max vertex size. Please try agian\n");
				break;
            }
            insertEdge(headvertex, edge_first, edge_second);
            break;
        case 'p': case 'P':
			printGraph(headvertex);
			break;
        case 'd': case 'D':
			printf("Please input start vertex : ");
			scanf("%d", &start_vertex);
            depthFirstSearch(headvertex, start_vertex);
            break;
        case 'b': case 'B':
			printf("Please input start vertex : ");
			scanf("%d", &start_vertex);
            breathFirstSearch(headvertex, start_vertex);
			break;
        default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
        
        }

    }while(command != 'q' && command != 'Q');

    return 0;
}

int initializeGraph(headVertex** h){
    if(*h != NULL){
        free(*h);
    }

    (*h) = (headVertex*)malloc(sizeof(headVertex) * MAX_VERTEX_SIZE);

    for(int a=0; a<MAX_VERTEX_SIZE; a++){
        (*h)[a].a_vertex = NULL;
    }

    return 1;
}

int freeGraph(headVertex* h){
    headVertex* head = h;
    Vertex* temp = NULL;
    Vertex* p = NULL;
    int a = 0;

    for(a=0; head + a != NULL; a++){
        p = head[a].a_vertex;
        while(p != NULL){
            temp = p;//해제할 노드를 저장
            p = p->link;
            free(temp);
        }
    }

    //마지막에 동적할당한 배열 해제
	free(h);
	return 0;
}

int insertVertex(headVertex* h){
    if(h == NULL){
        printf("You should initialize graph\n");
		return 0;
    }

    int num = 0;

    for(num=0; num<MAX_VERTEX_SIZE; num++){
        if((h+num)->a_vertex == NULL){
            Vertex* node = (Vertex*)malloc(sizeof(Vertex));
            node->key = num;
            node->link = NULL;
            (h+num)->a_vertex =node;
            return 1;
        }
    }

    //for문이 끝까지 다 돌면
	printf("Graph is full!!\n\n");
	return 0;
}

void insertEdge(headVertex* h, int edge_first, int edge_second){
	Vertex* first_vertex = find_header(h, edge_first);
	Vertex* second_vertex = find_header(h, edge_second);//동적할당 받은 정점의 주소 저장

	if(first_vertex == NULL || second_vertex == NULL){//둘 중하나라도 NULL이면, 즉 둘 중 하나라도 아직 생성된 정점이 아니면
		printf("There is no vertex which you find\n");
		return ;
	}

	insert_tail(first_vertex, second_vertex->key);
	insert_tail(second_vertex, first_vertex->key);
}

Vertex* find_header(headVertex* h, int num){//리스트의 첫번째, 즉 정점의 주소를 반환하는 함수
	return (h+num)->a_vertex;
}

int insert_tail(Vertex* vertex, int _key){//인자로 끝에 추가해줄 vertex와, 추가할 vertex의 번호를 준다.
	//여기서 vertex는 헤드 vertex배열에 저장된 vertex노드
	Vertex* node = (Vertex*)malloc(sizeof(Vertex));
	node->key = _key;//값 할당
	node->link = NULL;//주소 NULL 할당

	while(vertex->link != NULL){//vertex의 끝으로 이동

		if(vertex->link->key == _key){//edge 중복 입력시 예외처리!
			printf("Edge already exist!\n");
			return 0;
		}
		vertex = vertex->link;
	}
	vertex->link = node;//vertex의 끝에 추가
	return 1;
}

void printGraph(headVertex* h){
	Vertex* node = NULL;
	int a=0;

	while((h+a)->a_vertex != NULL && a<MAX_VERTEX_SIZE){//vertex head 의 배열을 바깥쪽 반복문으로
		printf("Vertex [%d] : ", a);// 정점 출력
		node = (h+a)->a_vertex->link;//해당 정점의 다음 주소를 저장

		while(node != NULL){//edge로 연결된 부분 출력
			printf("[%d] ", node->key);
			node = node->link;
		}
		printf("\n");
		a++;
	}
}