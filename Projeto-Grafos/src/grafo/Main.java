package grafo;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {

    /**
     * @param args - Not used
     * @throws IOException - May happen when reading a file
     */
    public static void main(String[] args) throws IOException {
        Grafo g = new Grafo();
        int MaxNumVertices = 50;
        int[][] MatrizAdjacentes = new int[MaxNumVertices][MaxNumVertices];
        int[][] MatrizAdjacentesInv = new int[MaxNumVertices][MaxNumVertices];
        int[] vetorGrau = new int[MaxNumVertices];
       int[] vetorGrauInv = new int[MaxNumVertices];
        //int i, j = 0;
        System.out.println(g);
        g.lerArquivo("grafo-01.txt");
        System.out.println(g);
       // g.Imprime_listaAdjacente();
       g.Preenche_ListaAdjacenteInv();
        g.Imprime_listaAdjacente();
       g.IniciarMatriz(MatrizAdjacentes);
        g.IniciarMatriz(MatrizAdjacentesInv);
        g.preencheMatrizAdj(MatrizAdjacentes,g.adj);
        //g.preencheMatrizAdj(MatrizAdjacentesInv,g.adj_inv);
        //g.preencheMatrizAdj(MatrizAdjacentesInv);
        System.out.println("Matriz Adjacente :");
        g.ImprimeMatriz(MatrizAdjacentes);
        System.out.println("Matriz Adjacente Inv. :");
        g.ImprimeMatriz(MatrizAdjacentesInv);
        g.preenchevetorGrau(vetorGrau);
        System.out.printf("VetorGrau: ");
        g.imprimeVetor(vetorGrau);
        g.BFS(5);
        g.dfsStart(5);
        

    }

}
