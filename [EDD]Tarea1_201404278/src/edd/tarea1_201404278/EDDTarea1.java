
package edd.tarea1_201404278;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import javax.swing.JOptionPane;
import java.util.ArrayList;
/**
 *
 * @author GUDIEL
 */
public class EDDTarea1 extends javax.swing.JFrame {

    ArrayList<Object> listaPrimos = new ArrayList<Object>();
    ArrayList<Object> clonacion = new ArrayList<Object>(); //PARA MODIFICAR DATOS
    
    public EDDTarea1() {
        initComponents();
        this.setLocationRelativeTo(null);
        rb1.setSelected(true);
        txtIngresarNumero.enable(false);
        txtCantidad.enable(false);
        txtListaNumeros.enable(false);
        btt2.setEnabled(false);        
        
    }

    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        rb1 = new javax.swing.JRadioButton();
        rb2 = new javax.swing.JRadioButton();
        jLabel1 = new javax.swing.JLabel();
        txtIngresarFecha = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        txtDiaDeSemana = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        txtIngresarNumero = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        txtCantidad = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        txtListaNumeros = new javax.swing.JTextArea();
        btt1 = new javax.swing.JButton();
        btt2 = new javax.swing.JButton();
        jLabel6 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jPanel1.setBackground(new java.awt.Color(0, 0, 102));
        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        rb1.setFont(new java.awt.Font("Dialog", 0, 18)); // NOI18N
        rb1.setForeground(new java.awt.Color(255, 0, 0));
        rb1.setText("DETERMINAR DIA DE LA SEMANA");
        rb1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                rb1ActionPerformed(evt);
            }
        });
        jPanel1.add(rb1, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 20, 330, -1));

        rb2.setFont(new java.awt.Font("Dialog", 0, 18)); // NOI18N
        rb2.setForeground(new java.awt.Color(255, 0, 0));
        rb2.setText("ALGORITMO ' Criba de Eratostenes '");
        rb2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                rb2ActionPerformed(evt);
            }
        });
        jPanel1.add(rb2, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 190, 330, -1));

        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setText("INGRESE FECHA:");
        jPanel1.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 70, -1, -1));
        jPanel1.add(txtIngresarFecha, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 70, 140, 30));

        jLabel2.setForeground(new java.awt.Color(255, 255, 255));
        jLabel2.setText("RESULTADO:");
        jPanel1.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 130, -1, -1));
        jPanel1.add(txtDiaDeSemana, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 130, 140, 30));

        jLabel3.setForeground(new java.awt.Color(255, 255, 255));
        jLabel3.setText("INGRESE NUMERO:");
        jPanel1.add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 250, -1, -1));
        jPanel1.add(txtIngresarNumero, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 240, 140, 30));

        jLabel4.setForeground(new java.awt.Color(255, 255, 255));
        jLabel4.setText("CANTIDAD:");
        jPanel1.add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 300, -1, -1));
        jPanel1.add(txtCantidad, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 290, 140, 30));

        jLabel5.setForeground(new java.awt.Color(255, 255, 255));
        jLabel5.setText("LISTA DE NUMEROS:");
        jPanel1.add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 360, -1, -1));

        txtListaNumeros.setColumns(20);
        txtListaNumeros.setRows(5);
        jScrollPane1.setViewportView(txtListaNumeros);

        jPanel1.add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 340, 370, 70));

        btt1.setText("COMPILAR");
        btt1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btt1ActionPerformed(evt);
            }
        });
        jPanel1.add(btt1, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 90, 120, 50));

        btt2.setText("COMPILAR");
        btt2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btt2ActionPerformed(evt);
            }
        });
        jPanel1.add(btt2, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 260, 120, 50));

        jLabel6.setForeground(new java.awt.Color(255, 255, 255));
        jLabel6.setText("EJ. 01/07/1995");
        jPanel1.add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 90, -1, -1));

        getContentPane().add(jPanel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 570, 440));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btt1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btt1ActionPerformed
        obtenerDia();
    }//GEN-LAST:event_btt1ActionPerformed

    private void btt2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btt2ActionPerformed
        listaPrimos.clear();
        clonacion.clear();
        try 
        {
            if (Integer.parseInt(txtIngresarNumero.getText())>0) 
            {
                numerosPrimos();
            }else
            {
                JOptionPane.showMessageDialog(null, "INGRESAR NUMERO MAYOR QUE CERO!");
            }
            
        } catch (Exception e) 
        {
            JOptionPane.showMessageDialog(null, "INGRESE NUMERO NATURAL!");
        }
        
    }//GEN-LAST:event_btt2ActionPerformed

    private void rb1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_rb1ActionPerformed
        rb1.setSelected(true);
        rb2.setSelected(false);
        txtIngresarNumero.enable(false);
        txtCantidad.enable(false);
        txtListaNumeros.enable(false);
        btt2.setEnabled(false);
        txtIngresarFecha.enable(true);
        txtDiaDeSemana.enable(true);
        btt1.setEnabled(true);
        limpiar();
    }//GEN-LAST:event_rb1ActionPerformed

    private void rb2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_rb2ActionPerformed
        rb1.setSelected(false);
        rb2.setSelected(true);
        txtIngresarFecha.enable(false);
        txtDiaDeSemana.enable(false);
        btt1.setEnabled(false);
        txtIngresarNumero.enable(true);
        txtCantidad.enable(true);
        txtListaNumeros.enable(true);
        btt2.setEnabled(true);
        limpiar();
    }//GEN-LAST:event_rb2ActionPerformed

    void obtenerDia()
    {
        
        SimpleDateFormat df = new SimpleDateFormat("dd/MM/yyyy");
        Date fechaActual;
        String fech="01/01/1700";
        try {
            
        fechaActual = df.parse(txtIngresarFecha.getText());
        
            if (fechaActual.before(df.parse(fech))==true)//antes de 1700
            {
               JOptionPane.showMessageDialog(null, "NO SE PERMITE FECHA ANTERIOR A 1700");

                
            }else
            {
                GregorianCalendar fechaCalendario = new GregorianCalendar();
                fechaCalendario.setTime(fechaActual);
                int diaSemana = fechaCalendario.get(Calendar.DAY_OF_WEEK);

                if (diaSemana == 1) {
                txtDiaDeSemana.setText("DOMINGO");
                } else if (diaSemana == 2) {
                txtDiaDeSemana.setText("LUNES");
                } else if (diaSemana == 3) {
                txtDiaDeSemana.setText("MARTES");
                } else if (diaSemana == 4) {
                txtDiaDeSemana.setText("MIERCOLES");
                } else if (diaSemana == 5) {
                txtDiaDeSemana.setText("JUEVES");
                } else if (diaSemana == 6) {
                txtDiaDeSemana.setText("VIERNES");
                } else if (diaSemana == 7) {
                txtDiaDeSemana.setText("SABADO");
                }
            }              
                
        } catch (Exception e) 
        {
            JOptionPane.showMessageDialog(null, "ERROR AL INGRESAR FECHA");
        }
        
        
    }
    
    void numerosPrimos()
    {
        Integer valor=Integer.parseInt(txtIngresarNumero.getText()); //valor ingresado
        Integer valorObtenido;
        Integer valorObtenido2;
        Integer contadorDeNumerosPrimos=0;
        String valorObtenido3;
        String numeroPrimos="";
        
        for (int i = 2; i <= valor; i++) 
        {            
            listaPrimos.add(i); //se agregan a la lista desde el numero 2
            clonacion.add(i); //se hace una clonacion de lista para modificar datos
        }
        
        System.out.println(clonacion); //impresion de todos los numeros de la lista
        
        for (int i = 0; i < listaPrimos.size(); i++) 
        {            
            try 
            {
                valorObtenido=Integer.parseInt(listaPrimos.get(i).toString()); //obtener valor del indice 0 ej. el valor de 2
            
                for (int j = i+1; j < listaPrimos.size(); j++) //empieza a recorrer de i+1, desde posicion 2, por ej. desde el valor de 3
                {
                    valorObtenido2=Integer.parseInt(listaPrimos.get(j).toString()); //obtener valor del indice j (el valor que le sigue) ej. el valor de 3

                    if (valorObtenido2%valorObtenido==0) // si el modulo = 0  Ej. 3 / 2  
                    {
                         clonacion.set(j, "eliminado"); //para cada multiplo que encuentra se le envia "eliminar" en el indice correspondiente
                    }
                }                            
            } catch (Exception e) 
            {
            }
                        
        }
        
        System.out.println(clonacion); //impresion de lista con los numeros eliminados
        
        for (int k = 0; k < clonacion.size(); k++) //para agregar los numeros datos al textArea
        {
            valorObtenido3=clonacion.get(k).toString();
            
            if (!valorObtenido3.equals("eliminado")) //si es diferente de "eliminado"
            {
                numeroPrimos=numeroPrimos + valorObtenido3+", ";
                contadorDeNumerosPrimos=contadorDeNumerosPrimos+1;
            }
        }
        
        txtCantidad.setText(contadorDeNumerosPrimos.toString());
        txtListaNumeros.setText(numeroPrimos);
        
        
    }
    
    void limpiar()
    {
        txtCantidad.setText("");
        txtDiaDeSemana.setText("");
        txtIngresarFecha.setText("");
        txtIngresarNumero.setText("");
        txtListaNumeros.setText("");
    }
    
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(EDDTarea1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(EDDTarea1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(EDDTarea1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(EDDTarea1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new EDDTarea1().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btt1;
    private javax.swing.JButton btt2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JRadioButton rb1;
    private javax.swing.JRadioButton rb2;
    private javax.swing.JTextField txtCantidad;
    private javax.swing.JTextField txtDiaDeSemana;
    private javax.swing.JTextField txtIngresarFecha;
    private javax.swing.JTextField txtIngresarNumero;
    private javax.swing.JTextArea txtListaNumeros;
    // End of variables declaration//GEN-END:variables
}
