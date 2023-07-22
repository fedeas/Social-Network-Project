package social.network;

import java.awt.Toolkit;
import java.awt.event.WindowEvent;
import javax.swing.table.DefaultTableModel;
import static social.network.NetWork.Users;
import static social.network.NetWork.UsersArray;

public class Accept_Reject_Friends extends javax.swing.JFrame {

    public Accept_Reject_Friends() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jTextField1 = new javax.swing.JTextField();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();
        jLabel1 = new javax.swing.JLabel();
        jButton3 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "ID", "EMAIL"
            }
        ));
        jScrollPane1.setViewportView(jTable1);

        jButton1.setText("Accept");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("Decline");

        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jTextArea1.setText("Write the ID and\npress the action you\nwant");
        jScrollPane2.setViewportView(jTextArea1);

        jLabel1.setText("ID:");

        jButton3.setText("Back");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 433, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jButton1)
                            .addComponent(jButton2)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                .addComponent(jLabel1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 54, Short.MAX_VALUE)
                                .addComponent(jTextField1, javax.swing.GroupLayout.Alignment.LEADING)))
                        .addGap(0, 0, Short.MAX_VALUE))))
            .addGroup(layout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(jButton3))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 330, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 84, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(33, 33, 33)
                .addComponent(jButton1)
                .addGap(40, 40, 40)
                .addComponent(jButton2)
                .addGap(98, 98, 98)
                .addComponent(jButton3))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
    public static String IDnew;
    public static int IdCheck;
    public static String RemoveEmail;
    //The add button
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        IDnew = jTextField1.getText();
        IdCheck =Integer.parseInt(IDnew);
        RemoveEmail = UserFRs[IdCheck][1];
        int i = 0;
        boolean flag = false;
        //Adds the current user to the user he accepted and removes him from the requestlist
        while (i<UserFRs.length && flag==false)
        {
            if(UserFRs[IdCheck][1].equals(RemoveEmail))
            {
                 
                 Users.get(UsersArray[IdCheck][0]).getFriendList();
                 Users.get(UsersArray[IdCheck][0]).RemoveListRequest();
                 flag = true;
            }
            i++;
        }
        
        i = 0;
        flag = false;
        //Adds the user we want to your friendlist and deletes him from the pendinglist
        while (i<UserFRs.length && flag==false)
        {
            if(UserFRs[i][1].equals(Authenticator.Email))
            {
                 Users.get(UsersArray[i][0]).getFriendList2();
                 Users.get(UsersArray[i][0]).RemoveListPending();
                 flag = true;
            }
            i++;
        }
        //Creates a new table
        Array2D1();     
    }//GEN-LAST:event_jButton1ActionPerformed
    //Back Button
    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
      WindowEvent winClosingEvent = new WindowEvent(this,WindowEvent.WINDOW_CLOSING);
      Toolkit.getDefaultToolkit().getSystemEventQueue().postEvent(winClosingEvent);
      Menu menu4  = new Menu();
      menu4.setVisible(true);
    }//GEN-LAST:event_jButton3ActionPerformed
    
    public static String[][] UserFRs;
    //From list to array
    public void ListToArray(){
       int i = 0;
       boolean flag = false;
       while (i<NetWork.UsersArray.length && flag==false)
        {
            if(NetWork.UsersArray[i][1].equals(NetWork.Email))
            {
                
               UserFRs = new String[ Users.get(UsersArray[i][0]).UserFriendRequests.size()][2];
               flag = true;
            }
            i++;
        }
        i = i - 1;
        String[] array = new String[Users.get(UsersArray[i][0]).UserFriendRequests.size()];
        Users.get(UsersArray[i][0]).UserFriendRequests.toArray(array); // fill the array
        
        for (i = 0; i<Users.get(UsersArray[i][0]).UserFriendRequests.size(); i++)
        {
            UserFRs[i][0] = Integer.toString(i);
            UserFRs[i][1] = array[i];
        }
        
    }
    public void Array2D1(){    
      //The creation of our Jtable from the 2DArray
      DefaultTableModel  model = (DefaultTableModel)jTable1.getModel();
      for (int i= 0; i<UserFRs.length; i++)
      {
        String[] row = new String[UserFRs[i].length];
            
        for (int j = 0; j < UserFRs[i].length; j++)
        {
            row[j] = UserFRs[i][j];
        }
           model.addRow(row);
      }
       
     } 
    public static void main(String args[]) {

        
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Accept_Reject_Friends().setVisible(true);
            }
        });
}
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTable jTable1;
    private javax.swing.JTextArea jTextArea1;
    private javax.swing.JTextField jTextField1;
    // End of variables declaration//GEN-END:variables
}
