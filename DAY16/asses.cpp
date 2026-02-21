#include <iostream>
#include<array>
using namespace std;

#define MAX 5
enum CAR_feature{
    EngineControl = 0,
    FuelSystem,
    Ignition,
    SensorModule,
    LoggingSystem
};
int graph[MAX][MAX] = {0};
array<bool,MAX>visited={false};

string CAR_feature(int node)
{
    switch(node) 
    {
        case EngineControl: return "EngineControl";
        case FuelSystem: return "FuelSystem";
        case Ignition: return "Ignition";
        case SensorModule: return "SensorModule";
        case LoggingSystem: return "LoggingSystem";
        default: return "Unknown";
    }
}


// DFS function
void  dfs(int node)
{
    visited[node] = true;
    for(int i = 0; i < MAX; i++)
    {
        if(graph[node][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
    cout << "Activating Feature: " << CAR_feature(node)<< endl;
}
int main()
{
    graph[EngineControl][FuelSystem] = 1;
    graph[EngineControl][Ignition] = 1;
    graph[FuelSystem][SensorModule] = 1;
    graph[Ignition][SensorModule] = 1;
    graph[SensorModule][LoggingSystem] = 1;

    cout << "Starting ECU Activation:\n";

    dfs(EngineControl);
}
