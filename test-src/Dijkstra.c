#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INF 0xFFFFFFFF

typedef enum { false, true } bool;

unsigned int dijkstra(
    unsigned int size,
    unsigned int *graph )
{
  unsigned int resultant[size];
  bool fixed[size];
  unsigned int i, v, current_vertex = 0;
  resultant[0] = 0;
  for( i=1; i<size; i++)
  {
    resultant[i] = INF;
    fixed[i] = false;
  }

  while(true)
  {
    fixed[current_vertex] = true;
    unsigned int distance = resultant[current_vertex];
    // for each edge from current_vertex
    for( v=0; v<size; v++)
    {
      if( graph[current_vertex*size +v] < INF )
      {
        // assign new distance if lower than previous
        unsigned int vdistance = distance + graph[current_vertex*size +v];
        if( vdistance < resultant[v] ) resultant[v] = vdistance;
      }
    }
    // find lowest distance not yet fixed
    unsigned int min = INF;
    for( v=0; v<size; v++)
    {
      if( fixed[v] ) continue;
      if( resultant[v] < min)
      {
        min = resultant[v];
        current_vertex = v;
      }
    }
    // exit if reached end vertex or if no more edges
    if(current_vertex == size - 1) return resultant[size-1];
    if(min >= INF)
    {
      printf("No path to final vertex.\n");
      exit(1);
    }
  }
}

int main()
{
  // create a graph
  unsigned int size = 0x6000;
  unsigned int *graph = (unsigned int *)malloc(sizeof(unsigned int)*size*size);
  int i,j;
  srand(size);
  for( i=0; i<size; i++)
  {
    for( j=0; j<size; j++)
    {
      if(i==j) graph[i*size +j] = 0;
      else if(j==size-1) graph[i*size +j] = INF;
      else graph[i*size +j] = (rand() % 0xFFFFFF00)+1;
    }
  }
  graph[(rand() % size-1)*size + size-1] = 0xFFFFFF01;
  // call dijkstra's algorithm
  unsigned int answer = dijkstra( size, graph);
  free(graph);
}
