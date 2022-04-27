pragma solidity ^0.5.0;
contract ApprovalContract {
 address   public sender;
 address payable public receiver;
 address constant public approver = 0xC10674bFce6a9933db3Dd6F4ee895b8970Ab5b78;
 function deposit(address payable _receiver) external payable {
    require(msg.value > 0);
    sender = msg.sender;
    receiver = _receiver; 
   
 }
 function approve() external payable {
      if(receiver==approver){
    receiver.transfer(address(this).balance  );}
  
 }
 
}