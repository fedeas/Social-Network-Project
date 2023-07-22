package social.network;

import java.util.List;
import java.util.ArrayList;



public class User extends FriendRequest { 
    public static List<String> UserFriendList;
    public static List<String> UserPendingRequests;
    public static List<String> UserFriendRequests;
    //List with his Friends.
    public void UserFriends(){
        UserFriendList = new ArrayList<>();
      //  UserFriendList.clear();
    }
    //List with the requests that he sent
    public  void UserPendingReq(){
        UserPendingRequests = new ArrayList<>();
      //  UserPendingRequests.clear();
    }
    //List with friend requests that he has to answer
    public void UserFriendReq(){
        UserFriendRequests = new ArrayList<>();
     //   UserFriendRequests.clear();
    }
    //Request = The Email of the user who is currently log in
    String Request;
    public   List<String> getListRequest() {
        Request = Authenticator.Email;
        UserFriendRequests.add(Request);
        return  UserFriendRequests;
    }

    public  List<String> getListPending() {
        UserPendingRequests.add(PendingEmail);
        return UserPendingRequests;
    }
    //List of friends from the accepted user
    public List<String> getFriendList() {
        
        UserFriendList.add(Accept_Reject_Friends.RemoveEmail);
        return UserFriendList;
    }
    //List of friends from the current user
     public List<String> getFriendList2() {
        
        UserFriendList.add(Authenticator.Email);
        return UserFriendList;
    }
     //Removes the current user from the list he was invited
     public List <String> RemoveListRequest(){
         UserFriendRequests.remove(Authenticator.Email);
         return UserFriendRequests;
     }
     //Removes the user who sent the request
      public List <String> RemoveListPending(){
          UserPendingRequests.remove(Accept_Reject_Friends.RemoveEmail);
          return UserPendingRequests;
      }
    
    

    
    public static void main(){
        
   }
}