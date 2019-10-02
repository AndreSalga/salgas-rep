package grafo;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import static java.sql.Types.NULL;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Queue;
import java.util.StringTokenizer;

public class Grafo {

    ArrayList<Integer>[] adj;
    ArrayList<Integer>[] adj_inv;

    @SuppressWarnings("unchecked")
    public Grafo() {
        this.adj = new ArrayList[0];
    }

    public int getNumVertices() {
        return adj.length;
    }

    public List<Integer> getAdjacentes(int v) {

        return adj[v];
    }

    public int getGrau(int v) {
        // basta retornar o tamanho da lista que é a quantidade de vizinhos
        return adj[v].size();
    }

    @SuppressWarnings("unchecked")
    public void lerArquivo(String nomeArquivo) throws IOException {
        BufferedReader inputFile = new BufferedReader(new FileReader(nomeArquivo));
        StringTokenizer tokenizer;

        String line;
        int numVertices;

        line = inputFile.readLine();
        numVertices = Integer.parseInt(line.trim());
        this.adj = new ArrayList[numVertices];

        String sucessorStr;
        int sucessor;

        for (int v = 0; v < numVertices; v++) {
            this.adj[v] = new ArrayList();

            line = inputFile.readLine();
            tokenizer = new StringTokenizer(line);

            while (tokenizer.hasMoreTokens()) {
                sucessorStr = tokenizer.nextToken();
                sucessor = Integer.parseInt(sucessorStr.trim());

                if (sucessor != -1) {
                    this.insereAresta(v, sucessor);
                }
            }
        }
    }

    /**
     * Insere uma aresta do vertice "v" para o v�rtice "u".
     */
    private void insereAresta(int v, int u) {
        adj[v].add(u);

    }

    private int getAresta(int v, int u) {
        adj[v].get(u);
        return u;

    }

    public String toString() {
        StringBuilder builder = new StringBuilder();

        for (int i = 0; i < adj.length; i++) {
            builder.append("Adj[");
            builder.append(i);
            builder.append("] = ");
            //adj[i].get(i);
            //System.out.println(adj[i].get(i));
            builder.append(adj[i].toString().replace('[', '{').replace(']', '}'));
            builder.append("   Grau = ");
            builder.append(this.getGrau(i));
            builder.append("\n");
        }
        return builder.toString();
    }

    public int[] preenchevetorGrau(int vetorGrau[]) {
        int i, v = 0;
        for (i = 0; i < this.adj.length; i++) {
            vetorGrau[i] = this.getGrau(i);
        }
        return vetorGrau;
    }

    public void preencheMatrizAdj(int MatrizAdj[][], ArrayList<Integer>[] adj2) {
        List<Integer>[] aux = new ArrayList[this.getNumVertices()];
        int j;
        int i;
        //int p = -1;
        for (i = 0; i < adj2.length; i++) {
            for (j = 0; j < adj2[i].size(); j++) {
                aux[i] = adj2[i];
                if (aux[i].get(j) != -1) {
                    MatrizAdj[i][aux[i].get(j)] = 1;
                }
                // System.out.printf("%1d  ", aux[i].get(v));
            }
            //System.out.printf(" - ");// formata o grafo por vertice; se /n
        }
        //exibe como vetor todos os vertices do grafo
        System.out.printf("\n\n");
    }

    public void Imprime_listaAdjacente() {
        List<Integer>[] aux = new ArrayList[this.getNumVertices()];
        int j;
        int i = 0;
        for (i = 0; i < adj.length; i++) {
            for (j = 0; j < this.adj[i].size(); j++) {
                aux[i] = this.adj[i];

                System.out.printf("%1d  ", this.adj[i].get(j));
            }
            //System.out.printf(" - ");// formata o grafo por vertice; se /n
        }
        //exibe como vetor todos os vertices do grafo
        System.out.printf("\n\n");
    }

    public void Preenche_ListaAdjacenteInv() {
        // List<Integer>[] aux = new ArrayList[this.getNumVertices()];
        int j;
        int i = 0;
        for (i = this.adj.length; i <= 0; i--) {
            for (j = this.adj[i].size(); j <= 0; j++) {
                this.adj_inv[i].add(this.adj[i].get(j));
            }
            //System.out.printf(" - ");// formata o grafo por vertice; se /n
        }
        //this.Imprime_listaAdjacente();
    }

    public void IniciarMatriz(int[][] Matriz) {
        int i, j;
        for (i = 0; i < this.adj.length; i++) {
            for (j = 0; j < this.adj.length; j++) {
                Matriz[i][j] = 0;
            }
        }
    }

    public void ImprimeMatriz(int Matriz[][]) {
        int i;
        int j;
        for (i = 0; i < this.adj.length; i++) {
            for (j = 0; j < this.adj.length; j++) {
                System.out.printf("% 1d", Matriz[i][j]);
            }
            System.out.printf("\n");
        }
        System.out.printf("\n");
    }

    public void imprimeVetor(int Vetor[]) {
        int i;

        for (i = 0; i < this.adj.length; i++) {

            System.out.printf(" - %1d ", Vetor[i]);
        }
        System.out.printf("\n\n");
    }

    public void imprimeVetor(String Vetor[]) {
        int i;

        for (i = 0; i < this.adj.length; i++) {

            System.out.printf(" - %s ", Vetor[i].toString());
        }
        System.out.printf("\n\n");
    }

