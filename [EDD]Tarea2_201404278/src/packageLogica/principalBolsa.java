
package packageLogica;

/**
 *
 * @author GUDIEL
 */
public class principalBolsa {
    
    public static void main(String[] args)
    {
        bolsa miLista=new bolsa();
        
        System.out.println("Esta Vacia? " + miLista.estaVacia());
        
        miLista.insertar(10);
        miLista.insertar("gudiel");
        miLista.insertar(20);
        miLista.insertar(30);
        miLista.insertar(40);
        miLista.insertar(50.5);
        miLista.insertar("Estructura");
        miLista.insertar("De");
        miLista.insertar("Datos");
        
        System.out.println("La lista tiene: " + miLista.cuantos() + " elementos");
        System.out.println("Despues de cierto elemento hay: " + miLista.cuantosApartirDeElemento(30) + " elementos");
        System.out.println("Despues de cierto elemento hay: " + miLista.cuantosApartirDeElemento("Estructura") + " elementos");
        System.out.println("Despues de cierto elemento hay: " + miLista.cuantosApartirDeElemento("gudiel") + " elementos");
        System.out.println("Esta Vacia? " + miLista.estaVacia());
    }
    
}
