package social.network;

import java.awt.Toolkit;
import java.awt.event.WindowEvent;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
import static social.network.NetWork.Users;
import static social.network.NetWork.UsersArray;


public class FriendRequest extends javax.swing.JFrame{
public static String ID;
public static Integer MaxFriends = 20;
    public FriendRequest() {
       initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();
        jTextField1 = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Add Friends");

        jTable1.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "ID", "EMAIL"
            }
        ));
        jTable1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jTable1MouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(jTable1);

        jScrollPane2.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);

        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jTextArea1.setText("Enter the ID of the user\nyou would like to add.");
        jScrollPane2.setViewportView(jTextArea1);

        jTextField1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField1ActionPerformed(evt);
            }
        });

        jButton1.setText("Add");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("Back");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 284, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, 55, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jButton1)
                            .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 248, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(0, 22, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addComponent(jButton2)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 350, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 63, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(28, 28, 28)
                        .addComponent(jButton1)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jButton2))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jTextField1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField1ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextField1ActionPerformed

    private void jTable1MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jTable1MouseClicked
        //If to not be able to edit the table
        boolean a=jTable1.isEditing();
        if (a==false)
        {
            JOptionPane.showMessageDialog(null,"You can not edit this table");
        }
    }//GEN-LAST:event_jTable1MouseClicked
        int CheckID;
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
       ID = jTextField1.getText();
       CheckID = Integer.parseInt(ID);		
       String CheckString = String.valueOf(NoFriends[CheckID][1]);
       //Checks if you are trying to add yourself which is invalid.
        if (Authenticator.Email.equals(CheckString))
       { 
           JOptionPane.showMessageDialog(null,"You can not add yourself.");
       }
       else
       {
            RequestList(); 
            PendingList();
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
      //Close the add friend window and opens a new menu
      WindowEvent winClosingEvent = new WindowEvent(this,WindowEvent.WINDOW_CLOSING);
      Toolkit.getDefaultToolkit().getSystemEventQueue().postEvent(winClosingEvent);
      Menu menu3  = new Menu();
      menu3.setVisible(true);
    }//GEN-LAST:event_jButton2ActionPerformed
    //The email of the user we want to send a friend request
    static String PendingEmail;
    String Status;
    //Status Rejected = -1, Pending = 0, Accepted = 1
    public void PendingList()
     { 
       PendingEmail = String.valueOf(NoFriends[CheckID][1]);
       Status = "Pending";
       int i = 0;
       boolean flag = false;
       //Filling the User we are adding with our information
       while (i<NetWork.UsersArray.length && flag==false)
        {
            if(NetWork.UsersArray[i][1].equals(PendingEmail))
            {
                Users.get(UsersArray[i][0]).getListPending();
                flag = true;
            }
            i++;
        }
       

        }
    
    public void RequestList()
    { 
        int i = 0;
        boolean flag = false;
        //Filling the current user with the information of the user we are adding
        while (i<=NetWork.UsersArray.length && flag==false)
        {
            if(NetWork.UsersArray[i][1].equals(NetWork.Email))
            {
                Users.get(UsersArray[i][0]).getListRequest();
                flag = true;
            }
           i++;
        }
      
}
    
    //Creates a new hashmap will all the non-friends of the user.
    public static HashMap<String, String> NotFriends = new HashMap<>();
    //Method to Fill the Hashmap
    public void FillNoFriends(){
        HashMap<String , String> usersInformation = NetWork.usersInformation;
        int SizeMain;
        SizeMain = usersInformation.size();
        String[] Size = new String[SizeMain];
          for (int i=0; i<SizeMain; i++) {
            Size[i]= (String) usersInformation.keySet().toArray()[i];     
            NotFriends.put(Integer.toString(i),Size[i]);
        }
        
    }
    
    
    
    //Creation of 2D Array
    public static Object[][] NoFriends = new Object[MaxFriends][2];
    //Method to go from HashMap to 2DArray
    public  void HashMapTo2D() {
   
   
    Set entries = NotFriends.entrySet();
    Iterator entriesIterator = entries.iterator();

    int i = 0;
    while(entriesIterator.hasNext())
        {
            Map.Entry mapping = (Map.Entry) entriesIterator.next();
            NoFriends[i][0] = mapping.getKey();
            NoFriends[i][1] = mapping.getValue();
            i++;
        }
    } 
     public void Array2D(){    
      //The creation of our Jtable from the 2DArray
      DefaultTableModel  model = (DefaultTableModel)jTable1.getModel();
      for (int i= 0; i<NoFriends.length; i++)
      {
        Object[] row = new Object[NoFriends[i].length];
            
        for (int j = 0; j < NoFriends[i].length; j++)
        {
            row[j] = NoFriends[i][j];
        }
           model.addRow(row);
      }
       
     } 
    
    public void main(String args[]) {

    } 
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTable jTable1;
    private javax.swing.JTextArea jTextArea1;
    private javax.swing.JTextField jTextField1;
    // End of variables declaration//GEN-END:variables
}
