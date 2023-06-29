#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* vertices[MAX_NODES];
} Graph;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        graph->vertices[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, char src, char dest) {
    int srcIndex = src - 'A';
    int destIndex = dest - 'A';

    Node* newNode = createNode(dest);
    newNode->next = graph->vertices[srcIndex];
    graph->vertices[srcIndex] = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->vertices[destIndex];
    graph->vertices[destIndex] = newNode;
}

void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        Node* currentNode = graph->vertices[i];
        if (currentNode != NULL) {
            printf("Adjacency list of vertex %c: ", i + 'A');
            while (currentNode != NULL) {
                printf("%c ", currentNode->data);
                currentNode = currentNode->next;
            }
            printf("\n");
        }
    }
}

void breadthFirstSearch(Graph* graph, char startNode) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    int startIndex = startNode - 'A';

    visited[startIndex] = 1;
    queue[rear++] = startIndex;

    printf("BFS Traversal: ");
    while (front != rear) {
        int currentNodeIndex = queue[front++];
        printf("%c ", currentNodeIndex + 'A');

        Node* currentNode = graph->vertices[currentNodeIndex];

        // Sort the neighbors before enqueueing them
        int neighbors[MAX_NODES];
        int numNeighbors = 0;
        while (currentNode != NULL) {
            int neighborIndex = currentNode->data - 'A';
            if (visited[neighborIndex] == 0) {
                neighbors[numNeighbors++] = neighborIndex;
                visited[neighborIndex] = 1;
            }
            currentNode = currentNode->next;
        }

        // Sort the neighbors
        for (int i = 0; i < numNeighbors - 1; i++) {
            for (int j = 0; j < numNeighbors - i - 1; j++) {
                if (neighbors[j] > neighbors[j + 1]) {
                    int temp = neighbors[j];
                    neighbors[j] = neighbors[j + 1];
                    neighbors[j + 1] = temp;
                }
            }
        }

        // Enqueue the sorted neighbors
        for (int i = 0; i < numNeighbors; i++) {
            queue[rear++] = neighbors[i];
                }
    }
    printf("\n");
}

void depthFirstSearchUtil(Graph* graph, int currentIndex, int visited[MAX_NODES]) {
    visited[currentIndex] = 1;
    printf("%c ", currentIndex + 'A');

    Node* currentNode = graph->vertices[currentIndex];

    // Sort the neighbors before recursively traversing them
    int neighbors[MAX_NODES];
    int numNeighbors = 0;
    while (currentNode != NULL) {
        int neighborIndex = currentNode->data - 'A';
        if (visited[neighborIndex] == 0) {
            neighbors[numNeighbors++] = neighborIndex;
            visited[neighborIndex] = 1;
        }
        currentNode = currentNode->next;
    }

    // Sort the neighbors
    for (int i = 0; i < numNeighbors - 1; i++) {
        for (int j = 0; j < numNeighbors - i - 1; j++) {
            if (neighbors[j] > neighbors[j + 1]) {
                int temp = neighbors[j];
                neighbors[j] = neighbors[j + 1];
                neighbors[j + 1] = temp;
            }
        }
    }

    // Recursively traverse the sorted neighbors
    for (int i = 0; i < numNeighbors; i++) {
        depthFirstSearchUtil(graph, neighbors[i], visited);
    }
}

void depthFirstSearch(Graph* graph, char startNode) {
    int visited[MAX_NODES] = {0};
    int startIndex = startNode - 'A';

    printf("DFS Traversal: ");
    depthFirstSearchUtil(graph, startIndex, visited);
    printf("\n");
}

void insertNode(Graph* graph, char newNode) {
    int newNodeIndex = newNode - 'A';

    if (graph->vertices[newNodeIndex] == NULL) {
        Node* node = createNode(newNode);
        graph->vertices[newNodeIndex] = node;
    }
}

void deleteEdge(Graph* graph, char src, char dest) {
    int srcIndex = src - 'A';
    int destIndex = dest - 'A';

    // Delete edge from src to dest
    Node* currentNode = graph->vertices[srcIndex];
    Node* prevNode = NULL;

    while (currentNode != NULL && currentNode->data != dest) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode != NULL) {
        if (prevNode == NULL) {
            graph->vertices[srcIndex] = currentNode->next;
        } else {
            prevNode->next = currentNode->next;
        }

        free(currentNode);
    }

    // Delete edge from dest to src (for undirected graph)
    currentNode = graph->vertices[destIndex];
    prevNode = NULL;

    while (currentNode != NULL && currentNode->data != src) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode != NULL) {
        if (prevNode == NULL) {
            graph->vertices[destIndex] = currentNode->next;
        } else {
            prevNode->next = currentNode->next;
        }

        free(currentNode);
    }
}

void deleteVertex(Graph* graph, char vertex) {
    int vertexIndex = vertex - 'A';

    // Delete all edges connected to the vertex
    Node* currentNode = graph->vertices[vertexIndex];

    while (currentNode != NULL) {
        char connectedVertex = currentNode->data;
        deleteEdge(graph, vertex, connectedVertex);
        currentNode = graph->vertices[vertexIndex];  // Update currentNode after deleting the edge
    }

    // Free the vertex node
    free(graph->vertices[vertexIndex]);
    graph->vertices[vertexIndex] = NULL;
}




int main() {
    Graph* graph = createGraph();

    // Adding edges to the graph
    addEdge(graph, 'A', 'B');
    addEdge(graph, 'B', 'C');
    addEdge(graph, 'B', 'D');
    addEdge(graph, 'D', 'E');
    addEdge(graph, 'E', 'F');
    addEdge(graph, 'C', 'D');
    //addEdge(graph, 'C', 'G');
    //addEdge(graph, 'E', 'G');

    // Printing the graph
    printf("Graph before deletion:\n");
    printGraph(graph);

    // Deleting an edge
    deleteEdge(graph, 'E', 'F');

    // Deleting a vertex
    deleteVertex(graph, 'A');

    printf("\nGraph after deletion:\n");
    printGraph(graph);

    // Performing BFS traversal
    printf("\n");
    breadthFirstSearch(graph, 'B');

    // Performing DFS traversal
    printf("\n");
    depthFirstSearch(graph, 'B');

    return 0;
}