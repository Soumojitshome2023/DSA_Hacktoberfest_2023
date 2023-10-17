import java.util.*;

class DijkstraAlgorithm {
    private int V; // Number of vertices
    private List<List<Node>> graph;

    public DijkstraAlgorithm(int V) {
        this.V = V;
        graph = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            graph.add(new ArrayList<>());
        }
    }

    public void addEdge(int source, int destination, int weight) {
        Node node = new Node(destination, weight);
        graph.get(source).add(node);
    }

    public void dijkstra(int source) {
        int[] distance = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[source] = 0;

        PriorityQueue<Node> minHeap = new PriorityQueue<>(V, Comparator.comparingInt(a -> a.weight));
        minHeap.add(new Node(source, 0));

        while (!minHeap.isEmpty()) {
            int u = minHeap.poll().node;

            for (Node neighbor : graph.get(u)) {
                int v = neighbor.node;
                int weight = neighbor.weight;

                if (distance[u] != Integer.MAX_VALUE && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    minHeap.add(new Node(v, distance[v]));
                }
            }
        }

        printShortestPaths(distance, source);
    }

    private void printShortestPaths(int[] distance, int source) {
        System.out.println("Shortest distances from source vertex " + source + ":");
        for (int i = 0; i < V; i++) {
            System.out.println("Vertex " + i + ": " + distance[i]);
        }
    }

    public static void main(String[] args) {
        int V = 6;
        DijkstraAlgorithm graph = new DijkstraAlgorithm(V);

        graph.addEdge(0, 1, 4);
        graph.addEdge(0, 2, 2);
        graph.addEdge(1, 3, 3);
        graph.addEdge(1, 2, 5);
        graph.addEdge(2, 3, 7);
        graph.addEdge(3, 4, 2);
        graph.addEdge(4, 0, 4);
        graph.addEdge(4, 1, 4);
        graph.addEdge(4, 5, 6);

        int sourceVertex = 0;
        graph.dijkstra(sourceVertex);
    }

    static class Node {
        int node;
        int weight;

        public Node(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }
}