    public void BFS(int s) {
        //List<Integer>[] aux = new ArrayList[this.getNumVertices()];
        //int v;
        int u = 0;
        String[] cor = new String[this.adj.length];
        double d[] = new double[this.adj.length];
        int ante[] = new int[this.adj.length];
        Queue<Integer> q = new LinkedList();

        for (int i = 0; i < adj.length; i++) {
            cor[i] = "BRANCO";
            d[i] = 0;
        }
        cor[u] = "BRANCO";
        d[u] = Double.POSITIVE_INFINITY;
        ante[u] = NULL;
        cor[s] = "CINZA";
        // d[s] = 0;
        q.add(s);
        Iterator<Integer> i;
        while (!q.isEmpty()) {
            u = q.poll();
            i = adj[u].listIterator();
            while (i.hasNext()) {
                int v = i.next();
                if (cor[v].equals("BRANCO")) {
                    d[v] = d[u] + 1;
                    ante[v] = u;
                    cor[v] = "CINZA";
                    q.add(v);
                }

                System.out.printf("BFS:\n\n");
                System.out.printf("ante :");
                this.imprimeVetor(ante);
                System.out.printf("Cor :");
                this.imprimeVetor(cor);
                System.out.printf("Distancia:  ");
                for (int r = 0; r < this.adj.length; r++) {
                    System.out.printf(" %s ", d[r]);
                }
                System.out.printf("\n");
            }
            cor[u] = "PRETO";
        }

        //this.imprimeVetor(d);
        //System.out.printf(" - ");// formata o grafo por vertice; se /n
        // }
        System.out.printf("\nFINAL + BFS:\n\n");
        System.out.printf("ante :");
        this.imprimeVetor(ante);
        System.out.printf("Cor :");
        this.imprimeVetor(cor);
        System.out.printf("Distancia:  ");
        for (int r = 0; r < this.adj.length; r++) {
            System.out.printf(" %s ", d[r]);
        }
        System.out.printf("\n");
    }
    // Recursive DFS
public void dfsStart(int s) {
        int tempo = 0;
        int v = 0;
        String[] cor = new String[this.adj.length];
        int i[] = new int[this.adj.length];
        int f[] = new int[this.adj.length];
        int ante[] = new int[this.adj.length];
        for (int u = 0; u < adj.length; u++) {
            cor[u] = "BRANCO";
            i[u] = f[u] = -1;
            ante[u] = -1;
        }
        tempo = 1;
        dfsVisit(s, cor, i, f, ante, tempo);
        System.out.printf("\n\n#FINAL => DFS:\n\n");
        System.out.printf("ante :");
        this.imprimeVetor(ante);
        System.out.printf("Cor :");
        this.imprimeVetor(cor);
    }
    public void dfsVisit(int u, String[] cor, int[] i, int[] f, int[] ante, int tempo) {
        int v;
        cor[u] = "cinza";
        i[u] = tempo++;
        ListIterator<Integer> it = adj[u].listIterator();
        while (it.hasNext()) {
            v = it.next();
            if (cor[v].equals("BRANCO")) {
                ante[v] = u;
                dfsVisit(v, cor, i, f, ante, tempo);
            }
            System.out.printf("DFS:\n\n");
            System.out.printf("ante :");
            this.imprimeVetor(ante);
            System.out.printf("Cor :");
            this.imprimeVetor(cor);
        }
        cor[u] = "PRETO";
        f[u] = tempo++;
        
    }

    
}
/* A eficiência tá aqui - ver para prova e 2°GQ
void BFS(int s) 
    { 
        // Mark all the vertices as not visited(By default 
        // set as false) 
        boolean visited[] = new boolean[V]; 
  
        // Create a queue for BFS 
        LinkedList<Integer> queue = new LinkedList<Integer>(); 
  
        // Mark the current node as visited and enqueue it 
        visited[s]=true; 
        queue.add(s); 
  
        while (queue.size() != 0) 
        { 
            // Dequeue a vertex from queue and print it 
            s = queue.poll(); 
            System.out.print(s+" "); 
  
            // Get all adjacent vertices of the dequeued vertex s 
            // If a adjacent has not been visited, then mark it 
            // visited and enqueue it 
            Iterator<Integer> i = adj[s].listIterator(); 
            while (i.hasNext()) 
            { 
                int n = i.next(); 
                if (!visited[n]) 
                { 
                    visited[n] = true; 
                    queue.add(n); 
                } 
            } 
        } 
    } 

void DFSUtil(int v,boolean visited[]) 
    { 
        // Mark the current node as visited and print it 
        visited[v] = true; 
        System.out.print(v+" "); 
  
        // Recur for all the vertices adjacent to this vertex 
        Iterator<Integer> i = adj[v].listIterator(); 
        while (i.hasNext()) 
        { 
            int n = i.next(); 
            if (!visited[n]) 
                DFSUtil(n, visited); 
        } 
    } 
  
    // The function to do DFS traversal. It uses recursive DFSUtil() 
    void DFS(int v) 
    { 
        // Mark all the vertices as not visited(set as 
        // false by default in java) 
        boolean visited[] = new boolean[V]; 
  
        // Call the recursive helper function to print DFS traversal 
        DFSUtil(v, visited); 
    } 

*/
