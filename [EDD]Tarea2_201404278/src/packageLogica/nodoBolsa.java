
package packageLogica;

/**
 *
 * @author GUDIEL
 */
public class nodoBolsa {
    
    Object dato;
    nodoBolsa siguiente;
    
    public nodoBolsa(Object dato){
        this.dato=dato;
        this.siguiente=this;
    }
    
}
