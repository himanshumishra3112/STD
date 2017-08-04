public class ATMMachine {
	ATMState hasCard;     
	ATMState noCard;
	ATMState hasCorrectPin;
	ATMState atmOutOfMoney;
	ATMState atmState;
	int cashInMachine = 2000;
	boolean correctPinEntered = false;
	public ATMMachine(){
		hasCard = new HasCard(this);
		noCard = new NoCard(this);
		hasCorrectPin = new HasPin(this);
		atmOutOfMoney = new NoCash(this);
		atmState = noCard;
		if(cashInMachine < 0){
			atmState = atmOutOfMoney;
		}
	}
	void setATMState(ATMState newATMState){
		atmState = newATMState;
	}
	public void setCashInMachine(int newCashInMachine){
		cashInMachine = newCashInMachine;
	}
	public void insertCard() {
		atmState.insertCard();
	}
	public void ejectCard() {
		atmState.ejectCard();
	}
	public void requestCash(int cashToWithdraw) {
		atmState.requestCash(cashToWithdraw);
	}
	public void insertPin(int pinEntered){
		atmState.insertPin(pinEntered);
	}
	public ATMState getYesCardState() { return hasCard; }
	public ATMState getNoCardState() { return noCard; }
	public ATMState getHasPin() { return hasCorrectPin; }
	public ATMState getNoCashState() { return atmOutOfMoney; }
}
public interface ATMState {
	void insertCard();
	void ejectCard();
	void insertPin(int pinEntered);
	void requestCash(int cashToWithdraw);
}
public class HasCard implements ATMState {
	ATMMachine atmMachine;
	public HasCard(ATMMachine newATMMachine){
		atmMachine = newATMMachine;
	}
	public void insertCard() {
		System.out.println("You can only insert one card at a time");
	}
	public void ejectCard() {
		System.out.println("Your card is ejected");
		atmMachine.setATMState(atmMachine.getNoCardState());
	}
	public void requestCash(int cashToWithdraw) {
		System.out.println("You have not entered your PIN");
	}
	public void insertPin(int pinEntered) {
		if(pinEntered == 1234){
			System.out.println("You entered the correct PIN");
			atmMachine.correctPinEntered = true;
			atmMachine.setATMState(atmMachine.getHasPin());
		} else {
			System.out.println("You entered the wrong PIN");
			atmMachine.correctPinEntered = false;
			System.out.println("Your card is ejected");
			atmMachine.setATMState(atmMachine.getNoCardState());
		}	
	}	
}
