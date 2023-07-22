package social.network;

import java.util.HashMap;
import java.util.Map;
import javax.swing.JOptionPane;

public class NetWork extends Authenticator{
    // Create a HashMap object called usersInformation
public static   HashMap<String, String> usersInformation = new HashMap<>(); 
   public static  void savemode(){
    //We create a bool variable to be able to check the Key of the Hashmap
    boolean isKeyPresent = false;
    String KeyToCheck = Email;
     //We create a bool variable to be able to check the Value of the Hashmap
    boolean isValuePresent = false;
    String ValueToCheck = Username;
    //We check if the key and value are inside the HashMap
    isKeyPresent = usersInformation.containsKey(KeyToCheck);
    isValuePresent = usersInformation.containsValue(ValueToCheck);
    if (isKeyPresent == true && isValuePresent == true)
    { 
      //Open the new menu if both key and value are True
      Menu menu  = new Menu();
      menu.setVisible(true);
    }
    else if (isKeyPresent == true && isValuePresent==false)
    {
      //If key is true and value false we get a message says wrong username
      NetWork wrong = new NetWork();
      wrong.WrongUser();
    }
    else
    {
        //If both are false we get the message to register the new account
        NetWork message = new NetWork();
        message.msg();        
    }
    
   }
    //Creates a map with key  his User(Number) and value the class Users
    public static Map<String, User> Users = new HashMap<String, User>();
    //Creates an array which saves in the first column the User(number) and in the second column his email
    public static String UsersArray [][] = new String[20][2];
    //The method that contains the message of a new account registration
    public void msg(){
        int k = 0;
        int o = 2;
        int  YesOrNo;
        YesOrNo = JOptionPane.showConfirmDialog(null,"Want to register the new account?","",JOptionPane.YES_NO_OPTION);
        if(YesOrNo == 0)
        {
         //
         usersInformation.put(Email,Username);
         while (Users.containsKey("User"+k)) //Check to see if an account already has this ID
          {
             k++;
          }
         User us = new User();
         Users.put("User"+k, us);
         us.UserFriendReq();
         us.UserFriends();
         us.UserPendingReq();
         UsersArray[o][0]= "User"+k;
         UsersArray[o][1]= Email;
         o++;
        
         
         Menu menu  = new Menu();
         menu.setVisible(true);
        }
        else
        {
         Authenticator framescreen  = new Authenticator();
         framescreen.setVisible(true);
        }
    }
    //The method that contains the message of the invalid username
    public void WrongUser(){
        int  YesOrNo;
        YesOrNo = JOptionPane.showConfirmDialog(null,"Wrong Username.Try again?","",JOptionPane.YES_NO_OPTION);
        if(YesOrNo == 0)
        {        
         Authenticator framescreen  = new Authenticator();
         framescreen.setVisible(true);
        }
        else
        {
         this.dispose();
        }
    }
    // public static User User0 = new User();
    // public static User User2 = new User();
    public static void main(){
        //Some ready user infromation
        usersInformation.put("C3", "Acathan");
        usersInformation.put("C2", "Hello");
        User us = new User();
        Users.put("User0", us);
        us.UserFriendReq();
        us.UserFriends();
        us.UserPendingReq();
        UsersArray[0][0]= "User0";
        UsersArray[0][1]= "C3";
        Users.put("User1", us);
        us.UserFriendReq();
        us.UserFriends();
        us.UserPendingReq();
        UsersArray[1][0]= "User1";
        UsersArray[1][1]= "C2";
        
        
   }
} 