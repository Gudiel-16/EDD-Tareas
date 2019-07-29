
package packageLogica;

/**
 *
 * @author GUDIEL
 */
public class bolsa {
    
    nodoBolsa ultimo;
    
    public bolsa()
    {
        this.ultimo=null;
    }
    
    //para verificar si esta vacia
    public boolean estaVacia()
    {
        return ultimo==null;
    }
    
    //para insertar un elemento
    public bolsa insertar(Object elemento)
    {
        nodoBolsa temp = new nodoBolsa(elemento);//se crea un nodo

        if (ultimo != null) {//si ya hay por lo menos un nodo
            temp.siguiente = ultimo.siguiente;//el puntero siguiente del nuevo nodo es igual al primer nodo (ultimo.siguiente quiere decir que apunta al primero)
            ultimo.siguiente = temp;//el ultimo nodo apunta al nuevo nodo creado
        } else {
            ultimo = temp;
        }
        return this;
    }
    
    //para saber cuentos elementos hay
    public int cuantos()
    {
        int contador=0;
        nodoBolsa actual=ultimo.siguiente;
        
        do {
            contador++;
            actual=actual.siguiente; 
        } while (actual!=ultimo.siguiente);
                
        return contador;
    }
    
    public int cuantosApartirDeElemento(Object elemento)
    {
        int contador=0;  
        int op;
        
        if (elemento=="") {
            System.out.println("ajaja");
        }
        boolean encontrado=false;
        nodoBolsa actual=ultimo;
                
        while (actual.siguiente!=ultimo && !encontrado) //cuantos hay desde el 0 hasta que encuentra el elemento
        {            
            encontrado=(actual.siguiente.dato==elemento);
            if (!encontrado) 
            {
                actual=actual.siguiente;
            }
            contador++;
        }
                
        op=contador-1;
        
        return op;
    }
    
    
    
}
