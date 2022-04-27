var ApprovalContract = artifacts.require("Dice.sol");
module.exports = function(deployer) {
 deployer.deploy(ApprovalContract);
}